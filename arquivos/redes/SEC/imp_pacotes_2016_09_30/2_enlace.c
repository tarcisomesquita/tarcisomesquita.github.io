
int enlace() {
   
   // Imprime pacotes Ethernet
   if (pcap_global_hdr.network == 1) {
      if(enlace_ethernet()) return 1;
   }
   
   // interface 802.11 wireless LAN
   else if(pcap_global_hdr.network == 105) {
      if(enlace_wlan()) return 1;
   }
      
   // PPP0 Linux 'cooked' capture encapsulation.
   else if(pcap_global_hdr.network == 113) {
      if(enlace_ppp()) return 1;
   }
   
   // radiotap link-layer followed by an 802.11 header
   else if(pcap_global_hdr.network == 127) {
      if(enlace_radio()) return 1;
   }
   
   // Formato de rede não suportado
   else {
      printf("\n");
      hexdump_string(total + 0, cache, pcap_packet_hdr.incl_len);
      total = total + pcap_packet_hdr.incl_len;
   }
   
   return 0;
}

