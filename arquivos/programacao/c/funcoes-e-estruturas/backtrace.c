
// clear ; gcc -Wall -static /media/arq_blue/programacao/linguagem_c/funcoes_etc/backtrace.c -o backtrace.elf && ./backtrace.elf

// #include<execinfo.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// Store up to SIZE return address of the current program state in  ARRAY and return the exact number of values stored.
extern int backtrace (void **__array, int __size);

// Return names of functions from the backtrace list in ARRAY in a newly malloc()ed memory block.
extern char **backtrace_symbols (void **__array, int __size);

// This function is similar to backtrace_symbols() but it writes the result immediately to a file.
extern void backtrace_symbols_fd (void **__array, int __size, int __fd);

#include <stdio.h>
#include <stdlib.h>

// Obtain a backtrace and print it to stdout.
void print_trace(void)
{
   void *array[10];
   size_t size;
   char **strings;
   size_t i;
   
   printf ("[%p] print_trace\n", print_trace);
   size = backtrace(array, 10);
   strings = backtrace_symbols(array, size);
   
   printf ("Obtained %zd stack frames.\n", size);
   
   for (i = 0; i < size; i++)
      printf ("%s\n", strings[i]);
   
   free(strings);
}


// A dummy function to make the backtrace more interesting.
void dummy_function(void)
{
   printf ("[%p] dummy_function\n", dummy_function);
   print_trace();
}

int main(void)
{
   printf ("[%p] main\n", main);
   dummy_function();
   return 0;
}

