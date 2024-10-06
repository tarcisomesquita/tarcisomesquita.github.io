
// Seek to a certain position on STREAM. Altera a posição do ponteiro de um arquivo. Retorna 0 se OK.
// If you try to change the file position on a file that doesn't support random access, you get the errno = ESPIPE

//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//extern int printf(char *, ...);
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int fseek (FILE *__stream, long int __off, int __whence);
// The possibilities for the third argument to `fseek'.
#define SEEK_SET   0   // Seek from beginning of file. Posiciona a partir do inicio do arquivo.
#define SEEK_CUR   1   // Seek from current position.
#define SEEK_END   2   // Seek from end of file. Retrocede do final do arquivo.

// Exemplo:
// fseek(arq,10L,SEEK_SET); // Posiciona no 10º byte do inicio do arquivo.
// fseek(arq,sizeof(float),SEEK_CUR); // Avança 4 bytes.

extern int getc(FILE *);
extern FILE *fopen(const char *, const char *);
extern int printf(const char *, ...);
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);
int scanf (const char *, ...);

/*
// Exemplo: Leitura de um caracter em um arquivo binário.
int main()
{
   FILE *fp;
   if ((fp=fopen("teste.txt","rb")) == 0)
   {
      printf("Arquivo não pode ser aberto\n");
      return(1);
   }
   fseek(fp,6L,0);  // L força que seja um inteiro longo
   printf("\nO sexto caracter é '%c'\n\n", getc(fp));   // lê o caracter sexto caracter
   return(0);
}
*/


struct cidades
{
   int codigo;
   char nome[50];
   char uf[3];
};

int main(void)
{
   FILE *arquivo;
   struct cidades cidade;
   int achou, cod_temp;

   arquivo=fopen("cidades.dat","r+b"); // TENTA ABRIR PARA LEITURA/GRAVACAO
   if(arquivo==0)                      // SE NAO CONSEGUIR CRIA O ARQUIVO
   {
      arquivo = fopen("cidades.dat","w+b");
      if(arquivo==0)
      {
         fprintf(stderr,"Nao consegui criar o arquivo");
         return(1);
      }
   }
   
   do
   {
      printf("Codigo : ");
      printf("Nome.. : ");
      printf("Estado.: ");
      scanf("%d", &cod_temp);
      fflush(stdin);
      if(cod_temp==0) break;
      rewind(arquivo); // POSICIONA NO INICIO DO ARQUIVO
      achou = 0;
      while(fread(&cidade,sizeof(cidade),1,arquivo)==1 && !feof(arquivo)) // LE ATE O FINAL PROCURANDO CODIGO
      {
         if(cidade.codigo==cod_temp)
         {
            printf("Codigo ja cadastrado. Tecle Algo...");
            getch();
            achou = 1;
            break;
         }
      }
      if(!achou)
      {
         cidade.codigo = cod_temp;
         gets(cidade.nome);
         gets(cidade.uf);
         // POSICIONA NO FINAL PARA INCLUSAO E GRAVA NOVO REGISTRO
         fseek(arquivo,0L,SEEK_END);
         fwrite(&cidade,sizeof(cidade),1,arquivo);
      }
   }while(1);
   rewind(arquivo);
   //EXIBE TODOS OS REGISTROS CADASTRADOS
   while(fread(&cidade,sizeof(cidade),1,arquivo)==1 && !feof(arquivo))
      printf("%04d %-50s %2s\n",cidade.codigo,cidade.nome,cidade.uf);
   
   fclose(arquivo);
   return(0);
} 

