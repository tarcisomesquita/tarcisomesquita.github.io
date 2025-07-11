
// htons convert between host and network byte order
// ntohs faz o inverso

// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


int main()
{
   unsigned short int num;
   num = htons(3500);
   fprintf(stdout,"3500 = 0x%04X\n", num);
   return(0);
}

