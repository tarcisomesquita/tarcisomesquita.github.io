
// Print a message describing the meaning of the value of errno.

// #include <stdio.h>
extern void perror(const char *s);
extern int sprintf(char *s, const char *format, ...);

// #include<sys/stat.h>
extern int mkdir(const char *path, unsigned int mode);

int main() {
   char file_line[50];
   
   if (mkdir("teste/teste", 0777) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   return 0;
}

