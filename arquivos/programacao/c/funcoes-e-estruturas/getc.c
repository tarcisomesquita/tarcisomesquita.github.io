
// Lê um caractere em uma fila aberta

// #include<stdio.h> = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern FILE *fopen(const char *, const char *);
extern int getc(FILE *);
extern int printf(const char *, ...);

int main(int argc, char **argv)
{
   FILE *stream;
   char arquivo = '\0';
   
   if(argc < 2)
   {
      printf("Forneça nome do programa.\n");
      return(1);
   }
   
   stream = fopen(argv[1], "r");
   
   for(;arquivo != '$';)
   {
      arquivo = getc(stream);
      printf("%c", arquivo);
   }
   printf("\n\n");
   return(0);
}

