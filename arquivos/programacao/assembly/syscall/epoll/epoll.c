// clear ; gcc -Wall epoll.c -o epoll.elf && ./epoll.elf

#include <sys/epoll.h>
#include <stdio.h>

int main() {
   #define MAX_EVENTS 10
   struct epoll_event ev, events[MAX_EVENTS];
   int listen_sock, conn_sock, nfds, epollfd, n;
   
   // Set up listening socket, 'listen_sock' (socket(), bind(), listen())
   
   epollfd = epoll_create(10);
   if (epollfd == -1) {
      perror("epoll_create");
      return 1;
   }
   
   ev.events = EPOLLIN;
   ev.data.fd = listen_sock;
   if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
      perror("epoll_ctl: listen_sock");
      return 1;
   }
   
   for (;;) {
      nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
      if (nfds == -1) {
         perror("epoll_pwait");
         return 1;
      }
      
      for (n = 0; n < nfds; ++n) {
         if (events[n].data.fd == listen_sock) {
            //conn_sock = accept(listen_sock,(struct sockaddr *) &local, &addrlen);
            if (conn_sock == -1) {
               perror("accept");
               return 1;
            }
            //setnonblocking(conn_sock);  // "nonblocking socket on which listen has been called"
            ev.events = EPOLLIN | EPOLLET;
            ev.data.fd = conn_sock;
            if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
               perror("epoll_ctl: conn_sock");
               return 1;
            }
         }
         else {
            //do_use_fd(events[n].data.fd); // lê do fd
         }
      }
   }
   return 0;
}

