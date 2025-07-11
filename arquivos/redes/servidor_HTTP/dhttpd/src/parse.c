
// Returns a pointer to the start of a line
char *getline(char *line, char *delims) {
    int i = 0;

    if (line == NULL)
	return NULL;

    for (i = 0; line[i] != '\0'; i++)
	if (matches_delim(line[i], delims))
	    line[i] = '\0';
	    return &line[i];
    return NULL;
}
    
    
void find_vhost(conn_t *conn)
{
    vhost_t *vhl;
    
    /* Find a matching vhost */
    for (vhl = conf->vhl; vhl != NULL && vhl->name != NULL; vhl = vhl->next)
	if (dstrncmp(vhl->name, conn->req->host,
		    strlen(conn->req->host)) == 0) {
	    conn->vh = conn->req->vh = vhl;
	    conn->state = FOUND;
	    break;
	}
		

    /* Find default vhost if we didn't match any */
    if ((conn->vh == NULL) || (vhl->name == NULL))
	for (vhl = conf->vhl; vhl != NULL && vhl->name != NULL; vhl = vhl->next)
	    if (dstrncmp(vhl->name, "default", 7) == 0) {
		conn->vh = conn->req->vh = vhl;
		conn->state = FOUND;
		break;
	    }
		    

    /* Still no match, abort */
    if ((conn->vh == NULL) || (vhl->name == NULL))
	conn->state = FAULT;
}

/*
 * Attempts to set the vhost to default. This must succeed.
 */
void default_vhost(conn_t *conn) {
    vhost_t *vhl;

    for (vhl = conf->vhl; vhl != NULL && vhl->name != NULL; vhl = vhl->next)
	if (dstrncmp(vhl->name, "default", 7) == 0) {
	    conn->vh = conn->req->vh = vhl;
	    conn->state = FOUND;
	    return;
	}

    /* This is user error */
    DEBUG_OUT("Hey buddy; where's the default vhost!?\n");
    abort();
}

/* Quick verion of parse_name_value assuming that strlen(delims) == 2 */

int parse_name_value2(const char *line, char *name, const int max_name,
	char *value, const int max_value, char *delims) {

    int i = 0, tmp = 0;
    for (;line[i] && line[i] != delims[0] && line[i+1] != delims[1];i++)
	if (tmp < max_name)
	    name[tmp++]=line[i];
    name[tmp] = '\0';
    if ((line[i]) && (line[i+1])) i+=2;
	else return -1;
    tmp = 0;
    for (;line[i];i++)
	if (tmp < max_value)
	    value[tmp++] = line[i];
    value[tmp]='\0';
    return 0;
}





/* 
 * Parses request line 
 *
 * Returns:
 * 0 on succesful parsing (200)
 * -1 on format error (400)
 * -2 on internal parse error (500)
 * -3 on a string that is too long (414)
 */
int parse_request_line(conn_t *conn, const char *line) {
    int i = 0, len = 0, state = FIRST, len2 = 0;
    const int max_method = 16;
    char method[max_method];

    if (line == NULL)
	return -1;
    len = strlen(line);

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Parsing request line: %s\n", line);
#endif
	
    /* Who says sscanf() is ugly? :P */
    for (; line[i] ; i++) {
	if (state == FIRST) {
	    if (isupper(line[i]) && isalpha(line[i])) {
		if (i < max_method -1)
		    method[len2++] = line[i];
		continue;
	    } else if (line[i] == ' ') { /* No spaces in URIs! */
		state = SECOND;
		method[len2] = '\0';
		len2 = 0;
		conn->req->method = get_method_number(method);
		continue;
	    } 

	    return -1;
	} else if (state == SECOND) {
	    if (len2 >= _POSIX_PATH_MAX - 1)
		return -3;

	    if (line[i] == ' ') {
		conn->req->file[len2] = '\0';
		state = THIRD;
		continue;
	    }
	    /* Overflow prevented by length check before loop 
	       WHERE, DUBLET ? WHERE ? SOMEWHERE! :D */

	    conn->req->file[len2++] = line[i]; 
	    continue;
	} else if (state == THIRD) {
	    /* XXX: Not very adaptable towards the future (eg: HTTP/12.10)
	     * Still RFC 2616 compatible */
	    if (dstrncmp(&line[i], "HTTP/", 5) == 0) {
	       if (isdigit(line[i + 5]) && line[i + 6] == '.' && 
		       isdigit(line[i + 7])) {
		   /* XXX: Very naughty trick */
		   strlcpy(conn->req->http_version, &line[i], 9);
		   return 0;
	       } else {
	       strlcpy(conn->req->http_version, "HTTP/1.0",9);
#ifndef RELEASE
	       if (debug)
		       DEBUG_OUT2("Couldn't extract version from: %s\n", &line[i+4]);
#endif
		}
	    }
	    return -1;
	} 
	return -2;
    }
    return -1; /* If we get here, then we expected more, but didn't get it */
}

