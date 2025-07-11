
// sudo tcpdump -i wlan0 -e -s 0 '(ether dst host F0:7D:68:E7:68:E6)' -w send_ethernet_raw.pcap 
// clear ; gcc -Wall send_ethernet_raw.c -o send_ethernet_raw.elf && sudo ./send_ethernet_raw.elf ; echo $?

// send packets to a specific MAC address from a specific interface


// #include<bits/socket.h> // = = = = = = = = = = = = = = = = = =
struct sockaddr {
   unsigned short int sa_family; // address family and length.
   char sa_data[14];             // Address data.
};


// #include <sys/socket.h>
extern int socket(int domain, int type, int protocol) __attribute__ ((__nothrow__));
// Send N bytes of BUF on socket FD to peer at address ADDR (which is ADDR_LEN bytes long).
// Returns the number sent, or -1 for errors.
extern int sendto (int fd, const void *buf, unsigned int n, int flags, const struct sockaddr * addr, unsigned int addr_len);


// #include <bits/socket.h>
#define   PF_PACKET   17      // Packet family.  
#define   AF_PACKET   PF_PACKET

// Types of sockets.
enum __socket_type {
   SOCK_STREAM = 1,           // Sequenced, reliable, connection-based byte streams. 
   SOCK_DGRAM = 2,            // Connectionless, unreliable datagrams of fixed maximum length. 
   SOCK_RAW = 3,              // Raw protocol interface. 
   SOCK_RDM = 4,              // Reliably-delivered messages. 
   SOCK_SEQPACKET = 5,        // Sequenced, reliable, connection-based, datagrams of fixed maximum length. 
   SOCK_DCCP = 6,             // Datagram Congestion Control Protocol. 
   SOCK_PACKET = 10,          // Linux specific way of getting packets at the dev level.  For writing rarp and other similar things on the user level.
   SOCK_CLOEXEC = 02000000,   // Atomically set close-on-exec flag for the new descriptor(s). 
   SOCK_NONBLOCK = 04000      // Atomically mark descriptor(s) as non-blocking. 
};


// #include <netinet/in.h>
// Standard well-defined IP protocols. 
enum {
   IPPROTO_IP = 0,        // Dummy protocol for TCP. 
   IPPROTO_HOPOPTS = 0,   // IPv6 Hop-by-Hop options. 
   IPPROTO_ICMP = 1,      // Internet Control Message Protocol. 
   IPPROTO_IGMP = 2,      // Internet Group Management Protocol.
   IPPROTO_IPIP = 4,      // IPIP tunnels (older KA9Q tunnels use 94). 
   IPPROTO_TCP = 6,       // Transmission Control Protocol. 
   IPPROTO_EGP = 8,       // Exterior Gateway Protocol. 
   IPPROTO_PUP = 12,      // PUP protocol. 
   IPPROTO_UDP = 17,      // User Datagram Protocol. 
   IPPROTO_IDP = 22,      // XNS IDP protocol. 
   IPPROTO_TP = 29,       // SO Transport Protocol Class 4. 
   IPPROTO_DCCP = 33,     // Datagram Congestion Control Protocol. 
   IPPROTO_IPV6 = 41,     // IPv6 header. 
   IPPROTO_ROUTING = 43,  // IPv6 routing header. 
   IPPROTO_FRAGMENT = 44, // IPv6 fragmentation header. 
   IPPROTO_RSVP = 46,     // Reservation Protocol. 
   IPPROTO_GRE = 47,      // General Routing Encapsulation. 
   IPPROTO_ESP = 50,      // encapsulating security payload. 
   IPPROTO_AH = 51,       // authentication header. 
   IPPROTO_ICMPV6 = 58,   // ICMPv6. 
   IPPROTO_NONE = 59,     // IPv6 no next header. 
   IPPROTO_DSTOPTS = 60,  // IPv6 destination options. 
   IPPROTO_MTP = 92,      // Multicast Transport Protocol. 
   IPPROTO_ENCAP = 98,    // Encapsulation Header. 
   IPPROTO_PIM = 103,     // Protocol Independent Multicast. 
   IPPROTO_COMP = 108,    // Compression Header Protocol. 
   IPPROTO_SCTP = 132,    // Stream Control Transmission Protocol. 
   IPPROTO_UDPLITE = 136, // UDP-Lite protocol. 
   IPPROTO_RAW = 255,     // Raw IP packets. 
   IPPROTO_MAX
};

