
/*
Fechar as filas abertas. Caso o programa seja encerrado sem que as filas sejam fechadas, dados gravados nos buffers podem ser perdidos.
*/


//#include<stdio.h> = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);
extern int fclose(FILE *ponteiro_para_o_arquivo);
extern int printf(const char *, ...);

int main()
{
   FILE *fp;
   
   if((fp = fopen("teste.txt","w")) == '\0')
   {
      printf("Não posso abrir o Arquivo teste.\n");
      return(1);
   }
   fclose(fp);
   return(0);
}

