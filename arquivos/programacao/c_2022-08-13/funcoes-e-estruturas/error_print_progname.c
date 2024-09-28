
/*

Parece-me que esta função serve para escrever o nome do programa na tela, mas ela não funciona. Então, pode deletá-la do código.

*/

/* If NULL, error will flush stdout, then print on stderr the program
   name, a colon and a space.  Otherwise, error will call this
   function without parameters instead.  */

// #include<error.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void (*error_print_progname)(void);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;
extern int fflush(FILE *);

extern int printf(const char *, ...);

int main()
{
//   void *a;
//   char b[] = "tarciso";
//   a = &b;
//   error_print_progname = &b;
   printf("%ld\n", error_print_progname);
//   (*error_print_progname)();
   return 0;
}

