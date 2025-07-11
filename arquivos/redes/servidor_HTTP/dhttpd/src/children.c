/* $Id: children.c,v 1.109 2004/01/09 15:16:24 dublet Exp $
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
#include <pwd.h>
#include <regex.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#if HAVE_CONFIG_H
# include <config.h>
#endif

#ifdef HAVE_WARN
#include <err.h>
#endif

#ifdef HAVE_POLL
#include <poll.h>

/* Some l33n0x distros seem to think POLLRDNORM shouldn't be defined by default
 * */
#ifndef POLLRDNORM
#define POLLRDNORM POLLIN
#endif
#ifndef POLLWRNORM
#define POLLWRNORM POLLOUT
#endif
#else
#error "Your system doesn't have poll()!? The 80s are calling; they want their OS back!"
#endif

#ifdef HAVE_OPENSSL
# include <openssl/err.h>
# include <openssl/ssl.h>
#endif

#include "parse.h"
#include "children.h"
#include "send.h"
#include "recv.h"
#include "file.h"
#include "http.h"
#include "dhttpd.h"
#include "log.h"
#include "types.h"
#include "mime.h"
#include "scripts.h"
#include "additional.h"
#include "cache.h"

#ifdef HAVE_QOS
#include <qos/qos.h>
#endif

/* Some global vars used throughout the functions */
int server_socket;
#ifdef HAVE_OPENSSL
int secure_ss;
SSL_CTX *ctx;
#endif				/* HAVE_OPENSSL */
conn_t **client_sockets;
struct pollfd polls[MAX_POLL];
#ifdef HAVE_OPENSSL
pid_t children[4];
#else
pid_t children[2];
#endif

/* Some global global functions */
#ifndef RELEASE
extern unsigned int debug;
#endif
extern conf_t *conf;

#define FD_POLL(fdes, index, type) 	polls[index].fd = fdes;\
					polls[index].events = type;\
					polls[index].revents = 0;\
					index++;

/* Some signal handlers, this is needed because we need to restore 
 * signal handlers after ignoring them for a tiny bit. XXX: This should probably
 * be done using signal sets!
 */
void main_shutdown(int);
void restart(int);

conn_t *get_conn_at(const int index) {
    if (client_sockets) return client_sockets[index]; else return NULL;
}


void caught_signal(int sig)
{
    log_err("Caught signal %d, performing quick shutdown\n", sig);
    DEBUG_OUT2("Caught signal #%d, aborting!\n", sig);

    CLOSE(server_socket);
#ifdef HAVE_OPENSSL
    close(secure_ss);
#endif				/* HAVE_OPENSSL */

    exit(1);
}

/* Sets proper response code, double if necessary */
void set_error(req_t *req, int error)
{
    if (req->error == 0) {
	req->response = error;
	req->error = 1;
    } else  
        req->double_err = error;
}

/* Simply send error if there was an error */
int handle_error(conn_t *conn)
{
    if (conn->state == FAULT || conn->req->error) { 
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT2("Located error in slot #%d\n", conn->sock_num);
#endif
	send_error(conn);
	return 1;
    }
return 0;
}

void init_conn(conn_t *conn)
{
#ifndef RELEASE 
    if (debug > 1)
	DEBUG_OUT2("initializing connection at index %d\n", conn->sock_num);
#endif

    conn->s = -1;
    conn->state = NEED_ACCEPT;
    MALLOC(conn->sa, sizeof(struct sockaddr_in));
#ifdef HAVE_IPV6
    MALLOC(conn->sa6, sizeof(struct sockaddr_in6));
#endif
    conn->req = NULL;
}