/* Simply extracts filename from received request, does not change it */
void parse_request(conn_t *conn)
{
    const char *delim = "\r\n"; 
    char *param = NULL, *field = NULL, *foo = NULL, host_parsed = 0, 
	*tmp = NULL;
    static char *line = NULL;
    int len = 0;
#ifndef RELEASE			/* testing SIGCHLD after 5 */
/*    static int count = 0;

    count++;
    if (count > 5)
	exit(42);
*/
#endif
#ifndef RELEASE
    if (debug)
	DEBUG_OUT("About to parse received request\n");
#endif
   
    /* Get request line */
    if (line == NULL) /* If line != NULL then we're running pipelined */ 
	if ((line = strtok(conn->req->recv_buf, delim)) == NULL) {
	    set_error(conn->req, 400);
	    conn->state = FAULT;
	    return;
	}

    switch (parse_request_line(conn, line)) {
	case -1:
	    set_error(conn->req, 405);
	    strncpy(conn->req->http_version, "HTTP/1.0", 8);
	    DEBUG_OUT2("Left of request: |%s|\n", line);
	    if (conn->f.is_persistent)
		line = NULL;
	    return;
	case -2:
	    set_error(conn->req, 500);
	    strncpy(conn->req->http_version, "HTTP/1.0", 8);
	    DEBUG_OUT2("Left of request: |%s|\n", line);
	    if (conn->f.is_persistent)
		line = NULL;
	    return;
	case -3:
	    set_error(conn->req, 414);
	    strncpy(conn->req->http_version, "HTTP/1.0", 8);
#ifndef RELEASE
	    if (debug)
		DEBUG_OUT3("Left of request: (%d) |%s|\n", strlen(line), line);
#endif
	    if (conn->f.is_persistent)
		line = NULL;
	    return;
	default:
	    break;
    }
	    
#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Method: %s\n", get_method(conn->req->method));
#endif

    /** RFC 2068 specifies this as possible methods:
     *
     *     Method         = "OPTIONS"                ; Section 9.2
     *                    | "GET"                    ; Section 9.3
     *                    | "HEAD"                   ; Section 9.4
     *                    | "POST"                   ; Section 9.5
     *                    | "PUT"                    ; Section 9.6
     *                    | "DELETE"                 ; Section 9.7
     *                    | "TRACE"                  ; Section 9.8
     *                    | extension-method
     *  RFC 2616 also specifies CONNECT for proxies.
     **
     * AI = Already Implemented
     * DI = Definatly should be Implemented
     * PI = Possible Implementation
     * NI = Not to be Implemented
     */

    /* Pre-handle methods */
    conn->req->response = 200;

    switch (conn->req->method) {
	case GET:
	case POST: 
	case HEAD:	/* AI */
	case TRACE:
	    break;
	case OPTIONS:
	case DELETE: /* NI */
	case PUT: /* PI */
	    set_error(conn->req, 501);
	    break;
	case CONNECT:
	    set_error(conn->req, 405); /* We're not some fscking pr0xy! */
	    break;
	default:
	    /* Other methods aren't explicit in the RFC */
	    set_error(conn->req, 400);	
	    break;
    }

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("Requested: %s\n", conn->req->file);
#endif

    /* RFC2068 dictates HTTP/1.1 servers should default to persistent 
     * connections. */
    conn->f.is_persistent = 0;
    if (dstrncmp2(conn->req->http_version, "HTTP/1.1", 9) == 0)
	conn->f.is_persistent = 1;
    
    /***** PARSE REQUEST PARAMETERS *****/
    /* Example request
     ** 
     * GET /favicon.ico HTTP/1.1
     * User-Agent: Mozilla/5.0 (compatible; Konqueror/3; NetBSD 1.6I; X11; i386; en)
     * Accept: text/ *, image/jpeg, image/png, image/ *, * / *
     * Accept-Encoding: x-gzip, gzip, identity
     * Accept-Charset: iso-8859-1, utf-8;q=0.5, *;q=0.5
     * Accept-Language: en
     * Host: localhost:8080
     */
    
    /* Allocate parse members */
    MALLOC(field, MAX_STR_LENGTH);
    MALLOC(param, MAX_STR_LENGTH);
   
    /* Parse additional request info per line */ 
    while ((line = strtok(NULL, delim)) != NULL && 
	    parse_name_value2(line, field, MAX_STR_LENGTH - 1, param, 
		MAX_STR_LENGTH - 1, ": ") >= 0) {
#ifndef RELEASE
	if (debug > 1)
	    DEBUG_OUT3("Parsed field '%s' with value '%s'\n", field, param);
#endif

	if (dstrncmp(field, "Host", 4) == 0) {
	    strlcpy(conn->req->host, param, MAX_STR_LENGTH);
	    host_parsed = 1;
	} else if (dstrncmp(field, "Referer", 7) == 0)
	    strlcpy(conn->req->referer, param, MAX_STR_LENGTH);
	else if (dstrncmp(field, "User-Agent", 10) == 0)
	    strlcpy(conn->req->useragent, param, MAX_STR_LENGTH);
	else if (dstrncmp(field, "Connection", 10) == 0) {
	    if (strncasecmp(param, "keep-alive", 10) == 0)
		conn->f.is_persistent = 1;
	    else if (strncasecmp(param, "close", 5) == 0)
		conn->f.is_persistent = 0;
	    /* Some browsers send 'keep-alive' in lowercase, but the RFC
	     * dictates 'Keep-Alive'.. oh well.. */
	} else if (dstrncmp(field, "Cookie", 6) == 0) {
	    conn->req->has_cookie = 1;
	    strlcpy(conn->req->cookie, param, MAX_STR_LENGTH);
	}
    }

    /* There is more data in recv buffer, probably pipelines request */
    conn->f.is_pipelined = 0;
    if ((line != NULL)) {
	if (conn->f.is_persistent) 
	    conn->f.is_pipelined = 1;
	else {
	    set_error(conn->req, 400);
	    return;
	}
    } 

    /***** POST PROCESS *****/
    
    /* ABSURI	= {SCHEME}":"({UCHAR}|{RESERVED})*
     * SCHEME	= {ALPHA}|{DIGIT}|[+-.]
     * UCHAR	= {UNRESERVED}|{ESCAPE}
     * UNRESERVED = {ALPHA}|{DIGIT}|{SAFE}|{EXTRA}
     * ALPHA	= [A-Za-z]
     * DIGIT	= [0-9]
     * SAFE	= [$-_.]
     * EXTRA	= [!*'(),]
     * ESCAPE	= "%"{HEX}{HEX}
     * HEX	= {DIGIT}|[A-Fa-f]
     * RESERVED = [;/?:@&=+]
     */

    MALLOC(tmp, (len = strlen(conn->req->file)));
    /* Tries to parse out the URI from the requested file 
     * XXX: Right now will leave '//' before the string */
    if (parse_name_value(conn->req->file, NULL, 0, tmp, len, ":") >= 0) {
	host_parsed = 1;
	free(conn->req->file);
	conn->req->file = tmp; /* XXX: file will still be too roomy, but not as
				  it was, not that we care, because doing a
				  realloc() would be too slow. */
    } else
	free(tmp);
       	

    
    /* HTTP/1.1 clients MUST include Host field! */
    if (dstrncmp2(conn->req->http_version, "HTTP/1.1", 8) == 0)
	if (!host_parsed)
	    set_error(conn->req, 400);

    /* Chomp off port number */
    if ((foo = memchr(conn->req->host, ':',
		      strlen(conn->req->host))) != NULL)
	foo[0] = '\0';

    conn->state = PARSED;

    /* If you love someone, set them free() */
    free(field);
    free(param);
    free(line);
}

