int fputc(int caracter, FILE *arquivo)
  	Escreve um caracter no arquivo. Retorna o caracter gravado ou EOF em caso de erro.


#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
   FILE *origem,*destino;
   int temp;
   if(argc!=3){
	  fprintf(stderr, "Numero de parametros incorreto\a");
	  exit(1);
   }
   if((origem=fopen(argv[1],"rb"))==NULL){
	  fprintf(stderr, "Nao consegui abrir %s",argv[1]);
	  exit(1);
   }
   if((destino=fopen(argv[2],"wb"))==NULL){
	  fprintf(stderr, "Nao consegui abrir %s",argv[2]);
	  exit(1);
   }
   do{
	  temp=fgetc(origem);
	  if(temp==EOF) break;
	  temp=fputc(temp,destino);
   }while(temp!=EOF);
   fclose(origem);
   fclose(destino);
}


