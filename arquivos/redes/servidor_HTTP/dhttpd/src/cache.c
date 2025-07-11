/* $Id: cache.c,v 1.15 2004/01/09 13:29:06 dublet Exp $
 * 
 * Dublet's HTTP Daemon
 *
 * Released under BSD license
 * Copyright (c) 2003, Kefren
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
 *     * Neither the name of the Kefren nor the names of its contributors
 *       may be used to endorse or promote products derived from this
 *       software without specific prior written permission.
 *     * All advertising materials mentioning features or use of this software
 *       must display the following acknowledgement:
 *          This product includes software developed by Kefren.
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
#include <time.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/param.h>

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include "dhttpd.h"
#include "types.h"
#include "cache.h"
#include "file.h"
#include "log.h"
#include "additional.h"

#ifndef RELEASE
extern unsigned int debug;
#endif
extern conf_t *conf;

void init_cache()
{
    int i;

    MALLOC(cache, sizeof(cache_t *) * conf->cache_size);

    for (i = 0; i < conf->cache_size; i++) {
	MALLOC (cache[i], sizeof(cache_t));
	cache[i]->handle = 
	    cache[i]->inuse = 
	    cache[i]->filename[0] = 
	    cache[i]->t = 0;
    }
}

void destroy_cache()
{
    int i;

    for (i = 0; i < conf->cache_size; i++) {
	if (cache[i]->handle) 
	    close(cache[i]->handle);
	free (cache[i]);
    }
    free(cache);
}

/* 
 * Fills request with come cached values
 *
 * Returns: 
 * -3 on directory
 * -2 on ENOTDIR
 * -1 on ENOENT
 * 0 on success
 */
int get_file_cache(req_t *req)
{
    int i, k = -1, timek = -1;
    time_t mint = 0;


    for (i = 0; i < conf->cache_size; i++) {
	if ((cache[i]->handle) && 
		(!dstrncmp2(req->file_loc, cache[i]->filename, 
			    _POSIX_PATH_MAX))) {
	    /* FOUND ! */
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT3("Cache for %s found at position %d\n", 
			req->file_loc, i);
#endif
	    req->fd = cache[i]->handle;
	    cache[i]->inuse++;
	    { /* If the stat buffer if older than a certain amount of time,
		 refresh it, so we pick up on changes */
		time_t curr_t = time(NULL);

		if (cache[i]->t != 0) { 
		    if (curr_t >= cache[i]->t + conf->max_cache_age)  {
			fstat(cache[i]->handle, &cache[i]->sb);
			cache[i]->t = curr_t;
#ifndef RELEASE
			DEBUG_OUT("Found old cache, restat()ed\n");
#endif
		    }
		} else 
		    cache[i]->t = curr_t;
	    }
	    req->sbuf = &cache[i]->sb;
	    return 0;
	}

	if ((k == -1) && (!cache[i]->handle)) 
	    k = i;	/* Find a place in case no cache is found */
	if ((k != -1) || (cache[i]->inuse)) 
	    continue;
	
	if (!mint) {
	    mint = cache[i]->t;
	    timek = i;
	    continue;
	}
	
	if ((cache[i]->t) && (cache[i]->t < mint)) {
	    mint = cache[i]->t;
	    timek = i;
	}
    }
/* Not in cache */
#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Not in cache %s\n", req->file_loc);
#endif

    if (k == -1) { /* no free place */
	k = timek;
	close(cache[k]->handle);
    }
    
    if ((req->fd = cache[k]->handle = open(req->file_loc, O_RDONLY)) != -1) {
	/* We do NOT cache errors */
	strlcpy(cache[k]->filename, req->file_loc, _POSIX_PATH_MAX);
	fstat(cache[k]->handle, &cache[k]->sb);
	/* Check if it is a directory */
	if (S_ISDIR(cache[k]->sb.st_mode)) {
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT2("Requested directory, appending stuff, %s\n",
			req->vh->index_doc);
#endif
	    /* If it is, retry with appending the index doc. */
	    append_index_doc(req);
	    close(req->fd);
	    if ((req->fd = cache[k]->handle = open(req->file_loc, 
			    O_RDONLY)) != -1) {
		strlcpy(cache[k]->filename, req->file_loc, _POSIX_PATH_MAX);
		fstat(cache[k]->handle, &cache[k]->sb);
	    } else {
		cache[k]->handle = 0;
		return errno == ENOTDIR ? -2 : -1;
	    }
	}
	req->sbuf = &cache[k]->sb;
	cache[k]->inuse++;
	cache[k]->t = time(NULL);
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT3("Ok, cached %s at place %d\n", req->file_loc, k);
#endif
    } else {
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT("Not cached\n");
#endif
	cache[k]->handle = 0;
	return errno == ENOTDIR ? -2 : -1;
    }
    
    return 0;
}

void done_file(req_t *req)
{
    int i;
    if (!req->fd) 
	return;
    
    for (i = 0; i < conf->cache_size; i++) {
	if (req->fd == cache[i]->handle) { /* FOUND */
	    cache[i]->inuse--;
	    return;
	}
    }
    /* Not found, we don't care... */
}

