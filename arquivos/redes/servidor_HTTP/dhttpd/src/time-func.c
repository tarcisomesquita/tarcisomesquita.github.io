#include <signal.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

char *get_rfc_date(time_t now, char *buf) {
    struct tm *tp;
    
    if (now == (time_t)NULL)
	return NULL;
    
    tp = gmtime(&now);
    
    /* RFC format: Tue, 04 Jun 2002 15:16:39 GMT */
    if (strftime(buf, 31, "%a, %d %b %Y %T GMT", tp) == 0)
	strncpy(buf, "strftime error", 14); 

    return buf;
}

/* Returns apache compliant timestamp for log files */
char *get_apache_date(char *buf) {
    time_t now;
    struct tm *tptr;

    if ((now = time(NULL)) == (time_t) -1)
	abort();
    tptr = gmtime(&now);

    /* Apache log format: 20/Jun/2002:14:30:19 +0200 */
    strftime(buf, 27, "%d/%b/%Y:%T %z", tptr);

    return buf;
}

char *timestamp(void) {
    time_t now;
    char *the_time;
    
    time(&now);
    the_time = ctime(&now);
    the_time[25] = '\0'; 
    
    return the_time;
}
