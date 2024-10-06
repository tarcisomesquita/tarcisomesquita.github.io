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

