
// Convert Internet host address from numbers-and-dots notation in CP into binary data in network byte order.

// use a função inet_aton em vez desta.
// is obsolete because INADDR_NONE is a valid address (255.255.255.255), and inet_aton provides a cleaner way to indicate error return. 

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


int main()
{
   unsigned int num;
   num = inet_addr("127.0.0.1");
   fprintf(stdout,"127.0.0.1 = 0x%08X\n", num);
   return(0);
}

