// This is an Ethernet frame header.
struct ppphdr {
   unsigned short int sentido;  // se o pacote está entrando ou saindo
   unsigned short int unknow1 ; // 
   unsigned long  int unknow2 ; // 
   unsigned long  int unknow3 ; // 
   unsigned short int unknow4 ; // 
   unsigned short int proto;    // protocolo
} *ppp_hdr = 0x00000000;

int enlace_ppp() {
   
   ppp_hdr = (struct ppphdr *)cache_pos;
   
   printf("\n\nCabeçalho PPP:\n");
   printf("Sentido: %04X\n", htons(ppp_hdr->sentido));
   printf("unknow:  %04X\n", htons(ppp_hdr->unknow1));
   printf("unknow:  %08X\n", (unsigned int)ppp_hdr->unknow2);
   printf("unknow:  %08X\n", (unsigned int)ppp_hdr->unknow3);
   printf("unknow:  %04X\n", htons(ppp_hdr->unknow4));
   printf("Proto:   %04X ;", htons(ppp_hdr->proto));
        if(htons(ppp_hdr->proto) == 0x0800) printf("  Internet Protocol, Version 4 (IPv4)\n");
   else if(htons(ppp_hdr->proto) == 0x0806) printf("  Address Resolution Protocol (ARP)\n");
   else if(htons(ppp_hdr->proto) == 0x86DD) printf("  Internet Protocol, Version 6 (IPv6)\n");
   else if(htons(ppp_hdr->proto) == 0x8864) printf("  PPPoE Session Message\n");
   else                                     printf("  EtherType DESCONHECIDO\n");
   
   cache_pos = cache_pos + sizeof(struct ppphdr);
   total = total + sizeof(struct ppphdr);
   
   if(htons(ppp_hdr->proto) == 0x0806) {
      if(rede_arp()) return 1;
   }
   else if(htons(ppp_hdr->proto) == 0x0800) {
      if(rede_ip()) return 1;
   }
   else if(htons(ppp_hdr->proto) == 0x8864) {
      printf("FAÇA ISSO\n"); return 1;
      //if(imp_ppp()) return 1;
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

