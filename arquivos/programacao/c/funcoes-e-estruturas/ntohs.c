
// Function to convert between host and network byte order.

// #include <netinet/in.h>
extern unsigned short int ntohs(unsigned short int netshort);
// "www" = 80 = 0x0050
// htons(80) = 0x5000
// ntohs(0x5000) = 80;


extern int printf(char *, ...);

int main() {
   printf("\nntohs(0x5000) = %u\n\n", ntohs(0x5000));
   return 0;
}

