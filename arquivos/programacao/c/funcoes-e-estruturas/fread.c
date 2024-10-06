
// Para acesso randômico a arquivos
// A função retorna o número de itens realmente lidos e avança o ponteiro de arquivo tamanho*num bytes.

// #include<stdio.h>  // = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern long unsigned int fread(void *buffer, long unsigned int size, long unsigned int n, FILE *arquivo);
// buffer : Ponteiro para uma área de memória, geralmente uma estrutura ou um vetor, onde serão armazenados os dados lidos do arquivo.
// size: Numero de bytes a ler. Geralmente sizeof(buffer).
// n : Numero de itens a ler. Geralmente 1.
// arquivo: Ponteiro FILE para um arquivo aberto anteriormente por fopen().

extern int printf(const char *, ...);
FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);


int main()
{
   int i;
   FILE *fp;
   unsigned char conteudo[500];
   fp = fopen("fread.c","r");
   fread(conteudo, 1, 500, fp);
   
   printf("\n");
   for(i = 0; i < 500; i++)
      printf("%c", conteudo[i]);
   printf("\n\n");
   
   return 0;
}

