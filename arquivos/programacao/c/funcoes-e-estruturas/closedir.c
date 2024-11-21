
// Close the directory stream DIRP.
// Return 0 if successful, -1 if not.

// #include<dirent.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef struct __dirstream DIR;
extern int closedir (DIR *__dirp);


/*
errno defined for this function:

EBADF
    The dirstream argument is not valid. 
*/

