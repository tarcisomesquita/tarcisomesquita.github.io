/* Dublet's HTTP Daemon                                                      
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

#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef HAVE_PERL
#include <pthread.h>
# include <EXTERN.h>
# include <perl.h>
#endif

#include "types.h"
#include "log.h"
#include "scripts.h"
#include "file.h"
#include "children.h"

#ifndef RELEASE
extern unsigned int debug;
#endif

#ifdef HAVE_PERL
static script_t **script_slots = NULL;
static pi_t **pi_pool = NULL;
#endif

#ifdef HAVE_PERL
/* Sets up all threads */
int scripts_init(int max_scripts) {
    int i = 0;

    MALLOC(script_slots, sizeof(script_t*) * (max_scripts + 1));

    for (i = 0; i < max_scripts; i++) {
	MALLOC(script_slots[i],sizeof(script_t));
	MALLOC(script_slots[i]->scriptPresent, sizeof(pthread_cond_t));
	MALLOC(script_slots[i]->scriptLock, sizeof(pthread_mutex_t));
	script_slots[i]->conn = NULL;
	pthread_create(&script_slots[i]->tid, NULL, run_scriptor, (void*)(script_slots[i]));
	pthread_detach(script_slots[i]->tid);
    }

    /* Sentinel for easy destroying (Sentinel == NULL pointer terminated) */
    script_slots[max_scripts] = NULL;

    pi_init(max_scripts); /* XXX: we should pass pi_init a value smaller than
			     max_scripts, being as it's quite unlikely that
			     all requests will involve Perl, at the same time */
    return 0;
}

/* Initialize a certain number of Perl interpreters */
int pi_init(int num) {
    int i = 0;
    pi_t *t = NULL;

    MALLOC(pi_pool, num * sizeof(pi_t) + 1);

    for (i = 0; i < num; i ++) {
	t = (pi_t *)(&pi_pool[i]);
	if ((t->pi = perl_alloc()) == NULL) {
	    (void) fprintf(stderr,
		    "Couldn't allocate memory for the "
		    "Perl interpreter at slot %d\n", i);
	    abort();
	} else
	    perl_construct(t->pi);
	pthread_mutex_init(t->lock, NULL); 
    }

    pi_pool[i] = NULL;
    return 0;
}

/* Destroys all Perl interpreters */
int pi_destroy(void) {
    int i = 0;
    pi_t *t = NULL;
    
    for (t = pi_pool[0]; t != NULL; t = pi_pool[++i]) {
	pthread_mutex_destroy(t->lock);
	perl_destruct(t->pi);
	perl_free(t->pi);
    }

    return 0;
}

/* Get an interpreter for a Perl script 
 * Returns -1 on failure */
int get_pi(script_t *s) {
    int i = 0;
    pi_t *t = pi_pool[i];

    for (; t != NULL; t = pi_pool[i++]) {
	if (pthread_mutex_trylock(t->lock) != EBUSY) {
	    pthread_mutex_lock(t->lock);
	    s->pi = t;
	    break;
	} else 
	    continue;
    }

    return t == NULL ? -1 : 0;
}

/* Requests for a thread to run the script in the conn.
 *
 * Returns -1 on failure or index of thread on success. 
 */
