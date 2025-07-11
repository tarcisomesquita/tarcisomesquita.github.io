#ifndef DHTTPD_H
#define DHTTPD_H

/* Length of recv() read() buffers (make sure they are large enough for any
   HTML document or output of script, and large enough to fit images */
#define BUFLEN 524288

/* Maximum length of a line. Used to parse files */
#define MAX_LINE_LENGTH 256

/* Maximum length of a string. Used to parse files */
#define MAX_STR_LENGTH 256

/* Tiny buffer used for continuous sending, should be kept at 1024 */
#define TINYBUF 1024

/* the location of error documents */
#define ERROR_400 "/error_400.html"
#define ERROR_401 "/error_401.html"
#define ERROR_402 "/error_402.html"
#define ERROR_403 "/error_403.html"
#define ERROR_404 "/error_404.html"
#define ERROR_405 "/error_405.html"
#define ERROR_406 "/error_406.html"
#define ERROR_407 "/error_407.html"
#define ERROR_408 "/error_408.html"
#define ERROR_409 "/error_409.html"
#define ERROR_410 "/error_410.html"
#define ERROR_411 "/error_411.html"
#define ERROR_412 "/error_412.html"
#define ERROR_413 "/error_413.html"
#define ERROR_414 "/error_414.html"
#define ERROR_415 "/error_415.html"
#define ERROR_500 "/error_500.html"
#define ERROR_501 "/error_501.html"
#define ERROR_502 "/error_502.html"
#define ERROR_503 "/error_503.html"
#define ERROR_504 "/error_504.html"
#define ERROR_505 "/error_505.html"
#endif /* DHTTPD_H */

