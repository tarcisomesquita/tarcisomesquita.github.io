// clear; gcc -Wall -Werror fstat.c -o fstat.elf && ./fstat.elf

// Get file attributes for the file, device, pipe, or socket that file descriptor FD is open on and put them in BUF.

//#include<time.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct timespec {
   long int tv_sec;
   long int tv_nsec;
};


//#include<bits/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct stat {
   unsigned long long int st_dev;
   unsigned short int __pad1;
   unsigned long int st_ino;
   unsigned int st_mode;
   unsigned int st_nlink;
   unsigned int st_uid;
   unsigned int st_gid;
   unsigned long long int st_rdev;
   unsigned short int __pad2;
   long int st_size;
   long int st_blksize;
   long int st_blocks;
   struct timespec st_atim;  // last access time
   struct timespec st_mtim;  // last modification time
   struct timespec st_ctim;  // creation time
   unsigned long int __unused4;
   unsigned long int __unused5;
};


//#include<sys/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int fstat(int fd, struct stat *buf);


// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define	STDIN_FILENO	0	// Standard input.


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);

// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open (const char *file, int oflag, ...);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY           00

// #include <unistd.h>
extern int close (int __fd);


int main(int argc, char **argv) {
   struct stat ttystat;
   int fd;
   
   if (argc != 2) {
      printf("Uso: %s /path/file\n", argv[0]);
      return 1;
   }
   
   fd = open(argv[1], O_RDONLY);
   if ( fd == -1) {
      printf("\nopen retornou ERRO.\n\n"); 
      return 1;
   }
   
   if (fstat(fd, &ttystat) < 0) {
      printf("\nfstat retornou ERRO.\n\n"); 
      return 1;
   }
   
   close(fd);
   
   printf("\n");
   printf("ttystat.st_dev     = %llu\n", ttystat.st_dev);
   printf("ttystat.__pad1     = %u\n", ttystat.__pad1);
   printf("ttystat.st_ino     = %lu\n", ttystat.st_ino);
   printf("ttystat.st_mode    = %u\n", ttystat.st_mode);
   printf("ttystat.st_nlink   = %u\n", ttystat.st_nlink);
   printf("ttystat.st_uid     = %u\n", ttystat.st_uid);
   printf("ttystat.st_gid     = %u\n", ttystat.st_gid);
   printf("ttystat.st_gid     = %u\n", ttystat.st_gid);
   printf("ttystat.__pad2     = %d\n", ttystat.__pad2);
   printf("ttystat.st_size    = %ld\n", ttystat.st_size);
   printf("ttystat.st_blksize = %ld\n", ttystat.st_blksize);
   printf("ttystat.st_blocks  = %ld\n", ttystat.st_blocks);
   
   printf("ttystat.st_atim.tv_sec  = %ld\n", ttystat.st_atim.tv_sec); // localtime((long int *)&(ttystat.st_atim.tv_sec));
   printf("ttystat.st_atim.tv_nsec = %ld\n", ttystat.st_atim.tv_nsec);
   printf("ttystat.st_mtim.st_sec  = %ld\n", ttystat.st_mtim.tv_sec);
   printf("ttystat.st_mtim.tv_nsec = %ld\n", ttystat.st_mtim.tv_nsec);
   printf("ttystat.st_ctim.tv_sec  = %ld\n", ttystat.st_ctim.tv_sec);
   printf("ttystat.st_ctim.tv_nsec = %ld\n", ttystat.st_ctim.tv_nsec);
   
   printf("ttystat.__unused4  = %lu\n", ttystat.__unused4);
   printf("ttystat.__unused5  = %lu\n", ttystat.__unused5);
   printf("\n");
   
   return 0;
}

