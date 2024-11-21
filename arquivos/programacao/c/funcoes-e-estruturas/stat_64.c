// gcc -Wall stat_64.c -o stat_64.elf && ./stat_64.elf stat_64.elf

// Get file attributes for FILE and put them in BUF.

// #include<time.h>
struct tm {
   int tm_sec;          // Seconds.      [0-60] (1 leap second)
   int tm_min;          // Minutes.      [0-59]
   int tm_hour;         // Hours.        [0-23]
   int tm_mday;         // Day.          [1-31]
   int tm_mon;          // Month.        [0-11]
   int tm_year;         // Year- 1900.
   int tm_wday;         // Day of week.  [0-6]
   int tm_yday;         // Days in year. [0-365]
   int tm_isdst;        // DST.          [-1/0/1]
   long int tm_gmtoff;  // Seconds east of UTC.
   const char *tm_zone; // Timezone abbreviation.
};
extern struct tm *localtime(long int *);


//#include<time.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct timespec {
   long int tv_sec;   // Seconds
   long int tv_nsec;  // Nanoseconds
};


//#include<x86_64-linux-gnu/bits/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct stat {
   unsigned long int st_dev;        // device
   unsigned long int st_ino;        // 
   unsigned long int st_nlink;      // Link count.
   unsigned int st_mode;            // File mode.
   unsigned int st_uid;             // User ID of the file's owner.
   unsigned int st_gid;             // Group ID of the file's owner.
   int __pad0;
   unsigned long int st_rdev;       // Device number, if device.
   long int st_size;                // Size of file, in bytes.
   long int st_blksize;             // Optimal block size for I/O.
   long int st_blocks;              // Number 512-byte blocks allocated.
   struct timespec st_atim;         // Time of last access.
   struct timespec st_mtim;         // Time of last modification.
   struct timespec st_ctim;         // Time of last status change. (criação)
   long int __glibc_reserved[3];    // 
};

//#include<sys/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int stat(const char *file, struct stat *buf);

extern int printf(char *, ...);

int main(int argc, char **argv) {
   struct stat st;
   struct tm *agora;
   
   if (argc != 2) {
      printf("Uso: %s /path/file\n", argv[0]);
      return 1;
   }
   stat(argv[1], &st);
   
   printf("\n");
   printf("st.st_dev     = %lu\n", st.st_dev);
   printf("st.st_ino     = %lu\n", st.st_ino);
   printf("st.st_nlink   = %lu\n", st.st_nlink);
   printf("st.st_mode    = %u\n", st.st_mode);
   printf("st.st_uid     = %u\n", st.st_uid);
   printf("st.st_gid     = %u\n", st.st_gid);
   printf("st.__pad0     = %d\n", st.__pad0);
   printf("st.st_rdev    = %lu\n", st.st_rdev);
   printf("st.st_size    = %ld\n", st.st_size);
   printf("st.st_blksize = %ld\n", st.st_blksize);
   printf("st.st_blocks  = %ld\n", st.st_blocks);
   
   printf("st.st_atim.tv_sec  = %ld   ", st.st_atim.tv_sec);
   agora = localtime(&st.st_atim.tv_sec);
   printf("%d/%d/%d %d:%d:%d %ld\n", agora[0].tm_mday, agora[0].tm_mon  + 1, agora[0].tm_year + 1900, \
                                     agora[0].tm_hour, agora[0].tm_min, agora[0].tm_sec, agora[0].tm_gmtoff);
   printf("st.st_atim.tv_nsec = %ld\n", st.st_atim.tv_nsec);
   
   printf("st.st_mtim.st_sec  = %ld   ", st.st_mtim.tv_sec);
   agora = localtime(&st.st_mtim.tv_sec);
   printf("%d/%d/%d %d:%d:%d %ld\n", agora[0].tm_mday, agora[0].tm_mon  + 1, agora[0].tm_year + 1900, \
                                     agora[0].tm_hour, agora[0].tm_min, agora[0].tm_sec, agora[0].tm_gmtoff);
   printf("st.st_mtim.tv_nsec = %ld\n", st.st_mtim.tv_nsec);
   
   printf("st.st_ctim.tv_sec  = %ld   ", st.st_ctim.tv_sec);
   agora = localtime(&st.st_ctim.tv_sec);
   printf("%d/%d/%d %d:%d:%d %ld\n", agora[0].tm_mday, agora[0].tm_mon  + 1, agora[0].tm_year + 1900, \
                                     agora[0].tm_hour, agora[0].tm_min, agora[0].tm_sec, agora[0].tm_gmtoff);
   printf("st.st_ctim.tv_nsec = %ld\n", st.st_ctim.tv_nsec);
   
   printf("st.__glibc_reserved[0]  = %ld\n", st.__glibc_reserved[0]);
   printf("st.__glibc_reserved[1]  = %ld\n", st.__glibc_reserved[1]);
   printf("st.__glibc_reserved[2]  = %ld\n", st.__glibc_reserved[2]);
   printf("\n");
   
   return 0;
}

