
/* 
wait a connection on socket FD.
when a connection arrives, open a new socket to communicate with it,
set *ADDR (which is *ADDR_LEN bytes long) to the address of the connecting peer and *ADDR_LEN to the address's actual length, and 
return the new socket's descriptor which is valid only for the particular connection, or -1 for errors.
*/

// the select function reports when the socket has a connection ready to be accepted 

// Structure describing an IPv4 socket address.
struct sockaddr_in {
   unsigned short int familia;   
   unsigned short int porta;     // Port number.
   unsigned long int  ip;        // Internet address.
   unsigned char      zero[8];    // Pad to size of struct sockaddr
};


// #include <sys/socket.h>
extern int socket(int domain, int type, int protocol);
extern int bind(int sock, struct sockaddr_in *addr, int len_len);
extern int listen(int sock, int n);
extern int accept(int sock, struct sockaddr_in *addr, int *addr_len);
extern int recv(int FD, char *BUFFER, int LEN, int FLAGS);
extern int send(int conexao, const void *buf, unsigned long int n, int flags);

#define PF_INET  2       // DOMAIN IPv4
#define AF_INET  PF_INET // DOMAIN IPv4

enum socket_type {
   SOCK_STREAM = 1  // TYPE TCP: Sequenced, reliable, connection-based byte streams.  
};

// #include <netinet/in.h>
enum {
   IPPROTO_TCP = 6  // PROTOCOL TCP
};


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int hostshort);
extern unsigned short int ntohs(unsigned short int netshort);

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *cp);
extern char *inet_ntoa(unsigned int in);

//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int strlen(char *str);

// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int close(int fd);

extern int printf(char *, ...);

int main() {
   char pagina[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\nContent-Length: 22\r\n\r\n<html>Funciona.</html>";
   int sock, conexao, endereco_size = sizeof(struct sockaddr_in);
   struct sockaddr_in endereco_local, endereco_remoto;
   char entrada[1024];
   
   if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
      printf("\nsocket\n\n");
      return 1;
   }
   
   endereco_local.familia = AF_INET;
   endereco_local.porta   = htons(8092);
   endereco_local.ip      = inet_addr("127.0.0.1");
   
   if (bind(sock, &endereco_local, sizeof(struct sockaddr_in)) < 0) {
      printf("\nbind\n\n");
      return 1;
   }
   
   if (listen(sock, 5) < 0) {
      printf("\nlisten\n\n");
      return 1;
   }
   
   if ((conexao = accept(sock, &endereco_remoto, &endereco_size)) < 0) {
      printf("\naccept\n\n");
      return 1;
   }
   
   recv(conexao, entrada, 1024, 0);
   printf("%s:%u\n%s\n", inet_ntoa(endereco_remoto.ip), ntohs(endereco_remoto.porta), entrada);
   
   send(conexao, pagina, strlen(pagina), 0);   // envia a página inicial para o cliente.
   close(conexao);
   close(sock);
   
   return 0;
}

