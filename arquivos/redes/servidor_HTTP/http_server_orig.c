
// clear ; gcc -Wall http_server.c -o http_server.elf && sudo ./http_server.elf >> http_server-conexoes.txt &

// cada vez que fornece uma página deixa um processo novo rodando
// usar a função scandir para gerar o index.html

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<signal.h>
#include<fcntl.h>

#define CONNMAX 1000
#define BYTES 1024

char ROOT[] = "/home/ubuntu/Desktop/www";
int listenfd, clients[CONNMAX];
void respond(int);

unsigned long int print_addrinfo(struct addrinfo _addrinfo) {
   int i;
   
   printf("\n");
   printf("addrinfo.ai_flags     = %02d           // Input flags.\n", _addrinfo.ai_flags);
   printf("addrinfo.ai_family    = %02d           // Protocol family for socket. IPv4 é 2\n", _addrinfo.ai_family);
   printf("addrinfo.ai_socktype  = %02d           // Socket type.\n", _addrinfo.ai_socktype);
   printf("addrinfo.ai_protocol  = %02d           // Protocol for socket.\n", _addrinfo.ai_protocol);
   printf("addrinfo.ai_addrlen   = %02u           // Length of socket address.\n", _addrinfo.ai_addrlen);
   printf("addrinfo.ai_addr      = 0x%08X   // Socket address for socket.\n", (unsigned int)_addrinfo.ai_addr);
   printf("addrinfo.ai_canonname = 0x%08X   // Canonical name for service location.\n", (unsigned int)_addrinfo.ai_canonname);
   printf("addrinfo.ai_next      = 0x%08X   // Pointer to next in list.\n\n", (unsigned int)_addrinfo.ai_next);
   
   if (_addrinfo.ai_addr != 0) {
      printf("addrinfo.ai_addr[0].sa_family = %02u   // address family and length.\n", _addrinfo.ai_addr[0].sa_family);
      printf("addrinfo.ai_addr[0].sa_data   = ");
      for (i = 0; i < 14; i++) printf("%u ", (unsigned char)_addrinfo.ai_addr[0].sa_data[i] );
      printf("\n\n");
   }
   
   if (_addrinfo.ai_canonname != 0) printf("addrinfo.ai_canonname = \"%s\"   // Canonical name for service location.\n\n", _addrinfo.ai_canonname);
   
   return (unsigned long int)_addrinfo.ai_next;
}

void startServer(char *port) {
   struct addrinfo hints, *res, *p;
   
   // getaddrinfo for host
   memset (&hints, 0, sizeof(hints));
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags = AI_PASSIVE;
   if (getaddrinfo( NULL, port, &hints, &res) != 0) {
      perror ("getaddrinfo() error");
      exit(1);
   }
   
   // socket and bind
   for (p = res; p!=NULL; p=p->ai_next) {
      print_addrinfo(p[0]);
      listenfd = socket (AF_INET, SOCK_STREAM, 0);
      if (listenfd == -1) continue;
      if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) break;
   }
   if (p == NULL) {
      perror ("socket() or bind()");
      exit(1);
   }
   
   freeaddrinfo(res);
   
   // listen for incoming connections
   if ( listen(listenfd, 1000000) != 0 ) {
      perror("listen() error");
      exit(1);
   }
}

//client connection
void respond(int n) {
   char mesg[99999], *reqline[3], data_to_send[BYTES], path[99999];
   int rcvd, fd, bytes_read;

   memset( (void*)mesg, (int)'\0', 99999 );

   rcvd = recv(clients[n], mesg, 99999, 0);
   
   // receive error
   if (rcvd < 0) fprintf(stderr,("recv() error\n"));
   // receive socket closed
   else if (rcvd == 0) fprintf(stderr,"Client disconnected upexpectedly.\n");
   // message received
   else {
      printf("%s", mesg);
      reqline[0] = strtok (mesg, " \t\n");
      if ( strncmp(reqline[0], "GET\0", 4)==0 ) {
         reqline[1] = strtok (NULL, " \t");
         reqline[2] = strtok (NULL, " \t\n");
         if ( strncmp( reqline[2], "HTTP/1.0", 8)!=0 && strncmp( reqline[2], "HTTP/1.1", 8)!=0 )
         {
            write(clients[n], "HTTP/1.0 400 Bad Request\n", 25);
         }
         else
         {
            if ( strncmp(reqline[1], "/\0", 2)==0 )
                reqline[1] = "/index.html";        //Because if no file is specified, index.html will be opened by default (like it happens in APACHE...

            strcpy(path, ROOT);
            strcpy(&path[strlen(ROOT)], reqline[1]);

            if ( (fd=open(path, O_RDONLY))!=-1 )    //FILE FOUND
            {
                send(clients[n], "HTTP/1.0 200 OK\n\n", 17, 0);
                while ( (bytes_read=read(fd, data_to_send, BYTES))>0 )
                    write (clients[n], data_to_send, bytes_read);
            }
            else    write(clients[n], "HTTP/1.0 404 Not Found\n", 23); //FILE NOT FOUND
         }
      }
   }

   //Closing SOCKET
   shutdown (clients[n], SHUT_RDWR);         //All further send and recieve operations are DISABLED...
   close(clients[n]);
   clients[n]=-1;
}

int main(int argc, char **argv) {
   struct sockaddr_in clientaddr;
   socklen_t addrlen;
   int i, slot = 0;
   char c, PORT[6];
   
   //printf("\n\nPID = %d\n", getpid());
   strcpy(PORT,"80");
   
   //printf("Server started at PORT %s%s%s with ROOT %s%s%s\n", "\033[92m",PORT, "\033[0m", "\033[92m", ROOT, "\033[0m");
   
   // Setting all elements to -1: signifies there is no client connected
   for (i=0; i < CONNMAX; i++) clients[i] = -1;
   startServer(PORT);
   
   // ACCEPT connections
   while (1) {
      addrlen = sizeof(clientaddr);
      clients[slot] = accept(listenfd, (struct sockaddr *) &clientaddr, &addrlen);
      
      if (clients[slot] < 0) printf("\naccept() error\n\n");
      else {
         if ( fork()==0 ) {
            respond(slot);
            exit(0);
         }
      }
      
      while (clients[slot] != -1) slot = (slot+1)%CONNMAX;
   }
   
   return 0;
}

