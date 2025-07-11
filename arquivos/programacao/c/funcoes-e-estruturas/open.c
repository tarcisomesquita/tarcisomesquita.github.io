
// Open FILE and return a new file descriptor for it, or -1 on error.
// OFLAG determines the type of access used.
// If O_CREAT is on OFLAG, the third argument is taken as a `mode_t', the mode of the created file.

// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open (const char *file, int oflag, ...);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY           00
#define O_WRONLY           01
#define O_RDWR             02
#define O_CREAT          0100   // not fcntl
#define O_APPEND        02000
#define O_SYNC         010000   // only implemented on blocks devices and on files located on an ext2 file system
#define O_DIRECT       040000   // Direct disk access
#define O_NOATIME    01000000   // Do not set atime

extern int printf(char *, ...);

int main() {
   int fd;
   fd = open("teste.txt", O_CREAT|O_RDWR|O_APPEND|O_SYNC|O_NOATIME, 0664); // the mode_t 0664 é a permissão para o arquivo
   printf("\nfd = %d\n\n", fd);
   return 0;
}

