
// Put the local address of FD into *ADDR and its length in LEN. 
// The return value is 0 on success and -1 on error.

struct sockaddr
{
   unsigned short int sa_family;
   char sa_data[14];
};


// #include<sys/socket.h>
extern int getsockname (int __fd, const struct sockaddr * __addr, int __len);

// estabeleça a conexão, depois copie e struct

/*
É o inverso de bind

The following errno error conditions are defined for this function:
EBADF
    The socket argument is not a valid file descriptor.
ENOTSOCK
    The descriptor socket is not a socket.
ENOBUFS
    There are not enough internal buffers available for the operation. 
*/
