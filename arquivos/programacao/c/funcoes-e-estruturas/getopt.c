

// gcc -Wall teste.c -o teste.elf && ./teste.elf -b -a -c d -d -h -e

// getopt retorna o caracter da opção
// retorna -1 se não houver opção
// retorna ? se a opção for inválida


/*
optind is the index of the next element of the argument list to be process, and 
optarg indicates an optional parameter to a command line option.
optopt is the command line option last matched.
opterr can be set to 0 to prevent getopt() from printing error messages.


in the string shortopts
if an option character is followed by a colon (‘:’) to indicate that it takes a required argument.
if an option character is followed by two colons (‘::’), its argument is optional (não consegui fazer isso funcionar)

The variables opterr and optind are both initialized to 1.
The optind variable may be set to another value before a calls to getopt() to skip over some argv entries.

extern int optreset;
to evaluate a single set of arguments multiple times the variable optreset must be set to 1 before the second and each additional calls to getopt(), and the variable optind must be reinitialized.

Programs should obtain these definitions by the inclusion of <unistd.h>. 
*/

// #include<getopt.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *optarg;
extern int opterr;
extern int optind;
extern int optopt;
extern int getopt(int argc, char **argv, char *shortopts);

extern int printf(char *, ...);

int main(int argc, char **argv)
{
   int i, c;
   
   for(i = 1; i < 7 ; i++)
   {

      printf("optind = %d, argv[%d] = %s\n", optind, optind, argv[optind]);
      
      c = getopt(argc, argv, "abc:def");
      printf("getopt = %c\n",c);
      
      if( c == 'c' )
      {
         printf("*optarg = %c\n",*optarg);
      }
      else
         printf("optarg = 0x%08X\n", (unsigned int)optarg);
      
      printf("optopt = %c\n", optopt);
      printf("opterr = %d\n", opterr);
      printf("\n");
   }
   return(0);
}

