
// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);

// #include <sys/socket.h>
struct sockaddr
{
   unsigned short int sa_family;
   char sa_data[14];
};

extern int socket(int __domain, int __type, int __protocol);
extern int bind (int __fd, const struct sockaddr * __addr, int __len);

//PROTOCOL FAMILY
#define	PF_INET		2	// IP protocol family.  

//DOMAIN
#define	AF_INET		PF_INET

//TYPE
enum __socket_type
{
  SOCK_STREAM = 1		// Sequenced, reliable, connection-based byte streams.  
};


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);
extern unsigned long int htonl(unsigned long int __hostlong);

// Address to accept any incoming messages.
#define	INADDR_ANY		((unsigned long int)0x00000000)

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


int main()
{
   unsigned short int port = 3500;
   int sock;
   struct sockaddr_in name;

   /* Create the socket. */
   sock = socket (PF_INET, SOCK_STREAM, 0);
   if (sock < 0)
   {
      fprintf(stdout, "Erro ao socket\n");
      return 1;
   }
   
   // Give the socket a name.
   name.sin_family = AF_INET;
   name.sin_port = htons(port);
   name.sin_addr.s_addr = htonl(INADDR_ANY);
   if (bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0)
   {
      fprintf(stdout, "Erro ao bind\n");
      return 1;
   }
   
   fprintf(stdout, "sock = 0x%08X\n", sock);
   return sock;
}

