
/*
void *realloc(void *prt, unsigned tamanho)
Altera o tamanho da área alocada por malloc().
Se o bloco não puder ser realocado retorna NULL.
*/


//#include"/usr/lib/gcc/i486-linux-gnu/4.3/include/stddef.h" // = = = = = = = = = = = = = = = = = =
typedef long unsigned int size_t;


//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *malloc(size_t __size);
extern void *calloc(size_t __nmemb, size_t __size);
extern void *realloc(void *__ptr, size_t __size);
extern void free(void *__ptr);


int main()
{
   int *buffer1, *buffer2, *buffer3;
   buffer1 = (int*)malloc(100*sizeof(int));
   buffer2 = (int*)calloc(100,sizeof(int));
   buffer3 = (int*)realloc(buffer2,500*sizeof(int));
   free(buffer1);
   free(buffer3);
   return(0);
}

