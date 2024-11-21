// showip.c -- show IP addresses for a host given on the command line
/*
$ showip www.example.net
IP addresses for www.example.net:

  IPv4: 192.0.2.88

$ showip ipv6.example.com
IP addresses for ipv6.example.com:

  IPv4: 192.0.2.101
  IPv6: 2001:db8:8c00:22::171
*/

// #include <bits/socket.h> // = = = = = = = = = = = = = = = = = = = = = = = = 
// Structure describing a generic socket address.
struct sockaddr {
   unsigned short int sa_family; // Common data: address family and length.
   char sa_data[14]; // Address data.
};

// Protocol families.
#define PF_UNSPEC 0 // Unspecified.
#define PF_INET   2 // IP protocol family.

// Address families.
#define AF_UNSPEC PF_UNSPEC
#define AF_INET PF_INET

// Types of sockets.
enum __socket_type {
  SOCK_STREAM = 1 // Sequenced, reliable, connection-based byte streams.
};

// #include <netdb.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
// Structure to contain information about address of a service provider.
struct addrinfo {
  int ai_flags;             // Input flags.
  int ai_family;            // Protocol family for socket.
  int ai_socktype;          // Socket type.
  int ai_protocol;          // Protocol for socket.
  unsigned int ai_addrlen;  // Length of socket address.
  struct sockaddr *ai_addr; // Socket address for socket.
  char *ai_canonname;       // Canonical name for service location.
  struct addrinfo *ai_next; // Pointer to next in list.
};

// Translate name of a service location and/or a service name to set of socket addresses.
extern int getaddrinfo(const char *name, const char *service, const struct addrinfo *req, struct addrinfo **pai);
// name: "www.example.com" or IP
// service: "http" or port number
// pai: will point to the results

// Free `addrinfo' structure AI including associated storage.
extern void freeaddrinfo(struct addrinfo *ai);

// Convert error return from getaddrinfo() to a string.
extern const char *gai_strerror(int ecode);


// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =
#define INET6_ADDRSTRLEN 46

// Internet address.
struct in_addr {
   unsigned int s_addr;
};

// Structure describing an Internet socket address.
struct sockaddr_in {
   unsigned short int sin_family;
   unsigned short int sin_port;  // Port number.
   struct in_addr sin_addr;      // Internet address.
   
   // Pad to size of `struct sockaddr'.
   unsigned char sin_zero[sizeof (struct sockaddr) -
      (sizeof (unsigned short int)) -
      sizeof (unsigned short int) -
      sizeof (struct in_addr)];
};

// IPv6 address
struct in6_addr {
   union {
      unsigned       char __u6_addr8[16];
      unsigned short int  __u6_addr16[8];
      unsigned       int  __u6_addr32[4];
   } __in6_u;
   #define s6_addr   __in6_u.__u6_addr8
   #define s6_addr16 __in6_u.__u6_addr16
   #define s6_addr32 __in6_u.__u6_addr32
};

// Ditto, for IPv6.
struct sockaddr_in6 {
   unsigned short int sin6_family;
   unsigned short int sin6_port;  // Transport layer port #
   unsigned int sin6_flowinfo;    // IPv6 flow information
   struct in6_addr sin6_addr;     // IPv6 address
   unsigned int sin6_scope_id;    // IPv6 scope-id
};


// #include <arpa/inet.h>
extern const char *inet_ntop (int AF, const void *CP, char *BUF, unsigned long int LEN);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *memset(void *__s, int __c, unsigned long int __n);

extern int printf(char *, ...);

unsigned long int print_addrinfo(struct addrinfo _addrinfo) {
   int i;
   
   printf("\n");
   printf("addrinfo.ai_flags     = %02d           // Input flags.\n", _addrinfo.ai_flags);
   printf("addrinfo.ai_family    = %02d           // Protocol family for socket. IPv4 é 2\n", _addrinfo.ai_family);
   printf("addrinfo.ai_socktype  = %02d           // Socket type.\n", _addrinfo.ai_socktype);
   printf("addrinfo.ai_protocol  = %02d           // Protocol for socket.\n", _addrinfo.ai_protocol);
   printf("addrinfo.ai_addrlen   = %02u           // Length of socket address.\n", _addrinfo.ai_addrlen);
   printf("addrinfo.ai_addr      = 0x%08X   // Socket address for socket.\n", (unsigned int)_addrinfo.ai_addr);
   printf("addrinfo.ai_canonname = 0x%08X   // Canonical name for service location.\n", (unsigned int)_addrinfo.ai_canonname);
   printf("addrinfo.ai_next      = 0x%08X   // Pointer to next in list.\n\n", (unsigned int)_addrinfo.ai_next);
   
   if (_addrinfo.ai_addr != 0) {
      printf("addrinfo.ai_addr[0].sa_family = %02u   // address family and length.\n", _addrinfo.ai_addr[0].sa_family);
      printf("addrinfo.ai_addr[0].sa_data   = ");
      for (i = 0; i < 14; i++) printf("%u ", (unsigned char)_addrinfo.ai_addr[0].sa_data[i] );
      printf("\n\n");
   }
   
   if (_addrinfo.ai_canonname != 0) printf("addrinfo.ai_canonname = \"%s\"   // Canonical name for service location.\n\n", _addrinfo.ai_canonname);
   
   return (unsigned long int)_addrinfo.ai_next;
}


int main(int argc, char **argv) {
   struct addrinfo hints, *res, *p;
   int status;
   char ipstr[INET6_ADDRSTRLEN];
   
   if (argc != 2) {
      printf("usage: showip hostname\n");
      return 1;
   }
   
   memset(&hints, 0, sizeof hints);
   hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
   hints.ai_socktype = SOCK_STREAM;
   
   if ((status = getaddrinfo(argv[1], 0x00, &hints, &res)) != 0) {
      printf("getaddrinfo: %s\n", gai_strerror(status));
      return 1;
   }
   
   print_addrinfo(hints);
   for(p = res;print_addrinfo(p[0]) != 0x00; p = p->ai_next);
   
   
   printf("\nIP addresses for %s:\n\n", argv[1]);
   
   for(p = res;p != 0x00; p = p->ai_next) {
      void *addr;
      char *ipver;
      
      // get the pointer to the address itself,
      // different fields in IPv4 and IPv6:
      if (p->ai_family == AF_INET) { // IPv4
         struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
         addr = &(ipv4->sin_addr);
         ipver = "IPv4";
      } else { // IPv6
         struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
         addr = &(ipv6->sin6_addr);
         ipver = "IPv6";
      }
      
      // convert the IP to a string and print it:
      inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
      printf("  %s: %s\n", ipver, ipstr);
   }
   
   freeaddrinfo(res); // free the linked list
   
   return 0;
}


