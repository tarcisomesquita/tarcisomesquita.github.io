// clear ; gcc -Wall prog_PE.c -o prog_PE.elf && ./prog_PE.elf hello-fasm.exe

unsigned char *buffer = 0x00000000;
unsigned int offset = 0x00000000;

#include "includes.c"
#include "headers.c"
#include "print_HEADER_DOS.c"
#include "print_HEADER_NT.c"
#include "print_HEADER_SECTION.c"
#include "print_SECOES.c"


int main(int argc, char **argv) {
   int fd, n;
   struct stat arquivo;
   
   if (argc != 2) {
      printf("\nERRO: sintaxe de uso: %s file.exe\n\n", argv[0]);
      return 1;
   }
   
   if (lstat(argv[1], &arquivo)) {
      printf("\nlstat retornou diferente de 0 para o arquivo \"%s\"\n\n", argv[1]); 
      return 1;
   }
   
   buffer = malloc(arquivo.st_size);
   if(! buffer) {
      printf("\nERRO:\nNão foi possível alocar memória para buffer.\n\n");
      return 1;
   }
   
   fd = 0x00000000;
   fd = open(argv[1], O_RDONLY|O_NOATIME);
   if (fd == 0x00000000) {
      printf("\nErro ao abrir o arquivo.\n\n");
      free(buffer);
      return 1;
   }
   
   n = read(fd, buffer, arquivo.st_size);
   if (n != arquivo.st_size) {
      printf("n = 0x%02X ERRO\n", (unsigned int)n);
      printf("n = read(fd, buffer, %lu);\n\n", arquivo.st_size);
      close(fd);
      free(buffer);
      return 1;
   }
   close(fd);
   
   if (print_HEADER_DOS())     { free(buffer); return 1;}
   if (print_HEADER_NT())      { free(buffer); return 1;}
   if (print_HEADER_SECTION()) { free(buffer); return 1;}
   if (print_SECOES())         { free(buffer); return 1;}
   
   free(buffer); return 0;
}