void init_req(conn_t *conn)
{
#ifndef RELEASE
    if (debug)
	DEBUG_OUT("initializing request\n");
#endif

    if (conn->req != NULL) {
#ifndef RELEASE
	if (debug) 
	    DEBUG_OUT2("index %d already has req initialized, "
		    "skipping malloc()ing: prepare for segfaults.\n", 
		    conn->sock_num);
#endif
	memset(conn->req->http_version, 0, MAX_STR_LENGTH);
	memset(conn->req->host, 0, MAX_STR_LENGTH);
	memset(conn->req->referer, 0, MAX_STR_LENGTH);
	memset(conn->req->file, 0, _POSIX_PATH_MAX);
	memset(conn->req->file_loc, 0, _POSIX_PATH_MAX);
	memset(conn->req->recv_buf, 0, BUFLEN);
	memset(conn->req->file_buf, 0, BUFLEN);
	memset(conn->req->useragent, 0, MAX_STR_LENGTH);
    } else {
	MALLOC(conn->req, sizeof(req_t));

	/* We'll need these buffers soon */
	MALLOC(conn->req->http_version, MAX_STR_LENGTH);
	MALLOC(conn->req->host, MAX_STR_LENGTH);
	MALLOC(conn->req->referer, MAX_STR_LENGTH);
	MALLOC(conn->req->file, _POSIX_PATH_MAX);
	MALLOC(conn->req->file_loc, _POSIX_PATH_MAX);
	MALLOC(conn->req->recv_buf, BUFLEN);
	MALLOC(conn->req->file_buf, BUFLEN);
	MALLOC(conn->req->useragent, MAX_STR_LENGTH);
	MALLOC(conn->req->cookie, MAX_STR_LENGTH);

	/* This pointer remains the same, if the request has already been 
	 * initialized */
	conn->req->conn = conn;
    }


    /* Explicitly make some pointers point to nothing */
# ifdef HAVE_OPENSSL
    conn->req->ssl_s = NULL;
# endif				/* HAVE_OPENSSL */
#ifdef HAVE_PERL
    conn->req->perl_argv =
	conn->req->perl_env = NULL;
#endif				/* HAVE_PERL */
#ifdef HAVE_LINUX_ZCT
    conn->req->offset = NULL;
#endif				/* HAVE_LINUX_ZCT */
    conn->req->sbuf = NULL;
    
    /* Set some defaults */
    conn->req->response = 200;
    conn->req->method = UNKNOWN;
    conn->req->file_size =
	conn->req->fd =
	conn->req->sent_bytes =
	conn->f.is_secure =
	conn->f.is_ipv6 =
	conn->f.is_persistent = 
	conn->req->has_cookie = 0;
#ifdef HAVE_PERL
    conn->req->perl_argc = 0;
#endif
    /*conn->req->sockets = client_sockets; */

#ifndef RELEASE
    if (debug > 1)
	DEBUG_OUT("done intializing\n");
#endif
}

void free_req(req_t *req)
{
#ifdef HAVE_OPENSSL
    SSL_free(req->ssl_s);
#endif
    free(req->referer);
    free(req->host);
    free(req->http_version);
    free(req->file_loc);
    free(req->useragent);
    free(req->file);
    free(req->recv_buf);
    free(req->cookie);
    if (req->file_buf) 
	free(req->file_buf);
/*    free(req->date); */
}

void clean_conn(conn_t *conn)
{
#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Cleaning connection at slot #%d\n", conn->sock_num);
#endif
    CLOSE(conn->s);
    free_req(conn->req);
    free(conn->req);
    free(conn->sa);
    conn->s = -1;
    conn->req = NULL;
    conn->sa = NULL;
    conn->vh = NULL;
#ifdef HAVE_IPV6
    if (conn->sa6) 
	free(conn->sa6);
    conn->sa6 = NULL;
#endif /* HAVE_IPV6 */
    conn->state = NEED_ACCEPT;
}

