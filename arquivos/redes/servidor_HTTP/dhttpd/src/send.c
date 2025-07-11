/* $Id: send.c,v 1.69 2004/01/08 15:14:27 dublet Exp $
 *
 * Dublet's HTTP Daemon                                                      
 *
 * Released under BSD license
 * Copyright (c) 2002, Dublet
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 *
 *     * Redistributions of source code must retain the above copyright 
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright 
 *       notice, this list of conditions and the following disclaimer in 
 *       the documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Dublet nor the names of its contributors 
 *       may be used to endorse or promote products derived from this 
 *       software without specific prior written permission.
 *     * All advertising materials mentioning features or use of this software
 *	 must display the following acknowledgement:
 *	    This product includes software developed by Dublet.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER 
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef HAVE_WARN
#include <err.h>
#endif

#ifdef HAVE_OPENSSL
# include <openssl/err.h>
# include <openssl/ssl.h>
#endif

#ifdef HAVE_LINUX_ZCT
# include <sys/sendfile.h>
#endif

#include "file.h"
#include "children.h"
#include "http.h"
#include "dhttpd.h"
#include "log.h"
#include "mime.h"
#include "time-func.h"
#include "types.h"
#include "send.h"
#include "additional.h"
#include "cache.h"
#include "parse.h"

#ifdef HAVE_QOS
#include <qos/qos.h>
#endif

#define HTTP_VERSION "HTTP/1.1"
/* XXX: If you add here, mind the size of the header downwards! */
#define ALLOWED "GET, POST, HEAD, TRACE"
#ifndef RELEASE
extern unsigned int debug;
#endif
extern struct config *conf;
extern struct connection **client_sockets;

int send_data(const void *data, const int len, conn_t *conn)
{
    int numbytes = 0;

    if (conn->f.is_secure == 1) {
#ifdef HAVE_OPENSSL
	if ((numbytes = SSL_write(conn->req->ssl_s, data, len)) <= 0) {
	    conn->state = FAULT;
	    SETTITLE;
	    perror("sendfile()");
	    ERROR("SSL_write() failed\n");
	    return -1;
	}
#else
	DEBUG_OUT("This shouldn't happen!\n");
	return -1;
#endif				/* HAVE_OPENSSL */
    } else {
#ifdef HAVE_LINUX_ZCT
	if (data == NULL) {
	    if ((numbytes = sendfile(conn->s, conn->req->fd, conn->req->offset,
			    len)) == -1) {
		conn->state = FAULT;
		SETTITLE;
		perror("send()");
		return -1;
	    }
	} else
#endif
	if ((numbytes = SEND(conn->s, data, len, 0)) == -1) {
	    if (errno == ENOBUFS || errno == EAGAIN) {
		if (conn->send_interval) 
		    conn->send_interval *= 2;
		else 
		    conn->send_interval = 2;

		if (!conn->last_success) 
		    time(&conn->last_success);
	    } else {
		conn->state = FAULT;
		SETTITLE;
		return -1;
	    }
	} else {
	    conn->send_interval = 0;
	    if (!time(&conn->last_success)) {
#ifndef RELEASE
		DEBUG_OUT2("time() failed!? %s\n", strerror(errno));
#endif
	    }
	}
    }

    return numbytes;
}

