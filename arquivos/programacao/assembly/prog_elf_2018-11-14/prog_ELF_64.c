// clear ; gcc -Wall -static prog_ELF_64.c -o prog_ELF_64.elf && strip ./prog_ELF_64.elf && ./prog_ELF_64.elf prog_ELF_64.elf

//#include "includes.c"
//#include "le_shdr.c"
//#include "codigos.c"

#include <stdio.h>    // printf
#include <fcntl.h>    // open
#include <unistd.h>   // close, read, lseek
#include<linux/elf.h> // struct elf64_hdr

#include "print_ehdr.c"
#include "print_phdr.c"
#include "print_shdr.c"

int main(int argc, char **argv) {
   int fd, i;
   unsigned int off_local;
   struct elf64_hdr  ehdr;
   struct elf64_phdr phdr;
   struct elf64_shdr shdr;

   if (argc != 2) {
      printf("\nERRO: sintaxe de uso: ./prog_ELF_64.elf file_64.elf\n\n");
      return 1;
   }
   
   fd = open(argv[1],O_RDONLY);
   
   if (fd < 0) {
      printf("\nErro ao abrir o arquivo.\n\n");
      return 1;
   }
   
   printf(   
".intel_syntax noprefix\n"
".text\n"
".global _start\n"
"_start:\n\n"
);
   
   read(fd, &ehdr, sizeof(ehdr));
   if (print_ehdr(&ehdr)) { close(fd); return 1; }
   
   printf("phdr:\n");
   lseek(fd, ehdr.e_phoff, SEEK_SET); // Seek from beginning of file.
   off_local = ehdr.e_phoff;
   for (i=0; i < ehdr.e_phnum; i++) {
      read(fd, &phdr, sizeof(phdr));
      if (print_phdr(i, off_local, &phdr)) { close(fd); return 1; }
      off_local += ehdr.e_phentsize;
   }
   
   printf("shdr:\n");
   lseek(fd, ehdr.e_shoff, SEEK_SET); // Seek from beginning of file.
   off_local = ehdr.e_shoff;
   for (i=0; i < ehdr.e_shnum; i++) {
      read(fd, &shdr, sizeof(shdr));
      if (print_shdr(i, off_local, &shdr)) { close(fd); return 1; }
      off_local += ehdr.e_shentsize;
   }
   
   
   close(fd);
   return 0;
}

