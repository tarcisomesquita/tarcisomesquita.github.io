/*
IP header: 20 bytes 
 .-------+-------+---------------+-------------------------------.
 |Version|  IHL  |Type of Service|          Total Length         |
 |-------+-------+---------------+-------------------------------|
 |         Identification        |Flags|      Fragment Offset    |
 |---------------+---------------+-------------------------------|
 |  Time to Live |    Protocol   |         Header Checksum       |
 |---------------+---------------+-------------------------------|
 |                       Source Address                          |
 |---------------------------------------------------------------|
 |                    Destination Address                        |
 `---------------------------------------------------------------'
*/

struct ipv4 {
   unsigned char      ip_vlh;      // version and header length
   unsigned char      ip_tos;      // type of service
   unsigned short int ip_len;      // total length
   unsigned short int ip_id;       // identification
   unsigned short int ip_off;      // fragment offset field
   unsigned char      ip_ttl;      // time to live
   unsigned char      ip_p;        // protocolip
   unsigned short int ip_sum;      // checksum
   unsigned char      ip_src[4];   // source address
   unsigned char      ip_dst[4];   //dest address
} *ip_packet = 0;


int rede_ip() {
   ip_packet = (struct ipv4 *)cache_pos;
   
   printf("\n\nCabeçalho IP:\n");
   printf("version  . . . . . . . (04) %u   ", (unsigned char)(ip_packet->ip_vlh>>4));
   if((ip_packet->ip_vlh>>4) == 4) printf("ipv4\n");
   
   printf("header length  . . . . (04) %u   (words de 4 bytes)\n", (unsigned char)(ip_packet->ip_vlh&0x0F));
   
   printf("TOS  . . . . . . . . . (08) %u\n", (unsigned char)ip_packet->ip_tos);
   
   printf("total length . . . . . (16) %u\n", htons(ip_packet->ip_len));
   
   printf("identification . . . . (16) %u\n", htons(ip_packet->ip_id));
   
   printf("flags  . . . . . . . . (03) %u ", (htons(ip_packet->ip_off))>>12);
   if (((htons(ip_packet->ip_off))>>12)&0x04) printf("tem mais fragmentos\n"); 
   else if (((htons(ip_packet->ip_off))>>12)&0x02) printf("não pode fragmentar\n");
   else printf("\n");
   
   printf("fragment offset  . . . (13) %u \n", (htons(ip_packet->ip_off))&0x0FFF);
   
   printf("TTL  . . . . . . . . . (08) %u \n", ip_packet->ip_ttl);
   
   printf("protocol . . . . . . . (08) %u ", ip_packet->ip_p);
   if(ip_packet->ip_p == 1) printf("ICMP\n");
   else if(ip_packet->ip_p == 6) printf("TCP\n");
   else if(ip_packet->ip_p == 0x11) printf("UDP\n");
   else printf(" DESCONHECIDO\n");
   
   printf("header checksum  . . . (16) 0x%02X\n", htons(ip_packet->ip_sum));
   
   printf("source address . . . . (32) %u.%u.%u.%u\n", \
                    ip_packet->ip_src[0], ip_packet->ip_src[1], ip_packet->ip_src[2], ip_packet->ip_src[3]);
   
   printf("destination address  . (32) %u.%u.%u.%u\n", \
                    ip_packet->ip_dst[0], ip_packet->ip_dst[1], ip_packet->ip_dst[2], ip_packet->ip_dst[3]);
   
   cache_pos = cache_pos + sizeof(struct ipv4);
   total = total + sizeof(struct ipv4);
   
        if (ip_packet->ip_p == 1)    { if (imp_icmp()) return 1; }
   else if (ip_packet->ip_p == 6)    { if (imp_tcp()) return 1; }
   else if (ip_packet->ip_p == 0x11) { if (imp_udp()) return 1;}
   else {
      int falta = pcap_packet_hdr.incl_len - (cache_pos - cache);
      
      printf("\n");
      hexdump_string(total, cache_pos, falta);
      cache_pos = cache_pos + falta;
      total = total + falta;
   }
   
   return 0;
}

