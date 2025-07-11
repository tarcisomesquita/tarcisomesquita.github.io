/*
802.3 Ethernet frame structure 10/100Mbps
Preamble: 7 octets of 10101010 = 0xAA
Start of frame delimiter: 1 octet of 10101011 = 0xAB
MAC destination: 6 octetsrede_stp
MAC source: 6 octets
Ethertype or length: 2 octets
Payload (Dados): 46–1500 octets
Frame check sequence (32-bit CRC - Cyclic Redundancy Check): 4 octets
Interframe gap: 12 octets
*/

char s_Ethe_1[] = "MAC destination . . . . . (48)";
char s_Ethe_2[] = "MAC source  . . . . . . . (48)";
char s_Ethe_3[] = "Ethertype . . . . . . . . (16)";

// This is an Ethernet frame header.
struct ethhdr {
   unsigned char h_dest[6];    // destination eth addr
   unsigned char h_src[6];     // source ether addr
   unsigned short int h_proto; // packet type ID field
} *ether_hdr = 0x00000000;


int enlace_ethernet() {
   ether_hdr = (struct ethhdr *)cache_pos;
   
   printf("\n\nCabeçalho Ethernet:\n");
   printf("%s %02X:%02X:%02X:%02X:%02X:%02X\n", s_Ethe_1, \
              ether_hdr->h_dest[0], ether_hdr->h_dest[1], ether_hdr->h_dest[2], ether_hdr->h_dest[3], ether_hdr->h_dest[4], ether_hdr->h_dest[5]);
   printf("%s %02X:%02X:%02X:%02X:%02X:%02X\n", s_Ethe_2, \
              ether_hdr->h_src[0], ether_hdr->h_src[1], ether_hdr->h_src[2], ether_hdr->h_src[3], ether_hdr->h_src[4], ether_hdr->h_src[5]);
   printf("%s 0x%04X", s_Ethe_3, (unsigned int)htons(ether_hdr->h_proto));
/*
/usr/include/linux/if_ether.h
EtherType 	Protocol
0x8035 	Reverse Address Resolution Protocol (RARP)
If the value is less than 0600 then the field indicates Length.
*/
        if (htons(ether_hdr->h_proto) == 0x0027) printf("  Extensão: ");
   else if (htons(ether_hdr->h_proto) == 0x0806) printf("  Address Resolution Protocol (ARP)\n");
   else if (htons(ether_hdr->h_proto) == 0x0800) printf("  Internet Protocol, Version 4 (IPv4)\n");
   else if (htons(ether_hdr->h_proto) == 0x8863) printf("  PPPoE Discovery Message\n");
   else if (htons(ether_hdr->h_proto) == 0x8864) printf("  PPPoE Session Message\n");
   else if (htons(ether_hdr->h_proto) == 0x86DD) printf("  Internet Protocol, Version 6 (IPv6)\n");
   else                   printf("  EtherType DESCONHECIDO\n");
   
   total = total + sizeof(struct ethhdr);
   cache_pos = cache_pos + sizeof(struct ethhdr);
   
   if(htons(ether_hdr->h_proto) == 0x0027) {
      if (cache_pos[0] == 0x42 && cache_pos[1] == 0x42  && cache_pos[2] == 0x03) {
         printf("  Spanning Tree Protocol (STP)\n");
         cache_pos = cache_pos + 3;
         if(rede_stp()) return 1;
      }
      else { printf("Verifique isso!\n"); return 1;}  
   }
   else if(htons(ether_hdr->h_proto) == 0x0806) {
      if(rede_arp()) return 1;
   }
   else if(htons(ether_hdr->h_proto) == 0x0800) {
      if(rede_ip()) return 1;
   }
   else if(htons(ether_hdr->h_proto) == 0x8864) {
//      if(imp_ppp()) return 1;
      total = total + pcap_packet_hdr.incl_len;
   }
   else if(htons(ether_hdr->h_proto) == 0x86DD) {
      if(rede_ipv6()) return 1;
      total = total + pcap_packet_hdr.incl_len;
   }
   else {
      printf("\n");
      hexdump_string(total + 0, cache, pcap_packet_hdr.incl_len);
      total = total + pcap_packet_hdr.incl_len;
   }
   
   return 0;
}

