
// Call a function on every element in a directory tree.

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
   struct timespec st_atim;
   struct timespec st_mtim;
   struct timespec st_ctim;
   unsigned long int __unused4;
   unsigned long int __unused5;
};


//#include<ftw.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef int (*__ftw_func_t) (const char *__filename, const struct stat *status, int flag);
extern int ftw (const char *dir, __ftw_func_t func, int descriptors);


extern int printf(char *, ...);

int func (const char *filename, const struct stat *st, int flag) {
   printf("filename = %s\n", filename);
   return 0;
}


int main() {
   int descriptors;
   ftw ("/home/ubuntu/Desktop/", func, descriptors);
   return 0;
}

