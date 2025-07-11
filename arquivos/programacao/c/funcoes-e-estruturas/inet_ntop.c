
// converts an Internet address (either IPv4 or IPv6) from network (binary) to presentation (textual) form.
// AF should be either AF_INET or AF_INET6
// CP is a pointer to the address to be converted.
// BUF should be a pointer to a buffer to hold the result
// LEN is the length of this buffer.
// return is the buffer address.

// #include <sys/socket.h>
//PROTOCOL FAMILY
#define	PF_INET		2	// IP protocol family.  

//DOMAIN
#define	AF_INET		PF_INET

// #include <arpa/inet.h>
extern const char *inet_ntop (int AF, const void *CP, char *BUF, unsigned long int LEN);

// #include <sys/socket.h>
struct in_addr {
   unsigned long int s_addr; // Internet address
};

// #include <stdio.h>
extern int printf(const char *, ...);

int main(int argc, char *argv[]) {
   char string[16];
   char *address;
   struct in_addr endereco;
   
   endereco.s_addr = 0x6400A8C0; // = C0.A8.00.64 = 192.168.0.100
   address = (char *)inet_ntop (AF_INET, &endereco, string, sizeof(string));
   printf("\naddress = %p\n&string = %p\nstring = \"%s\"\n\n", address, &string, string);
   
   return 0;
}