void reset_conn(conn_t *conn)
{
    /* We could easily switch vhosts */
    conn->vh = NULL;
    /* Reset state */
    if (conn->f.is_pipelined == 1)
	conn->state = READ;
    else {
	if (conn->s != -1) CLOSE(conn->s);
	conn->s = -1;
	conn->state = NEED_ACCEPT;
	}
    /* Reset some request specific flags */
    conn->req->error = 0;

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Reset connection\n");
#endif
}

/* Make socket non-blocking */
int setnonblock(int sock)
{
    int opts = 1;

    if (ioctl(sock, FIONBIO, &opts) < 0) {
	SETTITLE;
	perror("ioctl");
	return -2;
    }

    return 0;
}

/* Accept new connection and put it into the queue */
int new_connection(int child_type)
{
    int c_s = -1, i, sin_size = 0;
    struct sockaddr_in cin;
#ifdef HAVE_IPV6
    struct sockaddr_in6 cin6;
#endif/* HAVE_IPV6 */
    struct sockaddr *cp;
    conn_t *queue_place = NULL;

#ifndef RELEASE
    if (debug) 
	DEBUG_OUT("Got new connection\n");
#endif

    if ((child_type & INET6) == INET6 || (child_type & SINET6) == SINET6) {
#ifdef HAVE_IPV6
	cp = (struct sockaddr *)&cin6;
	sin_size = sizeof(cin6);
#else
	FATAL("This shouldn't happen, aborting!\n");
#endif /* HAVE_IPV6 */
    } else {
	cp = (struct sockaddr *)&cin;
	sin_size = sizeof(cin);
    }

    /* accept() connection, and fill info struct */
#ifdef HAVE_OPENSSL
    if (child_type == INET || child_type == INET6) {
#endif
	if ((c_s = ACCEPT(server_socket, cp, &sin_size)) == -1) {
	    SETTITLE;
	    perror("accept()");
	    return -2;
	}
#ifdef HAVE_OPENSSL
    } else if (child_type == SINET || child_type == SINET6) {
	if ((c_s = ACCEPT(secure_ss, cp, &sin_size)) == -1) {
	    SETTITLE;
	    perror("accept()");
	    return -2;
	}
    }
#endif

    setnonblock(c_s);  

    /* Find a place in the backlog */
    for (i = 0; i < conf->backlog; i++) {
	if ((get_conn_at(i)->s == -1) || (get_conn_at(i)->state==NEED_ACCEPT)) {
	    queue_place = get_conn_at(i);

	    queue_place->s = c_s;
	    queue_place->state = QUEUED;
	    if ((child_type & INET6) == INET6 || (child_type & SINET6) == SINET6)  {
#ifdef HAVE_IPV6
		queue_place->f.is_ipv6 = 1;
		memcpy(queue_place->sa6, &cin6, sizeof(cin6));
#else 
		FATAL("IPv6 connection but I was compiled without IPv6 and I'm not even listen to a AF_INET6 socket!\n");
#endif /* HAVE_IPV6 */
	    } else {
		queue_place->f.is_ipv6 = 0;
		memcpy(queue_place->sa, &cin, sizeof(cin));
	    }
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT2("queued at place #%d\n", i);
#endif
	    break;
	}
#ifndef RELEASE
	else if (debug)
	    DEBUG_OUT2("place %d taken\n", i);
#endif
    }

    /* If the socket hasn't been queued, close it */
    if (queue_place == NULL) {
	CLOSE(c_s);
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT("Failed to queue client\n");
#endif
	return -4;
    }

    /* Must unclog socket to avoid trouble */
    if (setnonblock(queue_place->s) < 0) {
#ifndef RELEASE
	DEBUG_OUT("Cannot set nonblock\n");
#endif
	queue_place->f.is_persistent = 0;
	queue_place->state = FAULT;
	return -3;
    }

    init_req(queue_place);

#ifdef HAVE_OPENSSL
    /* Set up the SSL socket on top of the normal one */
    if ((child_type & SINET) == SINET || (child_type & SINET6) == SINET6) {
	queue_place->req->ssl_s = SSL_new(ctx);
	SSL_set_fd(queue_place->req->ssl_s, c_s); 
	queue_place->f.is_secure = 1;
	if (SSL_accept(queue_place->req->ssl_s) == -1)
	    ERR_print_errors_fp(stderr);
    }
#endif

    return 0;
}

