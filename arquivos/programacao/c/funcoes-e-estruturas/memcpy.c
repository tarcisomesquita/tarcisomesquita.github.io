
/* Copy N bytes of SRC to DEST.  */

//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *memcpy (void *__restrict __dest, const void *__restrict __src, unsigned long int __n);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

int main()
{
   unsigned char teste[] = "Isso ";
   memcpy(teste, "abcde", 5);
   fprintf(stdout, "teste = \"%s\"\n", teste);
   return 0;
}