struct in_addr {
   unsigned int s_addr; // Internet address
};

extern unsigned short int htons(unsigned short int hostshort);

// Structure describing an Internet socket address.
struct sockaddr_in {
   unsigned short int sin_family; 
   unsigned short int sin_port;     // Port number.
   struct in_addr sin_addr;         // Internet address.
   
   // Pad to size of struct sockaddr
   unsigned char sin_zero[sizeof(struct sockaddr) - (sizeof(unsigned short int)) - sizeof(unsigned short int) - sizeof(struct in_addr)];
};


// #include<net/if.h> // = = = = = = = = = = = = = = = = = =
 // Device mapping structure.
struct ifmap {
   unsigned long int mem_start;
   unsigned long int mem_end;
   unsigned short int base_addr;
   unsigned char irq;
   unsigned char dma;
   unsigned char port;
};

#define IF_NAMESIZE   16   // Length of interface name.
#define IFNAMSIZ   IF_NAMESIZE
// Interface request structure used for socket ioctl's
struct ifreq {
   union {
      char ifrn_name[16]; // Interface name, e.g. "eth0".
   } ifr_ifrn;
   
   union {
      struct sockaddr ifru_addr;       // 
      struct sockaddr ifru_dstaddr;
      struct sockaddr ifru_broadaddr;
      struct sockaddr ifru_netmask;
      struct sockaddr ifru_hwaddr;
      short int ifru_flags;
      int ifru_ivalue;
      int ifru_mtu;
      struct ifmap ifru_map;
      char ifru_slave[16];
      char ifru_newname[16];
      char *ifru_data;
   } ifr_ifru;
};

#define ifr_name        ifr_ifrn.ifrn_name        // interface name 
#define ifr_hwaddr      ifr_ifru.ifru_hwaddr      // MAC address 
#define ifr_addr        ifr_ifru.ifru_addr        // address
#define ifr_dstaddr     ifr_ifru.ifru_dstaddr     // other end of p-p lnk
#define ifr_broadaddr   ifr_ifru.ifru_broadaddr   // broadcast address
#define ifr_netmask     ifr_ifru.ifru_netmask     // interface net mask
#define ifr_flags       ifr_ifru.ifru_flags       // flags
#define ifr_metric      ifr_ifru.ifru_ivalue      // metric
#define ifr_mtu         ifr_ifru.ifru_mtu         // mtu
#define ifr_map         ifr_ifru.ifru_map         // device map
#define ifr_slave       ifr_ifru.ifru_slave       // slave device
#define ifr_data        ifr_ifru.ifru_data        // for use by interface
#define ifr_ifindex     ifr_ifru.ifru_ivalue      // interface index     
#define ifr_bandwidth   ifr_ifru.ifru_ivalue      // link bandwidth
#define ifr_qlen        ifr_ifru.ifru_ivalue      // queue length
#define ifr_newname     ifr_ifru.ifru_newname     // New name


//#include<linux/if_ethernet.h>
#define ETH_ALEN	6		// Octets in one ethernet addr


// #include<sys/types.h>
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));


//#include<net/ethernet.h>
// This is an Ethernet frame header.
struct ether_header {
   u_int8_t  ether_dhost[6];  // destination eth addr
   u_int8_t  ether_shost[6];  // source ether addr
   u_int16_t ether_type; // packet type ID field
} __attribute__ ((__packed__));;


