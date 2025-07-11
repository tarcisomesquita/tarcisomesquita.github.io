/* $Id: file.c,v 1.68 2004/01/09 15:28:46 dublet Exp $
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
#include <regex.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/param.h>		/* for MAXPATHLEN */
#include <sys/wait.h>
#include <netinet/in.h>

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include "dhttpd.h"
#include "children.h"
#include "send.h"
#include "recv.h"
#include "scripts.h"
#include "http.h"
#include "log.h"
#include "types.h"
#include "file.h"
#include "mime.h"
#include "scripts.h"
#include "cache.h"
#include "additional.h"

#ifdef HAVE_QOS
#include <qos/qos.h>
#endif

#ifndef RELEASE
extern unsigned int debug;
#endif
extern char **environ;
extern struct config *conf;
extern int server_socket;

/* Guess weither file 'file' is a script */
int file_is_script(char *file)
{
    char *filename = rindex(file, '/');
    char *ext;

    if (filename == NULL || (ext = rindex(filename, '.')) == NULL)
	return PLAINTEXT;

    ext++;
    if (ext[0] == 'p') {
	if (ext[1] == 'h' && ext[2] == 'p')
	    return EX_PHP;
	else if (ext[1] == 'l')
#ifdef HAVE_PERL
	    return EX_PERL;
#else
	    return EX_CGI;
#endif
    } else if (!dstrncmp(ext, "cgi", 3))
	return EX_CGI;

    return PLAINTEXT;
}

char **cgiparse(char *file)
{
    int i, k = 0, oldi = 0, count = 1, file_len = strlen(file);
    char **ret = NULL;
    char *blah = NULL;

    MALLOC(blah, file_len + 2);
    strncpy(blah, file, file_len);
    
    blah[file_len] = '?';
    blah[file_len + 1] = 0;
    
    for (i = 0; file[i]; i++) 
	if ((file[i] == '?') || (file[i] == '&')) 
	    count++;

    if (!count) {
#ifndef RELEASE
	DEBUG_OUT ("CGI parser error !\n");
#endif
	return NULL;
    }
    
    MALLOC(ret, sizeof(char *) * (count + 1));
    for (i = 0; blah[i] != 0; i++) {
	if ((blah[i] == '?') || (blah[i] == '&')) {
	    blah[i] = 0;
	    MALLOC(ret[k], i - oldi + 1);
	    strlcpy(ret[k], blah + oldi, i - oldi + 1);
	    oldi = i + 1;
	    k++;
	    continue;
	}
    }
    
    ret[k] = NULL;
    free(blah);
    return ret;
}

/*
 * Returns the first string appended with the last, seperated by a space.
 *
 * Otherwise returns:
 * -NULL if both args are NULL
 * -first if last is NULL
 * -last if first is NULL
 */ 
char *append(char *first, char *last) {
    char *res;
    int len_fir = 0, len_sec = 0, i, j = 0;

    if (first == NULL)
	if (last == NULL)
	    return NULL;
	else 
	    return last;
    else if (last == NULL)
	return first;

    len_fir = strlen(first), len_sec = strlen(last);
    
    MALLOC(res, len_fir + len_sec + 2);
    for (i = 0; i < len_fir; ) 
	res[j++] = first[i++];
    res[j++] = ' ';
    for (i = 0; i < len_sec; )
	res[j++] = last[i++];
    res[j] = '\0';

    return res;
}

/* 
 * Determinte command name that has to be executed
 */
