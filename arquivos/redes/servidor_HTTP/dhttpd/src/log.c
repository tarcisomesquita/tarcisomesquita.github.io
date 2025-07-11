

void log_request(const conn_t *conn)
{
#ifndef NI_MAXHOST
#define NI_MAXHOST 1025
#endif
    char atstamp[28], hbuf[NI_MAXHOST];
#ifdef HAVE_IPV6
    int err = 0;
#endif

    if (conn->vh == NULL)
	return;  /* Nowhere to print to! */

    /* Get timestamp */
    get_apache_date(atstamp);

    /* Get IP address */
    if (conn->sa == NULL) {
	if (conn->f.is_ipv6 == 1)
	    strncpy(hbuf, "::?", 3);
	else
	    strncpy(hbuf, "?.?.?.?", 7);
    } else {
	if (conn->f.is_ipv6 == 1) {
#ifdef HAVE_IPV6
	    if ((err =
		 getnameinfo((struct sockaddr *)conn->sa6,
			     sizeof(struct sockaddr_in6), hbuf,
			     NI_MAXHOST, NULL, 0,
			     NI_NUMERICHOST | NI_NUMERICSERV)) != 0) {
#ifndef RELEASE
		DEBUG_OUT2("could not get numeric hostname: %s\n",
			   strerror(err));
#endif
		strncpy(hbuf, "::!?", 4);
	    }
#endif
	} else
	    strncpy(hbuf, inet_ntoa(conn->sa->sin_addr), NI_MAXHOST-1);
    }

    switch (conn->vh->log_type) {
	case EXTENDED:
	    /*
	     * <date+time> <ip> <method> <file> <version> <status> <bytes> 
	     */
	    (void) fprintf(conn->vh->log_fd_ok,
			   "%s [%s] %s %s %s %d %ld\n",
			   atstamp, hbuf, get_method(conn->req->method),
			   conn->req->file, conn->req->http_version,
			   conn->req->response, conn->req->file_size);
	    break;
	case COMMON:
	    (void) fprintf(conn->vh->log_fd_ok,
			   "%s - - [%s] \"%s %s %s\" %d %ld\n",
			   hbuf, atstamp, get_method(conn->req->method),
			   conn->req->file, conn->req->http_version,
			   conn->req->response, conn->req->file_size);
	    break;
	case COMBINED:
	default:
	    /* Print it out */
	    (void) fprintf(conn->vh->log_fd_ok,
			   "%s - - [%s] \"%s %s %s\" %d %ld \"%s\" \"%s\"\n",
			   hbuf, atstamp, get_method(conn->req->method),
			   conn->req->file, conn->req->http_version,
			   conn->req->response, conn->req->file_size,
			   conn->req->referer, conn->req->useragent);
	    break;
    }


#ifndef RELEASE
    if (debug) {
	if (debug > 3) {
	    fflush(conn->vh->log_fd_ok);
	} 
	if (debug > 2) {
	    DEBUG_OUT2("Logged request, on fd: %d\n", fileno(conn->vh->log_fd_ok));
	} else {
	    DEBUG_OUT("Logged request\n");
	}
    }
#endif
}

void log_err_vhost(const req_t *req, const char *format, ...)
{
    va_list vars;

    (void) fprintf(req->vh->log_fd_err, "%s: ", timestamp());

    if (format) {
	va_start(vars, format);
	(void) vfprintf(req->vh->log_fd_err, format, vars);
	va_end(vars);
    }

    (void) fprintf(req->vh->log_fd_err, "\n"); 
}
