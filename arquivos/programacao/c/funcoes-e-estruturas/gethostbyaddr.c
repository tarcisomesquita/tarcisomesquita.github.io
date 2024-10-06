
// Return entry from host data base which address match ADDR with length LEN and type TYPE.

/*
h_errno codes
HOST_NOT_FOUND  No such host is known in the database.
TRY_AGAIN       This condition happens when the name server could not be contacted.
NO_RECOVERY     A non-recoverable error occurred.
NO_ADDRESS      The host database contains an entry for the name, but it doesn't have an associated Internet address. 
*/

// #include <netdb.h>
struct hostent {         // Description of data base entry for a single host.
   char *h_name;         // Official name of host.
   char **h_aliases;     // Alias list.
   int h_addrtype;       // Host address type.
   int h_length;         // Length of address.
   char **h_addr_list;   // List of addresses from name server. (terminated with a null pointer)
};
extern struct hostent *gethostbyaddr(const void *ADDR, unsigned int LEN, int TYPE);


// #include <sys/socket.h>
//PROTOCOL FAMILY
#define	PF_INET		2	// IP protocol family.  

//DOMAIN
#define	AF_INET		PF_INET


// #include <sys/socket.h>
struct in_addr {
   unsigned long int s_addr; // Internet address
};


// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *CP);


// #include <stdio.h>
extern int printf(const char *, ...);


int main(int argc, char *argv[]) {
   unsigned int num;
   struct in_addr endereco;
   struct hostent *estrutura;
   unsigned long int *t;
   
   num = inet_addr("200.147.118.40"); //  c8 93 76 28
   
   endereco.s_addr = num; // 0x6400A8C0 = C0.A8.00.64 = 192.168.0.100
   estrutura = gethostbyaddr((char *)&endereco, sizeof(endereco), AF_INET);
   if(!estrutura) printf("\nInverse name lookup failed\n\n");
   else {
      printf("\nestrutura->h_name = %s (não serve para conexão)\n", estrutura->h_name);
      printf("estrutura->h_aliases[0] = %s\n", estrutura->h_aliases[0]);
      printf("estrutura->h_addrtype = %d\n", estrutura->h_addrtype);
      printf("estrutura->h_length = %d\n", estrutura->h_length);
      printf("estrutura->h_addr_list[0] = %s\n\n", estrutura->h_addr_list[0]);
      t = (unsigned long int *)estrutura->h_addr_list[0];
      t = (unsigned long int *)*t;
      printf("t = 0x%08X\n\n", (unsigned int)t);
   }
   return 0;
}

