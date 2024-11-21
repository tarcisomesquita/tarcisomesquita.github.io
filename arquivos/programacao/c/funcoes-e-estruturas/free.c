
/*
Free a block allocated by `malloc', `realloc' or `calloc'.
leaves the value of ptr unchanged, hence it still points to the same (now invalid) location, and not to the null pointer.
If a null pointer is passed as argument, no action occurs.
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

