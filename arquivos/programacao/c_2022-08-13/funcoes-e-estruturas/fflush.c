
// Flush STREAM, or all streams if STREAM is NULL.

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int fflush (FILE *__stream);

struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern FILE *fopen(const char *, const char *);
extern int getc(FILE *);
extern int printf(const char *, ...);

// the fflush function causes any unwritten data for that stream to be delivered to the host environment to be written to the file; otherwise, the behavior is undefined.
// é errado usar fflush para limpar buffer de entrada

// para limpar buffer do teclado utilize o fflush(stdin) que tambem pode ser utilizado para atualizar a tela durante um loop , fflush(stdout).


#include <stdio.h> 

int main(void)
{
  int   ch;
  char  buf[BUFSIZ], a;
  
  a = getchar();
  puts("Flushing input");
  
  while ((ch = getchar()) != '\n' && ch != -1);
  
  printf("Enter some text: ");
  
  if (fgets(buf, sizeof(buf), stdin))
  {
    printf ("You entered: %s", buf);
  }
  
  return 0;
}


