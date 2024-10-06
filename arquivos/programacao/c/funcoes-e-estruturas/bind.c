
// Give the socket FD the local address ADDR (which is LEN bytes long). 
// The return value is 0 on success and -1 on failure.
// É o inverso de getsockname

struct sockaddr
{
   unsigned short int sa_family;
   char sa_data[14];
};


// #include<sys/socket.h>
extern int bind (int __fd, const struct sockaddr * __addr, int __len);


For Internet domain sockets, use
#include <netinet/in.h>
... 
bind (sd, (struct sockaddr_in *) &addr, length);

/*
man 7 ip

// #include<netinet/in.h>
#define   INADDR_ANY         ((long int)0x00000000)    // Address to accept any incoming messages.
#define   INADDR_BROADCAST   ((long int) 0xffffffff)   // Address to send to all hosts.

When INADDR_ANY is specified in the bind call, the socket will be bound to all local interfaces. 
When listen(2) or connect(2) are called on an unbound socket, it is automatically bound to a random free port with the local address set to INADDR_ANY.


/proc/sys/net/ipv4/

       ip_local_port_range
              Contains  two  integers that define the default local port range allocated to sockets.
              First number should be at least greater than 1024, or better, greater than 4096.

       ip_nonlocal_bind
              If  set, allows processes to bind(2) to non-local IP addresses.
*/

