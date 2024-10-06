
// Time used by the program so far (user time + system time).
// The result / CLOCKS_PER_SECOND is program time in seconds.
// Em caso de erro retorna -1

// #include <time.h>
extern long int clock(void);

#define CLOCKS_PER_SEC  1000000l


extern int printf(char *, ...);

int main()
{
   long int start, end;
   double cpu_time_used;
   int i;
   
   start = clock();
   for(i=0;i<1000000000;i++); // the work.
   end = clock();
   cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
   printf("\ncpu_time_used = %E\n\n", cpu_time_used);
   return 0;
}

