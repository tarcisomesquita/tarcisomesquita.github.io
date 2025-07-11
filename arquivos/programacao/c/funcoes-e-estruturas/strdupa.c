
/*
strdupa()is similar to strdup(), but use alloca(3) to allocate the buffer.
It is only available when using the GNU GCC suite.
*/

//#include <string.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
char *strdupa(const char *s);

