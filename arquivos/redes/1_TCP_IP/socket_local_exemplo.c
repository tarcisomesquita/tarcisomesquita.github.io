
// how to create and name a socket in the local namespace.

// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


// 26 "/usr/include/sys/un.h" 2 3 4
struct sockaddr_un
{
   unsigned short int sun_family;
   char sun_path[108]; // filename to use
};

// #include <sys/socket.h>
struct sockaddr
  {
    unsigned short int sa_family;
    char sa_data[14];
  };

extern int socket(int __domain, int __type, int __protocol);
extern int bind (int __fd, const struct sockaddr * __addr, int __len);

#define	PF_LOCAL	1	// Local to host (pipes and file-domain).  
#define	AF_LOCAL	PF_LOCAL
enum __socket_type
{
  SOCK_DGRAM = 2		// Connectionless, unreliable datagrams of fixed maximum length.  
                                // Used in the Internet domain with UDP.
};


// #include<string.h> // = = = = = = = = = = = = = = = =
extern char *strncpy(char *destino, char *origem, unsigned n);
extern unsigned int strlen(const char *);

int main() {
   struct sockaddr_un name;
   const char filename[] = "/home/ubuntu/Desktop/teste2.c";
   int sock;
   unsigned long int size;
   
   // Create the socket.
   sock = socket (PF_LOCAL, SOCK_DGRAM, 0);
   if (sock < 0) {
      fprintf(stdout,"Erro ao abrir o socket.\n");
      return 1;
   }
   
   // Bind a name to the socket.
   name.sun_family = AF_LOCAL;
   strncpy(name.sun_path, filename, sizeof(name.sun_path));
   fprintf(stdout, "name.sun_path = %s\n", name.sun_path);
   
   name.sun_path[sizeof(name.sun_path) - 1] = 0x00;
   
   size = ( (unsigned long int)&name.sun_path + strlen(name.sun_path) + 1);
   
   if (bind(sock, (struct sockaddr *) &name, size) < 0) {
      fprintf(stdout,"Erro ao bind\n");
      return 1;
   }
   
   fprintf(stdout,"sock = 0x%08X\n", sock);
   return 0;
}
