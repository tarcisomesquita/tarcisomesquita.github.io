//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

// If BUF is NULL, make STREAM unbuffered.
// Else make it use buffer BUF, of size BUFSIZ.  */
extern void setbuf(FILE *stream, char *buf);

#define _G_BUFSIZ  8192
#define _IO_BUFSIZ _G_BUFSIZ
#define BUFSIZ     _IO_BUFSIZ


   setbuf(stdout, NULL);
   setbuf(stderr, NULL);

