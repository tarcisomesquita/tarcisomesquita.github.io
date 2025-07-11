
// sudo tcpdump -i wlan0 -e -s 0 -w Desktop/senRawEth.pcap
// clear ; gcc -Wall -Werror sendRawEth.c -o sendRawEth.elf && sudo ./sendRawEth.elf

// #include <stdio.h>
extern int sprintf(char *s, const char *format, ...);
extern int printf(const char *format, ...);
extern void perror(const char *s);

//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *memset(void *s, int c, unsigned long int n);
extern char *strncpy(char *destino, char *origem, unsigned n);
extern char *strcpy(char *destino, char *origem);

// #include<sys/ioctl.h> // = = = = = = = = = = = = = = = = = =
extern int ioctl(int fd, unsigned long int request, ...);
#define SIOCGIFINDEX	0x8933		// name -> if_index mappin
#define SIOCGIFHWADDR	0x8927		// Get hardware address
#define SIOCGIFADDR	0x8915		// get PA address


// #include<bits/socket.h> // = = = = = = = = = = = = = = = = = =
struct sockaddr {
   unsigned short int sa_family; // address family and length.
   char sa_data[14];             // Address data.
};

// #include <sys/socket.h>
extern int socket(int domain, int type, int protocol);
#define	PF_PACKET	17	   // Packet family.  
#define	AF_PACKET	PF_PACKET
#define	SOCK_RAW	3	   // Raw protocol interface.  
#define	IPPROTO_RAW	255	   // Raw IP packets.  
// Send N bytes of BUF on socket FD to peer at address ADDR (which is ADDR_LEN bytes long).
// Returns the number sent, or -1 for errors.
extern int sendto (int fd, const void *buf, unsigned int n, int flags, const struct sockaddr *addr, unsigned int addr_len);

// #include<net/if.h> // = = = = = = = = = = = = = = = = = =
struct ifmap // Device mapping structure.
{
   unsigned long int mem_start;
   unsigned long int mem_end;
   unsigned short int base_addr;
   unsigned char irq;
   unsigned char dma;
   unsigned char port;
};

struct ifreq  // Interface request structure used for socket ioctl's
{
   union
   {
      char ifrn_name[16]; // Interface name, e.g. "en0".
   } ifr_ifrn;
   
   union
   {
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


// #include<linux/if.h> // = = = = = = = = = = = = = = = = = =
#define IFNAMSIZ 16
#define ifr_name	ifr_ifrn.ifrn_name	// interface name
#define ifr_hwaddr	ifr_ifru.ifru_hwaddr	// MAC address
#define	ifr_addr	ifr_ifru.ifru_addr	// address
#define ifr_ifindex	ifr_ifru.ifru_ivalue	// interface index


//#include<linux/if_ethernet.h>
#define ETH_ALEN	6		// Octets in one ethernet addr

//#include<linux/if_ether.h>
#define ETH_P_IP	0x0800		// Internet Protocol packet

//#include<ethernet.h>
// This is an Ethernet frame header.
struct ether_header {
   unsigned char ether_dhost[6];  // destination eth addr
   unsigned char ether_shost[6];  // source ether addr
   unsigned short int ether_type; // packet type ID field
};


// #include<linux/ip.h>
struct iphdr {
   unsigned int ihl:4;     // header length (4bits)
   unsigned int version:4; // version (4bits)
   unsigned int tos;       // type of service
   unsigned int tot_len;   // total length
   unsigned int id;        // identification
   unsigned int frag_off;  // fragment offset field
   unsigned int ttl;       // time to live
   unsigned int protocol;  // protocolip
   unsigned int check;     // checksum
   unsigned int saddr;     // source address
   unsigned int daddr;     // dest address
};

// #include<linux/udp.h>
struct udphdr {
   unsigned int source; // source port
   unsigned int dest;   // destination port
   unsigned int len;    // udp length
   unsigned int check;  // udp checksum
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

// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);
struct in_addr {
   unsigned long int s_addr; // Internet address
};

// #include <arpa/inet.h>
extern unsigned int inet_addr(const char *__cp);
extern char *inet_ntoa(struct in_addr __in);

unsigned short csum(unsigned short *buf, int nwords) {
   unsigned long sum;
   for(sum=0; nwords>0; nwords--) sum += *buf++;
   sum = (sum >> 16) + (sum &0xffff);
   sum += (sum >> 16);
   return (unsigned short)(~sum);
}

// #include <unistd.h>
extern int close (int __fd);

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
   int sockfd, tx_len = 0;
   char sendbuf[BUF_SIZ], file_line[50];
   struct ifreq if_idx, if_mac;
   struct ether_header *eh = (struct ether_header *) sendbuf;
   struct sockaddr_ll socket_address;
   
   //struct iphdr *iph = (struct iphdr *) (sendbuf + sizeof(struct ether_header));
   char ifName[IFNAMSIZ];
   
   // Get interface name
   if (argc > 1) strcpy(ifName, argv[1]);
   else          strcpy(ifName, DEFAULT_IF);
   
   // Open RAW socket to send on
   if ((sockfd = socket(AF_PACKET, SOCK_RAW, IPPROTO_RAW)) == -1) {
      sprintf(file_line, "\nTente sudo %s: %s:%d. ERRO", argv[0], __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   // Get the index of the interface to send on
   memset(&if_idx, 0, sizeof(struct ifreq));
   strncpy(if_idx.ifr_name, ifName, IFNAMSIZ-1);
   if (ioctl(sockfd, SIOCGIFINDEX, &if_idx) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   // Get the MAC address of the interface to send on
   memset(&if_mac, 0, sizeof(struct ifreq));
   strncpy(if_mac.ifr_name, ifName, IFNAMSIZ-1);
   if (ioctl(sockfd, SIOCGIFHWADDR, &if_mac) < 0) {
      sprintf(file_line, "\n%s:%d. ERRO", __FILE__, __LINE__ - 1);
      perror(file_line);
   }
   
   // Construct the Ethernet header
   memset(sendbuf, 0, BUF_SIZ);
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
   eh->ether_type = htons(ETH_P_IP); // Ethertype field
   tx_len += sizeof(struct ether_header);
   
   // Packet data
   sendbuf[tx_len++] = 0xde;
   sendbuf[tx_len++] = 0xad;
   sendbuf[tx_len++] = 0xbe;
   sendbuf[tx_len++] = 0xef;
   
   // Index of the network device
   socket_address.sll_ifindex = if_idx.ifr_ifindex;
   // Address length*/
   socket_address.sll_halen = ETH_ALEN;
   // Destination MAC
   socket_address.sll_addr[0] = MY_DEST_MAC0;
   socket_address.sll_addr[1] = MY_DEST_MAC1;
   socket_address.sll_addr[2] = MY_DEST_MAC2;
   socket_address.sll_addr[3] = MY_DEST_MAC3;
   socket_address.sll_addr[4] = MY_DEST_MAC4;
   socket_address.sll_addr[5] = MY_DEST_MAC5;
   
   // Send packet
   if (sendto(sockfd, sendbuf, tx_len, 0, (struct sockaddr*)&socket_address, sizeof(struct sockaddr_ll)) < 0)
       printf("Send failed\n");
   
   return 0;
}

