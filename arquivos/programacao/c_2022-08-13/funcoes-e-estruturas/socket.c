
// #include <sys/socket.h>
// Create a new socket of type TYPE in domain DOMAIN, using protocol PROTOCOL.
// If PROTOCOL is zero, one is chosen automatically.
// Returns a file descriptor for the new socket, or -1 for errors.
extern int socket(int domain, int type, int protocol);

// #include <bits/socket.h>

// DOMAIN (Protocol Families)
#define   PF_LOCAL        1   // Local to host (pipes and file-domain).  
#define   PF_INET         2   // IP protocol family.  
#define   PF_BRIDGE       7   // Multiprotocol bridge.  
#define   PF_INET6       10   // IP version 6.  
#define   PF_PACKET      17   // Packet family.  
#define   PF_BLUETOOTH   31   // Bluetooth sockets.  

// DOMAIN (Address Families)
#define   AF_PACKET   PF_PACKET
#define   AF_INET     PF_INET
#define   AF_INET6    PF_INET6

//TYPE  Processes communicate only between sockets of the same type.
enum __socket_type {
   SOCK_STREAM =  1,   // Sequenced, reliable, connection-based byte streams. Used in the Internet domain with TCP. 
   SOCK_DGRAM =   2,   // Connectionless, unreliable datagrams of fixed maximum length. Used in the Internet domain with UDP.
   SOCK_RAW =     3,   // Raw protocol interface.  
   SOCK_PACKET = 10    // Linux specific way of getting packets at the dev level.  For writing rarp and other similar things on the user level. 
};

//PROTOCOL
// #include <netinet/in.h>
// Standard well-defined IP protocols.
enum {
   IPPROTO_IP     =   0,   // Dummy protocol for TCP. O sistema operacional escolhe um protocolo.
   IPPROTO_ICMP   =   1,   // Internet Control Message Protocol.  
   IPPROTO_TCP    =   6,   // Transmission Control Protocol.  
   IPPROTO_UDP    =  17,   // User Datagram Protocol.  
   IPPROTO_IPV6   =  41,   // IPv6 header.  
   IPPROTO_ICMPV6 =  58,   // ICMPv6.  
   IPPROTO_RAW    = 255    // Raw IP packets.  
};

// #include <unistd.h>
extern int close (int fd);


// Socket options can be set with setsockopt(2) and read with getsockopt(2).

int main() {
   signed long int rsocket; Manual page ip(7) line 1

   rsocket = socket(AF_INET,SOCK_STREAM,IPPROTO_IP);
   close(rsocket);
   return(rsocket);
}

/*
Exemplos:

socket(PF_INET, SOCK_DGRAM,  IPPROTO_UDP)
socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)
socket(PF_INET, SOCK_RAW,    IPPROTO_RAW)

socket(PF_INET6, SOCK_RAW, IPPROTO_IPV6)
socket(PF_INET6, SOCK_RAW, IPPROTO_ICMPV6)
socket(PF_INET6, SOCK_RAW, IPPROTO_RAW))

socket(PF_LOCAL, SOCK_DGRAM,  0)
socket(PF_LOCAL, SOCK_STREAM, 0)

socket(PF_PACKET, SOCK_RAW,   IPPROTO_RAW)
socket(PF_PACKET, SOCK_RAW,   htons(ETH_P_ALL));
socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_ALL))
*/

/*
Datagram sockets (UDP)
sendto() or sendmsg()
recvfrom() or recvmsg()
While recv() requires one buffer for the arriving data, recvfrom() requires two buffers, one for the incoming message and another to receive the source address.

Datagram sockets can also use connect() to connect the socket to a specified destination socket. When this is done, send() and recv() are used to send and receive data.

accept() and listen() are not used with datagram sockets.
*/

/*
Veja man 7 socket

socketpair(2) returns two connected anonymous sockets (only implemented for a few local families like AF_UNIX)
send(2), sendto(2), and sendmsg(2) send data over a socket, and recv(2), recvfrom(2), recvmsg(2) receive data from a socket.
poll(2) and select(2) wait for arriving data or a readiness to send data.
write(2), writev(2), sendfile(2), read(2), and readv(2) can be used to read and write data.
getsockname(2) returns the local socket address and getpeername(2) returns the remote socket address.
getsockopt(2) and setsockopt(2) are used to set or get socket layer or protocol options.
ioctl(2) can be used to set or read some other options.
close(2) is used to close a socket. shutdown(2) closes parts of a full-duplex socket connection.

Seeking, or calling pread(2) or pwrite(2) with a non-zero position is not supported on sockets.
*/