/* Parses the config file */
void parse_config_file(struct config *conf)
{
    FILE *fl;
    char *cfg_line = NULL, *name, *value, *vh;
#ifdef HAVE_FGETLN
    char *buf;
#endif
    int linecount = 0, state = NONE;
    struct vhost *vhl;
    char *cfg_file;
    char no_cfg = 0;
#ifdef HAVE_FGETLN
    size_t len;
#else
    size_t len = MAX_STR_LENGTH;
#endif

    if (conf == NULL) {
	FATAL("conf stuct == NULL, should not happen!\n");
    }

    cfg_file = conf->config_file;
    /* Check if no config file was specified and switch to dhttpd.conf */
    if (cfg_file == NULL) {
	MALLOC(conf->config_file, 13);
	strlcpy(conf->config_file, "dhttpd.conf", 13);
	no_cfg = 1;
	cfg_file = conf->config_file;
    }

    /* Open file(or stdin if config_file == --) */
    fl = dstrncmp(cfg_file, "--",
		 2) == 0 ? stdin : fopen(cfg_file, "r");

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("cfg: Parsing %s\n", cfg_file);
#endif

    /* Check if file is open */
    if (fl == NULL || ferror(fl)) {
	FATAL("Couldn't open config file!\n"); 
	/* Config file opening error is fatal */
    }

    /* Allocate some memory */
#ifndef HAVE_FGETLN
    MALLOC(cfg_line, MAX_LINE_LENGTH);
#endif
    MALLOC(vh, MAX_STR_LENGTH);
    MALLOC(name, MAX_STR_LENGTH);
    MALLOC(value, MAX_STR_LENGTH);
    MALLOC(vhl, sizeof(struct vhost));
    conf->vhl = vhl;

    /* Read config file */
#ifdef HAVE_FGETLN
    while (!feof(fl) && (cfg_line = fgetln(fl, &len)) != NULL) {
#else
    while (!feof(fl) && (cfg_line = fgets(cfg_line, len, fl)) != NULL) {
#endif
	++linecount;

	/* Skip lines beginning with '#' and empty ones */
	if (cfg_line[0] == '#' || cfg_line[0] == '\n' || cfg_line[0] == '\0')
	    continue;

#ifdef HAVE_FGETLN
	/* Replace the newline with C string terminator */
	if (cfg_line[len - 1] == '\n')
	    cfg_line[len - 1] = '\0';
	else {
	    MALLOC(buf, strlen(cfg_line) + 1);
	    free(cfg_line);
	    buf[strlen(cfg_line)] = '\0';
	    cfg_line = buf;
	}
#endif
	
	if (state == NONE) {
	    if (strstr(cfg_line, "<global>") != NULL) {
		state = GLOBAL;
		continue;
	    } else if (sscanf(cfg_line, "<vhost:%[^>]>", vh) == 1) {	/* "<vhost:%[^>]>" */
#ifndef RELEASE
		if (debug) 
		    DEBUG_OUT2("cfg: Encountered vhost: %s\n", vh);
#endif
		set_vh_defaults(vhl);
		strlcpy(vhl->name, vh, MAX_STR_LENGTH);
		state = VHOST;
		continue;
	    } else if (strstr(cfg_line, "<QoS>")) {
#ifndef RELEASE
		if (debug)
			DEBUG_OUT("cfg: Encountered QoS\n");
#endif
#ifdef HAVE_QOS
		MALLOC (conf->qos, sizeof(qos_t));
		state = QOS;
		continue;
#else
		ERROR("Warning: found QoS section in your config file, but compiled without QoS support!\n");
		continue;
#endif	/* HAVE_QOS */
	    } 
	} else if (state == GLOBAL) {
	    if (strstr(cfg_line, "</global>") != NULL) {
		state = NONE;	/* End of global configuring */
		continue;
	    } 
	} else if (state == VHOST) {
	    if (strstr(cfg_line, "</vhost>") != NULL) {
		MALLOC(vhl->next, sizeof(struct vhost));
		vhl = vhl->next;
		state = NONE;	/* We've reached the end of this vhost */
		continue;
	    } 
#ifdef HAVE_QOS
	} else if (state == QOS) {
	    if (strstr(cfg_line, "</QoS>")) {
		state = NONE;
		continue;
	    }
#endif
	} else {
	    DEBUG_OUT2("cfg: Ignoring bogus line: %s\n", cfg_line);
	    continue;
	}

	/* Get name / value pair */
	if (parse_name_value(cfg_line, name, MAX_STR_LENGTH, value, 
		    MAX_STR_LENGTH, "= ") != 0) {
	    /* If we couldn't extract a pair, continue to next line */
	    DEBUG_OUT3("cfg: unexpected line at line %d: %s!\n", linecount,
		       cfg_line);
	    continue;
	}

#ifndef RELEASE
	/* Some debug output */
	if (debug)
	    DEBUG_OUT3("cfg: (%s,%s)\n", name, value);
#endif

	/* Do what must be done */
	if (state == GLOBAL) {
	    if (dstrncmp(name, "port", 4) == 0)
		conf->port = atoi(value);
	    else if (dstrncmp(name, "debug", 5) == 0)
#ifndef RELEASE
		debug = atoi(value);
#else
		{
		ERROR("You have defined the `debug' option, yet you did "
			"not wish for any debugging when you ./configured this "
			"beast; ignoring..\n");
		}
#endif
	    else if (dstrncmp(name, "https_port", 10) == 0) {
#ifdef HAVE_OPENSSL
		conf->ssl_port = atoi(value);
#else
		ERROR("Defined https port, but compiled without https "
			"support, ignoring...\n");
#endif
	    } else if (dstrncmp(name, "timeout", 7) == 0)
		conf->timeout = atoi(value);
	    else if (dstrncmp(name, "max_connections", 15) == 0)
		conf->backlog = atoi(value);
	    else if (dstrncmp(name, "script_pool", 11) == 0)
		conf->script_pool = atoi(value);
	    else if (dstrncmp(name, "jail_root", 9) == 0)
		strlcpy(conf->jail_root, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "user", 4) == 0)
		strlcpy(conf->user, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "perl_bin", 8) == 0)
		strlcpy(conf->perl_bin, value, MAX_STR_LENGTH);	    
	    else if (dstrncmp(name, "php_bin", 7) == 0)
		strlcpy(conf->php_bin, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "mime_file", 9) == 0)
		strlcpy(conf->mime_file, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "default_mime_type", 15) == 0)
		strlcpy(conf->default_mime_type, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "large_access_log_buffer", 21) == 0)
		conf->use_large_access_log_buffer = 1;
	    else if (dstrncmp(name, "cache_size", 10) == 0)
		conf->cache_size = atoi(value);
	    else if (dstrncmp(name, "max_cache_age", 15) == 0)
		conf->max_cache_age = atoi(value);
	    else if (dstrncmp(name, "listen_on", 9) == 0)
		strlcpy(conf->bind_addr, value, MAX_STR_LENGTH);
	    else
		DEBUG_OUT2("cfg: Unknown entity at line %d\n", linecount);
	} else if (state == VHOST) {
	    if (dstrncmp(name, "index_document", 12) == 0)
		strlcpy(vhl->index_doc, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "document_base", 11) == 0)
		strlcpy(vhl->doc_base, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "access_log", 10) == 0)
		strlcpy(vhl->log_ok, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "error_log", 9) == 0)
		strlcpy(vhl->log_err, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "log_type", 8) == 0)
		vhl->log_type = log_get_type(value);
	    else
		DEBUG_OUT2("cfg: Unknown entity at line %d\n", linecount);
