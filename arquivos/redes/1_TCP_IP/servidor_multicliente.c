#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);

#define MAXMSG  512

int read_from_client(int filedes) {
   char buffer[MAXMSG];
   int nbytes;
   
   nbytes = read(filedes, buffer, MAXMSG);
   if (nbytes < 0)         // Read error.
   {
      perror("read");
      return 1;
   }
   else if (nbytes == 0)   // End-of-file.
   return -1;
   else                   // Data read.
   {
      fprintf(stderr, "Server: got message: `%s'\n", buffer);
      return 0;
   }
}


int main() {
   int sock;
   struct {
      signed long int __fds_bits[512];
   } active_fd_set, read_fd_set;
   unsigned long int i;
   struct sockaddr_in clientname;
   size_t size;
   
   int yes = 1;
   register int len;
   struct sockaddr_in saun;
 
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   
   if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
      fprintf(stdout,"server: socket\n");
      return 1;
   }
   
   // Create the address we will be binding to.
   saun.sin_family = AF_INET;
   saun.sin_port = htons(8080);
   saun.sin_addr.s_addr = inet_addr("127.0.0.1");
   //   saun.sin_addr.s_addr = inet_addr("192.168.43.170");
   
   // Try to bind the address to the socket.
   len = sizeof(struct sockaddr_in);
   
   setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
   if (bind(sock, &saun, len) < 0) {
      fprintf(stdout,"server: bind\n");
      return 1;
   }
   
   // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
   
   //sock = make_socket(PORT);   // Create the socket and set it up to accept connections.
   if (listen(sock, 1) < 0) {
      printf("\nlisten\n\n");
      return 1;
   }
   
   // Initialize the set of active sockets.
   for (i = 0; i < 512; ++i) active_fd_set.__fds_bits[i] = 0;
   printf("\nsock = %d  (1 << (sock % 2)) = %08X\n\n", sock, (1 << (sock % 2)));
   //FD_SET(sock, &active_fd_set);
   active_fd_set.__fds_bits[1] = 0x00000002;
   
   while (1) {
      read_fd_set = active_fd_set;  // Block until input arrives on one or more active sockets.
      if (select(1024, &read_fd_set, 0x00, 0x00, 0x00) < 0) {
         printf("\nselect\n\n");
         return 1;
      }
      
      // Service all the sockets with input pending.
      for (i = 0; i < 1024; ++i) {
         if (((((&read_fd_set)->__fds_bits)[((i) / 2)] & ((__fd_mask) 1 << ((i) % 2))) != 0)) {
         //if (FD_ISSET(i, &read_fd_set)) {
            if (i == sock) {
               int new;  // Connection request on original socket.
               size = sizeof(clientname);
               new = accept(sock, (struct sockaddr *) &clientname, &size);
               if (new < 0) {
                  perror("accept");
                  return 1;
               }
               fprintf(stderr, "Server: connect from host %s, port %hd.\n", inet_ntoa(clientname.sin_addr), ntohs(clientname.sin_port));
               //FD_SET(new, &active_fd_set);
               (((&active_fd_set)->__fds_bits)[((new) / 2)] |= ((__fd_mask) 1 << ((new) % 2)));
            }
            else {
               if (read_from_client(i) < 0) // Data arriving on an already-connected socket.
               {
                  close(i);
                  //FD_CLR(i, &active_fd_set);
                  (((&active_fd_set)->__fds_bits)[((i) / 2)] &= ~((__fd_mask) 1 << ((i) % 2)));
               }
            }
         }
      }
   }
}

