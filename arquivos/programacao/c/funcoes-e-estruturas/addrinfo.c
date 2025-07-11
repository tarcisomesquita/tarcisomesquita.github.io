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

