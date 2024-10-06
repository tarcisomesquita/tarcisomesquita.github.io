// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = =
extern long int syscall(long int __sysno, ...);

// #include<asm/unistd_32.h> // = = = = = = = = = = = = = = = = = = = = = = =
#define __NR_init_module	128

// #include<sys/mman.h> // = = = = = = = = = = = = = = = = = = = = = = =
extern void *mmap(void *addr, unsigned long int len, int prot, int flags, int fd, long int offset);
extern int munmap(void *addr, unsigned long int len);
#define MAP_FAILED   ((void *) -1)

// #include<bits/mman.h> // = = = = = = = = = = = = = = = = = = = = = = =
#define PROT_READ   0x1  // Page can be read.
#define MAP_SHARED  0x01 // Share changes.
#define MAP_PRIVATE 0x02 // Changes are private.


// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open (const char *file, int oflag, ...);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY           00

// #include <unistd.h>
extern int close(int fd);

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

extern int printf(char *, ...);


void *try_to_mmap_module(const char *filename, unsigned long int *image_size_p) {
   void *image;
   struct stat st;
   int fd;

   fd = open(filename, O_RDONLY);
   fstat(fd, &st);
   image = 0x00000000;
   
   if (st.st_size <= *image_size_p) {
      unsigned long int image_size = st.st_size;
      image = mmap(0x00000000, image_size, PROT_READ, MAP_PRIVATE, fd, 0);
      if (image == MAP_FAILED) image = 0x00000000;
      else *image_size_p = image_size;
   }
   close(fd);
   return image;
}

#  define INT_MAX	2147483647  // 0x7FFFFFFF
int bb_init_module(const char *filename, const char *options) {
   unsigned long int image_size;
   char *image;
   int rc;
   
   image_size = INT_MAX - 4095;
   
   image = try_to_mmap_module(filename, &image_size);
   if (! image) return 1;
   
   rc = syscall(__NR_init_module, image, image_size, options);
   
   munmap(image, image_size);
   
   return rc; // retorna 0 para sucesso
}


int main(int argc, char **argv) {
   char *filename;
   char *options = "";
   int rc;
   
   if (argc !=2 ) {
      printf("\nUsage: insmod /lib/modules/.../name.ko\n\n");
      return 1;
   }
   
   filename = argv[1];
   
   rc = bb_init_module(filename, options);
   return rc;
}

/*
clear && (unset TERM ORBIT_SOCKETDIR SSH_AGENT_PID GPG_AGENT_INFO SHELL XDG_SESSION_COOKIE GTK_RC_FILES WINDOWID GTK_MODULES LS_COLORS GNOME_KEYRING_SOCKET SSH_AUTH_SOCK SESSION_MANAGER USERNAME DESKTOP_SESSION GDM_XSERVER_LOCATION PWD LANG GDM_LANG GDMSESSION HISTCONTROL SHLVL HOME GNOME_DESKTOP_SESSION_ID LOGNAME XDG_DATA_DIRS DBUS_SESSION_BUS_ADDRESS LESSOPEN WINDOWPATH LESSCLOSE RUNNING_UNDER_GDM XAUTHORITY DISPLAY COLORTERM MAIL OLDPWD _ ; PATH=/bin:/usr/bin ; strace -s 100 -i -f -v ./insmod.elf /lib/modules/2.6.28-11-generic/kernel/drivers/net/wireless/iwlwifi/iwl3945.ko) 1>teste.txt 2>&1
*/

