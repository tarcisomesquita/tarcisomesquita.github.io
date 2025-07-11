
struct in6_addr {
   union {
      unsigned       char   __u6_addr8[16];
      unsigned short int    __u6_addr16[8];
      unsigned long  int    __u6_addr32[4];
   } __u6_addr;                               // 128-bit IP6 address
};

struct ip6_hdr {
   unsigned short int  inicio;
   unsigned short int  inicio2;
   unsigned short int  plen;           // payload length
   unsigned       char nxt;            // next header
   unsigned       char hlim;           // hop limit
   struct in6_addr ip6_src;            // source address
   struct in6_addr ip6_dst;            // destination address
} *ipv6_packet = 0;


int rede_ipv6() {
   ipv6_packet = (struct ip6_hdr *)cache_pos;
   
   printf("\n\nCabeçalho IPv6:\n");
   printf("version  . . . . . . . (04) %u   \n", (unsigned int)((ipv6_packet->inicio & 0x00F0)>>4));
   printf("trafego  . . . . . . . (08) %02X  \n", (unsigned char)(((ipv6_packet->inicio & 0x000F)<<4) + ((ipv6_packet->inicio & 0xF000)>>12)));
   printf("flow . . . . . . . . . (20) %05X  \n", (unsigned int)(((ipv6_packet->inicio & 0x0F00)<<8) + ipv6_packet->inicio2));
   printf("plen . . . . . . . . . (16) 0x%04X  \n", (unsigned int)(htons(ipv6_packet->plen)));
   printf("nxt  . . . . . . . . . (08) %02X       ; ", (unsigned int)(ipv6_packet->nxt));
   if (ipv6_packet->nxt == 0x3A ) printf("ICMPv6\n");
   else                           printf("\n");
   printf("hlim . . . . . . . . . (08) %02X  \n", (unsigned int)(ipv6_packet->hlim));
   
   
//   cache_pos = cache_pos + sizeof(struct ip6_hdr);
//   total = total + sizeof(struct ip6_hdr);
   
//        if (ip_packet->ip_p == 6)    { if (imp_tcp()) return 1; }
//   else if (ip_packet->ip_p == 0x11) { if (imp_udp()) return 1;}
//   else {
   {  
      int falta = pcap_packet_hdr.incl_len - (cache_pos - cache);
      
      printf("\n");
      hexdump_string(total, cache_pos, falta);
      cache_pos = cache_pos + falta;
      total = total + falta;
   }
   
   return 0;
}

/*
2014/07/19  21:07:29.406759  = = = = = = = = = offset = 0x00000234 = = = = = = = = = = = = = =

Pcap_Packet_Header:
ts_sec:           0x53CADE11      ; number of seconds elapsed since 00:00:00 on January 1, 1970
ts_usec:          0x000634E7      ; tempo em microsegundos
incl_len:              00110      ; quantidade de bytes capturados
orig_len:              00110      ; quantidade de bytes que o pacote possuia


Cabeçalho Ethernet:
MAC destination . . . . . (48) 33:33:00:00:00:01
MAC source  . . . . . . . (48) FC:B0:C4:62:CE:F4
Ethertype . . . . . . . . (16) 0x86DD  Internet Protocol, Version 6 (IPv6)


Cabeçalho IPv6:
version  . . . . . . . (04) 6   
trafego  . . . . . . . (08) 00  
flow . . . . . . . . . (20) 00000  
plen . . . . . . . . . (16) 3800  
nxt  . . . . . . . . . (08) 3A  
hlim . . . . . . . . . (08) FF  

00000250        60 00 00 00 00 38  3A FF FE 80 00 00 00 00  |  `....8:.......|
00000260  00 00 FE B0 C4 FF FE 62  CE F4 FF 02 00 00 00 00  |.......b........|
00000270  00 00 00 00 00 00 00 00  00 01 86 00 D2 89 40 40  |..............@@|
00000280  00 00 00 00 00 00 00 00  00 00 03 04 40 C0 FF FF  |............@...|
00000290  FF FF FF FF FF FF 00 00  00 00 FD F4 22 EF E2 81  |............"...|
000002A0  00 01 00 00 00 00 00 00  00 01 01 01 FC B0 C4 62  |...............b|
000002B0  CE F4                                             |..              |

ubuntu@ubuntu:~/Desktop$ tcpdump -vvv -n -r teste.pcap | grep -A 15 '21:07:29'
reading from file teste.pcap, link-type EN10MB (Ethernet)
21:07:29.406759 IP6 (hlim 255, next-header ICMPv6 (58) payload length: 56) fe80::feb0:c4ff:fe62:cef4 > ff02::1: [icmp6 sum ok] ICMP6, router advertisement, length 56
	hop limit 64, Flags [other stateful], pref medium, router lifetime 0s, reachable time 0s, retrans time 0s
	  prefix info option (3), length 32 (4): fdf4:22ef:e281:1::1/64, Flags [onlink, auto], valid time infinitys, pref. time infinitys
	    0x0000:  40c0 ffff ffff ffff ffff 0000 0000 fdf4
	    0x0010:  22ef e281 0001 0000 0000 0000 0001
	  source link-address option (1), length 8 (1): fc:b0:c4:62:ce:f4
	    0x0000:  fcb0 c462 cef4

*/
