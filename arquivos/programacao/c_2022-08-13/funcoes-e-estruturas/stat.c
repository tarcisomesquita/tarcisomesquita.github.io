
// Get file attributes for FILE and put them in BUF.

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
extern int stat(const char *__restrict __file, struct stat *__restrict __buf);

extern int printf(char *, ...);

int main(int argc, char **argv) {
   struct stat st;
   
   if (argc != 2) {
      printf("Uso: %s /path/file\n", argv[0]);
      return 1;
   }
   stat(argv[1], &st);
   
   printf("\n");
   printf("st.st_dev     = %llu\n", st.st_dev);
   printf("st.__pad1     = %u\n", st.__pad1);
   printf("st.st_ino     = %lu\n", st.st_ino);
   printf("st.st_mode    = %u\n", st.st_mode);
   printf("st.st_nlink   = %u\n", st.st_nlink);
   printf("st.st_uid     = %u\n", st.st_uid);
   printf("st.st_gid     = %u\n", st.st_gid);
   printf("st.st_gid     = %u\n", st.st_gid);
   printf("st.__pad2     = %d\n", st.__pad2);
   printf("st.st_size    = %ld\n", st.st_size);
   printf("st.st_blksize = %ld\n", st.st_blksize);
   printf("st.st_blocks  = %ld\n", st.st_blocks);
   
   printf("st.st_atim.tv_sec  = %ld\n", st.st_atim.tv_sec);
   printf("st.st_atim.tv_nsec = %ld\n", st.st_atim.tv_nsec);
   printf("st.st_mtim.st_sec  = %ld\n", st.st_mtim.tv_sec);
   printf("st.st_mtim.tv_nsec = %ld\n", st.st_mtim.tv_nsec);
   printf("st.st_ctim.tv_sec  = %ld\n", st.st_ctim.tv_sec);
   printf("st.st_ctim.tv_nsec = %ld\n", st.st_ctim.tv_nsec);
   
   printf("st.__unused4  = %lu\n", st.__unused4);
   printf("st.__unused5  = %lu\n", st.__unused5);
   printf("\n");
   
   return 0;
}

