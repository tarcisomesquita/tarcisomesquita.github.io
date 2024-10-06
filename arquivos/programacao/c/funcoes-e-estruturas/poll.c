// clear ; gcc -Wall -static  poll.c -o poll.elf && strace -f ./poll.elf

// Test for events on multiple sockets simultaneously
// #include <sys/poll.h>
struct pollfd {
    int fd;         // the socket file descriptor
    short events;   // Types of events poller cares about. If this field is specified as zero, then all events are ignored for fd and revents returns zero.
    short revents;  // Types of events that actually occurred.
};

// Type used for the number of file descriptors.
typedef unsigned long int nfds_t;

// Poll the file descriptors described by the NFDS structures starting at FDS.
// If TIMEOUT is nonzero and not -1, allow TIMEOUT milliseconds for an event to occur; if TIMEOUT is -1, block until an event occurs.
// Returns the number of file descriptors with events, zero if timed out, or -1 for errors.
extern int poll(struct pollfd *fds, unsigned long int nfds, int timeout);

// is very similar to select() in that they both watch sets of file descriptors for events, such as incoming data ready to recv(), socket ready to send() data to, out-of-band data ready to recv(), errors, etc.

// you pass an array of nfds struct pollfds in fds, each is a socket descriptor.

// #include <bits/poll.h>
// (if you set fd to a negative number, this struct pollfd is ignored and its revents field is set to zero)
// Event types (alert when):
#define POLLIN  0x001 // There is data to read.
#define POLLPRI 0x002 // There is urgent data to read.
#define POLLOUT 0x004 // Writing now will not block.

// These are extensions for Linux.
# define POLLMSG	0x400
# define POLLREMOVE	0x1000
# define POLLRDHUP	0x2000  // Stream socket peer closed connection, or shut down writing half of connection.

// These bits need not be set in `events', but they will appear in `revents' to indicate the status of the file descriptor.
#define POLLERR  0x008  // Error ocorred.
#define POLLHUP  0x010  // Remote side Hung up.
#define POLLNVAL 0x020  // Invalid polling request.

// #include <sys/socket.h>
extern int socket(int __domain, int __type, int __protocol);

//PROTOCOL FAMILY
#define PF_INET  2 // IP protocol family.  

//TYPE  Processes communicate only between sockets of the same type.
enum __socket_type { SOCK_STREAM = 1 };

//PROTOCOL
// #include <netinet/in.h>
enum { IPPROTO_TCP = 6 };

enum { MSG_OOB = 0x01}; // Process out-of-band data.

// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =
// Structure describing an IPv4 socket address.
struct sockaddr_in {
   unsigned short int familia;   
   unsigned short int porta;     // Port number.
   unsigned long int  ip;        // Internet address.
   unsigned char      zero[8];   // Pad to size of struct sockaddr
};

// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =
extern int connect(int fd, const struct sockaddr_in *addr, unsigned long int len);
extern unsigned short int htons(unsigned short int hostshort);

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *cp);

// #include <unistd.h>
extern int close (int fd);

int main() {
   int rv;
   char buf1[256], buf2[256];
   struct pollfd ufds[2];
   signed long int r_socket1, r_socket2;
   struct sockaddr_in end_remoto1, end_remoto2;
   
   r_socket1 = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   r_socket2 = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

   end_remoto1.familia = PF_INET;
   end_remoto1.porta   = htons(8081);
   end_remoto1.ip      = inet_addr("127.0.0.1");
   
   end_remoto2.familia = PF_INET;
   end_remoto2.porta   = htons(8082);
   end_remoto2.ip      = inet_addr("127.0.0.1");
   
   connect(r_socket1, &end_remoto1, sizeof(end_remoto1));
   connect(r_socket2, &end_remoto2, sizeof(end_remoto2));
   
   // set up the array of file descriptors.
   // in this example, we want to know when there's normal or out-of-band data ready to be recv()'d...
   ufds[0].fd = r_socket1;
   ufds[0].events = POLLIN | POLLPRI; // check for normal or out-of-band
   
   ufds[1].fd = r_socket2;
   ufds[1].events = POLLIN; // check for just normal data
   
   // If ufds[1].fd is negative, then the corresponding events field is ignored and the revents field returns zero.
   // (This provides an easy way of ignoring a file descriptor for a single poll() call: simply negate the fd field.)
   
   // wait for events on the sockets, 3.5 second timeout
   rv = poll(ufds, 2, 8500);
   
   if (rv == -1) perror("poll"); // error occurred in poll()
   else if (rv == 0) printf("Timeout occurred!  No data after 3.5 seconds.\n");
   else {
      // check for events on s1:
      if (ufds[0].revents & POLLIN)  recv(r_socket1, buf1, sizeof buf1, 0);       // receive normal data
      if (ufds[0].revents & POLLPRI) recv(r_socket1, buf1, sizeof buf1, MSG_OOB); // out-of-band data
      
      // check for events on s2:
      if (ufds[1].revents & POLLIN) recv(r_socket2, buf2, sizeof buf2, 0);
   }

   close(r_socket1);
   close(r_socket2);
   return 0;
}

