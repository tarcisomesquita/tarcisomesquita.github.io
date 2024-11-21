// clear ; gcc -Wall getifaddrs.c -o getifaddrs.elf && ./getifaddrs.elf

// #include <ifaddrs.h>

// Structure describing a generic socket address.
struct sockaddr {
   unsigned short int sa_family; // Address family and length.
   char sa_data[14];             // Address data.
};

// The `getifaddrs' function generates a linked list of these structures.
// Each element of the list describes one network interface. 
struct ifaddrs {
   struct ifaddrs *ifa_next; // Pointer to the next structure. 
   
   char *ifa_name;         // Name of this network interface. 
   unsigned int ifa_flags; // Flags as from SIOCGIFFLAGS ioctl. 
   
   struct sockaddr *ifa_addr;    // Network address of this interface. 
   struct sockaddr *ifa_netmask; // Netmask of this interface. 
   union {
      // If the IFF_BROADCAST bit is set in `ifa_flags', then `ifa_broadaddr' is valid.
      // If the IFF_POINTOPOINT bit is set, then `ifa_dstaddr' is valid.
      struct sockaddr *ifu_broadaddr; // Broadcast address of this interface.
      struct sockaddr *ifu_dstaddr;   // Point-to-point destination address. 
   } ifa_ifu;
   // These very same macros are defined by <net/if.h> for `struct ifaddr'.
   // So if they are defined already, the existing definitions will be fine. 
   
   #define ifa_broadaddr ifa_ifu.ifu_broadaddr
   #define ifa_dstaddr   ifa_ifu.ifu_dstaddr
   
   void *ifa_data; // Address-specific data (may be unused). 
};


// Create a linked list of `struct ifaddrs' structures, one for each network interface on the host machine.
// If successful, store the list in *IFAP and return 0.  On errors, return -1 and set `errno'.
// The storage returned in *IFAP is allocated dynamically and can only be properly freed by passing it to `freeifaddrs'. 
extern int getifaddrs(struct ifaddrs **ifap);

// Reclaim the storage allocated by a previous `getifaddrs' call. 
extern void freeifaddrs(struct ifaddrs *ifa);


struct sockaddr_in {
   unsigned short int familia;   
   unsigned short int porta;     // Port number.
   unsigned long int  ip;        // Internet address.
   unsigned char      zero[8];   // Pad to size of struct sockaddr
};

extern int printf(char *, ...);

int main() {
   struct ifaddrs *teste, *teste2, *teste0;
   struct sockaddr_in *address;
   int i;
   
   if (getifaddrs(&teste) != 0 ) return 1;
   
   teste0 = teste;
   for (i=0; ; i++) {
      printf("i = %d\n", i);
      printf("next  = 0x%08X\n", (unsigned int)teste[0].ifa_next);
      printf("name  = %s\n", teste[0].ifa_name);
      printf("flags = 0x%08X\n", teste[0].ifa_flags);
      
      address = (struct sockaddr_in *)teste[0].ifa_addr;
      //printf("porta = 0x%04X\n", (unsigned int)address[0].porta);
      printf("ip    = 0x%08X\n", (unsigned int)address[0].ip);
      
      address = (struct sockaddr_in *)teste[0].ifa_netmask;
      //printf("mask  = 0x%08X\n", (unsigned int)address[0].ip);

      printf("\n\n");
      
      teste2 = teste[0].ifa_next;
      if (teste2 == 0) break;
      teste = teste2;
   }
   
   freeifaddrs(teste0);
   return 0;
}

