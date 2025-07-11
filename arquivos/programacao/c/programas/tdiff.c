// Read NBYTES into BUF from FD.
// Return the number read, -1 for errors or 0 for EOF.
// blocks the program until input is available on the file descriptor; para evitar isso use a função select

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int read(int fd, void *buf, unsigned long int n);
extern int write(int fd, void *buf, unsigned long int n);

// #include<bits/fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define O_RDONLY           00

// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open(const char *file, int oflag, ...);
extern int close(int fd);

int main(int argc, char **argv) {
   char usage[]     = "\nusage:\ntdiff file1 file2\n\n";
   char erro1[]     = "\nfalhou a abertura do file1\n\n";
   char erro2[]     = "\nfalhou a abertura do file2\n\n";
   char erro3[]     = "\nERRO de leitura um um dos arquivos.\n\n";
   char igual[]     = "\nOs arquivos são IGUAIS.\n\n";
   char diferente[] = "\nOs arquivos são DIFERENTES.\n\n";
   
   int fd1, fd2, leu1, leu2;
   unsigned long int buf1, buf2;
   
   if (argc != 3) {
      write(1, usage, 27);
      return 1;
   }
   
   fd1 = open(argv[1], O_RDONLY);
   if (fd1 == -1) {
      write(1, erro1, 29);
      return 1;
   }
   
   fd2 = open(argv[2], O_RDONLY);
   if (fd2 == -1) {
      write(1, erro2, 29);
      close(fd1);
      return 1;
   }
   
   buf1 = 0x00000000;
   buf2 = 0x00000000;
   for (;;) {
      leu1 = read(fd1, (void *)&buf1, 4);
      leu2 = read(fd2, (void *)&buf2, 4);
      
      // Erro de leitura
      if (leu1 == -1 || leu2 == -1) {
         write(1, erro3, 38);
         close(fd1);
         close(fd2);
         return 1;
      }
      
      // Arquivos com tamanhos diferentes são diferentes.
      if (leu1 != leu2) {
         write(1, diferente, 31);
         break;
      }
      
      // Leituras diferente, então arquivos diferente.
      if (buf1 != buf2) {
         write(1, diferente, 31);
         break;
      }
      
      // final dos arquivos, então arquivos iguais.
      if (leu1 == 0) {
         write(1, igual, 27);
         break;
      }
   }
   
   close(fd1);
   close(fd2);
   
   return 0;
}

