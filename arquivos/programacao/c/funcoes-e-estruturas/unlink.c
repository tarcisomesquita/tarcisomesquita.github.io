// clear ; gcc -Wall -static unlink.c -o unlink.elf && strace ./unlink.elf /home/ubuntu/Desktop/creat-teste.txt

// Remove the link NAME.
// #include <unistd.h>
extern int unlink (const char *name);

extern int printf(char *, ...);

int main(int argc, char **argv) {
   if (argc != 2) return 1;
   
   // use a função creat para criar um arquivo
   if (unlink(argv[1]) < 0) {
      printf("\nCan't remove file %s\n\n", argv[1]);
      return 1;
   }
   
   return 0;
}

