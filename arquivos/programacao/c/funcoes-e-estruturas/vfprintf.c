
// Write formatted output to stream from argument list ARG.
// Return the total number of characters written or a number negative for error.


//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
typedef __builtin_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)


//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//extern int printf(char *, ...);
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;
extern int vfprintf (FILE *s, const char *format, va_list arg);


int tprintf(const char *format, ...)
{
   va_list arg;
   int done;
   va_start(arg,format);
   done = vfprintf(stdout, format, arg);
   va_end(arg);
   return(done);
}


int main()
{
   int a;
   a = tprintf("1 2 3 testando %s %u\n", " numero =", 8);
   tprintf("%d\n",a);
   return(0);
}

