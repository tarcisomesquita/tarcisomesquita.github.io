/* $Id: recv.c,v 1.21 2003/11/24 10:00:19 dublet Exp $
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

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>	/* XXX: needed to fix bug in NetBSD's <arpa/inet.h> */
#include <arpa/inet.h>

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "parse.h"
#include "file.h"
#include "http.h"
#include "dhttpd.h"
#include "log.h"
#include "mime.h"
#include "time-func.h"
#include "types.h"

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

#ifdef HAVE_QOS
#include <qos/qos.h>
#endif

#ifndef RELEASE
extern unsigned int debug;
#endif
extern struct config *conf;

int read_data(conn_t *conn)
{
    int numbytes = 0;

    if (conn->f.is_secure == 1) {
#ifdef HAVE_OPENSSL
	if ((numbytes = SSL_read(conn->req->ssl_s,
				 conn->req->recv_buf,
				 BUFLEN)) <= 0) {
            switch (SSL_get_error(conn->req->ssl_s, numbytes)) {
		case SSL_ERROR_ZERO_RETURN:
		case SSL_ERROR_WANT_CONNECT:
		case SSL_ERROR_WANT_X509_LOOKUP:
		case SSL_ERROR_SYSCALL:
		case SSL_ERROR_SSL:
		    ERROR("SSL_read() failed\n");
		    conn->state = FAULT;
		    return -2;
		case SSL_ERROR_WANT_READ:
		case SSL_ERROR_WANT_WRITE:
		case SSL_ERROR_NONE:
		default:
		    break;
	    } 
	} else /* XXX Assumes we're done with reading */
	     conn->state = READ; 
#else
	FATAL("MAJOR FUCKUP REPORTING FOR DUTY, SIR!!\n");
#endif
    } else {
	if ((numbytes = RECV(conn->s, conn->req->recv_buf,
			     BUFLEN, 0)) == -1) {
	    if (errno != EAGAIN) {
		SETTITLE;
		conn->state = FAULT;
		perror("recv()");
		return -1;
	    }
	} else /* XXX Assumes we're done with reading */
	    conn->state = READ; 
    }

    return numbytes;
}

int read_request(conn_t *conn)
{
    int numbytes = 0;

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("About to receive client data\n");
#endif

    numbytes = read_data(conn);

#ifndef RELEASE
    if (debug)
	DEBUG_OUT3("%d bytes read from index %d\n", numbytes, conn->sock_num);
#endif

    return numbytes;
}

/* Actions needed upon entering the reading state of a connection */
void read_child(conn_t *conn)
{
#ifndef RELEASE
    if (debug)
	DEBUG_OUT("In child, about to read request\n");
#endif

    if (read_request(conn) == -1) {
	conn->state = FAULT;	
	return;
    }

    parse_request(conn);
}
