
// Change the process's working directory to the one FD is open on.

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int fchdir(int __fd);
extern char *getcwd(char *__buf, unsigned long int __size);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open (const char *file, int oflag, ...);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY	     00


// #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern char *strerror(int errnum);


// #include<errno.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int *__errno_location(void);
#define errno (*__errno_location())


int main()
{
   char *mydirectory;
   int file;
   mydirectory = getcwd(0x00000000, 0x00000000);
   fprintf(stdout, "\nmydirectory = %s\n", mydirectory);
   
   file = open("/media/arq_blue/",O_RDONLY);
   if(fchdir(file))
   {
      fprintf(stdout, "fchdir retornou diferente de zero\n");
      fprintf(stdout, "%s\n",strerror(errno));
   }
   mydirectory = getcwd(0x00000000, 0x00000000);
   fprintf(stdout, "mydirectory = %s\n\n", mydirectory);
   
   return 0;
}

/*
The normal, successful return value from fchdir is 0. A value of -1 is returned to indicate an error. The following errno error conditions are defined for this function:

EACCES
    Read permission is denied for the directory named by dirname.
EBADF
    The filedes argument is not a valid file descriptor.
ENOTDIR
    The file descriptor filedes is not associated with a directory.
EINTR
    The function call was interrupt by a signal.
EIO
    An I/O error occurred. 
*/
