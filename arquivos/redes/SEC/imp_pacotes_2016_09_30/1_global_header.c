
struct pcap_hdr_s {
   unsigned       int magic_number;   // magic number: 0xa1b2c3d4
   unsigned short int version_major;  // major version number: 2
   unsigned short int version_minor;  // minor version number: 4
     signed       int thiszone;       // GMT to local correction
   unsigned       int sigfigs;        // accuracy of timestamps
   unsigned       int snaplen;        // max length of captured packets, in bytes, use 65535 para não truncar pacotes
   unsigned       int network;        // data link type
} pcap_global_hdr;
/*
http://wiki.wireshark.org/Development/LibpcapFileFormat
Next generation pcap (pcapng) file format available at: http://www.winpcap.org/ntar/draft/PCAP-DumpFileFormat.html.

thiszone: the correction time in seconds between GMT (UTC) and the local timezone of the following packet header timestamps. Examples: If the timestamps are in GMT (UTC), thiszone is simply 0. If the timestamps are in Central European time (Amsterdam, Berlin, ...) which is GMT + 1:00, thiszone must be -3600. In practice, time stamps are always in GMT, so thiszone is always 0.

sigfigs: in theory, the accuracy of time stamps in the capture; in practice, all tools set it to 0

snaplen: maximum length defined by user to be captured (typically 65535)

network: link-layer header type. In http://www.tcpdump.org/linktypes.html have:
  1   => Ethernet (10Mb, 100Mb, 1000Mb, and up). IEEE 802.3
  105 => wireless LAN. IEEE 802.11
  127 => radiotap link-layer followed by an 802.11 header
  113 => DSL (PPPoE). Linux 'cooked' capture encapsulation.
*/

int imp_global_header() {
   
   printf("\nPcap_Global_Header:\n");
   
   if(pcap_global_hdr.magic_number != 0xa1b2c3d4) {
      printf("\nERRO. O magic number é diferente de 0xa1b2c3d4\n\n");
      return 1;
   }
   else printf("Magic_Number:     0x%08X      ; pcap file\n", (unsigned int)pcap_global_hdr.magic_number);
   
   if(pcap_global_hdr.version_major != 2) {
      printf("\nERRO. version_major diferente de 2\n\n");
      return 1;
   }
   else printf("Version_Major:    %u               ; versão é 2.4\n", pcap_global_hdr.version_major);
   
   if(pcap_global_hdr.version_minor != 4) {
      printf("\nERRO. version_minor diferente de 4\n\n");
      return 1;
   }
   else printf("Version_Minor:    %u               ; \n", pcap_global_hdr.version_minor);
   
   if(pcap_global_hdr.thiszone != 0) {
      printf("\nERRO. thiszone diferente de 0. Este programa não suporta isso.\n\n");
      return 1;
   }
   else printf("Thiszone:         %d               ; sem correção de tempo em relação ao GMT\n", pcap_global_hdr.thiszone);
   
   if(pcap_global_hdr.sigfigs != 0) {
      printf("\nERRO. O sigfigs é diferente de 0. Este programa não suporta isso.\n\n");
      return 1;
   }
   else printf("sigfigs:          %u               ; accuracy of time stamps\n", (unsigned int)pcap_global_hdr.sigfigs);
   
   printf("snaplen:          %05u           ; length for the capture, typically 65535\n", (unsigned int)pcap_global_hdr.snaplen);
   
   if(pcap_global_hdr.network == 1)
      printf("network:          %03u             ; enlace Ethernet\n", (unsigned int)pcap_global_hdr.network);
   else if(pcap_global_hdr.network == 105)
      printf("network:          %03u             ; interface 802.11 wireless LAN\n", (unsigned int)pcap_global_hdr.network);
   else if(pcap_global_hdr.network == 113)
      printf("network:          %03u             ; Linux 'cooked' capture encapsulation.\n", (unsigned int)pcap_global_hdr.network);
   else if(pcap_global_hdr.network == 127)
      printf("network:          %03u             ; Radio tape.\n", (unsigned int)pcap_global_hdr.network);
   else {
      printf("network:          %03u ; \n", (unsigned int)pcap_global_hdr.network);
      printf("\nERRO. network desconhecida. Este programa não suporta isso.\n\n");
      return 1;
   }
   
   total = total + sizeof(struct pcap_hdr_s);
   return 0;
}