#ifdef HAVE_OPENSSL
void ShowCerts(SSL * ssl)
{
    X509 *cert;
    char *line;

    cert = SSL_get_peer_certificate(ssl);	/* Get certificates (if available) */
    if (cert != NULL) {
	DEBUG_OUT("Server certificates:\n");
	line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
	DEBUG_OUT2("Subject: %s\n", line);
	free(line);
	line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
	DEBUG_OUT2("Issuer: %s\n", line);
	free(line);
	X509_free(cert);
    } else
	DEBUG_OUT("No certificates.\n");
}

void LoadCertificates(char *CertFile, char *KeyFile)
{
    /* set the local certificate from CertFile */
    if (SSL_CTX_use_certificate_file(ctx, CertFile, SSL_FILETYPE_PEM) <= 0) {
	ERR_print_errors_fp(stderr);
	a_lot_of_panic();
    }
    /* set the private key from KeyFile (may be the same as CertFile) */
    if (SSL_CTX_use_PrivateKey_file(ctx, KeyFile, SSL_FILETYPE_PEM) <= 0) {
	ERR_print_errors_fp(stderr);
	a_lot_of_panic();
    }
    /* verify private key */
    if (!SSL_CTX_check_private_key(ctx)) {
	DEBUG_OUT("Private key does not match the public certificate\n");
	a_lot_of_panic();
    }
}

int initServerCTX(void)
{
    SSL_METHOD *method;

    OpenSSL_add_all_algorithms();	/* load & register all 
					   cryptos, etc. */
    SSL_load_error_strings();	/* load all error messages */
    method = SSLv2_server_method(); /* create new server-method 
				       instance */

    /* create new context from method */
    if ((ctx = SSL_CTX_new(method)) == NULL) {
	ERR_print_errors_fp(stderr);
	return -1;
    }

    return 0;
}
#endif /* HAVE_SSL */

/* Actions needed to run on poll() */
void child(int child_type)
{
    int i, backlog = conf->backlog, polind;
    conn_t *conn = NULL;

    /* Check if the server socket alerted us, then make new connection */
    if (polls[0].revents & POLLRDNORM)
	if (new_connection(child_type) < 0)
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT("Acception connection failed\n");
#else
	;
#endif

    for (i = 0; i < backlog; i++) {
	conn = get_conn_at(i);
	do {
	    switch (conn->state) {
		case NEED_ACCEPT: /* Most likely scenario, just break */
		    break; 
		case QUEUED:
		    if (conn->s == -1) 
			break;
		    for (polind = 0; polind < MAX_POLL; polind++)
			if (polls[polind].fd == conn->s) 
			    break; /* Check the place in poll[] */
		    if ((polind == MAX_POLL) || 
			    (!((polls[polind].revents & POLLRDNORM))))
			break;	/* Nothing yet */
		    read_request(conn);
		    if (handle_error(conn))
		    	break;
		case READ:
		    parse_request(conn);
		    if (handle_error(conn))
		    	break;
		case PARSED:
		    find_vhost(conn);
		    if (handle_error(conn))
		    	break;
		case FOUND:
		    if ((conn->req->method == GET) ||
			    (conn->req->method == HEAD) ||
			    (conn->req->method == POST)) {
			handle_file(conn->req);
			handle_error(conn);
		    } else
			conn->state = PROCESSED;
		    break;
		case EXECUTING:
		    if (read_another_chunk(conn->req) == 0) {
			close(conn->req->fd);
			close(conn->req->write_pipe);
#ifndef RELEASE
			if (debug)
			    DEBUG_OUT("CGI finished\n");
#endif
			 conn->state = PROCESSED;
		    }
		    break;
#ifdef HAVE_PERL
		    handle_execute(conn);
#endif
		    handle_error(conn);
		    continue;
		case PROCESSED:
#ifndef RELEASE
		    if (debug)
			DEBUG_OUT2("going into send_request, response: %d\n",
				conn->req->response);
#endif
		    send_response(conn);
		    break;
		case SENT:
		    log_request(conn);
		    reset_conn(conn);
		    break;
		case FAULT:
		    reset_conn(conn);
		    break;
#ifndef RELEASE
		default:
		    DEBUG_OUT2("Something wrong happened here " 
			    "(conn->state = %d)\n", conn->state);
#endif
	    }
	} while (conn->state == READ || 
		conn->state == PARSED || 
		conn->state == FOUND || 
		conn->state == SENT || 
		conn->state == FAULT); 
    }
}

