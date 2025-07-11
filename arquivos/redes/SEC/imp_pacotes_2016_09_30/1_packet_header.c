struct tm {
   int tm_sec;          // Seconds.      [0-60] (1 leap second)
   int tm_min;          // Minutes.      [0-59]
   int tm_hour;         // Hours.        [0-23]
   int tm_mday;         // Day.          [1-31]
   int tm_mon;          // Month.        [0-11]
   int tm_year;         // Year- 1900.
   int tm_wday;         // Day of week.  [0-6]
   int tm_yday;         // Days in year. [0-365]
   int tm_isdst;        // DST.          [-1/0/1]
   long int tm_gmtoff;  // Seconds east of UTC.
   const char *tm_zone; // Timezone abbreviation.
};

extern struct tm *localtime(long int *);


struct pcap_rec_hdr_s {
   unsigned int ts_sec;         // timestamp seconds
   unsigned int ts_usec;        // timestamp microseconds
   unsigned int incl_len;       // number of octets of packet saved in file
   unsigned int orig_len;       // actual length of packet
} pcap_packet_hdr;
/*
ts_sec: the date and time when this packet was captured. This value is in seconds since January 1, 1970 00:00:00 GMT. Use time() function from time.h to get this value.

ts_usec: the microseconds when this packet was captured. Use gettimeofday().

incl_len: the number of bytes of packet data captured and saved in the file.

orig_len: the length of the packet as it appeared on the network when it was captured.
*/

int imp_packet_header() {
   struct tm *data;
   long int teste = pcap_packet_hdr.ts_sec;
   
   data = localtime((long int *)&teste);
   
   printf("\n\n%04d/%02d/%02d  %02d:%02d:%02d.%06u  = = = = = = = = = offset = 0x%08X = = = = = = = = = = = = = =\n\n", \
                    data->tm_year+1900, data->tm_mon + 1, data->tm_mday, data->tm_hour, data->tm_min, data->tm_sec, pcap_packet_hdr.ts_usec, (unsigned int)total);
   printf("Pcap_Packet_Header:\n");
   printf("ts_sec:           0x%08X      ; number of seconds elapsed since 00:00:00 on January 1, 1970\n", (unsigned int)pcap_packet_hdr.ts_sec);
   printf("ts_usec:          0x%08X      ; tempo em microsegundos\n", (unsigned int)pcap_packet_hdr.ts_usec);
   printf("incl_len:              %05u      ; quantidade de bytes capturados\n", pcap_packet_hdr.incl_len);
   printf("orig_len:              %05u      ; quantidade de bytes que o pacote possuia\n", pcap_packet_hdr.orig_len);
   
   total = total + sizeof(struct pcap_rec_hdr_s);
   return 0;
}

