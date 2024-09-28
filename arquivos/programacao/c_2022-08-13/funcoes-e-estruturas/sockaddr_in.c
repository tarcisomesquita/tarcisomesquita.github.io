// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =
/*
// Structure describing an Internet socket address.
struct sockaddr_in {
   unsigned short int sin_family;
   unsigned short int sin_port;  // Port number.
   struct in_addr sin_addr;      // Internet address.
   
   // Pad to size of `struct sockaddr'.
   unsigned char sin_zero[sizeof (struct sockaddr) -
      (sizeof (unsigned short int)) -
      sizeof (unsigned short int) -
      sizeof (struct in_addr)];
};
*/

// Structure describing an IPv4 socket address.
struct sockaddr_in {
   unsigned short int familia;   
   unsigned short int porta;     // Port number.
   unsigned long int  ip;        // Internet address.
   unsigned char      zero[8];   // Pad to size of struct sockaddr
};

// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int hostshort);
extern unsigned short int ntohs(unsigned short int netshort);

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *cp);
extern char *inet_ntoa(unsigned int in);

extern int printf(char *, ...);


int main() {
   struct sockaddr_in endereco_local;
   
   endereco_local.familia = 2; // IPv4, pode-se escrever PF_INET ou AF_INET
   endereco_local.porta   = htons(8081);
   endereco_local.ip      = inet_addr("127.0.0.1");
   
   printf("\n"\
          "endereco_local.familia = %u\n" \
          "endereco_local.porta   = 0x%04X       porta = %u\n" \
          "endereco_local.ip      = 0x%08X   ip    = %s\n\n", \
          endereco_local.familia, \
          endereco_local.porta, ntohs(endereco_local.porta), \
          (unsigned int)endereco_local.ip, inet_ntoa(endereco_local.ip));
   return 0;
}

