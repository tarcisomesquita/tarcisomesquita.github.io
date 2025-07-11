// #include</usr/include/netinet/ip_icmp.h>

struct icmp {
   unsigned char      type;         // 
   unsigned char      code;         // 
   unsigned short int checksum;     // 
   unsigned short int identifier;   // 
   unsigned short int sequence;     // 
} *icmp_packet = 0;

//types
#define ICMP_ECHOREPLY		0	// Echo Reply		
#define ICMP_DEST_UNREACH	3	// Destination Unreachable
#define ICMP_SOURCE_QUENCH	4	// Source Quench	
#define ICMP_REDIRECT		5	// Redirect (change route)
#define ICMP_ECHO		8	// Echo Request		
#define ICMP_TIME_EXCEEDED	11	// Time Exceeded	
#define ICMP_PARAMETERPROB	12	// Parameter Problem	
#define ICMP_TIMESTAMP		13	// Timestamp Request	
#define ICMP_TIMESTAMPREPLY	14	// Timestamp Reply	
#define ICMP_INFO_REQUEST	15	// Information Request	
#define ICMP_INFO_REPLY		16	// Information Reply	
#define ICMP_ADDRESS		17	// Address Mask Request	
#define ICMP_ADDRESSREPLY	18	// Address Mask Reply	


// Codes for UNREACH.
#define ICMP_NET_UNREACH	0	// Network Unreachable	
#define ICMP_HOST_UNREACH	1	// Host Unreachable	
#define ICMP_PROT_UNREACH	2	// Protocol Unreachable	
#define ICMP_PORT_UNREACH	3	// Port Unreachable	
#define ICMP_FRAG_NEEDED	4	// Fragmentation Needed/DF set
#define ICMP_SR_FAILED		5	// Source Route failed	
#define ICMP_NET_UNKNOWN	6
#define ICMP_HOST_UNKNOWN	7
#define ICMP_HOST_ISOLATED	8
#define ICMP_NET_ANO		9
#define ICMP_HOST_ANO		10
#define ICMP_NET_UNR_TOS	11
#define ICMP_HOST_UNR_TOS	12
#define ICMP_PKT_FILTERED	13	// Packet filtered
#define ICMP_PREC_VIOLATION	14	// Precedence violation
#define ICMP_PREC_CUTOFF	15	// Precedence cut off
#define NR_ICMP_UNREACH		15	// instead of hardcoding immediate value

// Codes for REDIRECT.
#define ICMP_REDIR_NET		0	// Redirect Net		
#define ICMP_REDIR_HOST		1	// Redirect Host	
#define ICMP_REDIR_NETTOS	2	// Redirect Net for TOS	
#define ICMP_REDIR_HOSTTOS	3	// Redirect Host for TOS

// Codes for TIME_EXCEEDED.
#define ICMP_EXC_TTL		0	// TTL count exceeded	
#define ICMP_EXC_FRAGTIME	1	// Fragment Reass time exceeded

int imp_icmp() {
   if ((pcap_packet_hdr.incl_len - (cache_pos - cache)) < sizeof(struct icmp)) {
      printf("\n\nERRO: poucos bytes para um pacote ICMP\n\n");
      return 1;
   }
   
   icmp_packet = (struct icmp *)cache_pos;
   
   printf("\n\nCabeçalho ICMP:\n");
   printf("type . . . . . . . . (08) 0x%02X   ", icmp_packet->type);
   if(icmp_packet->type == 0)      printf("Reply\n");
   else if(icmp_packet->type == 8) printf("Request\n");
   else                            printf("VERIFICAR ISSO\n");
   
   printf("code . . . . . . . . (08) 0x%02X\n", icmp_packet->code);
   
   printf("checksum . . . . . . (16) 0x%04X\n", icmp_packet->checksum);
   
   printf("identifier . . . . . (16) 0x%04X\n", icmp_packet->identifier);
   
   printf("sequence . . . . . . (16) 0x%04X\n", icmp_packet->sequence);
   
   total = total + sizeof(struct icmp);
   cache_pos = cache_pos + sizeof(struct icmp);
   
   printf("Data:\n");
   
   hexdump_string(total, cache_pos, pcap_packet_hdr.incl_len - (cache_pos - cache));
   cache_pos = cache_pos + (cache_pos - cache);
   total = total + (cache_pos - cache);
   
   return 0;
}

