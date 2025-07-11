// rm mac.c ; cat mac_gen.c | sed ' s/A1//g; s/A2//g; s/A3//g; s/A4//g; s/A5//g; s/A6//g; s/IA1//g; s/IA2//g; s/IA3//g; s/IA4//g; s/E1//g; s/E2//g; s/E3//g; s/E4//g; s/E5//g; s/E6//g; s/IE1//g; s/IE2//g; s/IE3//g; s/IE4//g;' > mac.c ; gcc -Wall mac.c -o mac.elf && sudo ./mac.elf

// man 7 netdevice 
// Packet sockets are not subject to the input or output firewall chains.
// man 2 process_vm_writev  permite alterar um processo na memória

#define PF_PACKET 17 // Packet family.
#define SOCK_RAW 3
// SOCK_RAW packets are passed to and from the device driver without any changes in the packet data.
// SOCK_DGRAM, the physical header is removed before the packet is passed to  the  user. 

// protocol
// linux/if_ether.h
#define ETH_P_LOOP 0x0060  // Ethernet Loopback packet
#define ETH_P_IP   0x0800  // Internet Protocol packet
#define ETH_P_ARP  0x0806  // Address Resolution packet
#define ETH_P_RARP 0x8035  // Reverse Addr Res packet
#define ETH_P_ALL  0x0003  // Every packet (be careful!!!)
// htons (ETH_P_ALL) = 0x0300
// When protocol is set to htons(ETH_P_ALL) all protocols are received.  All incoming packets will be passed to socket before they are passed to the protocols implemented in the kernel.


// #include <bits/socket.h> // = = = = = = = = = = = = = = = = = = = = = = = = 
// Structure describing a generic socket address.
struct sockaddr {
   unsigned short int sa_family; // Address family and length.
   char sa_data[18];             // Address data.
};

// linux/if_packet.h // (see man 7 packet)
// link level
struct sockaddr_ll {
   unsigned short int sll_family;
   unsigned short int sll_protocol;
                  int sll_ifindex;
   unsigned short int sll_hatype;
   unsigned char      sll_pkttype;
   unsigned char      sll_halen;
   unsigned char      sll_addr[8];
};
// When  you  send  packets,  it is enough to specify sll_family, sll_addr, sll_halen, sll_ifindex, and sll_protocol.  The other fields        should be 0.  sll_hatype and sll_pkttype are set on received packets for your information.

//#include <sys/socket.h>
extern int socket(int domain, int type, int protocol);
extern long int sendto(int fd, void *buf, unsigned long int n, int flags, struct sockaddr *addr, unsigned int addr_len);

//#include<net/if.h>
// Convert an interface name to an index.
extern unsigned int if_nametoindex(char *ifname);

//#include <unistd.h>
extern int close(int fd);
extern int usleep(unsigned int useconds);

extern int printf(char *, ...);
extern void perror(char *);

//  #include <netinet/ip.h>  // IP_MAXPACKET (which is 65535)
unsigned char p[65535];

int main() {
   unsigned char n;
   int sd, frame_length;
   long int bytes;
   struct sockaddr_ll device = {0x0011, 0x0000, 0x00000000, 0x0000, 0x00, 0x06, {0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0x00, 0x00} };
   //device.sll_family = PF_PACKET; // 17 = 0x11
   //device.sll_halen = 6;
   
   device.sll_ifindex = if_nametoindex("enp7s0");
   if (device.sll_ifindex == 0) {
      printf("\nERRO: if_nametoindex() failed to obtain interface index\n\n");
      return 1;
   }
   

/*
// Cabeçalho Ethernet:
MAC destination . . . . . (48) FF:FF:FF:FF:FF:FF
MAC source  . . . . . . . (48) E0:34:01:00:30:22
Ethertype . . . . . . . . (16) 0x0806  Address Resolution Protocol (ARP)
*/
   
   p[ 0] = 0xE1; p[ 1] = 0xE2; p[ 2] = 0xE3; p[ 3] = 0xE4; p[ 4] = 0xE5; p[ 5] = 0xE6;  // MAC destination
   p[ 6] = 0xA1; p[ 7] = 0xA2; p[ 8] = 0xA3; p[ 9] = 0xA4; p[10] = 0xA5; p[11] = 0xA6;  // MAC source
   p[12] = 0x08; p[13] = 0x06;                                                          // Ethertype ARP
   

/*
Cabeçalho ARP
Hardware type (HTYPE) . . . . . .(16)  0x0001   Ethernet
Protocol type (PTYPE) . . . . . .(16)  0x0800   IPv4
Hardware address length (HLEN) . (08)  0x06     
Protocol address length (PLEN) . (08)  0x04     
Operation (OPER) . . . . . . . . (16)  0x0001   request
Sender hardware address (SHA) . .(48)  E0:34:01:00:30:22
Sender protocol address (SPA) . .(32)  192.168.1.252
Target hardware address (SHA) . .(48)  00:00:00:00:00:00
Target protocol address (SPA) . .(32)  192.168.1.132
*/ 
   
   p[14] = 0x00; p[15] = 0x01;  // Hardware type
   p[16] = 0x08; p[17] = 0x00;  // Protocol type
   p[18] = 0x06;  // Hardware address length
   p[19] = 0x04;  // Protocol address length
   p[20] = 0x00; p[21] = 0x02; // reply
   p[22] = 0xA1; p[23] = 0xA2; p[24] = 0xA3; p[25] = 0xA4; p[26] = 0xA5; p[27] = 0xA6;   // Sender hardware address
   p[28] = IA1;  p[29] = IA2;  p[30] = IA3;  p[31] = IA4;                                // Sender protocol address
   p[32] = 0xE1; p[33] = 0xE2; p[34] = 0xE3; p[35] = 0xE4; p[36] = 0xE5; p[37] = 0xE6;   // Target hardware address
   p[38] = IE1;  p[39] = IE2;  p[40] = IE3;  p[41] = IE4;                                // Target protocol address
   
   frame_length = 42 + 12; // o driver wireless acrescrenta um header de 12 bytes

   // Submit request for a raw socket descriptor.
   sd = socket(PF_PACKET, SOCK_RAW, 0x0300);
   //sd = socket(PF_PACKET, SOCK_RAW, 0x0806);
   if (sd < 0) {
      printf("\nERRO: socket() failed\n\n");
      return 1;
   }
   
   n = 2;
   for ( ; ; ) {
      p[31] = n;
      bytes = 0;
      bytes = sendto(sd, p, frame_length, 0, (struct sockaddr *)&device, sizeof(device)); // Send ethernet frame to socket.
      if (bytes <= 0) {
         perror("> ");
         printf("\nERRO: sendto() failed\n\n");
         return 1;
      }
      n++;
      if (n == 255) { n = 2; usleep(500);}
   }
   close(sd);
   
   return 0;
}