/* Does the wild poll() thang, returns errors only of they are truely fatal */
int do_select(int child_type)
{
    int i = 0, polind = 0, considered;
    struct passwd *user_info;
    conn_t *conn = NULL;
    const unsigned int clients_size = conf->backlog * sizeof(conn_t *);

    /**
     * If we are running as root: chroot if possible and 
     * drop any root priviliges. If we do not succeed, we will
     * refuse to run. 
     */
    if (getuid() == (uid_t) 0) {
	ERROR("Running as ROOT!! YOU BAD BOY/GIRL!!\n"
	      "You should change this ASAP!\n"
	      "Attempting to compensate with chroot and setuid.\n");
	if (chroot(conf->jail_root) == -1) {
	    DEBUG_OUT2("Couldn't chroot() to %s\n", conf->jail_root);
	    return -1;
	} 
	user_info = getpwnam(conf->user);
	if (setuid(user_info->pw_uid) == -1) {
	    DEBUG_OUT("chouldn't set UID");
	    return -1;
	}
    }

    MALLOC(client_sockets, clients_size);
#ifdef RELEASE
    memset(client_sockets, 0, clients_size);
#endif
#ifdef HAVE_QOS
    add_socket_qos (server_socket);
    qos_set_default (conf->qos);
#endif

    for (;;) {

	for (polind = 0; polind < MAX_POLL; polind++)
	    polls[polind].fd = -1;
	polind = 0;

	switch (child_type) {
	    case INET:
	    case INET6:
		FD_POLL(server_socket, polind, POLLRDNORM);
		break;
#ifdef HAVE_OPENSSL
	    case SINET:
	    case SINET6:
		FD_POLL(secure_ss, polind, POLLRDNORM);
		break;
#endif
	}

	for (i = 0; i < conf->backlog; i++) {
	    conn = get_conn_at(i);

	    /* If queue place is not initialized, do it */
	    if (conn == NULL) {
#ifndef RELEASE
		if (debug) 
		    DEBUG_OUT("Allocating new slot\n");
#endif
		MALLOC(client_sockets[i], sizeof(conn_t));
		conn = get_conn_at(i);
		init_conn(conn);
	    }

	    considered = conn->s;
	    /* If the socket is supposed to be read, put it in the read set 
	     * otherwise in the write set */
	    if (conn->s == -1) 
		continue;

	    switch (conn->state) {
		case QUEUED:
		    if (polind == MAX_POLL) 
			break;
		    FD_POLL(considered, polind, POLLRDNORM);
		    break;
		case PROCESSED:
		    if (polind == MAX_POLL) 
			break;
		    FD_POLL(considered, polind, POLLWRNORM);
		    break;
		case EXECUTING:
		    considered = conn->req->fd;
		    if (polind == MAX_POLL) 
			break;
		    DEBUG_OUT2("Fd %d is executing\n", considered);
		    FD_POLL(considered, polind, POLLIN | POLLRDNORM);
		    break;
		default:
		    break;
	    }

	}
	conn = NULL;

	switch (poll(polls, polind, conf->timeout)) {
		case 0:		/* No sockets pending */
	    		break;
		case -1:		/* Error during poll() */
	    		SETTITLE;
	    		perror("poll");
	    		return -3; /* XXX: We just return an error, which 
				      results in total program shutdown. Not 
				      very nice, but this shouldn't occur
				      in any case. */
		default:		/* We've got pending sockets */
	    		child(child_type);
	    		break;
	}
    }
}

