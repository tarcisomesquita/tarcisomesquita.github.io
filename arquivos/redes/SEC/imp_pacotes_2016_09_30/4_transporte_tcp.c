
/*
TCP header: 20 bytes
 .-------------------------------+-------------------------------.
 |          Source Port          |       Destination Port        |
 |-------------------------------+-------------------------------|
 |                        Sequence Number                        |
 |---------------------------------------------------------------|
 |                    Acknowledgment Number                      |
 |-------------------+-+-+-+-+-+-+-------------------------------|
 |  Data |           |U|A|P|R|S|F|                               |
 | Offset| Reserved  |R|C|S|S|Y|I|            Window             |
 |       |           |G|K|H|T|N|N|                               |
 |-------+-----------+-+-+-+-+-+-+-------------------------------|
 |           Checksum            |         Urgent Pointer        |
 `---------------------------------------------------------------'
*/

struct tcp {
   unsigned short int tcp_sp;   // source port
   unsigned short int tcp_dp;   // destination port
   unsigned       int tcp_sn;   // sequence number
   unsigned       int tcp_an;   // acknowledgment number
   unsigned char      tcp_hl;   // header length (bit 7 a 4)
   unsigned char      tcp_fl;   // flags (bit 5 a 0)
   unsigned short int tcp_win;  // window size
   unsigned short int tcp_sum;  // TCP checksum
   unsigned short int tcp_urgp; // urgent pointer
} *tcp_packet = 0;

