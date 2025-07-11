// clear ; gcc -Wall -static creat.c -o creat.elf && strace ./creat.elf /home/ubuntu/Desktop/creat-teste.txt

// Create and open FILE, with mode MODE.
// If FILE already exist, remove it and creat a new.

// #include <fcntl.h>
extern int creat (const char *file, unsigned int mode);

// #include <linux/stat.h>
#define S_IRWXU 00700
#define S_IRUSR 00400
#define S_IWUSR 00200
#define S_IXUSR 00100

#define S_IRWXG 00070
#define S_IRGRP 00040
#define S_IWGRP 00020
#define S_IXGRP 00010

#define S_IRWXO 00007
#define S_IROTH 00004
#define S_IWOTH 00002
#define S_IXOTH 00001

// #include <stdio.h>
extern int printf(char *, ...);

// #include <unistd.h>
extern int close (int __fd);

int main(int argc, char **argv) {
   int fd;
   
   if (argc != 2) return 1;
   
   // use a função unlink para remover o arquivo
   if ((fd = creat(argv[1], S_IRUSR|S_IWUSR)) == -1) {
      printf("\nCan't create file %s\n\n", argv[1]);
      return 1;
   }
   close(fd);
   return 0;
}

