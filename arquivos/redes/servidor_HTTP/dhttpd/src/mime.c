/* $Id: mime.c,v 1.28 2004/01/08 21:20:39 dublet Exp $
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
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <netinet/in.h>

#include "types.h"
#include "dhttpd.h"
#include "log.h"
#include "types.h"
#include "mime.h"
#include "additional.h"

#if HAVE_CONFIG_H
# include <config.h>
#endif

#ifndef RELEASE
extern unsigned int debug;
#endif
extern struct connection **client_sockets;
extern conf_t *conf;

static mime_t **mime_table;
static unsigned int mime_count;
static unsigned prev_hash = 0;

void create_and_fill_mime_table(unsigned elements)
{
    create_mime_table(elements);

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Building MIME type list\n");
#endif

    add_type("html", 5, "text/html", 0);
    add_type("htm", 4, "text/html", 0);
    add_type("gif", 4, "image/gif", 0);
    add_type("jpg", 4, "image/jpeg", 0);
    add_type("css", 4, "text/css", 0);
    add_type("txt", 4, "text/plain", 0);
    add_type("jpeg", 5, "image/jpeg", 0);
    add_type("php", 4, "text/html", 0);
    add_type("pl", 3, "text/html", 0);
    add_type("cgi", 4, "text/html", 0);
    add_type("mpg", 4, "video/mpeg", 0);
    add_type("mpeg", 5, "video/mpeg", 0);
    add_type("gz", 3, "application/x-gzip", 0);
    add_type("pdf", 4, "application/pdf", 0);
    add_type("png", 4, "image/png", 0);
    add_type("ps", 3, "application/postscript", 0);
    add_type("tif", 4, "image/tiff", 0);
    add_type("tiff", 5, "image/tiff", 0);
    add_type("dvi", 4, "application/x-dvi", 0);
}


const char *get_mime_type(req_t *req)
{
    mime_t *mp;
    char *filename, *ext;

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("About to detect mime type\n");
#endif

    /* Special case */
    if (req->response == 200 && req->method == TRACE)
	return "message/http"; /* Special case, RFC recommended */

    /* Retrieve extention */
    if ((filename = rindex(req->file_loc, '/')) == NULL 
	    || (ext = rindex(filename, '.')) == NULL) {
#ifndef RELEASE
	DEBUG_OUT2("Couldn't get extension from %s!\n", req->file_loc);
#endif
	return conf->default_mime_type;
    }

    ext++;
#ifndef RELEASE
    if (debug > 3)
	DEBUG_OUT2("Extension: %s\n", ext);
#endif
    
    /* Compare */ 
    if ((mp = find_type(ext, strlen(ext))) == NULL) {
	/* Return error */
	log_err("Requested Content-Type of unknown origin, "
		"defaulting to %s, please think of adding: %s\n",
		conf->default_mime_type, req->file_loc);
	return conf->default_mime_type;
    }

#ifndef RELEASE
    if (debug > 4)
	DEBUG_OUT2("Mime type: %s\n", mp->type);
#endif

    return mp->type;
}
/*
 * Several hash implementations.
 *
 * KANDR is the simple hash from K&R, and their copyright.
 *
 * FNV is public domain code.
 * http://www.isthe.com/chongo/tech/comp/fnv/
 *
 * Others borrowed.
 * http://burtleburtle.net/bob/hash/doobs.html
 *
 * This is a hash which does not deal with collisions, as each extension
 * MUST be unique.
 */
