
The function getpeername() will tell you who is at the other end of a connected stream socket. The synopsis:

#include <sys/socket.h>

int getpeername(int sockfd, struct sockaddr *addr, int *addrlen); 

sockfd is the descriptor of the connected stream socket, addr is a pointer to a struct sockaddr (or a struct sockaddr_in) that will hold the information about the other side of the connection, and addrlen is a pointer to an int, that should be initialized to sizeof *addr or sizeof(struct sockaddr).

The function returns -1 on error and sets errno accordingly.

Once you have their address, you can use inet_ntop(), getnameinfo(), or gethostbyaddr() to print or get more information.

Example

// assume s is a connected socket

socklen_t len;
struct sockaddr_storage addr;
char ipstr[INET6_ADDRSTRLEN];
int port;

len = sizeof addr;
getpeername(s, (struct sockaddr*)&addr, &len);

// deal with both IPv4 and IPv6:
if (addr.ss_family == AF_INET) {
    struct sockaddr_in *s = (struct sockaddr_in *)&addr;
    port = ntohs(s->sin_port);
    inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
} else { // AF_INET6
    struct sockaddr_in6 *s = (struct sockaddr_in6 *)&addr;
    port = ntohs(s->sin6_port);
    inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
}

printf("Peer IP address: %s\n", ipstr);
printf("Peer port      : %d\n", port);