int our_child_died() {
    pid_t corpse_id = wait(NULL);
    
    if (children[0] == corpse_id || children[1] == corpse_id 
#ifdef HAVE_OPENSSL
	    || children[2] == corpse_id || children[3] == corpse_id
#endif
	    )
	return 1;
    return 0;
}

/* XXX TODO fix SSL code! TODO XXX */
/* Ensures main looping of the server threads, respawns them if no _serious_ 
 * errors occured */
void loop(conf_t *conf)
{
    int reuse_addr = 1, i = 0, ss = 0;
    char portstr[6];
    char *listen_on = NULL;
    pid_t forkret = 0;
#ifdef HAVE_GETADDRINFO
    int gai_err;
    struct addrinfo ai;
    struct addrinfo *aip = &ai, *aip0;

#define family aip->ai_family
#define flags aip->ai_flags
#define socktype aip->ai_socktype
#define protocol aip->ai_protocol
#define canonname aip->ai_canonname
#define addr aip->ai_addr
#define addrlen aip->ai_addrlen
    memset(&ai, 0, sizeof(ai));
#else
    struct sockaddr sa;
    struct sockaddr *sap = &sa;
#define family sap->sa_family
#define flags
#define socktype
#define protocol
#define canonname
#define addr
#define addrlen
#warning "Not fully implemented, you should probably upgrade your OS anyway!"
    memset(&sa, 0, sizeof(sa));
#endif

#ifdef HAVE_OPENSSL

    initServerCTX();

    LoadCertificates("newreq.pem", "newreq.pem");
#endif /* HAVE_OPENSSL */

    /* Default actions upon certain signals */
    signal(SIGTERM, SIG_DFL);
    signal(SIGHUP, SIG_DFL);
    signal(SIGINT, SIG_DFL);
    /* Ignore any closing of remote sockets */
    signal(SIGPIPE, SIG_IGN);

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Using port %d\n", conf->port);
#endif

    flags = AI_PASSIVE;
    family = PF_UNSPEC;
    socktype = SOCK_STREAM;

#ifdef HAVE_OPENSSL
    for (i = 0; i < 2; i++) {
#else
    i = 0;
#endif /* HAVE_OPENSSL */
	portstr[5] = '\0';
	if (i == 0)
	    ultostr(conf->port, portstr);
#ifdef HAVE_OPENSSL
	else 
	    ultostr(conf->ssl_port, portstr);
#endif	/* HAVE_OPENSSL */

	if (strncasecmp(conf->bind_addr, "any", 3) != 0 &&
		strncasecmp(conf->bind_addr, "all", 3) != 0)
	    listen_on = conf->bind_addr;
	
#ifdef HAVE_GETADDRINFO
	if ((gai_err = getaddrinfo(listen_on, portstr, &ai, &aip0)) != 0) {
	    DEBUG_OUT3("Error: %s (%s)\n", gai_strerror(gai_err), listen_on);
	    return;
	}
#endif

#ifndef RELEASE
	if (debug)
	    DEBUG_OUT("Setting up sockets\n");
#endif

#ifdef HAVE_GETADDRINFO
	for (aip = aip0; aip; aip = aip->ai_next) {
#endif
/* XXX: Artifact of kefren's thinking
#ifndef HAVE_IPV6
	    if (aip->ai_family == PF_INET6) 
		continue;
#endif
*/
	    
	    if ((ss = socket(family, socktype, protocol)) == -1) {
		perror("socket");
		continue;
	    }

	    if (setsockopt(ss, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, 
			sizeof(reuse_addr)) == -1) {
		perror("setsockopt");
		continue;
	    }

#ifndef RELEASE
	    if (debug > 1)
		DEBUG_OUT2("Binding to address: %s\n", canonname);
#endif

	    if (bind(ss, addr, addrlen) == -1) {
		if (conf->loop_child != -3) {
		    perror("bind()");
		    log_err("Couldn't bind to port %s, aborting\n", portstr);
		    DEBUG_OUT ("Tip: you can use -p <portnumber> to "
			    "use another port\n");
		}
#ifndef RELEASE
			else if (debug)
				DEBUG_OUT2("Skiping bind for family %d\n",
					family);
#endif
		CLOSE(ss);
		continue;
	    }

	    if (listen(ss, conf->backlog) == -1) {
		perror("listen()");
		ERROR("Couldn't listen, continuing\n");
		CLOSE(ss);
		continue;
	    }

#ifndef RELEASE
	    if (debug)
		DEBUG_OUT2("Accepting connections for family %d\n", family);
#endif
	    conf->loop_child = 0;
	    switch (forkret = fork()) {
	    case 0:
#ifdef HAVE_SETPROCTITLE
		setproctitle("No errors");
#endif /* HAVE_SETPROCTITLE */
		/* Initialize thread pool for scrips */
#ifdef HAVE_PERL
		scripts_init(conf->script_pool);
#endif
		/* Initialize caching engine */
		init_cache();
		
		switch (i) {
		case 0:
#ifndef RELEASE
		    if (debug) 
			DEBUG_OUT("Going into normal socket poll\n");
#endif
		    server_socket = ss;
		    if ((aip->ai_family & PF_INET) == PF_INET) {
			children[0] = forkret;
			while (do_select(INET) > 0);
#ifdef HAVE_IPV6
		    } else if ((aip->ai_family & PF_INET6) == PF_INET6) {
			children[1] = forkret;
			while (do_select(INET6) > 0);
#endif
		    } else 
			ERROR("Only IPv4 and IPv6 in dhttpd, sorry\n");
#ifndef RELEASE
		    if (debug) 
			DEBUG_OUT("Got back from do_select\n");
#endif
		    break;
#ifdef HAVE_OPENSSL
		case 1:
		    secure_ss = ss;
# ifndef RELEASE
		    if (debug) 
			DEBUG_OUT3("Going into secure socket: %s, %d\n", 
				portstr, secure_ss);
# endif
		    if ((family & PF_INET) == PF_INET) {
			children[2] = forkret;
			while (do_select(SINET) > 0);
		    } 
# ifdef HAVE_IPV6
		    else if ((family & PF_INET6) == PF_INET6) {
			children[3] = forkret;
			while (do_select(SINET6) > 0);
		    }
# endif
		    
# ifndef RELEASE
		    if (debug) 
			DEBUG_OUT("Got back from do_select\n");
# endif
		    break;
#endif	/* HAVE_OPENSSL */
#ifndef RELEASE
		default:
		    ERROR("PANIC: unknown socket\n");
		    break;
#endif
		}
		break;
	    case -1:
		ERROR("PANIC: cannot fork\n");
		break;
	    default:
		conf->loop_child = 0;
	    }
	}

#ifdef HAVE_GETADDRINFO
	freeaddrinfo(aip0);
#endif
#ifdef HAVE_OPENSSL
    }
#endif

    signal(SIGTERM, main_shutdown);
    signal(SIGINT, main_shutdown);
    signal(SIGHUP, restart);
		
    if (forkret > 0) {
	while (!our_child_died());
	CLOSE(ss);
    }
#ifndef RELEASE
    if (debug) 
	DEBUG_OUT ("loop finished\n");
#endif
}
