
//#include "imp_tcp.c"
/*
struct pppoe_tag {
   unsigned short tag_type;
   unsigned short tag_len;
   char tag_data[0];
} __attribute ((packed));
*/
struct pppoe_hdr {
   unsigned char ver : 4;      // Must be set to 1
   unsigned char type : 4;     // Must be set to 1
   unsigned char code;         // Code
   unsigned short sid;         // Session ID
   unsigned short length;      // length of packet
   unsigned short protocol;    // ?
//   struct pppoe_tag tag[0];
} *pppoe_packet = 0; ;


int imp_ppp() {
   unsigned char      c;
   unsigned short int *n1;
   if ((int)(nc_f-nc_i) < sizeof(struct pppoe_hdr) && end_of_file == 0 ) if (enche_cache()) return 1;
   
   if ((int)(nc_f-nc_i) < sizeof(struct pppoe_hdr) ) {
      fprintf(stderr, "\nERRO. O tamanho dos dados é menor que o tamanho do cabeçalho de um pacote pppoe.\n\n");
      return 1;
   }
   
   if (! (pppoe_packet = malloc((long unsigned int)sizeof(struct pppoe_hdr)))) {
      fprintf(stderr, "\nERRO não foi possível alocar %d bytes para o struct pppoe_packet.\n\n", sizeof(struct pppoe_hdr));
      return 1;
   }
   
   pppoe_packet->ver = (cache[nc_i]&0xF0)>>4;
   
   pppoe_packet->type = cache[nc_i]&0x0F;
   
   pppoe_packet->code = cache[nc_i+1];
   
   c = cache[nc_i+2] ; cache[nc_i+2] = cache[nc_i+3]; cache[nc_i+3] = c;
   n1 = (unsigned short int *)&cache[nc_i+2];
   pppoe_packet->sid = *n1;
   
   c = cache[nc_i+4] ; cache[nc_i+4] = cache[nc_i+5]; cache[nc_i+5] = c;
   n1 = (unsigned short int *)&cache[nc_i+4];
   pppoe_packet->length = *n1;
   
   c = cache[nc_i+6] ; cache[nc_i+6] = cache[nc_i+7]; cache[nc_i+7] = c;
   n1 = (unsigned short int *)&cache[nc_i+6];
   pppoe_packet->protocol = *n1;
   
   fprintf(stdout, "\n\nCabeçalho PPPoE:\n");
   
   fprintf(stdout, "version . . . . . . . (04) %u   ", pppoe_packet->ver);
   if(pppoe_packet->ver != 1) {
      fprintf(stdout, "Deveria ser 1.\n");
      return 1;
   }
   else fprintf(stdout, "valor fixo\n");
   
   fprintf(stdout, "type  . . . . . . . . (04) %u   ", pppoe_packet->type);
   if(pppoe_packet->ver != 1) {
      fprintf(stdout, "Deveria ser 1.\n");
      return 1;
   }
   else fprintf(stdout, "valor fixo\n");
   
   fprintf(stdout, "code  . . . . . . . . (08) %u\n", (unsigned char)pppoe_packet->code);
   
   fprintf(stdout, "session_id  . . . . . (16) %u\n", pppoe_packet->sid);
   
   fprintf(stdout, "data_lenght . . . . . (16) %u\n", pppoe_packet->length);
   
   if (pppoe_packet->protocol == 0x8021) {
      fprintf(stdout, "protocolo   . . . . . (16) 0x8021   Internet Protocol (IP)\n");
   }
   else if (pppoe_packet->protocol == 0xC021) {
      fprintf(stdout, "protocolo   . . . . . (16) 0xC021   Link Control Protocol (LCP)\n");
   }
   else if (pppoe_packet->protocol == 0xC023) {
      fprintf(stdout, "protocolo   . . . . . (16) 0xC023   Password Authentication Protocol (PAP)\n");
   }
   else fprintf(stdout, "protocolo?  . . . . . (16) 0x%04X\n", pppoe_packet->protocol);
   
   nc_i = nc_i + sizeof(struct pppoe_hdr);
   ja_imp = ja_imp + sizeof(struct pppoe_hdr);
   
   if ((pppoe_packet->code == 0) && (pppoe_packet->protocol == 0x0021)) {
      if (imp_ip()) return 1;
   }
   else {
      if ((nc_f-nc_i) < (pcap_packet_hdr->incl_len - ja_imp) && end_of_file == 0 ) if (enche_cache()) return 1;
      
      if ((nc_f-nc_i) < (pcap_packet_hdr->incl_len - ja_imp)) {
         fprintf(stderr, "\nERRO. O tamanho dos dados é menor que o tamanho capturado do pacote.\n\n");
         return 1;
      }
      
      fprintf(stdout, "\n");
      hexdump_string(stdout, file_offset, cache, nc_i, pcap_packet_hdr->incl_len - ja_imp);
      nc_i = nc_i + pcap_packet_hdr->incl_len - ja_imp;
   }
   free(pppoe_packet);
   return 0;
}

