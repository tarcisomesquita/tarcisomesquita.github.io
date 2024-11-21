
// Get the pathname of the current working directory, and put it in SIZE bytes of BUF.
// Returns NULL if the directory couldn't be determined or SIZE was too small.
// Returns BUF if successful.
// In GNU, if BUF is NULL, an array is allocated with `malloc';
// the array is SIZE bytes long, unless SIZE == 0, in which case it is as big as necessary.

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *getcwd(char *__buf, unsigned long int __size);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


int main()
{
   char *mydirectory;
   mydirectory = getcwd(0x00000000, 0x00000000);
   fprintf(stdout, "mydirectory = %s\n", mydirectory);
   return 0;
}


/*
The following errno error conditions are defined for this function:

EINVAL
    The size argument is zero and buffer is not a null pointer.
ERANGE
    The size argument is less than the length of the working directory name. You need to allocate a bigger array and try again.
EACCES
    Permission to read or search a component of the file name was denied. 
*/

/*
     char *
     gnu_getcwd ()
     {
       size_t size = 100;
     
       while (1)
         {
           char *buffer = (char *) xmalloc (size);
           if (getcwd (buffer, size) == buffer)
             return buffer;
           free (buffer);
           if (errno != ERANGE)
             return 0;
           size *= 2;
         }
     }
*/
