
// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern struct _IO_FILE *stdin;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);
extern int getchar(void);
extern int fileno (FILE *__stream);


// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int read (int __fd, void *__buf, unsigned long int __nbytes);
extern int close (int __fd);


// #include <sys/socket.h>

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

extern int socket(int __domain, int __type, int __protocol);
extern int send(int __fd, const void *__buf, unsigned long int __n, int __flags);
extern int connect (int __fd, const struct sockaddr_in * __addr, unsigned long int __len);


// #include <netdb.h>
// Description of data base entry for a single host.
struct hostent
{
   char *h_name;         // Official name of host.
   char **h_aliases;     // Alias list.
   int h_addrtype;       // Host address type.
   int h_length;         // Length of address.
   char **h_addr_list;   // List of addresses from name server. (terminated with a null pointer)
};

extern struct hostent *gethostbyname (const char *__name);


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);


// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned long int strlen(const char *str);


//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int atoi(const char *);


// #include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern char *strerror(int errnum);

// #include<errno.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int *__errno_location(void);
#define errno (*__errno_location())


#define BUFFERSIZE 5
char entrada[BUFFERSIZE];
char saida[BUFFERSIZE];

void get_entrada()
{
   char ch, *buffer;
   int i;
   
   buffer = entrada;
   
   for(;;)
   {
      fprintf(stdout, "\nEscreva a mensagem a ser enviada:\n");
      
      for(i = 0;; i++)
      {
         read (fileno(stdin), buffer, 1);
         buffer++;
         if(entrada[i] == '\n')
            break;
         if(i == (BUFFERSIZE - 1))
         {
            while ((ch = getchar()) != '\n' && ch != -1);
            fprintf(stdout, "\nERRO: O número de caracteres fornecidos excedeu a capacidade do buffer (%d bytes).", \
                       BUFFERSIZE - 1);
            buffer = entrada;
            break;
         }
      }
      
      if(buffer == entrada)
         continue;
      
      entrada[i] = 0x00;
      
//      fprintf(stdout, "%s\n", entrada);
      buffer = entrada;
      break;
   }
   return;
}

void get_saida(int s)
{
   char ch, *buffer;
   int i;
   
   buffer = saida;
   
   fprintf(stdout, "Aguardando receber mensagem ...\n");
   for(i = 0;; i++)
   {
      read(s, buffer, 1);
      buffer++;
      
      if(saida[i] == '\n')
         break;
      if(i == (BUFFERSIZE - 1))
      {
         for(;;)
         {
            read(s, &ch, 1);
            if(ch == 0x0A || ch == 0xFF)
               break;
         }
         fprintf(stdout, "\nERRO:\nRecebi o caracteres além limite do buffer (%d bytes).\n%s", \
                          BUFFERSIZE - 1, "Os caracteres em excesso foram apagados.\nRecebi: ");
         break;
      }
   }
   
   saida[i] = 0x00;
   
//   fprintf(stdout, "%s\n", saida);
//   buffer = saida;
   
   return;
}


int init_sockaddr(struct sockaddr_in *name, const char *hostname, unsigned short int port)
{
   struct hostent *hostinfo;
   unsigned int *ip;
   
   name->sin_family = AF_INET;
   name->sin_port = htons(port);
   hostinfo = gethostbyname(hostname);
   
   if (hostinfo == 0x00)
   {
      fprintf(stdout, "\nERRO: %s não é o nome de um host conhecido.\n\n", hostname);
      return 1;
   }
   ip = (unsigned int *)hostinfo->h_addr_list[0];
   name->sin_addr.s_addr = (unsigned long int)*ip;
//   name->sin_addr.s_addr = (unsigned long int)*hostinfo->h_addr_list[0];
   return 0;
}


int main(int argc, char **argv)
{
   unsigned char *ip_oct;
   int s, port;
   struct sockaddr_in name;
   
   if(argc != 3)
   {
      fprintf(stdout, "\nUse: ./myclient2.elf name port\n%s\n\n",
                      "Exemplo: ./myclient2.elf www.google.com 80");
      return 1;
   }
   
   fprintf(stdout, "\nvou conectar à:\n%s:%s\n", argv[1], argv[2]);
   
   port =  atoi(argv[2]);
   if(! port)
   {
      fprintf(stdout, "\nERRO: \'%s\' não foi reconhecido como sendo o número de uma porta.\n\n", argv[2]);
      return 1;
   }

   if(init_sockaddr(&name, argv[1], port))
      return 1;
   
   ip_oct = (unsigned char *)&name.sin_addr.s_addr;
   fprintf(stdout, "%u.%u.%u.%u:%d\n", ip_oct[0], ip_oct[1], ip_oct[2], ip_oct[3], port);
   
   s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   
   if(connect(s,(struct sockaddr *)&name,sizeof(name)) < 0)
   {
      fprintf(stdout, "\nERRO:\n%s\n\n", strerror(errno));
      return 1;
   }
   
   for(;;)
   {
      get_entrada();
      if(entrada[0] != '\n')
         send(s, entrada, strlen(entrada), 0);
      
      get_saida(s);
      fprintf(stdout,"%s\n", saida);
   }
   
   close(s);
   return 0;
}

