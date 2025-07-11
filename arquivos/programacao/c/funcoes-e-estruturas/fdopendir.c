
// Same as opendir, but open the stream on the file descriptor FD.

// #include<dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/// This is the data type of directory stream objects.
//   The actual structure is opaque to users.
typedef struct __dirstream DIR;

extern DIR *fdopendir (int __fd);


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
   int file;
   
   file = open("/media/arq_blua/",O_RDONLY);
   if(! fdopendir(file))
   {
      fprintf(stdout, "%s\n",strerror(errno));
   }
   
   return 0;
}

/*

If the fdopendir call returns successfully the file descriptor is now under the control of the system.
In case the function is unsuccessful it returns a null pointer and the file descriptor remains to be usable by the program. The following errno error conditions are defined for this function:

EBADF
    The file descriptor is not valid.
ENOTDIR
    The file descriptor is not associated with a directory.
EINVAL
    The descriptor does not allow reading the directory content.
ENOMEM
    Not enough memory available. 
*/
