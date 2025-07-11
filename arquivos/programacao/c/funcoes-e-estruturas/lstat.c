// gcc -Wall lstat.c -o lstat.elf && ./lstat.elf lstat.elf

// Get file attributes about FILE and put them in BUF.
// If FILE is a symbolic link, do not follow it.

//#include<time.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct timespec {
   long int tv_sec;
   long int tv_nsec;
};


//#include<bits/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct stat {
   unsigned long long int st_dev;   // device
   unsigned short int __pad1;       // File serial number.
   unsigned long int st_ino;        // 
   unsigned int st_mode;            // File mode.
   unsigned int st_nlink;           // Link count.
   unsigned int st_uid;             // User ID of the file's owner.
   unsigned int st_gid;             // Group ID of the file's owner.
   unsigned long long int st_rdev;  // Device number, if device.
   unsigned short int __pad2;       // 
   long int st_size;                // Size of file, in bytes.
   long int st_blksize;             // Optimal block size for I/O.
   long int st_blocks;              // Number 512-byte blocks allocated.
   struct timespec st_atim;         // Time of last access.
   struct timespec st_mtim;         // Time of last modification.
   struct timespec st_ctim;         // Time of last status change. (criação)
   unsigned long int __unused4;     // 
   unsigned long int __unused5;     // 
};


//#include<sys/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int lstat(const char *file, struct stat *buf);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);


int main(int argc, char **argv) {
   struct stat arquivo;
   
   if (argc != 2) {
      printf("\nUso: %s nome-do-arquivo\n\n", argv[0]); 
      return 1;
   }
   
   if (lstat(argv[1], &arquivo)) {
      printf("\nlstat retornou diferente de 0 para o arquivo \"%s\"\n\n", argv[1]); 
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


