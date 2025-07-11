
//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *malloc(long unsigned int __size);
extern void free (void *__ptr);

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
   long int tv_sec;
   long int tv_nsec;
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
extern int lstat(const char *file, struct stat *buf);


// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open(const char *file, int oflag, ...);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY           00
#define O_NOATIME    01000000   // Do not set atime

// #include <unistd.h>
extern int close(int fd);
extern int read(int fd, void *buf, unsigned long int nbytes);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);
extern int sprintf(char *string, char *format, ...);