int imp_tcp() {
   unsigned char      opt_len, i, j;
   unsigned short int *n1;
   unsigned long  int *n2;
   int falta;
   unsigned char *opt_tcp = 0x00000000;
   
   tcp_packet = (struct tcp *)cache_pos;
   
   printf("\n\nCabeçalho TCP:\n");
   
   printf("source port . . . . . .(16) %u\n", htons(tcp_packet->tcp_sp));
   
   printf("destination port . . . (16) %u\n", htons(tcp_packet->tcp_dp));
   
   printf("sequence number . . . .(32) %lu\n", htonl(tcp_packet->tcp_sn));
   
   printf("acknowledgment number .(32) %u\n", htons(tcp_packet->tcp_an));
   
   printf("header length . . . . .(04) %u DWORD\n", (unsigned char)(tcp_packet->tcp_hl>>4));
   
   printf("flags . . . . . . . . .(06) 0x%02X ", (unsigned char)tcp_packet->tcp_fl);
   if (tcp_packet->tcp_fl&0x40) printf("CWR | "); 
   if (tcp_packet->tcp_fl&0x20) printf("ECE | "); 
   if (tcp_packet->tcp_fl&0x10) printf("ACK | "); 
   if (tcp_packet->tcp_fl&0x08) printf("PUSH | "); 
   if (tcp_packet->tcp_fl&0x04) printf("RST | "); 
   if (tcp_packet->tcp_fl&0x02) printf("SYN | "); 
   if (tcp_packet->tcp_fl&0x01) printf("FIN | "); 
   printf("\n");
   
   printf("window size . . . . . .(16) %u\n", htons(tcp_packet->tcp_win));
   
   printf("TCP checksum . . . . . (16) %u\n", htons(tcp_packet->tcp_sum));
   
   printf("urgent pointer . . . . (16) %u\n", htons(tcp_packet->tcp_urgp));
   
   cache_pos = cache_pos + sizeof(struct tcp);
   total = total + sizeof(struct tcp);
   
   // Options
   opt_len = 0;
   opt_len = (tcp_packet->tcp_hl>>4)*4 - sizeof(struct tcp);
   
   if (opt_len) {
      opt_tcp = cache_pos;
      printf("\nTCP options:\n");
      for (i = 0; i < opt_len; ) {
         if (opt_tcp[i] == 0) {
            printf("0   End of option list.\n");
            i = i + 1;
         }
         else if (opt_tcp[i] == 1) {
            printf("1   No operation.\n");
            i = i + 1;
         }
         else if (opt_tcp[i] == 2) {
            printf("2   MSS, Maximum Segment Size = ");
            if (opt_tcp[i+1] != 4) {
               printf("\n\nERRO, comprimento != 4\n\n");
               return 1;
            }
            n1 = (unsigned short int *)&opt_tcp[i+2];
            printf("%u\n", htons(*n1));
            i = i + opt_tcp[i+1];
         }
         else if (opt_tcp[i] == 3) {
            printf("3   WSOPT, Window scale factor = ");
            if (opt_tcp[i+1] != 3) {
               printf("\n\nERRO, comprimento != 3\n\n");
               return 1;
            }
            printf("%u\n", opt_tcp[i+2]);
            i = i + opt_tcp[i+1];
         }
         else if (opt_tcp[i] == 4) {
            printf("4   SACK (Selective Acknowledgement) permitted\n");
            if (opt_tcp[i+1] != 2) {
               printf("\n\nERRO, comprimento != 2\n\n");
               return 1;
            }
            i = i + opt_tcp[i+1];
         }
         else if (opt_tcp[i] == 5) {
            printf("5   SACK\n");
            if ((opt_tcp[i+1]-2)%4) {
               printf("\n\nERRO, comprimento não é multiplo de DWORD\n\n");
               return 1;
            }
            for (j = 0; j < ((opt_tcp[i+1]-2)/4); j++) {
               n2 = (unsigned long int *)&opt_tcp[i+2+j*4+0];
               printf("    %lu\n", htonl(*n2));
            }
            i = i + opt_tcp[i+1];
         }
         else if (opt_tcp[i] == 6) {
            printf("6   ECHO   ");
            if (opt_tcp[i+1] != 6) {
               printf("\n\nERRO, comprimento != 6\n\n");
               return 1;
            }
            n2 = (unsigned long int *)&opt_tcp[i+2+0];
            printf("    %lu\n", htonl(*n2));
            i = i + opt_tcp[i+1];
         }
         else if (opt_tcp[i] == 7) {
            printf("7   ECHO reply   ");
            if (opt_tcp[i+1] != 6) {
               printf("\n\nERRO, comprimento != 6\n\n");
               return 1;
            }
            n2 = (unsigned long int *)&opt_tcp[i+2+0];
            printf("    %lu\n", htonl(*n2));
            i = i + opt_tcp[i+1];
         }
         else if (opt_tcp[i] == 8) {
            printf("8   TSOPT\n");
            if (opt_tcp[i+1] != 10) {
               printf("\n\nERRO, comprimento != 10\n\n");
               return 1;
            }
            n2 = (unsigned long int *)&opt_tcp[i+2+0];
            printf("    Timestamp Value:      %lu\n", htonl(*n2));
            
            n2 = (unsigned long int *)&opt_tcp[i+2+4];
            printf("    Timestamp Echo Reply: %lu\n", htonl(*n2));
            i = i + opt_tcp[i+1];
         }
         else {
            printf("%u   PROGRAME ISSO  ", opt_tcp[i]);
            for (j = 0; j < (opt_tcp[i+1]-2); j++) {
               printf("%02X ", opt_tcp[i+2+j]);
            }
            printf("\n");
            i = i + opt_tcp[i+1];
         }
      }
   }
   
   cache_pos = cache_pos + opt_len;
   total = total + opt_len;
   
   falta = pcap_packet_hdr.incl_len - (cache_pos - cache);
   if (falta) {
      if (htons(tcp_packet->tcp_dp) == 443 || htons(tcp_packet->tcp_sp) == 443) { if (aplicacao_https()) return 1; }
      else {
         printf("\n");
         hexdump_string(total, cache_pos, falta);
         
         total = total + falta;
         cache_pos = cache_pos + falta;
      }
   }
   
   return 0;
}

