
/*
newfd = accept(listener, (struct sockaddr *)&remoteaddr, &addrlen);
printf("new connection from %s on socket %d\n", \
       inet_ntop(remoteaddr.ss_family, get_in_addr((struct sockaddr*)&remoteaddr), remoteIP, INET6_ADDRSTRLEN), newfd);


    Set socket to be non-blocking.  All of the sockets for    
    the incoming connections will also be non-blocking since  
    they will inherit that state from the listening socket.   
   ***********************************************************
   int rc, on = 1;
   listen_sd = socket(AF_INET, SOCK_STREAM, 0);
   rc = ioctl(listen_sd, FIONBIO, (char *)&on);
   if (rc < 0)
   {
      perror("ioctl() failed");
      close(listen_sd);
      exit(-1);
   }
*/


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout; 
extern int fprintf(FILE *stream, const char *formatted_output, ...);
extern int sprintf (unsigned char *s, const char *format, ...);

// #include <sys/socket.h>
extern int socket(int __domain, int __type, int __protocol);
extern int send(int __fd, const void *__buf, unsigned long int __n, int __flags);

//PROTOCOL FAMILY
#define PF_INET  2 // IP protocol family.  

//DOMAIN Address families.  
#define AF_INET  PF_INET


//TYPE  Processes communicate only between sockets of the same type.
enum __socket_type {
   SOCK_STREAM = 1  // Sequenced, reliable, connection-based byte streams.  
   // A stream operates much like a telephone conversation.
   // Used in the Internet domain with TCP. 
}
;

//PROTOCOL
// #include <netinet/in.h>
enum {
   IPPROTO_TCP = 6    // Transmission Control Protocol.  
}
;


// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int read (int __fd, void *__buf, unsigned long int __nbytes);
extern int close (int __fd);


// #include <sys/socket.h>
struct sockaddr {
   unsigned short int sa_family;
   char sa_data[14];
}
;


// Internet address
struct in_addr {
   unsigned long int s_addr;
}
;

// Structure describing an Internet socket address.
struct sockaddr_in {
   
   unsigned short int sin_family; 
   unsigned short int sin_port;     // Port number.
   struct in_addr sin_addr;         // Internet address.
   
   // Pad to size of struct sockaddr
   unsigned char sin_zero[sizeof(struct sockaddr) -     \
   (sizeof(unsigned short int)) - \
   sizeof(unsigned short int) -  \
   sizeof(struct in_addr)];
}
;

// #include <sys/socket.h> // = = = = = = = = = = = = = = = = = = = = = =
extern int bind (int __fd, struct sockaddr_in *__addr, int __len);
extern int accept (int __fd, struct sockaddr_in * __addr, int * __addr_len);
extern int listen (int __fd, int __n);
enum {
   SHUT_RD = 0,  /* No more receptions.  */
   SHUT_WR = 1,  /* No more transmissions.  */
   SHUT_RDWR = 2  /* No more receptions or transmissions.  */
}
;

/* Shut down all or part of the connection open on socket FD.
   HOW determines what to shut down:
     SHUT_RD   = No more receptions;
     SHUT_WR   = No more transmissions;
     SHUT_RDWR = No more receptions or transmissions.
   Returns 0 on success, -1 for errors.  */
extern int shutdown (int __fd, int __how);


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);


// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);
extern const char *inet_ntop(int AF, const void *CP, char *BUF, unsigned long int LEN);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int strlen(unsigned char *str);

//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int atoi(const char *);

// #include <sys/socket.h>
extern int setsockopt (int __fd, int __level, int __optname, const void *__optval, unsigned int __optlen);

// #include <asm-generic/socket.h>
#define SOL_SOCKET 1
#define SO_REUSEADDR 2


// #include<bits/time.h>
struct timeval {
   long int tv_sec;  // Seconds
   long int tv_usec; // Microseconds
};

// #include<sys/select.h> // = = = = = = = = = = = = = = = = = = = = = =
typedef struct {
   long int __fds_bits[512];
} fd_set;

#define	FD_SETSIZE 1024 // Number of descriptors that can fit in an `fd_set'.

