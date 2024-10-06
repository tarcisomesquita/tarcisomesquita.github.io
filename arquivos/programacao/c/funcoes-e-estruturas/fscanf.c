
// Read formatted input from STREAM
// returns the number of items succesfully read or EOF.

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdin;	
extern struct _IO_FILE *stdout;	
extern int fscanf(FILE *stream, const char *formatted_input, ...);
extern int fprintf(FILE *stream, const char *formatted_output, ...);

int main ()
{
  auto unsigned char str[12];
  auto unsigned int a;

  // digite 0x0011223344
  // digite 0x11    teste  // espaços e tabs são ignorados na leitura
                           // um espaço é considerado o fim da variável

  fscanf(stdin,   "%2s %8X %11s", str, &a, str);  // %11s para evitar buffer overflow
  fprintf(stdout, "0x%X %s\n", a, str);
  return(0);
}

