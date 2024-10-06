
// htohl converts the uint32_t integer hostlong from host byte order to network byte order.
// ntohl (uint32_t netlong) converts the uint32_t integer netlong from network byte order to host byte order.

// #include <netinet/in.h>
extern unsigned long int htonl(unsigned long int __hostlong);