//#include<netinet/ip.h>
struct iphdr {
   unsigned int ihl:4;     // header length (4bits)
   unsigned int version:4; // version (4bits)
   u_int8_t     tos;       // type of service
   u_int16_t    tot_len;   // total length
   u_int16_t    id;        // identification
   u_int16_t    frag_off;  // fragment offset field
   u_int8_t     ttl;       // time to live
   u_int8_t     protocol;  // protocolip
   u_int16_t    check;     // checksum
   u_int32_t    saddr;     // source address
   u_int32_t    daddr;     // dest address
};


// #include<netinet/udp.h>
struct udphdr {
   u_int16_t source; // source port
   u_int16_t dest;   // destination port
   u_int16_t len;    // udp length
   u_int16_t check;  // udp checksum
};


// #include<linux/if_packet.h>
struct sockaddr_ll {
   unsigned short sll_family;
   unsigned short sll_protocol;
   int	          sll_ifindex;
   unsigned short sll_hatype;
   unsigned char  sll_pkttype;
   unsigned char  sll_halen;
   unsigned char  sll_addr[8];
};


// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);
extern char *inet_ntoa(struct in_addr __in);


// #include <stdio.h>
extern int sprintf(char *s, const char *format, ...);
extern int printf(const char *format, ...);
extern void perror(const char *s);


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *memset(void *s, int c, unsigned long int n);
extern char *strncpy(char *destino, char *origem, unsigned n);


// #include<sys/ioctl.h> // = = = = = = = = = = = = = = = = = =
extern int ioctl(int fd, unsigned long int request, ...);
#define SIOCGIFINDEX	0x8933		// name -> if_index mappin
#define SIOCGIFHWADDR	0x8927		// Get hardware address
#define SIOCGIFADDR	0x8915		// get PA address


// #include <unistd.h>
extern int close (int __fd);


unsigned short csum(unsigned short *buf, int nwords) {
   unsigned long sum;
   for(sum=0; nwords>0; nwords--) sum += *buf++;
   sum = (sum >> 16) + (sum &0xffff);
   sum += (sum >> 16);
   return (unsigned short)(~sum);
}


// F0:7D:68:E7:68:E6 roteador
#define MY_DEST_MAC0	0xF0
#define MY_DEST_MAC1	0x7D
#define MY_DEST_MAC2	0x68
#define MY_DEST_MAC3	0xE7
#define MY_DEST_MAC4	0x68
#define MY_DEST_MAC5	0xE6

#define DEFAULT_IF	"wlan0"
#define BUF_SIZ		1024