extern int select (int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *malloc(long unsigned int __size);

unsigned char entrada[50];
int fd_sock;

void make_page(unsigned char *entrada, unsigned char *saida, unsigned char *msg) {
   unsigned short int content_len;
   content_len = 371 + strlen(entrada) + strlen(saida);
   
   sprintf(msg, "%s%c%c%s%c%c%s%d%c%c%c%c", \
   "HTTP/1.1 200 OK", 0x0D, 0x0A, \
   "Content-Type: text/html; charset=UTF-8", 0x0D, 0x0A, \
   "Content-Length: ", content_len,0x0D, 0x0A, \
   0x0D, 0x0A
   );
   
   sprintf(msg, "%s%s%s%s%s%s%s%s", msg, \
   "<html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"><title>Prompt</title></head>", \
   "<body onLoad=\"entrada.text.focus()\"><p><pre>P.: ", \
   entrada, "</pre></p><p><pre>R.: ", saida, \
   "</pre></p><form name=\"entrada\" method=\"post\" action=\"http://localhost:8080\">   <input size=\"50\" name=\"text\" type=\"text\">   ", \
   "<input value=\"Pergunte\" type=\"submit\"></form></body></html>"
   );
   return;
}

unsigned char qbits(unsigned char t) {
   switch (t) {
      case '0': return 0x00;
      case '1': return 0x01;
      case '2': return 0x02;
      case '3': return 0x03;
      case '4': return 0x04;
      case '5': return 0x05;
      case '6': return 0x06;
      case '7': return 0x07;
      case '8': return 0x08;
      case '9': return 0x09;
      case 'A': return 0x0A;
      case 'B': return 0x0B;
      case 'C': return 0x0C;
      case 'D': return 0x0D;
      case 'E': return 0x0E;
      case 'F': return 0x0F;
   }
   return 0xFF;
}


unsigned char asciihextonum(unsigned char letra1, unsigned char letra2) {
   return ((qbits(letra1)<<4) + qbits(letra2));
}

int converte_caracter( unsigned char *entrada, unsigned char *frase_buffer, int msglen) {
   int i, e;
   
   if ((frase_buffer[0]  != 't') && \
   (frase_buffer[1]  != 'e') && \
   (frase_buffer[2]  != 'x') && \
   (frase_buffer[3]  != 't') && \
   (frase_buffer[4]  != '=') ) {
      return 1;
   }
   
   i = 5;
   for (e = 0; i < msglen ; e++) {
      if (frase_buffer[i] == '%') {
         entrada[e] = (unsigned char)asciihextonum(frase_buffer[i+1], frase_buffer[i+2]);
         i = i + 3;
      }
      else if (frase_buffer[i] == '+') {
         entrada[e] = ' ';
         i++;
      }
      else {
         entrada[e] = (char)frase_buffer[i];
         i++;
      }
   }
   
   return 0;
}

int startServer() {
   int yes = 1;
   struct sockaddr_in addr_local;
   
   fd_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if (fd_sock < 0) {
      fprintf(stdout,"\nERRO: socket\n\n");
      return 1;
   }
   setsockopt(fd_sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
   
   // Create the address we will be binding to.
   addr_local.sin_family = AF_INET;
   addr_local.sin_port = htons(8080);
   addr_local.sin_addr.s_addr = inet_addr("0.0.0.0");
   
   if (bind(fd_sock, &addr_local, sizeof(addr_local)) < 0) {
      fprintf(stdout,"\nERRO: bind\n\n");
      return 1;
   }
   
   // Listen on the socket.
   if (listen(fd_sock, 2) < 0) {
      fprintf(stdout,"\nERRO: listen\n\n");
      return 1;
   }
   
   return 0;
}

int main() {
   unsigned char buffer[1024], msg[1500], saida[50];
   int i, fromlen, msglen, fd_accept;
   unsigned short int n;
   struct sockaddr_in addr_remoto;
   char ip_remoto[16];
   
   if(startServer()) return 1;
   
   sprintf(entrada, "%s", " ");
   sprintf(saida, "%s", "Escreva sua pergunta.");
   
   make_page(&entrada[0], &saida[0], &msg[0]);
   
   // conecta ao cliente
   for (;;) {
      // Accept connections. addr_remoto will contain the address of the client.
      if ((fd_accept = accept(fd_sock, &addr_remoto, &fromlen)) < 0) {
         fprintf(stdout,"server: accept\n");
         return 1;
      }

      if(fromlen == 16) {
         inet_ntop(AF_INET, &addr_remoto.sin_addr, ip_remoto, sizeof(ip_remoto));
         fprintf(stdout, "\n%s:%d", ip_remoto, addr_remoto.sin_port);
      }
      else {
         close(fd_accept);
         continue;
      }
      
      // limpa o buffer para evitar erro de impressão
      for (n = 0; n < 1024; n++) {
         buffer[n] = 0x00;
      }
      
      // Carrega cabeçalho HTTP
      for (n = 0; n < 1024; ) {
         read(fd_accept, &buffer[n], 1);
         if (buffer[n] == -1) {
            n = 0;
            break;
         }
         
         // verifica se é o fim do cabeçalho HTTP
         if ((buffer[n] == 0x0A) && (n > 3)) {
            if (buffer[n-1] == 0x0D && buffer[n-2] == 0x0A && buffer[n-3] == 0x0D) {
               break;
            }
         }
         
         n = n + 1;
      }
      
      if ((n == 0) || (n < 15)) {
         close(fd_accept);
         continue;
      }
      
      msglen = 0;
      for (i = 0 ; buffer[i] != 0x00 ; i++) {
         // Content-Length: 
         if ((buffer[i] == 'C') && \
         (buffer[i+1]  == 'o') && \
         (buffer[i+2]  == 'n') && \
         (buffer[i+3]  == 't') && \
         (buffer[i+4]  == 'e') && \
         (buffer[i+5]  == 'n') && \
         (buffer[i+6]  == 't') && \
         (buffer[i+7]  == '-') && \
         (buffer[i+8]  == 'L') && \
         (buffer[i+9]  == 'e') && \
         (buffer[i+10] == 'n') && \
         (buffer[i+11] == 'g') && \
         (buffer[i+12] == 't') && \
         (buffer[i+13] == 'h') && \
         (buffer[i+14] == ':') && \
         (buffer[i+15] == ' ') ) {
            msglen = atoi((const char *)(&buffer[i+16]));
            //fprintf(stdout, "\nComprimento = %d\n", msglen);
            break;
         }
      }
      
      msglen = msglen + 2;
      // read some strings from the client
      for (i = n + 1 ; i - n + 1 < msglen ; i++) {
         read(fd_accept, &buffer[i], 1);
         if (buffer[i] == -1 || buffer[i] == 0x0A)
         break;
      }
      
      if ( converte_caracter((unsigned char *)&entrada[0], &buffer[n+1], msglen)) {
         sprintf(entrada, "Não consegui processar sua mensagem.");
      }
      
      if ((buffer[0] == 'G') && (buffer[1]  == 'E') && (buffer[2]  == 'T')) sprintf(entrada, " ");
      
      // extern char *cerebro();
      // unsigned int frase_size = SIZE_FRASE ; 
      // frase_size = strlen(frase);
      // if(frase[frase_size - 1] != 0x0a) while(getchar() != '\n'); //limpa o buffer de stdin
      // else frase_size = frase_size - 1;
      // if(! frase_size) continue;
      // printf("R.: %s", cerebro());
      // COLOCAR AQUI A CHAMADA AO BANCO DE DADOS
      // if () {
      //    fprintf(stdout, "\n");
      //    return 1;
      // }
      
      make_page(&entrada[0], &saida[0], &msg[0]);
      
      send(fd_accept, msg, strlen(msg), 0);   // send some strings to the client.
      close(fd_accept);
      
      // read some strings from the client
      for (i = n + 1 ; i - n + 1 < msglen ; i++) {
         //fprintf(stdout, "%c", buffer[i]);
         if (buffer[i] == -1 || buffer[i] == 0x0A)
         break;
      }
      fprintf(stdout, "\n");
      
      for (i=0 ; buffer[i] != 0x00 ; i++) {
         fprintf(stdout, "%c", buffer[i]);
      }
      fprintf(stdout, "\n");
   }
   close(fd_sock);
   return 0;
}

