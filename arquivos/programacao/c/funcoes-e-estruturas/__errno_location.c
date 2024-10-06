
// Function to get address of global `errno' variable.
// veja o exemplo em strerror.c

// #include<errno.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int *__errno_location(void);

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);

extern int printf(char *, ...);

int main()
{
  FILE *fp;
  fp = fopen("/dev/hd0", "r");
  if (! fp)
  {
     printf("*__errno_location() = %d\n",*__errno_location());
  }
     
  return(0);
}