int main(int argc, char **argv) {
   int sockfd;
   char file_line[50];
   struct ifreq if_idx, if_mac, if_ip;
   struct sockaddr_ll socket_address; // Destination address 
   char sendbuf[1024];
   int tx_len = 0;
   struct ether_header *eh;
   struct iphdr *iph;
   unsigned int ttl = 2;
   struct udphdr *udph;
   
   
   // Open the raw socket:
   if ((sockfd = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW)) == -1) {
      sprintf(file_line, "\nTente sudo %s: %s:%d. ERRO", argv[0], __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   // Get the index of the interface to send on:
   memset(&if_idx, 0, sizeof(struct ifreq));
   strncpy(if_idx.ifr_name, DEFAULT_IF, IFNAMSIZ-1);
   if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   // Get the MAC address of the interface to send on:
   memset(&if_mac, 0, sizeof(struct ifreq));
   strncpy(if_mac.ifr_name, DEFAULT_IF, IFNAMSIZ-1);
   if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   // Get the IP address of the interface to send on:
   memset(&if_ip, 0, sizeof(struct ifreq));
   strncpy(if_ip.ifr_name, DEFAULT_IF, IFNAMSIZ-1);
   if (ioctl(sockfd, SIOCGIFADDR, &if_ip) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   socket_address.sll_ifindex = if_idx.ifr_ifindex;  // Index of the network device
   socket_address.sll_halen = ETH_ALEN;              // Address length
   socket_address.sll_addr[0] = MY_DEST_MAC0;        // Destination MAC
   socket_address.sll_addr[1] = MY_DEST_MAC1;
   socket_address.sll_addr[2] = MY_DEST_MAC2;
   socket_address.sll_addr[3] = MY_DEST_MAC3;
   socket_address.sll_addr[4] = MY_DEST_MAC4;
   socket_address.sll_addr[5] = MY_DEST_MAC5;
   
   
   // Construct the Ethernet header:
   eh = (struct ether_header *)sendbuf;
   memset(sendbuf, 0, 1024);
   // Ethernet header
   eh->ether_shost[0] = ((unsigned char *)&if_mac.ifr_hwaddr.sa_data)[0];
   eh->ether_shost[1] = ((unsigned char *)&if_mac.ifr_hwaddr.sa_data)[1];
   eh->ether_shost[2] = ((unsigned char *)&if_mac.ifr_hwaddr.sa_data)[2];
   eh->ether_shost[3] = ((unsigned char *)&if_mac.ifr_hwaddr.sa_data)[3];
   eh->ether_shost[4] = ((unsigned char *)&if_mac.ifr_hwaddr.sa_data)[4];
   eh->ether_shost[5] = ((unsigned char *)&if_mac.ifr_hwaddr.sa_data)[5];
   eh->ether_dhost[0] = MY_DEST_MAC0;
   eh->ether_dhost[1] = MY_DEST_MAC1;
   eh->ether_dhost[2] = MY_DEST_MAC2;
   eh->ether_dhost[3] = MY_DEST_MAC3;
   eh->ether_dhost[4] = MY_DEST_MAC4;
   eh->ether_dhost[5] = MY_DEST_MAC5;
   eh->ether_type = htons(0x0800);
   tx_len += sizeof(struct ether_header);
   
   
   // Construct the IP header:
   iph = (struct iphdr *) (sendbuf + sizeof(struct ether_header));
   
   // IP Header 
   iph->ihl = 5;
   iph->version = 4;
   iph->tos = 16;          // Low delay
   iph->id = htons(54321);
   iph->ttl = ttl;          // hops
   iph->protocol = 17;      // UDP
   iph->saddr = inet_addr(inet_ntoa(((struct sockaddr_in *)&if_ip.ifr_addr)->sin_addr));
   // iph->saddr = inet_addr("192.168.0.112"); // Source IP address, can be spoofed 
   iph->daddr = inet_addr("192.168.33.1");    // Destination IP address 
   tx_len += sizeof(struct iphdr);
   
   
   // Construct the UDP header:
   udph = (struct udphdr *)(sendbuf + sizeof(struct iphdr) + sizeof(struct ether_header));
   
   // UDP Header
   udph->source = htons(3423);
   udph->dest = htons(5342);
   tx_len += sizeof(struct udphdr);
   
   
   // Packet data
   sendbuf[tx_len++] = 0xde;
   sendbuf[tx_len++] = 0xad;
   sendbuf[tx_len++] = 0xbe;
   sendbuf[tx_len++] = 0xef;
   
   
   // Fill in remaining header info:
   
   // Length of UDP payload and header
   udph->len = htons(tx_len - sizeof(struct ether_header) - sizeof(struct iphdr));
   // Length of IP payload and header
   iph->tot_len = htons(tx_len - sizeof(struct ether_header));
   
   // Calculate UDP checksum on completed header 
   udph->check = 0; // csum((unsigned short *)(sendbuf+sizeof(struct ether_header)+sizeof(struct iphdr)), sizeof(struct udphdr)/2);
   // Calculate IP checksum on completed header 
   iph->check = csum((unsigned short *)(sendbuf+sizeof(struct ether_header)), sizeof(struct iphdr)/2);
   
   
   // Send the raw Ethernet packet:
   
   if (sendto(sockfd, sendbuf, tx_len, 0, (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll)) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   if (close(sockfd)) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   return 0;
}

