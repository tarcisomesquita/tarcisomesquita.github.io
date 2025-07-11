// nc -vv -l 127.0.0.1 -p 8080
// gcc -Wall connect.c -o connect.elf && ./connect.elf ; echo $?

// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =
// Structure describing an IPv4 socket address.
struct sockaddr_in {
   unsigned short int familia;   
   unsigned short int porta;     // Port number.
   unsigned long int  ip;        // Internet address.
   unsigned char      zero[8];   // Pad to size of struct sockaddr
};

extern int socket(int domain, int type, int protocol);

// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =
// Open a connection on socket FD to peer at ADDR (which LEN bytes long).
// Used in client programs. Server program use the functions listen and accept.
// Return 0 on success, -1 for errors.
extern int connect(int fd, const struct sockaddr_in *addr, unsigned long int len);

#define   PF_INET       2   // IPv4 protocol family.  
#define   SOCK_STREAM   1   // Sequenced, reliable, connection-based byte streams.  
#define   IPPROTO_TCP   6   // Transmission Control Protocol.  

// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int hostshort);

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *cp);

// #include <unistd.h>
extern int close (int fd);

int main() {
   signed long int r_socket;
   signed long int r_connect;
   struct sockaddr_in end_remoto;
   
   end_remoto.familia = PF_INET;
   end_remoto.porta   = htons(8080);
   end_remoto.ip      = inet_addr("127.0.0.1");
   
   r_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   r_connect = connect(r_socket, &end_remoto, sizeof(end_remoto));
   
   close(r_connect);
   close(r_socket);
   return(r_connect);
}

