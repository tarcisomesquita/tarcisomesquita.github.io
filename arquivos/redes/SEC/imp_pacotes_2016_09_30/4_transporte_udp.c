
//#include <netinet/udp.h>      // struct udphdr
struct udphdr {
   unsigned short int source;   // source port
   unsigned short int dest;     // destination port
   unsigned short int len;      // udp length
   unsigned short int check;    // udp checksum
} *udp_packet = 0x00000000;

int imp_udp() {
   udp_packet = (struct udphdr *)cache_pos;
   
   printf("\n\nCabeçalho UDP:\n");
   printf("source port  . . . . . (16) %u\n", htons(udp_packet->source));
   printf("destination port . . . (16) %u\n", htons(udp_packet->dest));
   printf("lenght . . . . . . . . (16) %u\n", htons(udp_packet->len));
   printf("checksum . . . . . . . (16) %u\n", htons(udp_packet->check));
   
   cache_pos = cache_pos + sizeof(struct udphdr);
   total = total + sizeof(struct udphdr);
   
   if (htons(udp_packet->source) == 53 || htons(udp_packet->dest) == 53) {
      if (imp_dns()) return 1;
   }
   else {
      int falta = pcap_packet_hdr.incl_len - (cache_pos - cache);
      
      printf("\n");
      hexdump_string(total, cache_pos, falta);
      cache_pos = cache_pos + falta;
      total = total + falta;
   }
   return 0;
}

