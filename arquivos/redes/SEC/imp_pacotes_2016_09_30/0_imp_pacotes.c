
// clear ; gcc -Wall 0_imp_pacotes.c -o imp_pacotes.elf && ./imp_pacotes.elf teste.pcap | less

unsigned char *cache = 0x00000000;
unsigned char *cache_pos = 0x00000000;
unsigned long int total = 0;
int file;

//#include <stdio.h>
extern int printf(char *, ...);

// #include<fcntl.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int open(const char *file, int oflag, ...);
#define O_RDONLY           00

// #include <unistd.h>
extern int read(int fd, void *buf, unsigned long int nbytes);
extern int close(int fd);

//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void *malloc(long unsigned int __size);
extern void free(void *__ptr);

// #include <netinet/in.h>
extern unsigned short int htons(unsigned short int __hostshort);
extern unsigned long  int htonl(unsigned long  int __hostlong);
//#include <stdlib.h>
//#include <time.h>

//#include "enche_cache.c"
#include "hexdump_string.c"

#include "1_global_header.c"
#include "1_packet_header.c"

#include "5_aplicacao_dns.c"
#include "5_aplicacao_https.c"

#include "4_transporte_tcp.c"
#include "4_transporte_udp.c"
#include "4_transporte_icmp.c"

#include "3_rede_arp.c"
#include "3_rede_ip.c"
//#include "imp_ppp.c"
#include "3_rede_ipv6.c"
#include "3_rede_stp.c"

#include "2_enlace_ethernet.c"
#include "2_enlace_wlan.c"
#include "2_enlace_ppp.c"
#include "2_enlace_radio.c"
#include "2_enlace.c"


void sair() {
   printf("\nForam impressos %lu bytes\n\n", total);
   if (cache) free(cache);
   close(file);
   return;
}


int main(int argc, char **argv) {
   int n;
   
   if(argc != 2) {
      printf("\nSintaxe:\n./imp_pacotes.elf file.pcap\n\n");
      return 1;
   }
   
   file = -1;
   file = open(argv[1], O_RDONLY);
   //stream = fopen(argv[1],"rb");
   if(file < 0) {
      printf("\nERRO na abertura do arquivo \'%s\'\n\n", argv[1]);
      return 1;
   }
   
   n = 0;
   n = read(file, (void *)&pcap_global_hdr, sizeof(struct pcap_hdr_s));
   if (n != sizeof(struct pcap_hdr_s)) {
      printf("\nERRO na leitura do pcap_global_hdr\n\n");
      close(file);
      return 1;
   }
   
   if (imp_global_header()) { close(file); return 1; }
   
   cache = malloc((unsigned long int)pcap_global_hdr.snaplen);
   if (! cache) {
      printf("\nERRO não foi possível alocar %d bytes para cache.\n\n", pcap_global_hdr.snaplen);
      close(file);
      return 1;
   }
   
   for (;;) {
      n = 0;
      n = read(file, (void *)&pcap_packet_hdr, sizeof(struct pcap_rec_hdr_s));
      if (n == 0) break; // possível fim do arquivo
      if (n != sizeof(struct pcap_rec_hdr_s)) {
         printf("\nERRO: O arquivo deve estar quebrado.\n\n");
         sair();
         return 1;
      }
      if (imp_packet_header()) { sair(); return 1; }
      
      n = 0;
      n = read(file, (void *)cache, (unsigned long int)pcap_packet_hdr.incl_len);
      if (n != pcap_packet_hdr.incl_len) {
         printf("\nERRO: O arquivo deve estar quebrado.\n\n");
         sair();
         return 1;
      }
      cache_pos = cache;
      if (enlace()) { sair(); return 1; }
   }
   
   sair();
   return 0;
}