int request_script_thread(conn_t *conn) {
    int i = 0;
    script_t *t;

#ifndef RELEASE
    if (debug) 
	DEBUG_OUT2("Requesting a thread for socket %d\n", conn->s);
#endif

    for (t = (script_t *)(script_slots[0]); t != NULL; t = (script_t *)(script_slots[++i])) {
	if (t->conn == NULL) {
	    t->conn = conn;
#ifndef RELEASE
	    if (debug) 
		DEBUG_OUT("Signaling a thread\n");
#endif
	    pthread_cond_signal(t->scriptPresent);
	    break;
	} else
	    continue;
    }
    
    if (t != NULL){
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT2("Got a place at slot %d\n", i);
#endif
	    conn->state = EXECUTING;
	    conn->req->cgi_slot = i;
	}
#ifndef RELEASE
	else {
	    if (debug)
		DEBUG_OUT("No place found...\n");
	}
#endif

    return t == NULL ? -1 : i;
}
/* Opens a script to be interpreter */
int open_script(script_t *s) {
    switch (s->conn->req->script_type) {
	case PLAINTEXT:
#ifndef RELEASE
	    if (debug) 
		DEBUG_OUT("Plaintext files cannot be executed\n");
#endif
	    log_err("Tried to execute a normal file");
	    return -1;
#ifdef HAVE_PERL
	case EX_PERL:
	    s->conn->req->fd = 1; /* XXX: FD magic is totally wrong */
	    if (get_pi(s) == -1) 
		break;
	    if (!perl_parse(s->pi->pi, NULL, s->conn->req->perl_argc,
			s->conn->req->perl_argv, s->conn->req->perl_env))
		perl_run(s->pi->pi);
	    else
		set_error(s->conn->req, 500);
	    pthread_mutex_unlock(s->pi->lock);
	    break;
#else
	case EX_PERL:
#endif
	case EX_PHP:
	case EX_CGI:
	    if (exec_script(s->conn->req) == -1) {
		DEBUG_OUT("Error during execution\n");
		log_err("error during execution of file");
		return -1;
	    }                                                 
	    break;
	default:
#ifndef RELEASE
	    if (debug) 
		DEBUG_OUT("Don't know this script type\n");
#endif
	    log_err("Unknown script type");
	    return -1;
    }

    return 0;
}

/* Returns status of script processing 
 * Status:
 * 0: Available/Finished
 * 1: Locked at script level
 * 2: Locked at interpreter level (if available)
 */
#ifdef HAVE_PERL
int status_script(int id) {
    script_t *t = NULL;

    if (id > sizeof(script_slots)) {
	(void)fprintf(stderr, "WTF are you thinking!?!?\n");
	abort();
    }

    t = script_slots[id];

    if (pthread_mutex_trylock(t->scriptLock) == EBUSY) {
#ifdef HAVE_PERL
	if (pthread_mutex_trylock(t->pi->lock) == EBUSY) 
	    return 2;
	else
#endif /* HAVE_PERL */
	    return 1;
    }

    return 0;
}

/* Clears out all scripts, removes all threads, cleans up */
int scripts_destroy() {
    int i = 0;
    script_t *t = script_slots[i];

#ifndef RELEASE
    if (debug) 
	DEBUG_OUT ("Cleaning scripts\n");
#endif

    for (; t != NULL; t = script_slots[i++]) {
	pthread_cancel(t->tid);
	pthread_mutex_destroy(t->scriptLock);
	pthread_cond_destroy(t->scriptPresent);
	free(t->scriptLock);
	free(t->scriptPresent);
	free(t);
    }

    free (script_slots);

#ifdef HAVE_PERL
    pi_destroy();
#endif				/* HAVE_PERL */

    return 0;
}

/* This is the function that rules how a scripting thread behaves.
 * It waits for activation, and once it's activated it tries to run with
 * the appropriate interpreter, but that's handled by other functions.
 * It will set things up in such a way that is not noticable to other functions
 * this is actually a script, not a static file.
 */
void *run_scriptor(void *arg) {
    script_t *s = (script_t *)arg;
    
    if (pthread_mutex_init (s->scriptLock, NULL)) {
	DEBUG_OUT("Cannot init mutex");
	return NULL;
    }

    if (pthread_cond_init (s->scriptPresent, NULL)) {
	DEBUG_OUT("Cannot init cond");
	return NULL;
    }
    
    for (;;) {
	if (pthread_mutex_lock (s->scriptLock)) {
	    DEBUG_OUT ("Cannot lock mutex\n");
	    return NULL;
	}

	if (pthread_cond_wait(s->scriptPresent, s->scriptLock) == ETIMEDOUT) {
	    pthread_mutex_unlock(s->scriptLock);
	    continue;
	}
	/* We got woken up because we have something to do! */
	/* Cleaning the mutex */
	pthread_mutex_unlock(s->scriptLock);
	/* Double checking: Are we awake for nothing ? */
	if (s->conn == NULL) 
	    continue;
	/* execute script */
#ifndef RELEASE
	if (debug) 
	    DEBUG_OUT2("Script signal for socket %d\n",s->conn->s);
#endif
	open_script(s);
	s->conn->req->cgi_slot = -1;
	s->conn = NULL;
	/* go back to sleep */
    }

    return NULL;
}
#endif
#endif
