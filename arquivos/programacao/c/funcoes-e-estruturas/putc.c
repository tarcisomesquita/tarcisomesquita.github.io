
/*
Grava caracteres em fila previamente aberta

ch é o caracter a ser gravado
fp é o ponteiro devolvido por fopen

*/

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);
extern int fclose(FILE *);
extern int putc(int ch, FILE *fp);
extern int printf(const char *, ...);
extern int getchar(void);

int main(argc,argv)
int argc;
char *argv[];
{
   FILE *fp;
   char ch;
   if (argc < 2)
   {
      printf("Digite o Nome do Arquivo\n");
      return(1);
   }
   
   if((fp=fopen(argv[1],"w")) == '\0')
   {
      printf("Arquivo não pode ser aberto\n");
      return(1);
   }
   
   do
   {
      ch = getchar();
      putc(ch,fp);
   }while(ch != '$');
   fclose(fp);
   return(0);
}

