
/* Set N bytes of S to C.  

copies the value of c (converted to an unsigned char) into each of the first n bytes of the object beginning at s.

Returns the value of block.
*/

//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *memset(void *__s, int __c, unsigned long int __n);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

int main()
{
   unsigned long int teste = 0;
   memset(&teste, 2, 4);
   fprintf(stdout, "teste = 0x%08X\n", (unsigned int)teste);
   return 0;
}

