
// Write formatted output to STREAM.

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

int main(int argc, char *argv[]) {
   auto unsigned int numero = 10;
   
   fprintf(stdout, "numero = %u\n", numero);
   
   return 0;
}

