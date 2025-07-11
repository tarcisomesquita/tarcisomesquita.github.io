
/* Copy N bytes of SRC to DEST, guaranteeing correct behavior for overlapping strings. */

typedef unsigned int size_t;


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *memmove(void *dest, const void *src, size_t n);