int send_header(conn_t *conn)
{
    /* const char *crlf = "\r\n"; */
    char header[HEADER_MAX_LEN + 1], date[32], filesize[10], response[4];
    const char *mime_type;
    const char *response_text = http_response_text(&conn->req->response);
    int i = 0, k = 0;

#define ADD_CRLF strncat(header, crlf, 2);
#define ADD_CRLF2 header[k++]='\r'; header[k++]='\n';
#define APPEND(a, b) for (i = 0; b[i]; i++, k++) if (k < HEADER_MAX_LEN) a[k] = b[i]; else break;

    get_rfc_date(time(NULL), date);

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Putting header data into buffer\n");
#endif
    
    /* 
     * *sniff* snprintf() looks so much more elegant, but it's slow...
     *
     * ;(
     */ 
    /* Make response line */
    
    APPEND(header, conn->req->http_version);
    header[k++]=' ';
    ultostr((unsigned long)conn->req->response, response);
    response[3] = '\0';
    APPEND(header, response);
    header[k++]=' ';
    APPEND(header, response_text);
    ADD_CRLF2;
    /* Date line */
    APPEND(header, "Date: ");
    APPEND(header, date);
    ADD_CRLF2;
    /* Server identification line */
    APPEND(header, "Server: ");
    APPEND(header, SERVER_VERSION);
    ADD_CRLF2;
    /* Connection type line */
    APPEND(header, "Connection: ");
    if (conn->f.is_persistent) {
	APPEND(header, "Keep-Alive");
    } else {
	APPEND(header, "Close");
    }
    ADD_CRLF2;

    /* We MUST say which methods _are_ allowed if we aren't allowing one */
    if (conn->req->response == 405) {
	APPEND(header, "Allowed: ");
	APPEND(header, ALLOWED);
	ADD_CRLF2;
    }

   /* The WWW-Authenticate response-header field MUST be included in 401
    * (Unauthorized) response messages. */
    if (conn->req->response == 401) { /* XXX: Challenge!? */
	APPEND(header, "WWW-Authenticate: "); 
	APPEND(header, "I challenge thee!");
	ADD_CRLF2;
    }
	
    if ((conn->req->script_type == PLAINTEXT) ||
#ifndef HAVE_PERL
	    (conn->req->script_type == EX_PERL) ||
#endif
	(conn->req->script_type == EX_CGI)) {
	/* RFC2068, section 4.4
	 **
	 * 1. Any response message which MUST NOT include a message-body
	 * (such as the 1xx, 204, and 304 responses and any response to a HEAD
	 * request) is always terminated by the first empty line after the
	 * header fields, regardless of the entity-header fields present in the
	 * message.
	 */
	if ((conn->f.is_persistent == 1 &&
		    (conn->req->response == 204 ||
		     conn->req->response == 304 ||
		     (conn->req->response / 100) == 1)) ||
		conn->req->method != HEAD) {
	    filesize[10] = '\0';
	    APPEND(header, "Content-Length: ");
	    ultostr(conn->req->file_size, filesize);
	    APPEND(header, filesize);
	    ADD_CRLF2;
	}

	/* Append Last-Modified header, if possible.
	 * XXX: May not be accurate especially when 404 upon error */
	if (conn->req->script_type == PLAINTEXT && (conn->req->sbuf != NULL) && 
		(conn->req->sbuf->st_mtime != 0)) {
	    APPEND(header, "Last-Modified: ");
	    get_rfc_date(conn->req->sbuf->st_mtime, date);
	    APPEND(header, date);
	    ADD_CRLF2;
	}

#ifndef RELEASE
	if (debug)
	    DEBUG_OUT("Determening MIME type\n");
#endif

	/* When sending static files, this buffer will be empty, so then it should
	 * always return NULL.
	 * When sending dynamic files, this should happen after the completion of
	 * the script, so we can detect if the script was sending their own content
	 * type.
	 */
	if (strstr(conn->req->file_buf, "Content-Type:") == NULL) {
	    if (conn->req->script_type != PLAINTEXT) {
		/* A script was executed, but it didn't send out it's headers, 
		 * like it should. 
		 * This is seen in Apache as "Premature end of script headers".
		 */
		set_error(conn->req, 500);
		/*return -1;*/
	    } else {
		APPEND(header, "Content-Type: ");
		mime_type = get_mime_type(conn->req);
		APPEND(header, mime_type); 
		ADD_CRLF2; 
		ADD_CRLF2; /* Seperate us and the body */
	    }
	}
    }

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("About to send header\n");
#endif

    if (k >= HEADER_MAX_LEN)
	set_error(conn->req, 500);
    else
    	send_data(header, k, conn);

    return 0;
}