#define ROTATING
unsigned hash (char *key, unsigned len) {
    unsigned hash;
#ifdef KANDR
    for (hash = 0; *key; key++)
	hash = *key + 31 * hash;
    hash %= mime_count;
#elif defined(ADDITIVE)
    unsigned i;

    for (hash = len, i = 0; i < len; ++i)
	hash += key[i];
    hash %= mime_count;
#elif defined(KNUTH)
    for (hash = len; len--;)
	hash = ((hash << 5) ^ (hash >> 26)) ^ *key++;
    hash %= mime_count;
#elif defined(ROTATING)
    unsigned i;

    for (hash = len, i = 0; i < len; ++i)
	hash = (hash << 4) ^ (hash >> 28) ^ key[i];

    hash %= mime_count;
#elif defined(ONEATATIME)
    unsigned i;

    for (hash = 0, i = 0; i < len; ++i) {
	hash += key[i];
	hash += (hash << 10);
	hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    hash &= mime_count;
#elif defined(FNV1A)
#define FNV_32_PRIME 0x01000193
    unsigned i;

    for (hash = prev_hash, i = 0; i < len; i++) {
	hash ^= key[i];
	hash *= FNV_32_PRIME;
    }
    hash &= mime_count;
#else
#error "No hash functions defined"
#endif
    if (hash > mime_count) {
	DEBUG_OUT2("Hash greater than available choices %u!\n", hash);
    }
#ifdef HASH_DEBUG
    printf("%15s %3d\n", ext, hash);
#endif
    prev_hash = hash;
    return hash;
}

#define HASH_DEBUG
#ifdef HASH_DEBUG
void print_stats() {
    int chains;
    int chain_table[33];
    unsigned int i, j;

    for (j = 0; j < 33; j++)
	chain_table[j] = 0;
    
    for (i = 0; i < mime_count; i++) {
	mime_t *currNode = mime_table[i];

	if (currNode == NULL)
	    continue;
	else {
	    int chain_len = 0;

	    for (; ; currNode = currNode->next) {
		printf("-%5s %20s\n", currNode->ext, currNode->type);
		chain_len++;

		if (currNode->next == NULL) 
		    break;
	    }

	    if (chain_len > 32)
		chain_len = 32;
	    chain_table[chain_len]++;
	}
    }

    chains = 0;
    for (i = 32; i > 0; i--) {
	if (chain_table[i] == 0)
	    continue;
	else {
	    printf("%3d chains of len %2d\n", chain_table[i], i);
	    chains += chain_table[i];
	}
    }

    if (chains != 0) {
	printf("\n%d nodes in %u chains\n\n", mime_count, chains);

	printf("Size of hash table = %u\n"
		"Average chain length = %f\n"
		"Slot occupancy = %f\n"
		"Load factor = %f (bullshit number ATM)\n",
		mime_count,
		mime_count / (double)chains,
		(double)(((double)chains) / mime_count),
		(double)(((double)mime_count  / chains)));
    } else 
	printf("No chains found\n");
    
}
#endif

mime_t *add_type(char *ext, unsigned ext_len, char *type, unsigned type_len) {
    mime_t *new;
    unsigned hashval = hash(ext, ext_len);

    if ((new = mime_table[hashval]) != NULL) {
	/* Collision, extension already exists */
#ifndef RELEASE
	if (debug > 3)
	    DEBUG_OUT3("Ext (%s, %u) has collided!\n", ext, hashval);
#endif
	for (; new; new = new->next);
	MALLOC(new, sizeof(mime_t));
    } else { 
	MALLOC(new, sizeof(mime_t));
	mime_table[hashval] = new;
    }
    
    if (type_len == 0)
	type_len = strlen(type);

    ext_len++;
    type_len++;
    MALLOC(new->ext, ext_len);
    MALLOC(new->type, type_len);
    strlcpy(new->ext, ext, ext_len);
    strlcpy(new->type, type, type_len);
    new->next = NULL;
    ext_len--;


#ifndef RELEASE
    if (debug > 3)
	DEBUG_OUT3("Ext (%s) has hash %u\n", new->ext, hashval);
#endif


    return new;
}
	    
mime_t *find_type(char *ext, unsigned ext_len) {
    mime_t *mime = mime_table[hash(ext, ext_len)];

    if (!mime) 
	return NULL;
    
    /* Simply return element, if not chained */
    if (!mime->next) 
	return mime;

#ifndef RELEASE
    if (debug > 3)
	DEBUG_OUT2("Ext %s is chained, walking..\n", ext);
#endif

    /* Walk chain if present */
    for (; mime; mime = mime->next) 
	if (dstrncmp2(mime->ext, ext, ext_len) == 0)
	    return mime;

    return NULL;
}

/* Elements should be a prime */
int create_mime_table(unsigned elements) {
    MALLOC(mime_table, elements * sizeof(mime_t *));

#ifdef RELEASE
    memset(mime_table, 0, elements * sizeof(mime_t *));
#endif
    mime_count = elements;

    return 1;
}

int destroy_mime_table() {
    unsigned i;
    mime_t *curr;

    for (i = mime_count; i > 0; i--) {
	curr = mime_table[i];

	if (curr) {
	    free(curr->ext);
	    free(curr->type);
	    free(curr);
	}
    }

    return 0;
}
