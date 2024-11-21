// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =

// for IPv6.
struct sockaddr_in6 {
   unsigned short int sin6_family;
   unsigned short int sin6_port;  // Transport layer port #
   unsigned int sin6_flowinfo;    // IPv6 flow information
   struct in6_addr sin6_addr;     // IPv6 address
   unsigned int sin6_scope_id;    // IPv6 scope-id
};

