
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h> //?
#include <arpa/inet.h>
#include<string.h>
#include <unistd.h>


// Strings we send to the server.
char *strs[3] = {"This is the first string from the client.\n",  \
                 "This is the second string from the client.\n", \
                 "This is the third string from the client.\n"};

int main()
{
   unsigned char c;
   FILE *fd_socket2;
   register unsigned long int i, fd_socket;
   struct sockaddr_in destino;
   
   if((fd_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
   {
      perror("client: socket");
      exit(1);
   }
   
   destino.sin_family = AF_INET;
   destino.sin_port = htons(8080);
   destino.sin_addr.s_addr = inet_addr("127.0.0.1");
   
   if(connect(fd_socket,(struct sockaddr *)&destino,sizeof(destino)) < 0)
   {
      perror("client: connect");
      exit(1);
   }

   // We'll use stdio for reading the socket.
   fd_socket2 = fdopen(fd_socket, "r");

   // First we read some strings from the server and print them out.
   for (i = 0; i < 3; i++)
   {
      while ((c = fgetc(fd_socket2)) != EOF)
      {
         putchar(c);
         
         if (c == '\n')
         {
            break;
         }
      }
   }
   
   // Now we send some strings to the server.
   for (i = 0; i < 3; i++)
   {
      send(fd_socket, strs[i], strlen(strs[i]), 0);
   }
   
   // We can simply use close() to terminate the connection, since we're done with both sides.
   close(fd_socket);
   
   return(0);
}

