
// Return entry from host data base for host with NAME.
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

#define	PF_INET		2	// IP protocol family.  
#define	AF_INET		PF_INET

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

void init_sockaddr(struct sockaddr_in *name, const char *hostname, unsigned short int port)
{
   struct hostent *hostinfo;
   unsigned int *teste;
   unsigned char *teste2;
   
   name->sin_family = AF_INET;
   name->sin_port = htons (port);
   hostinfo = gethostbyname(hostname);
   
   if (hostinfo == 0x00)
   {
      fprintf(stdout, "Unknown host %s.\n", hostname);
      return;
   }

   fprintf(stdout, "hostinfo->h_name = %s\n", hostinfo->h_name);
   fprintf(stdout, "hostinfo->h_aliases[0] = %s\n", hostinfo->h_aliases[0]);
   fprintf(stdout, "hostinfo->h_aliases[1] = %s\n", hostinfo->h_aliases[1]);
   fprintf(stdout, "hostinfo->h_addrtype = 0x%08X\n", hostinfo->h_addrtype);
   fprintf(stdout, "hostinfo->h_length = 0x%08X\n", hostinfo->h_length);
   teste  = (unsigned int *)hostinfo->h_addr_list[0];
   teste2 = (unsigned char *)hostinfo->h_addr_list[0];
   fprintf(stdout, "hostinfo->h_addr_list[0] = 0x%08X = %u.%u.%u.%u\n", *teste, teste2[0], teste2[1], teste2[2], teste2[3]);
   
   name->sin_addr = *(struct in_addr *)hostinfo->h_addr_list;
}

int main()
{
   struct sockaddr_in name;
   init_sockaddr(&name, "www.google.com.br", 80);
   return 0;
}

