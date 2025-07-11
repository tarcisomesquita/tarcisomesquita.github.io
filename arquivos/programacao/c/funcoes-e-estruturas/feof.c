
/*
Retorna diferente de zero se foi tentado ultrapassar o final do arquivo.
*/

//extern int feof(FILE *arquivo);

#include<stdio.h>

int main(argc,argv)
int argc;
char *argv[];
{
   FILE *in, *out;
   
   if(argc != 3)
   {
      printf("Digite o Nome dos Arquivos\n");
      return(1);
   }
   
   if((in=fopen(argv[1],"rb")) == NULL)
   {
      printf("Arquivo origem não existe\n");
      return(1);
   }
   
   if((out=fopen(argv[2],"wb")) == NULL)
   {
      printf("Arquivo destino não existe\n");
      return(1);
   }
   
   for( ;! feof(in); )
      putc(getc(in),out);  /* esta é a cópia propriamente dita */
   fclose(in);
   fclose(out);
   return(0);
}

// = =

//include<libio.h> // = =
#define _IO_feof_unlocked(__fp) (((__fp)->_flags & _IO_EOF_SEEN) != 0)
#define _IO_EOF_SEEN 0x10

int feof(FILE *fp)
{
  int result;
  result = _IO_feof_unlocked(fp);
  return result;
}

  result = (((fp)->_flags & 0x10) != 0);

