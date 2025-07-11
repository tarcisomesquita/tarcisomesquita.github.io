// #include <bits/sigset.h>
typedef struct {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;


// #include <sys/epoll.h>
typedef union epoll_data {
   void *ptr;
   int fd;
   unsigned int u32;
   unsigned long long int u64;
} epoll_data_t;

struct epoll_event {
   unsigned int events;   // Epoll events
   epoll_data_t data;     // User data variable
};

// Creates an epoll instance.
// "size" is ignored, but must be greater than zero.
// Returns an fd for the new instance, that should be closed with close().
extern int epoll_create(int size);

// Same as epoll_create but with an FLAGS parameter.
extern int epoll_create1(int flags);

// Manipulate an epoll instance
// "epfd" is the epoll instance.
// "op" is one of the EPOLL_CTL_* constants defined above.
// "fd" is the target of the operation.
// "event" describes which events the caller is interested in and any associated user data.
// Returns 0 in case of success, -1 in case of error (the "errno" will contain the specific error code)
extern int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

// Wait for events on an epoll instance
// "epfd" is the epoll instance.
// "events" parameter is a buffer that will contain triggered events.
// "maxevents" is the maximum number of events to be returned ( usually size of "events" ).
// "timeout" specifies the maximum wait time in milliseconds (-1 == infinite).
// Returns the number of triggered events returned in "events" buffer, -1 in case of error (the "errno" will contain the specific error code)
extern int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

// Same as epoll_wait, but the thread's signal mask is temporarily and atomically replaced with the one provided as parameter.
extern int epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const __sigset_t *ss);


// Flags to be passed to epoll_create2.
enum {
   EPOLL_CLOEXEC  = 02000000,
   EPOLL_NONBLOCK = 04000
};

enum EPOLL_EVENTS {
   EPOLLIN     = 0x001,
   EPOLLPRI    = 0x002,
   EPOLLOUT    = 0x004,
   EPOLLRDNORM = 0x040,
   EPOLLRDBAND = 0x080,
   EPOLLWRNORM = 0x100,
   EPOLLWRBAND = 0x200,
   EPOLLMSG    = 0x400,
   EPOLLERR    = 0x008,
   EPOLLHUP    = 0x010,
   EPOLLRDHUP  = 0x2000,
   EPOLLONESHOT = (1 << 30),
   EPOLLET      = (1 << 31)
};

// Valid opcodes ( "op" parameter ) to issue to epoll_ctl().
#define EPOLL_CTL_ADD 1 // Add a file decriptor to the interface.
#define EPOLL_CTL_DEL 2 // Remove a file decriptor from the interface.
#define EPOLL_CTL_MOD 3 // Change file decriptor epoll_event structure.



// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout; 
extern int fprintf(FILE *stream, const char *formatted_output, ...);
extern int sprintf (unsigned char *s, const char *format, ...);

// #include <sys/socket.h>
extern int socket(int __domain, int __type, int __protocol);
extern int send(int __fd, const void *__buf, unsigned long int __n, int __flags);

//PROTOCOL FAMILY
#define PF_INET  2 // IP protocol family.  

//DOMAIN Address families.  
#define AF_INET  PF_INET


//TYPE  Processes communicate only between sockets of the same type.
enum __socket_type
{
   SOCK_STREAM = 1  // Sequenced, reliable, connection-based byte streams.  
   // A stream operates much like a telephone conversation.
   // Used in the Internet domain with TCP. 
}
;

//PROTOCOL
// #include <netinet/in.h>
enum
{
   IPPROTO_TCP = 6    // Transmission Control Protocol.  
}
;


// #include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int read (int __fd, void *__buf, unsigned long int __nbytes);
extern int close (int __fd);


// #include <sys/socket.h>
struct sockaddr
{
   unsigned short int sa_family;
   char sa_data[14];
}
;


// Internet address
struct in_addr
{
   unsigned long int s_addr;
}
;

// Structure describing an Internet socket address.
struct sockaddr_in
{
   
   unsigned short int sin_family; 
   unsigned short int sin_port;     // Port number.
   struct in_addr sin_addr;         // Internet address.
   
   // Pad to size of struct sockaddr
   unsigned char sin_zero[sizeof(struct sockaddr) -     \
   (sizeof(unsigned short int)) - \
   sizeof(unsigned short int) -  \
   sizeof(struct in_addr)];
}
;

// #include <sys/socket.h> // = = = = = = = = = = = = = = = = = = = = = =
extern int bind (int __fd, struct sockaddr_in *__addr, int __len);
extern int accept (int __fd, struct sockaddr_in * __addr, int * __addr_len);
extern int listen (int __fd, int __n);
enum
{
   SHUT_RD = 0,  /* No more receptions.  */
   SHUT_WR = 1,  /* No more transmissions.  */
   SHUT_RDWR = 2  /* No more receptions or transmissions.  */
}
;

/* Shut down all or part of the connection open on socket FD.
   HOW determines what to shut down:
     SHUT_RD   = No more receptions;
     SHUT_WR   = No more transmissions;
     SHUT_RDWR = No more receptions or transmissions.
   Returns 0 on success, -1 for errors.  */
extern int shutdown (int __fd, int __how);


// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);


// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int strlen(unsigned char *str);

//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int atoi(const char *);

// #include <sys/socket.h>
extern int setsockopt (int __fd, int __level, int __optname, const void *__optval, unsigned int __optlen);

// #include <asm-generic/socket.h>
#define SOL_SOCKET 1
#define SO_REUSEADDR 2



extern int write(int __fd, const void *__buf, unsigned long int __n);

int main() {
   int yes = 1;
   int fromlen, n;
   unsigned char buffer = 0x00;
   register int s, ns, len;
   struct sockaddr_in saun, fsaun;
   
   s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); if (s < 0) return 1;
   
   // Create the address we will be binding to.
   saun.sin_family = AF_INET;
   saun.sin_port = htons(8080);
   saun.sin_addr.s_addr = inet_addr("127.0.0.1");
   //   saun.sin_addr.s_addr = inet_addr("192.168.43.170");

   setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
   
   // Try to bind the address to the socket.
   len = sizeof(struct sockaddr_in);
   
   if (bind(s, &saun, len) < 0) return 1;
   if (listen(s, 5) < 0) return 2;
   
   // conecta ao cliente
   for (;;) {
      // Accept connections. fsaun will contain the address of the client.
      if ((ns = accept(s, &fsaun, &fromlen)) < 0) return 3;
      fprintf(stdout, "\nConexão aceita.  fromlen = %d\n\n", fromlen);
      for (;;) {
         n = read(ns, &buffer, 1); if (n == 0) break; write(1, &buffer, 1);
      }
      close(ns);
   }
   close(s);
   return 0;
}

