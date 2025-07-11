/*

Nome                             Número de bits
Hardware type (HTYPE) . . . . . .(16 bits)
Protocol type (PTYPE) . . . . . .(16 bits)
Hardware address length (HLEN) . (8 bits)
Protocol address length (PLEN) . (8 bits)
Operation (OPER) . . . . . . . . (16 bits)
Sender hardware address (SHA) . .(3*16 bits)
Sender protocol address (SPA) . .(2*16 bits)
Target hardware address (THA) . .(3*16 bits)
Target protocol address (TPA) . .(2*16 bits)

Hardware type (HTYPE)
Specifies the Link Layer protocol type.
Example: Ethernet is 1.

Protocol type (PTYPE)
Specifies the upper layer protocol for which the ARP request is intended. For IPv4, this has the value 0x0800. The permitted PTYPE values share a numbering space with those for Ethertype.

Hardware length (HLEN)
Length (in octets) of a hardware address. Ethernet addresses size is 6.

Protocol length (PLEN)
Length (in octets) of addresses used in the upper layer protocol. (The upper layer protocol specified in PTYPE.) IPv4 address size is 4.

Operation 
Specifies the operation that the sender is performing: 1 for request, 2 for reply.

Sender hardware address (SHA)
Hardware (MAC) address of the sender.

Sender protocol address (SPA)
Upper layer protocol address of the sender.

Target hardware address (THA)
Hardware address of the intended receiver. This field is ignored in requests.

Target protocol address (TPA)
Upper layer protocol address of the intended receiver.

Exemplo:
sudo tcpdump -i wlan0 -e -s 0 -w arp.pcap &

sudo arping -q -c 1  -I wlan0 192.168.0.1

sudo kill `pidof tcpdump`

./imp_pacotes.elf arp.pcap > arp.txt

*/


// #include <sys/socket.h>

struct in_addr {
   unsigned long int s_addr; // Internet address
};

// #include <arpa/inet.h>
extern int inet_aton(const char *CP, struct in_addr *INP);


// See RFC 826 for protocol description.
//  ARP packets are variable in size; the arphdr structure defines the fixed-length portion.

struct arphdr {
   unsigned short int ar_hrd;   // Format of hardware address.
   unsigned short int ar_pro;   // Format of protocol address.
   unsigned char ar_hln;        // Length of hardware address.
   unsigned char ar_pln;        // Length of protocol address.
   unsigned short int ar_op;    // ARP opcode (command).
   unsigned char ar_sha[6];     // Sender hardware address.
   unsigned char ar_sip[4];     // Sender IP address.
   unsigned char ar_tha[6];     // Target hardware address.
   unsigned char ar_tip[4];     // Target IP address.
} *arp_hdr = 0x00000000;

int rede_arp() {
   int falta;
   
   arp_hdr = (struct arphdr *)cache_pos;
   
   printf("\n\nCabeçalho ARP\n");
   printf("Hardware type (HTYPE) . . . . . .(16)  0x%04X   ", (unsigned int)htons(arp_hdr->ar_hrd));
   if (htons(arp_hdr->ar_hrd) == 0x0001) printf("Ethernet\n");
   else  printf("Desconhecido\n");
   
   printf("Protocol type (PTYPE) . . . . . .(16)  0x%04X   ", (unsigned int)htons(arp_hdr->ar_pro));
   if (htons(arp_hdr->ar_pro) == 0x0800) printf("IPv4\n");
   else  printf("Desconhecido\n");
   
   printf("Hardware address length (HLEN) . (08)  0x%02X     \n", (unsigned int)arp_hdr->ar_hln);
   printf("Protocol address length (PLEN) . (08)  0x%02X     \n", (unsigned int)arp_hdr->ar_pln);
   
   printf("Operation (OPER) . . . . . . . . (16)  0x%04X   ", (unsigned int)htons(arp_hdr->ar_op));
   if (htons(arp_hdr->ar_op) == 0x0001) printf("request\n");
   else if (htons(arp_hdr->ar_op) == 0x0002) printf("reply\n");
   else  printf("Desconhecido\n");
   
   printf("Sender hardware address (SHA) . .(48)  %02X:%02X:%02X:%02X:%02X:%02X\n", \
                    arp_hdr->ar_sha[0], arp_hdr->ar_sha[1], arp_hdr->ar_sha[2], arp_hdr->ar_sha[3], arp_hdr->ar_sha[4], arp_hdr->ar_sha[5]);
   
   printf("Sender protocol address (SPA) . .(32)  %u.%u.%u.%u\n", \
                    arp_hdr->ar_sip[0], arp_hdr->ar_sip[1], arp_hdr->ar_sip[2], arp_hdr->ar_sip[3]);
   
   printf("Target hardware address (SHA) . .(48)  %02X:%02X:%02X:%02X:%02X:%02X\n", \
                    arp_hdr->ar_tha[0], arp_hdr->ar_tha[1], arp_hdr->ar_tha[2], arp_hdr->ar_tha[3], arp_hdr->ar_tha[4], arp_hdr->ar_tha[5]);
   
   printf("Target protocol address (SPA) . .(32)  %u.%u.%u.%u\n", \
                    arp_hdr->ar_tip[0], arp_hdr->ar_tip[1], arp_hdr->ar_tip[2], arp_hdr->ar_tip[3]);
   
   total = total + sizeof(struct arphdr);
   cache_pos = cache_pos + sizeof(struct arphdr);
   
   falta = pcap_packet_hdr.incl_len - (cache_pos - cache);
   
   if (falta) {
      printf("\n");
      hexdump_string(total, (unsigned char *)cache_pos, falta);
      total = total + falta;
   }
   
   return 0;
}

