
// NÃO CONSEGUI ENTENDER ISSO

// Point into arrays of 384, so they can be indexed by any 'unsigned char' value [0,255]; by EOF (-1); or by any 'signed char' value [-128,-1].

//#include<ctype.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern const unsigned short int **__ctype_b_loc(void);


// #inclde<stdio.h>  // = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);

int main()
{
  signed short int is;
  unsigned short int iu;

  for (is=-128;is<0;is++)
     fprintf(stdout, "(*__ctype_b_loc())[%hd] = %hu\n", is, (*__ctype_b_loc())[is]);

  for (iu=0;iu<=255;iu++)
     fprintf(stdout, "(*__ctype_b_loc())[%hd] = %hu\n", iu, (*__ctype_b_loc())[iu]);

   return(0);
}

