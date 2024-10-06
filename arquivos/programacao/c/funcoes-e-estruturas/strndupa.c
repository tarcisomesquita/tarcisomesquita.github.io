
/*
strndupa()is similar to strndup(), but use alloca(3) to allocate the buffer.
It is only available when using the GNU GCC suite.
*/

//#include <string.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
char *strndupa(const char *s, size_t n);

