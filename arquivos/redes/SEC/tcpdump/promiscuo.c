
// clear ; gcc -Wall -static promiscuo.c -o promiscuo.elf && sudo ifconfig eth0 -promisc && sudo ./promiscuo.elf && sudo ifconfig eth0
// # strace -s 100 -i -f -v ./promiscuo.elf

// #include<sys/ioctl.h> // = = = = = = = = = = = = = = = = = =
extern int ioctl (int __fd, unsigned long int __request, ...);

/* IOCTLs for SCSI.  */
#define SCSI_IOCTL_SEND_COMMAND		1	/* Send a command to the SCSI host.  */
#define SCSI_IOCTL_TEST_UNIT_READY	2	/* Test if unit is ready.  */
#define SCSI_IOCTL_BENCHMARK_COMMAND	3
#define SCSI_IOCTL_SYNC			4	/* Request synchronous parameters.  */
#define SCSI_IOCTL_START_UNIT		5
#define SCSI_IOCTL_STOP_UNIT		6
#define SCSI_IOCTL_DOORLOCK		0x5380	/* Lock the eject mechanism.  */
#define SCSI_IOCTL_DOORUNLOCK		0x5381	/* Unlock the mechanism.  */


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);

// #include <unistd.h>
extern int close (int __fd);

//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *memset(void *__s, int __c, unsigned long int __n);
extern char *strncpy(char *dest, const char *src, unsigned long int n);

// #include <sys/socket.h>
extern int socket(int __domain, int __type, int __protocol);


// #include <bits/socket.h>

// DOMAIN (Protocol Families)
#define   PF_LOCAL        1   // Local to host (pipes and file-domain).  
#define   PF_INET         2   // IP protocol family.  
#define   PF_BRIDGE       7   // Multiprotocol bridge.  
#define   PF_INET6       10   // IP version 6.  
#define   PF_PACKET      17   // Packet family.  
#define   PF_BLUETOOTH   31   // Bluetooth sockets.  

// DOMAIN (Address Families)
#define   AF_PACKET   PF_PACKET
#define   AF_INET     PF_INET
#define   AF_INET6    PF_INET6

//TYPE  Processes communicate only between sockets of the same type.
enum __socket_type {
   SOCK_STREAM =  1,   // Sequenced, reliable, connection-based byte streams. Used in the Internet domain with TCP. 
   SOCK_DGRAM =   2,   // Connectionless, unreliable datagrams of fixed maximum length. Used in the Internet domain with UDP.
   SOCK_RAW =     3,   // Raw protocol interface.  
   SOCK_PACKET = 10    // Linux specific way of getting packets at the dev level.  For writing rarp and other similar things on the user level. 
};

// #include<bits/socket.h> // = = = = = = = = = = = = = = = = = =
struct sockaddr {
   unsigned short int sa_family; // address family and length.
   char sa_data[14];             // Address data.
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
# define ifr_name	ifr_ifrn.ifrn_name	// interface name
# define ifr_hwaddr	ifr_ifru.ifru_hwaddr	// MAC address
# define ifr_addr	ifr_ifru.ifru_addr	// address
# define ifr_dstaddr	ifr_ifru.ifru_dstaddr	// other end of p-p lnk
# define ifr_broadaddr	ifr_ifru.ifru_broadaddr	// broadcast address
# define ifr_netmask	ifr_ifru.ifru_netmask	// interface net mask
# define ifr_flags	ifr_ifru.ifru_flags	// flags
# define ifr_metric	ifr_ifru.ifru_ivalue	// metric
# define ifr_mtu	ifr_ifru.ifru_mtu	// mtu
# define ifr_map	ifr_ifru.ifru_map	// device map
# define ifr_slave	ifr_ifru.ifru_slave	// slave device
# define ifr_data	ifr_ifru.ifru_data	// for use by interface
# define ifr_ifindex	ifr_ifru.ifru_ivalue    // interface index
# define ifr_bandwidth	ifr_ifru.ifru_ivalue	// link bandwidth
# define ifr_qlen	ifr_ifru.ifru_ivalue	// queue length
# define ifr_newname	ifr_ifru.ifru_newname	// New name

// #include<linux/if.h> // = = = = = = = = = = = = = = = = = =
// Standard interface flags (netdevice->flags).
#define	IFF_UP		0x1		/* interface is up		*/
#define	IFF_BROADCAST	0x2		/* broadcast address valid	*/
#define	IFF_DEBUG	0x4		/* turn on debugging		*/
#define	IFF_LOOPBACK	0x8		/* is a loopback net		*/
#define	IFF_POINTOPOINT	0x10		/* interface is has p-p link	*/
#define	IFF_NOTRAILERS	0x20		/* avoid use of trailers	*/
#define	IFF_RUNNING	0x40		/* interface RFC2863 OPER_UP	*/
#define	IFF_NOARP	0x80		/* no ARP protocol		*/
#define	IFF_PROMISC	0x100		/* receive all packets		*/
#define	IFF_ALLMULTI	0x200		/* receive all multicast packets*/

#define IFF_MASTER	0x400		/* master of a load balancer 	*/
#define IFF_SLAVE	0x800		/* slave of a load balancer	*/

#define IFF_MULTICAST	0x1000		/* Supports multicast		*/

#define IFF_PORTSEL	0x2000          /* can set media type		*/
#define IFF_AUTOMEDIA	0x4000		/* auto media select active	*/
#define IFF_DYNAMIC	0x8000		/* dialup device with changing addresses*/

#define IFF_LOWER_UP	0x10000		/* driver signals L1 up		*/
#define IFF_DORMANT	0x20000		/* driver signals dormant	*/

#define IFF_ECHO	0x40000		/* echo sent packets		*/


// = =
#define SIOCSIFFLAGS	0x8914		/* set flags			*/

int main() {
   char in_dev[] = "eth0";
   struct ifreq ifr;
   int skfd, flags = IFF_BROADCAST | IFF_PROMISC | IFF_MULTICAST;

   if ((skfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
      printf("Failed to create AF_INET DGRAM socket.\n\n");
      return 1;
   }
   
   // Fetch interface flags
   memset(&ifr, 0, sizeof ifr);
   strncpy(ifr.ifr_name, in_dev, sizeof(ifr.ifr_name)-1);
   ifr.ifr_flags = flags;
   if (ioctl(skfd, SIOCSIFFLAGS, &ifr) < 0) {
      printf("Failed Set IFFlags\n\n");
      close(skfd);
      return 1;
   }
   
   close(skfd);
   return 0;
}


