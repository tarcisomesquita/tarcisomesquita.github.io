// fonte http://beej.us/guide/bgipc/output/html/multipage/mmap.html.

// To share data between processes you could map a section of a file in memory, and get a pointer to it.
// Memory mapped files can be very useful, especially on systems that don't support shared memory segments.

// To memory map a file, you use the mmap() system call
/*
void *mmap(void *addr, size_t len, int prot, int flags, int fildes, off_t off);
addr    Where we want the file mapped into. The best way to use this is to set it to (caddr_t)0 and let the OS choose it for you.
len     Length of the data we want to map into memory.
prot    Protection of access this process has to the memory mapped region. This is a bitwise-ORd values: PROT_READ, PROT_WRITE, and PROT_EXEC.
flags   You'll want to set it to MAP_SHARED if you're planning to share your changes to the file with other processes, or MAP_PRIVATE otherwise.
fildes  This is where you put that file descriptor you opened earlier.
off     This is the offset in the file that you want to start mapping from. Is a multiple of the virtual memory page size, obtained with getpagesize().

returns -1 on error, and sets errno. Otherwise, it returns a pointer to the start of the mapped data.
*/

/*
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

int fd, pagesize;
char *data;

fd = open("foo", O_RDONLY);
pagesize = getpagesize();
data = mmap((caddr_t)0, pagesize, PROT_READ, MAP_SHARED, fd, pagesize);
byte = data[0]; // leitura
data[0] = 'B';  // will cause a segmentation violation.
                // Open the file O_RDWR with prot set to PROT_READ|PROT_WRITE if you want read-write access to the data.
*/

/*
// to un-memory map a file:
int munmap(caddr_t addr, size_t len);
addr  is the returned from mmap()
len   is the same len passed to mmap()
returns -1 on error and sets the errno variable
//file will automatically unmap if your program exit.
*/

// If you have multiple processes manipulating the data in the same file, you might have to lock the file or use semaphores to regulate access to the file while a process messes with it.


// This program maps its own source to memory and prints the byte that's found at whatever offset you specify on the command line.
// Ex.: $ gcc -Wall mmap.c -o mmap.elf && ./mmap.elf 30

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char **argv) {
   int fd, offset;
   char *data;
   struct stat sbuf;
   
   if (argc != 2) {
      fprintf(stderr, "usage: ./mmap.elf offset\n");
      exit(1);
   }
   
   // Before mapping a file to memory, you need to get a file descriptor for it by using the open() system call:
   if ((fd = open("mmap.c", O_RDONLY)) == -1) {
      perror("open");
      exit(1);
   }
   
   if (stat("mmap.c", &sbuf) == -1) {
      perror("stat");
      exit(1);
   }
   
   offset = atoi(argv[1]);
   if (offset < 0 || offset > sbuf.st_size-1) {
      fprintf(stderr, "mmap: offset must be in the range 0-%ld\n", \
                                                             sbuf.st_size-1);
      exit(1);
   }
   
   data = mmap((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
   if (data == (caddr_t)(-1)) {
      perror("mmap");
      exit(1);
   }
   
   printf("byte at offset %d is '%c'\n", offset, data[offset]);
   
   return 0;
}

