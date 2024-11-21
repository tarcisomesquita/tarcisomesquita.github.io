
// Read NBYTES into BUF from FD.
// Return the number read, -1 for errors or 0 for EOF.
// blocks the program until input is available on the file descriptor; para evitar isso use a função select

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int read (int __fd, void *__buf, unsigned long int __nbytes);


// #include <sys/socket.h>
struct sockaddr
  {
    unsigned short int sa_family;
    char sa_data[14];
  };

extern int socket(int __domain, int __type, int __protocol);
extern int connect (int __fd, const struct sockaddr * __addr, unsigned long int __len);


//PROTOCOL FAMILY
#define	PF_INET		2	// IP protocol family.  

//DOMAIN
#define	AF_INET		PF_INET


//TYPE
enum __socket_type
{
  SOCK_STREAM = 1		// Sequenced, reliable, connection-based byte streams.  
};


//PROTOCOL
enum
{
   IPPROTO_IP = 0,	   // Dummy protocol for TCP.  
   IPPROTO_TCP = 6,	   // Transmission Control Protocol.  
};


// #include <netinet/in.h> //  = = = = = = = = = = = = = = = = = = = = = = = =
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


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


int main()
{
   char string[] = "Isso é um teste\n\n";
   unsigned long int n = 17;
   
   signed long int r_socket;
   signed long int r_connect;
   struct sockaddr_in servidor;
   
   servidor.sin_family = AF_INET;
   servidor.sin_port = htons(8080);
   servidor.sin_addr.s_addr = inet_addr("127.0.0.1");
   
   r_socket = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
   r_connect = connect(r_socket, (struct sockaddr *)&servidor, sizeof(servidor));
   
   read(r_socket, string, n);
   fprintf(stdout,"string = \"%s\"", string);
   return 0;
}

