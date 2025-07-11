extern int getchar(void);

struct dns_hdr {
   unsigned short int id;             // Identificação         
   unsigned short int op;             // Várias flags
   unsigned short int n_questions;    // Number of Questions
   unsigned short int n_answers;      // Number of Answers
   unsigned short int n_authority;    // Number of Authority
   unsigned short int n_additional;   // Number of Additional
} *dns_packet = 0x00000000;

int imp_name() {
   unsigned char c, *string, compacto;
   unsigned short int j;
   
   compacto = 0x00;
   string = (unsigned char *)cache_pos;
   c = string[0];
   string = string + 1;
   
   for (;;) {
      if ((c & 0xC0) == 0xC0) {
         unsigned short int pos;
         unsigned short int avanco;
         
         pos = htons(*((unsigned short int *)(string - 1))) & 0x3FFF;
         avanco = string + 1 - cache_pos;
         
         if (compacto == 0x00) {
            total = total + avanco;
            cache_pos = cache_pos + avanco;
         }
         
         string = (unsigned char *)dns_packet;
         string = string + pos;
         
         c = string[0];
         string = string + 1;
         
         compacto = 0x01;
         continue;
      }
      else if (c == 0x00) {
         unsigned short int avanco;
         
         if (compacto == 0x01) return 0;
         
         avanco = string - cache_pos;
         
         total = total + avanco;
         cache_pos = cache_pos + avanco;
         
         return 0;
      }
      
      for (j=0; j < c; j++) printf("%c", string[j]);
      printf(".");
      
      string = string + c;
      c = string[0];
      string = string + 1;
   }
   
   return 0;
}


int imp_dns() {
   unsigned short int i, type;
   
   dns_packet = (struct dns_hdr *)cache_pos;
   
   printf("\n\nCabeçalho DNS:\n");
   
   printf("Identificação  . . . . (16) %u\n", htons(dns_packet->id));
   
   if(htons(dns_packet->op) & 0x8000) printf("OP . . . . . . . . . . (01) 1      Response\n");
   else printf("OP . . . . . . . . . . (01) 0      Query\n");
   
   printf("QueryType              (04) %d      ", ( (htons(dns_packet->op) & 0x7800)>>11));
   if      (((htons(dns_packet->op) & 0x7800)>>11) == 0) printf("query\n");
   else if (((htons(dns_packet->op) & 0x7800)>>11) == 1) printf("inverse query\n");
   else if (((htons(dns_packet->op) & 0x7800)>>11) == 2) printf("server status request\n");
   else                                                  printf("reserved\n");
   
   if(htons(dns_packet->op) & 0x0400) printf("AA                     (01) 1      answer authoritive\n");
   else                               printf("AA                     (01) 0      answer not authoritive\n");
   
   if(htons(dns_packet->op) & 0x0200) printf("MT                     (01) 1      message truncated\n");
   else                               printf("MT                     (01) 0      message not truncated\n");
   
   if(htons(dns_packet->op) & 0x0100) printf("RD                     (01) 1      recursion desired\n");
   else                               printf("RD                     (01) 0      recursion not desired\n");
   
   if(htons(dns_packet->op) & 0x0080) printf("RA                     (01) 1      recursion available\n");
   else                               printf("RA                     (01) 0      recursion not available\n");
   
   if(!(htons(dns_packet->op) & 0x0038)) printf("Reserved               (03) 0b000\n");
   else {
      printf("DEVERIA ser reservado\n");
      return 1;
   }
   
   printf("ResponseType           (04) %d      ", htons(dns_packet->op) & 0x000F);
   if      ((htons(dns_packet->op) & 0x000F) == 0) printf("No error\n");
   else if ((htons(dns_packet->op) & 0x000F) == 1) printf("Format error\n");
   else if ((htons(dns_packet->op) & 0x000F) == 2) printf("Server failure\n");
   else if ((htons(dns_packet->op) & 0x000F) == 3) printf("Name Error\n");
   else if ((htons(dns_packet->op) & 0x000F) == 4) printf("Not Implemented\n");
   else if ((htons(dns_packet->op) & 0x000F) == 5) printf("Refused\n");
   else                                     printf("ERRO: deveria ser reservado\n");
   
   printf("Number of Questions    (16) %u\n", htons(dns_packet->n_questions));
   printf("Number of Answers      (16) %u\n", htons(dns_packet->n_answers));
   printf("Number of Authority    (16) %u\n", htons(dns_packet->n_authority));
   printf("Number of Additional   (16) %u\n", htons(dns_packet->n_additional));
   
   cache_pos = cache_pos + sizeof(struct dns_hdr);
   total = total + sizeof(struct dns_hdr);
   
   if (htons(dns_packet->n_questions)) printf("\nQuestões:\n");
   
   for (i=0; i < htons(dns_packet->n_questions); i++) {
      unsigned short int *valor;
      
      if (imp_name()) return 1;
      printf("\n");
      
      valor = (unsigned short int *)cache_pos;
      if      (htons(valor[0]) == 0x0001) printf("type = A (host address)");
      else if (htons(valor[0]) == 0x0002) printf("type = NS (authoritative name server)");
      else if (htons(valor[0]) == 0x0005) printf("type = CNAME (canonical name)");
      else                    printf("   type = ERRO (não implementei)");
      
      if      (htons(valor[1]) == 0x0001) printf("   class = IN (internet)");
      else                    printf("   class = ERRO (não implementei)");
      printf("\n");
      
      cache_pos = cache_pos + 4;
      total = total + 4;
   }
   
   if (htons(dns_packet->n_answers)) printf("\nRespostas:\n");
   
   for (i=0; i < htons(dns_packet->n_answers); i++) {
      unsigned short int *valor;
      unsigned long  int *lvalor;
      
      if (imp_name()) return 1;
      printf("\n");
      
      valor = (unsigned short int *)cache_pos;
      lvalor = (unsigned long int *)cache_pos;
      
      type = htons(valor[0]);
      if      (type == 0x0001) printf("type = A (host address)              ");
      else if (type == 0x0002) printf("type = NS (authoritative name server)");
      else if (type == 0x0005) printf("type = CNAME (canonical name)        ");
      else                     printf("type = ERRO (não implementei)        ");
      
      if      (htons(valor[1]) == 0x0001) printf("   class = IN (internet)");
      else                    printf("   class = ERRO (não implementei)");
      
      printf("   ttl = 0x%08X s", (unsigned int)lvalor[1]);
      
      printf("   rdlen = %u", htons(valor[4]));
      
      cache_pos = cache_pos + 10;
      total = total + 10;
      
      if (type == 0x0001) {
         printf("   %u.%u.%u.%u\n", cache_pos[0], cache_pos[1], cache_pos[2], cache_pos[3]);
         
         cache_pos = cache_pos + 4;
         total = total + 4;
      }
      else if (type == 0x0005) { printf("   "); if (imp_name()) return 1; printf("\n"); }
      else                     { printf("   type = ERRO (não implementei)");  return 1; }
   }
   
   if (htons(dns_packet->n_authority)) printf("\nERRO: não implementei a impressão dos authority\n");
   
   if (htons(dns_packet->n_additional)) printf("\nERRO: não implementei a impressão dos adicionais\n");
   
   {
      int falta = pcap_packet_hdr.incl_len - (cache_pos - cache);
      
      printf("\n");
      hexdump_string(total, cache_pos, falta);
      cache_pos = cache_pos + falta;
      total = total + falta;
   }
   
   return 0;
}