#ifdef HAVE_QOS
	} else if (state == QOS) {
	    if (!dstrncmp(name, "interface_bandwidth", 19))
		conf->qos->bandwidth = qos_get_bandwidth(value);
	    else if (!dstrncmp(name, "intype", 6))
		conf->qos->type = qos_get_intype(value);
	    else if (!dstrncmp(name, "type", 4))
		conf->qos->type = qos_get_type(value);
	    else
		DEBUG_OUT2("cfg: Unknown entity at line %d\n", linecount);
#endif	/* HAVE_QOS */
	}
	
	memset(name, 0, MAX_STR_LENGTH);
	memset(value, 0, MAX_STR_LENGTH);
    }

#ifndef RELEASE
    if (debug)
	DEBUG_OUT("cfg: Parsing completed\n");
#endif

/*    free(vhl);*/
    free(cfg_line);
    free(vh);
    free(name);
    free(value);

    if (no_cfg)
	free(cfg_file);

    /* Let's close the file, since we don't need it */
    fclose(fl);
}

void parse_mime_file(struct config *conf)
{
    FILE *fd;
    int linecount = 0;
    char *line, *ext, *type;
#ifdef HAVE_FGETLN
    char *buf;
#endif
#ifdef HAVE_FGETLN
    size_t len;
#else
    size_t len = MAX_STR_LENGTH;
#endif
    unsigned int ext_len, type_len;

    if (conf == NULL) {
	(void) fprintf(stderr, "conf == NULL, should not happen!\n");
	abort();
    } else if (conf->mime_file == NULL) {
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT
		("No mime file specified, using hardcoded listing..\n");
#endif
	create_and_fill_mime_table(127);
	return;
    }

#ifndef HAVE_FGETLN
    MALLOC(line, MAX_STR_LENGTH);
#endif
    MALLOC(ext, MAX_STR_LENGTH);
    MALLOC(type, MAX_STR_LENGTH);

#ifndef RELEASE
    if (debug)
	DEBUG_OUT2("parsing mime file (%s)\n", conf->mime_file);
#endif

    if ((fd = fopen(conf->mime_file, "r")) == NULL) {
	perror("during opening mime file");
#ifndef RELEASE
	if (debug)
	    DEBUG_OUT2
		("Couldn't open file: %s, using hardcoded listing..\n",
		 conf->mime_file);
#endif
	create_and_fill_mime_table(127);
	return;
    }

    create_mime_table(251);

#ifdef HAVE_FGETLN
    while (!feof(fd) && (line = fgetln(fd, &len)) != NULL) {
#else
    while (!feof(fd) && (line = fgets(line, len, fd)) != NULL) {
#endif
	++linecount;

        /* Skip lines beginning with '#' and empty ones */
        if (line[0] == '#' || line[0] == '\n' || line[0] == '\0')
            continue;

#ifdef HAVE_FGETLN
        if (line[len - 1] == '\n')
	    line[len - 1] = '\0';
	else {
	    MALLOC(buf, strlen(line) + 1);
	    strncat(buf, "\0", 1);
	    line = buf;
	}
#endif

	if (parse_name_value(line, type, MAX_STR_LENGTH, 
				    ext, MAX_STR_LENGTH, " \t") == 0) {
#ifndef RELEASE
	    if (debug > 2)
		DEBUG_OUT4("mime line %d: extension %s has type %s\n", 
			linecount, ext, type);
#endif
	    type_len = strlen(type);
	    ext_len = strlen(ext);

	    if (add_type(ext, ext_len, type, type_len) == NULL)
		DEBUG_OUT2("Duplicate extension (%s) is mime list; ignoring..\n" ,ext);
	} 
#ifndef RELEASE
	else if (debug) 
	    DEBUG_OUT4("mime line %d: couldn't parse: %s, %s\n", linecount, 
		    line, type);
#endif

    }
    free(type);
    free(ext);
/*    free(line); */

#ifndef RELEASE
    if (debug > 2)
	DEBUG_OUT("Done with mime\n");
#endif

    fclose(fd);
#ifndef RELEASE
    if (debug > 8)
	print_stats();
#endif
}
