
// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);
extern FILE *fdopen (int __fd, const char *__modes);
extern int fgetc(FILE *arquivo);
extern int sprintf (unsigned char *__restrict __s, const char *__restrict __format, ...);

// #include <sys/socket.h>
extern int socket(int __domain, int __type, int __protocol);
extern int send(int __fd, const void *__buf, unsigned long int __n, int __flags);

//PROTOCOL FAMILY
#define	PF_INET		2	// IP protocol family.  

//DOMAIN Address families.  
#define	AF_INET		PF_INET


//TYPE  Processes communicate only between sockets of the same type.
enum __socket_type
{
  SOCK_STREAM = 1		// Sequenced, reliable, connection-based byte streams.  
                                // A stream operates much like a telephone conversation.
                                // Used in the Internet domain with TCP. 
};

//PROTOCOL
// #include <netinet/in.h>
enum
{
   IPPROTO_TCP = 6	   // Transmission Control Protocol.  
};


// #include <unistd.h>
extern int close (int __fd);


// #include <sys/socket.h>
struct sockaddr
{
   unsigned short int sa_family;
   char sa_data[14];
};


// Internet address
struct in_addr
{
   unsigned long int s_addr;
};

// Structure describing an Internet socket address.
struct sockaddr_in
{

   unsigned short int sin_family; 
   unsigned short int sin_port;     // Port number.
   struct in_addr sin_addr;         // Internet address.
   
   // Pad to size of struct sockaddr
   unsigned char sin_zero[sizeof(struct sockaddr) -     \
                         (sizeof(unsigned short int)) - \
                          sizeof(unsigned short int) -  \
                          sizeof(struct in_addr)];
};

// #include <sys/socket.h> // = = = = = = = = = = = = = = = = = = = = = =
extern int bind (int __fd, struct sockaddr_in *__addr, int __len);
extern int accept (int __fd, struct sockaddr_in * __addr, int * __addr_len);
extern int listen (int __fd, int __n);
extern int connect (int __fd, const struct sockaddr_in * __addr, unsigned long int __len);


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);


// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int strlen(const unsigned char *str);


// Strings we send to the client.
#define NSTRS       1024           // number of strings


int main()
{
   unsigned char buffer[5*1024], strs[NSTRS], *c;
   FILE *fp;
   unsigned short int n, filesize;
   register int i, s, len;
   struct sockaddr_in saun;
   
   c = (unsigned char *)&filesize;
   
   sprintf(strs, "%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%s%c%c%c%c", \
           "GET /sete/ HTTP/1.1", 0x0D, 0x0A, \
           "Host: www.inbot.com.br", 0x0D, 0x0A, \
           "User-Agent: Mozilla/5.0 (X11; U; Linux i686; pt-BR; rv:1.9.0.8) Gecko/2009033100 Ubuntu/9.04 (jaunty) Firefox/3.0.8", 0x0D, 0x0A, \
           "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8", 0x0D, 0x0A, \
           "Accept-Language: pt-br,pt;q=0.8,en-us;q=0.5,en;q=0.3", 0x0D, 0x0A, \
           "Accept-Encoding: gzip,deflate", 0x0D, 0x0A, \
           "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7", 0x0D, 0x0A, \
           "Keep-Alive: 300", 0x0D, 0x0A, \
           "Connection: keep-alive", 0x0D, 0x0A, \
           0x0D, 0x0A
          );
   
      
   if((s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
   {
      fprintf(stdout,"server: socket\n");
      return 1;
   }
   
   // Create the address we will be binding to.
   saun.sin_family = AF_INET;

//   saun.sin_port = htons(2002);
//   saun.sin_addr.s_addr = inet_addr("143.54.1.23"); // elektra

   saun.sin_port = htons(80);
   saun.sin_addr.s_addr = inet_addr("173.192.3.53"); // www.inbot.com.br/sete/

//   saun.sin_port = htons(631); // cups
//   saun.sin_addr.s_addr = inet_addr("127.0.0.1");
   
   // Try to bind the address to the socket.
   len = sizeof(struct sockaddr_in);

   if(connect(s,&saun,sizeof(saun)) < 0)
   {
      fprintf(stdout, "client: connect\n");
      return 1;
   }

   // We'll use stdio for reading the socket.
   fp = fdopen(s, "r");



   // First we send some strings to the client.
   send(s, strs, strlen(strs), 0);

   // Then we read some strings from the client and print them out.
   for(n = 0; n < 5*1024; )
   {
      buffer[n] = fgetc(fp);
      fprintf(stdout,"%02X  %c\n", buffer[n], buffer[n]);
      if(buffer[n] == -1)
         break;
      if( (buffer[n] == 0x0A && buffer[n-1] == 0x0A) || \
          (buffer[n] == 0x0A && buffer[n-1] == 0x0D && buffer[n-2] == 0x0A && buffer[n-3] == 0x0D))
      {
         fprintf(stdout, "Estou no if.\n");
         break;
      }
      
      n = n + 1;
   }
   buffer[n+1] = 0x00;
   fprintf(stdout, "%s\n", buffer);
   
   fprintf(stdout, "\nFINAL DO CABEÇALHO.\n\n");
   
//   for(n = 0; n < filesize; )
//   {
//      buffer[n] = fgetc(fp);
//      fprintf(stdout,"%c", buffer[n]);
//      if(buffer[n] == -1)
//         break;
//      n = n + 1;
//   }
//   buffer[n] = 0x00;
//   fprintf(stdout, "%s\n", buffer);
   
// a mensagem termina com 0x0D, 0x0A, 0x0D, 0x0A

    // We can simply use close() to terminate the connection, since we're done with both sides.
   close(s);

   return 0;
}

