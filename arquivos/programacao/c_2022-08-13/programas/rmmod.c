// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = =
extern long int syscall(long int __sysno, ...);

// #include<asm/unistd_32.h> // = = = = = = = = = = = = = = = = = = = = = = =
#define __NR_delete_module   129

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = =
#define O_EXCL		   0200	// not fcntl
#define O_NONBLOCK	  04000

extern int printf(char *, ...);


int main(int argc, char **argv) {
   unsigned flags;
   int rc;
   
   if (argc !=2 ) {
      printf("\nUsage: rmmod.elf modulename\n\n");
      return 1;
   }
   
   flags = O_NONBLOCK;
   rc = syscall(__NR_delete_module, argv[1], flags);
   if (rc) return 1;
   
   return 0;
}

