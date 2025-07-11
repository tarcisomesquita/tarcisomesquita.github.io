// #include <netinet/in.h> // = = = = = = = = = = = = = = = = = = = = = = = = =

// IPv6 address
struct in6_addr {
   union {
      unsigned       char __u6_addr8[16];
      unsigned short int  __u6_addr16[8];
      unsigned       int  __u6_addr32[4];
   } __in6_u;
};

