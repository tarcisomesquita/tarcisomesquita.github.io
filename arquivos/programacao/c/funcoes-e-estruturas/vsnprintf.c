
// Maximum chars of output to write in MAXLEN.

//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
typedef __builtin_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)


//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//extern int printf(char *, ...);
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;
extern int vsnprintf (char *s, long unsigned int maxlen, const char *format, va_list arg);
extern int puts( const char *);


void PrintFError(char *format, ...)
{
  char buffer[256];
  va_list args;
  va_start(args, format);
  vsnprintf(buffer,10,format, args);
  puts(buffer);
  va_end (args);
}

int main()
{
   char szFileName[]="myfile.txt";
   PrintFError("Error opening %s", szFileName);
   return(0);
}

