
// #include<dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// This is the data type of directory stream objects.
typedef struct __dirstream DIR;

// Open a directory stream on NAME.
// Return a DIR stream on the directory, or NULL if it could not be opened.
extern DIR *opendir (const char *__name);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


// #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern char *strerror(int errnum);

// #include<errno.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int *__errno_location(void);
#define errno (*__errno_location())


int main()
{
   
   if(! opendir("/media/arq_blua"))
   {
      fprintf(stdout, "%s\n",strerror(errno));
   }
   
   return 0;
}

// Directory streams and the underlying file descriptors are closed on exec

/*
following errno are defined for this function:

EACCES
    Read permission is denied for the directory named by dirname.
EMFILE
    The process has too many files open.
ENFILE
    The entire system, or perhaps the file system which contains the directory, cannot support any additional open files at the moment. (This problem cannot happen on the GNU system.)
ENOMEM
    Not enough memory available. 
*/
