
//#include<ctype.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern const unsigned short int **__ctype_b_loc(void);
#define _ISbit(bit)   ((bit) < 8 ? ((1 << (bit)) << 8) : ((1 << (bit)) >> 8))
enum
{
   _ISspace = _ISbit(5)   // Whitespace.
};
#define __isctype(c, type)   ((*__ctype_b_loc())[(int) (c)] & (unsigned short int) type)
#define isspace(c)   __isctype((c), _ISspace)


// #inclde<stdio.h>  // = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);

int main()
{
   char test[]="    teste.";
   char *t=test;
   
   while(isspace(*t))
   {
      fprintf(stdout, "\n*t = %c    (*__ctype_b_loc())[(int) ((*t))]=%d\n\n" ,*t, (*__ctype_b_loc())[(int) ((*t))]);
      fprintf(stdout, "\n*t = %c    isspace(*t)=%d\n\n" ,*t, isspace(*t));  // isspace(*t) = (*__ctype_b_loc())[(int) ((*t))] & 8192;

      t++;
   }
   
   return(0);
}

