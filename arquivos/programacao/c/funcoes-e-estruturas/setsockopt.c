// #include <sys/socket.h>
// Set socket FD's option OPTNAME at protocol level LEVEL to *OPTVAL (which is OPTLEN bytes long).
// Returns 0 on success, -1 for errors.
extern int setsockopt (int fd, int level, int optname, const void *optval, unsigned int optlen);

// #include <asm-generic/socket.h>
#define SOL_SOCKET	1

#define SO_DEBUG	1
#define SO_REUSEADDR	2
#define SO_DONTROUTE	5
#define SO_BROADCAST	6
#define SO_SNDBUF	7
#define SO_RCVBUF	8
#define SO_KEEPALIVE	9
#define SO_LINGER	13

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

    int broadcast = 1;
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) return 1;
    
   // this call is what allows broadcast packets to be sent:
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast) < 0) return 1;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int yes = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int))

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// When close(fd), if have data waiting, close tries to complete this transmission.
// You can control this behavior using the SO_LINGER socket option to specify a timeout period.

// #include <bits/socket.h>
// Structure used to manipulate the SO_LINGER option.
struct linger {
   int l_onoff;    // Nonzero to linger on close.
   int l_linger;   // Time to linger.
};


  struct linger fix_ling;
  if ((sock = socket(domain, type, 0)) < 0) return -1;

  // don't leave the socket in a TIME_WAIT state if we close the connection */
  fix_ling.l_onoff  = 1;
  fix_ling.l_linger = 0;
  ret = setsockopt(sock, SOL_SOCKET, SO_LINGER, &fix_ling, sizeof(fix_ling));