/* Send any file in tiny chunks */
void send_file(conn_t *conn)
{
    void *addr = NULL;
    size_t size;
    off_t offset;

#ifndef RELEASE
    if (debug)
	DEBUG_OUT3("About to read/send file %s (%d)\n",
		   conn->req->file_loc, conn->req->fd);
#endif
    if (conn->req->sent_bytes == 0) {
	/* We send the header at the last moment */
	send_header(conn);
    }

    /* Read into buffer, and send */
    if (conn->req->file_size > conn->req->sent_bytes) {
#ifdef HAVE_LINUX_ZCT		/* XXX: code from send_data() should be here and after defined(HAVE_QOS) */
	conn->req->sent_bytes += send_data(NULL, BUFSIZE, i);
#else
# ifdef HAVE_QOS
	offset = 0;
	size = conn->req->file_size;
# else
	offset = conn->req->sent_bytes;
	size = BUFSIZE;
# endif
	if (conn->req->script_type == PLAINTEXT) {
	    if ((addr = mmap(NULL, size, PROT_READ, MAP_FILE | MAP_SHARED, 
			    conn->req->fd, offset)) == MAP_FAILED) {
#ifndef RELEASE
		if (debug)
		    DEBUG_OUT("Fuck, shit, crap, piss, weener\n");
		perror("mmap");
#endif
		SETTITLE;
		return;
	    } 
# ifdef	HAVE_QOS
	    size = conn->req->file_size;
# else
	    size = (conn->req->file_size > conn->req->sent_bytes + BUFSIZE) ? 
		    BUFSIZE : conn->req->file_size - conn->req->sent_bytes;
# endif
	} else {
	    addr = conn->req->file_buf;
	    size = conn->req->file_size;
	}
	conn->req->sent_bytes += send_data(addr, size, conn);
#endif
    }

    /* Finish up if we've finished sending 
     * XXX: Shouldn't be >=, really.. */
    if (conn->req->sent_bytes >= conn->req->file_size) {
	done_file(conn->req);
	conn->state = SENT;
    }

#ifdef HAVE_LINUX_ZCT
    /* linux zero copy tcp doesn't need any actions here */
#elif defined(HAVE_QOS)
    if (munmap(addr, conn->req->file_size)) {
	SETTITLE;
	DEBUG_OUT("Problem unmapping!\n");
    }
#else
    if (munmap(addr, BUFSIZE)) {
	SETTITLE;
	DEBUG_OUT("Problem unmapping!\n");
    }
#endif

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Done sending\n");
#endif
}

void send_err_during_error(conn_t *conn)
{
    if (conn->req->file_buf == NULL) {
	DEBUG_OUT("Why isn't filebuf allocated?\n");
	abort();
    }	
    
#ifndef RELEASE
    if (debug)
	DEBUG_OUT3("About to send error doc (%d, %d)\n",
		conn->req->response, conn->req->double_err);
#endif

    log_err
	("Couldn't find error document for error %d, using built-in\n",
	 conn->req->response);
    get_error_during_error_doc(&conn->req->response,
			       conn->req->file_buf);
    conn->req->file_size = strlen(conn->req->file_buf);
    send_header(conn);
    send_data(conn->req->file_buf, conn->req->file_size, conn);
}

void send_error(conn_t *conn)
{
#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Sending error file\n");
#endif
    conn->req->script_type = PLAINTEXT; /* Prevents bug trying to execute
					   static error pages as CGI, when 
					   a CGI crapped up. */
    
    close(conn->req->fd);
    conn->req->fd = 0;
    strlcpy(conn->req->file_loc, get_errordocument_name(&conn->req->response), 
	    MAX_STR_LENGTH);
    default_vhost(conn);
    handle_file(conn->req);
    if (proper_file(conn->req) == 0) {
        if (conn->req->method == HEAD)
	   send_header(conn);		/* HEAD only requires the header */
	else 
	    send_file(conn);
    } else
	send_err_during_error(conn);
    conn->state = SENT;
}

/* TRACE sends back the received buffer */
void send_trace(conn_t *conn)
{
    send_header(conn);
    send_data(conn->req->recv_buf,
	      strlen(conn->req->recv_buf), conn);
    conn->state = SENT;
}

void send_response(conn_t *conn)
{
    /* Send an error if in an error state */
    if (conn->state == FAULT || conn->req->error == 1) {
	send_error(conn);
	return;
    }
#ifndef HAVE_QOS    
    if (conn->send_interval && 
	    (time(NULL) < conn->last_success + conn->send_interval)) 
	return; /* Not ready for send, so don't try */
#endif
    /* Decide what action to take upon each method */
    if (conn->req->method == HEAD ||
	    /* Certian responses in HTTP/1.1 disallow us to send any
	     * body, so we wont. */
	    (conn->f.is_persistent == 1 &&
	    (conn->req->response == 204 ||
	    conn->req->response == 304 ||      	    
	    (conn->req->response / 100) == 1))) {
	send_header(conn); /* Send header, and mark for finish */
#ifndef RELEASE
	if (debug) 
	    DEBUG_OUT("HEAD asked, header sent\n");
#endif
	conn->state = SENT;
    } else if (conn->req->cgi_slot) {
	send_header(conn);
	send_data(conn->req->file_buf, conn->req->file_size, conn);
	conn->state = SENT;
    } else switch(conn->req->method) {
	case GET:
	case POST:
	    send_file(conn);
	    break;
	case TRACE:
	    send_trace(conn);
	    break;
	default:
	    send_error(conn);
	    break;
    }
}
