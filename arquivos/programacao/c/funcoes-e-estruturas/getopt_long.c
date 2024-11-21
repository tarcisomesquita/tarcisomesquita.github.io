
// clear ; gcc -Wall getopt_long.c -o getopt_long.elf && ./getopt_long.elf --debug -c --exec ls

/*
Return the option character from OPTS just read.
Return -1 when there are no more options. 
For unrecognized options, or options missing arguments, `optopt' is set to the option letter, and '?' is returned.

The argument `--' causes premature termination of argument scanning, explicitly telling `getopt' that there are no more options.

If OPTS begins with `--', then non-option arguments are treated as arguments to the option '\0'.
*/

// #include<getopt.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *optarg;
extern int opterr;
extern int optind;
extern int optopt;

struct option
{
  const char *name;
  int has_arg;
  int *flag;
  int val;
};

extern int getopt_long(int argc, const char **argv, const char *shortopts, const struct option *longopts, int *longind);

extern int printf(char *, ...);

int main(int argc, const char **argv)
{
   int c;
   opterr = 0;
   
   while(1)
   {
      int option_index = 0;
      static const struct option long_options[] = \
      {
         {         "close", 0, 0x00000000, 'c' },
         {         "debug", 0, 0x00000000, 'd' },
         {          "exec", 1, 0x00000000, 'e' },
         {               0, 0,          0,  0  }
      };
      
      c = getopt_long(argc, argv, "cde:g:G:hi:lL:no:p:P:rs:S:tTuvVxw:z", long_options, &option_index);
      
      if (c == -1)
         break;
      switch(c)
      {
         case 'c':
            printf("close\n");
            break;
         case 'd':
            printf("debug\n");
            break;
         case 'e':
            printf("exec\n");
            printf("optarg = %s\n",optarg);
            break;
         default:
            printf("default\n");
      }
      
      printf("option_index = %d\n", option_index);
      printf("optind = %d\n", optind);
      printf("optopt = %d\n", optopt);
      printf("opterr = %d\n", opterr);
      
      printf("\n");
   }
   
   return 0;
}

