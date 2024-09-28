
// gcc -Wall fstat_file.c -o fstat_file.elf && ./fstat_file.elf fstat_file.elf

// VEJA lstat

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


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);


int main(int argc, char **argv) {
   int fd;
   struct stat arquivo;
   
   if (argc != 2) {
      printf("\nUso: %s nome-do-arquivo\n\n", argv[0]); 
      return 1;
   }
   
   fd = 0;
   fd = open(argv[1], O_RDONLY|O_NOATIME, 0664); // the mode_t 0664 é a permissão para o arquivo
   if (! fd) {
      printf("\nNão foi possível abrir o arquivo \"%s\"\n\n", argv[1]); 
      return 1;
   }
   
   if (fstat(fd, &arquivo)) {
      printf("\nfstat retornou diferente de 0 o arquivo \"%s\"\n\n", argv[1]); 
      return 1;
   }
   
   printf("\n");
   printf("arquivo.st_dev     = %llu\n", arquivo.st_dev);
   printf("arquivo.__pad1     = %u\n", arquivo.__pad1);
   printf("arquivo.st_ino     = %lu\n", arquivo.st_ino);
   printf("arquivo.st_mode    = %u\n", arquivo.st_mode);
   printf("arquivo.st_nlink   = %u\n", arquivo.st_nlink);
   printf("arquivo.st_uid     = %u\n", arquivo.st_uid);
   printf("arquivo.st_gid     = %u\n", arquivo.st_gid);
   printf("arquivo.st_gid     = %u\n", arquivo.st_gid);
   printf("arquivo.__pad2     = %d\n", arquivo.__pad2);
   printf("arquivo.st_size    = %ld\n", arquivo.st_size);
   printf("arquivo.st_blksize = %ld\n", arquivo.st_blksize);
   printf("arquivo.st_blocks  = %ld\n", arquivo.st_blocks);
   
   printf("arquivo.st_atim.tv_sec  = %ld\n", arquivo.st_atim.tv_sec); // localtime((long int *)&(arquivo.st_atim.tv_sec));
   printf("arquivo.st_atim.tv_nsec = %ld\n", arquivo.st_atim.tv_nsec);
   printf("arquivo.st_mtim.st_sec  = %ld\n", arquivo.st_mtim.tv_sec);
   printf("arquivo.st_mtim.tv_nsec = %ld\n", arquivo.st_mtim.tv_nsec);
   printf("arquivo.st_ctim.tv_sec  = %ld\n", arquivo.st_ctim.tv_sec);
   printf("arquivo.st_ctim.tv_nsec = %ld\n", arquivo.st_ctim.tv_nsec);
   
   printf("arquivo.__unused4  = %lu\n", arquivo.__unused4);
   printf("arquivo.__unused5  = %lu\n", arquivo.__unused5);
   printf("\n");
   
   return 0;
}

