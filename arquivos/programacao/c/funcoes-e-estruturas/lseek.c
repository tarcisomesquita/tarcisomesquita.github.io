
// Values for the WHENCE argument to lseek.
#define SEEK_SET 0 // Seek from beginning of file.
#define SEEK_CUR 1 // Seek from current position.
#define SEEK_END 2 // Seek from end of file.

/*
Move FD's file position to OFFSET bytes from the:
   beginning of the file (if WHENCE is SEEK_SET)
   current position (if WHENCE is SEEK_CUR)
   end of the file (if WHENCE is SEEK_END)
Return the new file position.
*/

//#include<unistd.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern long int lseek (int fd, long int offset, int whence);

