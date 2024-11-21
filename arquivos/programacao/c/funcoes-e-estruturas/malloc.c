/*
void *malloc(unsigned tamanho)
Aloca memória (tamanho em bytes) e retorna um ponteiro para a memória alocada.
Retorna NULL se não existir memória disponível suficiente.
*/


//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *malloc(long unsigned int __size);
extern void free (void *__ptr);


extern int printf(const char *, ...);
extern int scanf(const char *, ...);


int main()
{
   int *vetor, num;
   register int i;
   long int soma = 0;
   
   printf("Numero de elementos do vetor: ");
   scanf("%d", &num);
   vetor = malloc(num*sizeof(int));
   
   if(vetor == '\0')
   {
      printf("Sem Memoria!\n");
      return(1);
   }
   
   for(i = 0; i < num; i++)
   {
      printf("Informe vetor[%d]: ", i);
      scanf("%d", &vetor[i]);
      soma += vetor[i];
   }
   
   printf("Total: %ld\n", soma);
   free(vetor);
   return(0);
}

