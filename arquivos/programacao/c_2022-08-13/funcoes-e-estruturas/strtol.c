
//  gcc -Wall strtol.c -o strtol.elf ; ./strtol.elf 34fer

// Convert a string to a long integer.

// #include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern long int strtol(const char *nptr, char **endptr, int base);


// #include<stdio.h>  // = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stderr;	
extern struct _IO_FILE *stdout;	
extern struct _IO_FILE *stdin;	
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int main(int argc, char **argv)
{
    char *ep;
    char *v = *++argv;
    unsigned long int b;
    b = strtol(v, &ep, 10);
    fprintf(stdout,"\n%ld     %s\n\n",b ,ep );
    return(0);
}

