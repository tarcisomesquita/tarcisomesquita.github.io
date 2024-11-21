

/*
Abre o arquivo e retorna um ponteiro para a estrutura do arquivo aberto, ou NULL em caso de erro.

Pode se dizer que ela abre uma fila de bytes
*/

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
FILE *fopen(char *nome_do_arquivo, char *modo_de_abertura);
extern int printf(const char *, ...);

int main()
{
   FILE *fp;
   
   if((fp = fopen("teste.txt","w")) == '\0')
   {
      printf("Não posso abrir o Arquivo teste.\n");
      return(1);
   }
   
   return(0);
}

/*
A string modo_de_abertura pode conter alguns dos seguintes caracteres:
Caracter 	Finalidade
"r" 	Abre para leitura
"w" 	Cria um novo arquivo para escrita. Se já existe é eliminado e recriado.
"a" 	Abre para escrita no final do arquivo (append).
"b" 	O arquivo é um arquivo binário.
"t" 	Arquivo texto. (Linha finalizadas com '\n' e arquivo com EOF)
"rb" 	Abre Arquivo Binário para Leitura
"wb" 	Cria Arquivo Binário para Gravação
"ab" 	Anexa a um Arquivo Binário
"r+" 	Abre Arquivo de Texto para Leitura/Gravação
"w+" 	Cria Arquivo de Texto para Leitura/Gravação
"a+" 	Abre ou Cria Arquivo de Texto para Leitura/Gravação
"r+b" 	Abre Arquivo Binário para Leitura/Gravação
"w+b" 	Cria Arquivo Binário para Leitura/Gravação
"a+b" 	Abre ou Cria Arquivo Binário para Leitura/Gravação
"rt" 	Idem a "r"
"wt" 	Idem a "w"
"at" 	Idem a "a"
"r+t" 	Idem a "r+"
"w+t" 	Idem a "w+"
"a+t" 	Idem a "a+"


Alguns arquivos são definidos e abertos automaticamente pelo C, e podem ser usados por qualquer programa:
Arquivo 	Descrição
stdin 	Dispositivo de entrada padrão (geralmente teclado)
stdout 	Dispositivo de saída padrão (geralmente o vídeo)
stderr 	Dispositivo de saída de erros (sempre o vídeo)
*/