char **get_cmd(req_t *req)
{
    char **cmd = NULL;	

    /*
     *  If the script had the X bit set on other, we can safely execute it 
     *  (hopefully) 
     *  
     *  This makes us able to execute scrips in ANY language, if the #! magic
     *  is set properly in the script.
     *  
     */
    if ((req->sbuf->st_mode & S_IXOTH) == S_IXOTH) 
	return cgiparse(req->file);

    switch (req->script_type) {
	case EX_PHP:
	    if (!conf->php_available) {
		set_error(req, 500);
		break;
	    }
	    MALLOC(cmd, sizeof(char *));
	    cmd[0] = append(conf->php_bin, req->file_loc);
	    break;
#ifndef HAVE_PERL
	case EX_PERL:
	    if (!conf->perl_available) {
		set_error(req, 500);
		break;
	    }
	    MALLOC(cmd, sizeof(char *));
	    cmd[0] = append(conf->perl_bin, req->file_loc);
	    cmd = cgiparse(req->file);
	    break;
#else
	case EX_PERL:
	    if (!conf->perl_available) {
		set_error(req, 500);
		break;
	    } /* Fall through */
#endif
	case EX_CGI:
	    cmd = cgiparse(req->file);
	    break;
	default:
	    set_error(req, 500); /* XXX Don't know what we could do otherwise */
	    break;
    }

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Command line: %s\n", cmd);
#endif

    return cmd;
}

/* 
 * Execute script of possibly any type
 */
