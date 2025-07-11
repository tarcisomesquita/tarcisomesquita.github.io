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
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

#if HAVE_CONFIG_H
# include <config.h>
#endif

#include "dhttpd.h"
#include "types.h"
#include "log.h"
#include "additional.h"

char *make_html_file(char *page, const char *title, const char *body)
{
    int i = 0, k = 0;
    const char *doctype =
	"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 Transitional//EN\" "
	"\"http://www.w3.org/TR/REC-html40/loose.dtd\">\n";
    const char *head1 = "<HTML>\n<HEAD>\n\t<TITLE>";
    const char *head2 = "</TITLE>\n</HEAD><BODY>";
    const char *foot = "</BODY>\n</HTML>\n\n";

#define APPEND(a, b) for (i = 0; b[i]; i++, k++) if (k < BUFLEN - 1) a[k] = b[i]; else break;

    APPEND(page, doctype);
    APPEND(page, head1);
    APPEND(page, title);
    APPEND(page, head2);
    APPEND(page, body);
    APPEND(page, foot);
    page[k] = '\0';

    return page;
}

void get_error_during_error_doc(unsigned short *response, char *buf)
{
    switch (*response) {
    case 404:
	buf = make_html_file(buf, "Error 404 on top of error",
		     "Error 404 while getting an error document. "
		     "The file wasn't found, did you follow a link from the site? "
		     "If so, you might want to notify the webmaster. <BR><BR>"
		     "<I>You step in the stream<BR>\n"
		     "but the water has moved on<BR>\n"
		     "The page is not here</I>\n");
	break;
    case 501:
        buf = make_html_file(buf, "Narf!",
		     "It seems that you or your browser used some odd request. "
		     "This is quite uncommon, but could be my fault, or yours."
		     "<BR><BR>"
		     "<I>Not implemented<BR>"
		     "Sorry, forgive my creator<BR>\n"
		     "Haiku: time waster</I\n");
	break;
    case 500:
	buf = make_html_file(buf, "Whoops.",
		     "<I>Bad weather all over<BR>"
		     "I did not do as I hoped<BR>"
		     "Sceen, mind. Both are blank</I>");
	break;
    case 403:
	buf = make_html_file(buf, "Authorization Required",
		     "<I>Login incorrect.<BR>\n"
		     "Only perfect spellers may<BR>\n"
		     "enter this system</I>"); 
	break;
    case 405:
	buf = make_html_file(buf, "Screw you!",
		    "That is one thing that I refuse to do!");
	break; 
    case 408:
	buf = make_html_file(buf, "Time-Out",
		     "<I>Server's poor response<BR>"
		     "Not quick enough for browser.<BR>"
		     "Timed out, plum blossom</I>\n");
	break;
    default:
	buf = make_html_file(buf, "Ooooops!",
		     "Meanwhile, King Arthur and Sir Bedemir, not more than "
		     "a swallow's flight away, had discovered something.<BR><BR>"
		     "<I>Errors have occured.<BR>\n"
		     "We won't tell you where or why<BR>\n"
		     "Lazy programmers.</I>");
	break;
    }
}

const char *get_errordocument_name(unsigned short *code)
{
    switch (*code) {
    case 400:
	return ERROR_400;
    case 401:
	return ERROR_401;
    case 402:
	return ERROR_402;
    case 403:
	return ERROR_403;
    case 404:
	return ERROR_404;
    case 405:
	return ERROR_405;
    case 406:
	return ERROR_406;
    case 407:
	return ERROR_407;
    case 408:
	return ERROR_408;
    case 409:
	return ERROR_409;
    case 410:
	return ERROR_410;
    case 411:
	return ERROR_411;
    case 412:
	return ERROR_412;
    case 413:
	return ERROR_413;
    case 414:
	return ERROR_414;
    case 415:
	return ERROR_415;
    case 500:
	return ERROR_500;
    case 501:
	return ERROR_501;
    case 502:
	return ERROR_502;
    case 503:
	return ERROR_503;
    case 504:
	return ERROR_504;
    case 505:
	return ERROR_505;
    default:
	return "";
    }
}

const char *get_method(unsigned char code) {
    switch (code) {
	case GET:
	    return "GET";
	case HEAD:
	    return "HEAD";
	case POST:
	    return "POST";
	case TRACE:
	    return "TRACE";
	case CONNECT:
	    return "CONNECT";
	case OPTIONS:
	    return "OPTIONS";
	case PUT:
	    return "PUT";
	default:
	    return "UNKOWN";
    }
    return NULL;
}

unsigned char get_method_number(const char *method) {
    int len = 0;
    
    if (method == NULL)
	return UNKNOWN;
    
    len = strlen(method);
    
    switch (len) { /* A dirty first length matching to prevent unnecessary
		      dstrncmp()s */
	case 3:
	    if (dstrncmp(method, "GET", len) == 0)
		return GET;
	    if (dstrncmp(method, "PUT", len) == 0)
		return PUT;
	    return UNKNOWN;
	case 4:
	    if (dstrncmp(method, "HEAD", len) == 0)
		return HEAD;
	    if (dstrncmp(method, "POST", len) == 0)
		return POST;
	    return UNKNOWN;
	case 5:
	    if (dstrncmp(method, "TRACE", len) == 0)
		return TRACE;
	    return UNKNOWN;
	case 7:
	    if (dstrncmp(method, "CONNECT", len) == 0)
		return CONNECT;
	    if (dstrncmp(method, "OPTIONS", len) == 0)
		return OPTIONS;
	    return UNKNOWN;
	default:
	    return UNKNOWN;
    }
    return UNKNOWN;
}    
	    

/* This was toooooo much typing...... */
const char *http_response_text(unsigned short *code)
{
    switch (*code) {
    case 100:
	return "Continue";
    case 101:
	return "Switching Protocols";
    case 200:
	return "OK";
    case 201:
	return "Created";
    case 202:
	return "Accepted";
    case 203:
	return "Non-Authoritative Information";
    case 204:
	return "No Content";
    case 205:
	return "Reset Content";
    case 206:
	return "Partial Content";
    case 300:
	return "Multiple Choices";
    case 301:
	return "Moved Perminently";
    case 302:
	return "Moved Temporarily";
    case 303:
	return "See other";
    case 304:
	return "Not Mofified";
    case 305:
	return "Use Proxy";
    case 400:
	return "Bad Request";
    case 401:
	return "Unauthorized";
    case 402:
	return "Payment Required";
    case 403:
	return "Forbidden";
    case 404:
	return "Not Found";
    case 405:
	return "Method Not Allowed";
    case 406:
	return "Not Acceptable";
    case 407:
	return "Proxy Authentication Required";
    case 408:
	return "Request Time-out";
    case 409:
	return "Conflict";
    case 410:
	return "Gone";
    case 411:
	return "Length Required";
    case 412:
	return "Precondition Failed";
    case 413:
	return "Request Entity Too Large";
    case 414:
	return "Request-URI Too Large";
    case 415:
	return "Unsupported Media Type";
    case 500:
	return "Internal Server Error";
    case 501:
	return "Not Implemented";
    case 502:
	return "Bad Gateway";
    case 503:
	return "Service Unavailable";
    case 504:
	return "Gateway Time-out";
    case 505:
	return "HTTP Version not supported";
    default:
	return "Extension Code";
    }
}