int exec_script(req_t *req)
{
    char **cmd = NULL;
    pid_t cpid = 0;
    int cgi_stdout[2], cgi_stdin[2], i;

    if (!req) 
	return -1; 
    else 
	req->file_size = 0;

    if ((cmd = get_cmd(req)) == NULL) {
	log_err("Couldn't find command to execute script: %s", req->file_loc);
	return -1;
    } 

    if (pipe(cgi_stdout) == -1 || pipe(cgi_stdin) == -1) {
	set_error(req, 500); /* Couldn't execute script */
	return -1;
    }

    req->fd = cgi_stdout[0];
    req->write_pipe = cgi_stdin[1];
#ifdef HAVE_VFORK
    switch (cpid = vfork()) {
#else
    switch (cpid = fork()) {
#endif
	case -1:
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT("Couldn't fork()\n");
#endif
	    return -1;
	case 0:
	    close(cgi_stdout[0]);
	    close(cgi_stdin[1]);
	    CLOSE(server_socket);

	    if (dup2(cgi_stdout[1], STDOUT_FILENO) != STDOUT_FILENO) {
		DEBUG_OUT("Could not make pipe STDOUT\n");
	    }
	    if (dup2(cgi_stdin[0], STDIN_FILENO) != STDIN_FILENO) {
		DEBUG_OUT("Could not make pipe STDIN\n");
	    }

	    /* Request specific 
	     *
	     * See: http://hoohoo.ncsa.uiuc.edu/cgi/env.html */
	    setenv("REQUEST_METHOD", get_method(req->method), 1);
	    {
		char prt[6];
		prt[5] = '\0';
		ultostr(conf->port, prt);
		setenv("SERVER_PORT", prt, 1);
	    }
	    setenv("SERVER_PROTOCOL", req->http_version, 1);
	    setenv("HTTP_USER_AGENT", req->useragent, 1);
	    setenv("PATH_TRANSLATED", "", 1);
	    setenv("SCRIPT_NAME", req->file_loc, 1);

	    if (req->has_cookie) 
		setenv("COOKIE", req->cookie, 1);
	    
	    if (cmd[1]) {
		{   char num[12]; 
		    num[11] = '\0';
		    ultostr(strlen(cmd[1]), num);
		    setenv("CONTENT_LENGTH", num, 1);
		}
		/* XXX: Wrong and blatant assumption. Usually sent along
		 * with HTML form. We should extract from there. But we're
		 * lazy and want a quick implementation. :P
		 */
		setenv("CONTENT_TYPE", "application/x-www-form-urlencoded", 1);
		/* Some CGI things only ready from STDIN if POST method is 
		 * used. */
		if (req->method != POST)
		    setenv("QUERY_STRING", cmd[1], 1);
	    } 

	    execve(req->file_loc, cmd, environ);
	    perror("execve");
	    DEBUG_OUT3("Tried to execute: `%s', but failed. Should I have used"
		    " `%s' instead?\n", req->file_loc, cmd[0]);
	    _exit(1);
	default:
	    close(cgi_stdout[1]);
	    close(cgi_stdin[0]);

	    /* Write arguments to pipe, if needed */
	    if (cmd[1] && req->method == POST) 
		if (!write(cgi_stdin[1], cmd[1], strlen(cmd[1])))
		    perror("Writing CGI args to pipe");

	    close(cgi_stdin[1]);

	    for (i = 0; cmd[i]; i++) 
		free(cmd[i]);
	    free(cmd);
	    req->cgi_slot = cpid;
	    break;
    }
    return 0;

}

ssize_t
read_another_chunk(req_t *req)
{
    char *tinybuf = NULL;
    ssize_t read_count = 0;

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Reading data into buffer\n");
#endif

    MALLOC(tinybuf, TINYBUF);

    if ((read_count = read(req->fd, tinybuf, TINYBUF)) == 0) {
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT("Nothing left to read\n");
#endif
	free(tinybuf);
	return 0;
    }

#ifndef RELEASE
    if (debug)
	DEBUG_OUT3("Read %d from fd %d\n", read_count, req->fd);
#endif

    if (req->file_size + read_count < BUFLEN) {
    	memmove(&req->file_buf[req->file_size], tinybuf, read_count);
    	req->file_size += read_count;
    } else {
	DEBUG_OUT("Eh?!\n");
	free(tinybuf);
	return 0;
    }

    free(tinybuf);
    return read_count;
}

/* check if the file exists, and weither we want to read and send it */
int proper_file(req_t *req)
{

    struct stat *sp = req->sbuf; /* For shortening this function :) */
    
    if (req->sbuf == NULL) {
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT("Stat buffer NULL!?\n");
#endif
	/*set_error(req, 500);*/
	return -2;
    }

    req->file_size = (unsigned long) sp->st_size;
#ifdef HAVE_PERM_CHECKS
    if ((sp->st_mode & S_IRUSR) != S_IRUSR ||
	(sp->st_mode & S_IRGRP) != S_IRGRP ||
	(sp->st_mode & S_IROTH) != S_IROTH ||
	/* File is not readable by someone, so therefor we don't want to read it */
	(sp->st_mode & S_IWOTH) == S_IWOTH ||
	/* Writable to other */
	(sp->st_gid == getegid() && (sp->st_mode & S_IWGRP) == S_IWGRP) ||
	/* Writable to the group we're in */
	(sp->st_gid == getgid() && (sp->st_mode & S_IWGRP) == S_IWGRP) ||
	/* Writable to the effective group we're in */
	(sp->st_uid == geteuid() && (sp->st_mode & S_IWUSR) == S_IWUSR) ||
	/* We're the owner, and can write */
	(sp->st_uid == getuid() && (sp->st_mode & S_IWUSR) == S_IWUSR)
	/* We're the owner and can write */
	) {
	set_error(req, 403);
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT("We're FUCKED D00D!\n");
#endif
	return -2;
    }

/*    if (req->method == HEAD)
	close(req->fd);	*//* We won't use the fd anymore, so rid of it */

#endif /* HAVE_PERM_CHECKS */
    return 0;			/* seems to be a good file! */
}

int prepend_doc_base(req_t *req) {
    register int i = 0, j = 0;
    const char *req_file = req->response == 200 ? req->file : 
	get_errordocument_name(&req->response);

    if (req->vh == NULL)
	return -1; /* XXX: ARGGGGHHHH */
    
    /* Prepend /, if it isn't present in the docbase */
    if (req->vh->doc_base[i] != '/')
	req->file_loc[j++] = '/';

    /* Copy document base */
    while (req->vh->doc_base[i])
	req->file_loc[j++] = req->vh->doc_base[i++];

    /* Append requested file */
    for (i = 0; req_file[i];)
	req->file_loc[j++] = req_file[i++];
    req->file_loc[j] = '\0';

    return j;
}

/* Appends index document to the file location, starting with the given
 * offset
 */
void append_index_doc(req_t *req) {
    register int i = 0, j = 0;

    while (req->file_loc[j])
       	j++;

    /* Append '/', if necessary */
    if (req->file_loc[j - 1] != '/')
	req->file_loc[j++] = '/';

    /* Append index doc */
    for (i = 0; req->vh->index_doc[i];)
	req->file_loc[j++] = req->vh->index_doc[i++];
    req->file_loc[j] = '\0';
}

void handle_execute(conn_t *conn) {
#ifdef HAVE_PERL
    int status;
 
    switch ((status = status_script(conn->req->cgi_slot))) {
	case 0:
	    conn->state = PROCESSED;
	    break;
	case 1:
	case 2:
	default:
	    break;
    }
#endif
}


/* Handle a file request, whether we are dealing with dynamic or static */
void handle_file(req_t *req)
{
    int flen = 0, j, i;
   
    /*if (strstr(req->file,"../") || strstr(req->file, "/..")) { */
    /* XXX: Ew?! :) */
    for (j = 0; req->file[j + 2]; j++) {
	if (req->file[j] == '.' && req->file[j + 1] == '.') {
	    if ((j > 1 && req->file[j - 1] == '/') || 
		     req->file[j + 2] == '/') { 
		/* Don't traverse upwards */
		log_err("Attempted to open invalid file");
		set_error(req, 403); /* XXX Not really that neat */
		return;
	    }
	}
    }

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("prepending base: %s\n", req->vh->doc_base);
#endif

    j = prepend_doc_base(req);

    for (i = 0; req->file_loc[i]; i++)
	if (req->file_loc[i] == '\?') {
	    req->file_loc[i] = '\0';
	    break;
	}

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Actual file to get: %s\n", req->file_loc);
#endif


    switch ((flen = get_file_cache(req))) {
	case -1:
	    set_error(req, 404);
	    return;
	case -2:
	    set_error(req, 406);
	    return;
	default:
	    break;
    }

    /* Stat requested location, and do some error checking */
    switch (flen) {
	case -1:
	    set_error(req, 404);
	    return; /* We should not continue with the rest of the function */
	case -2: /* XXX: We should probably have parsed this, as it is most 
			 likely a CGI */
	    set_error(req, 500);
	    log_err
		("Your document base contains something which is not a directory!");
	    return; /* We should not continue with the rest of the function */
	default:
	    break;
    }

    if (proper_file(req) < 0)
	return; /* Request no good, skip rest */

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Determining wether file is script, and executing it\n");
#endif

    switch ((req->script_type = file_is_script(req->file_loc))) {
	case PLAINTEXT:	/* Not a script */
	    req->conn->state = PROCESSED;
	    req->cgi_slot = 0;
	    break;
	case EX_CGI:
	    req->conn->state = EXECUTING;
	    if (exec_script(req) == -1) {
		set_error(req, 500);
		req->conn->state = FAULT;
		DEBUG_OUT("Error during execution\n");
		log_err("error during execution of file");
	    }
	    break;
	case EX_PERL:
#ifdef HAVE_PERL
	    if (request_script_thread(req->conn) == -1) {
		log_err("error during execution of file");
		flen = -4;
		req->conn->state = FAULT;
	    }
	    break;
#else
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT("Somewhere EX_PERL was set, but we don't have direct"
			" Perl support!\n");
#endif
	    /* Fall through */
#endif /* HAVE_PERL */
	default:
	    set_error(req, 500);
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT("OUCH!\n");
#endif
	    req->conn->state = FAULT;
	    break;
    }

#ifndef RELEASE
    if (debug) 
	DEBUG_OUT3("It's a %d, (%d) type file\n", req->script_type, PLAINTEXT);
#endif
}
