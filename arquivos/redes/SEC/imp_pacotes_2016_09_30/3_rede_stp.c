/*
Spanning Tree Protocol (STP).
The basic function of STP is to prevent bridge loops causing broadcast congestion.

STP desativa algumas rotas.
Root switch is that which lowest bridge ID. Em caso de empate, escolhe o menor MAC.
A prioridade tem que ser um múltiplo de 4096.


All switches determine their best cost path with reference to the Root Switch.
Data rate   Path cost
4   Mbps    5.000.000
10  Mbps    2.000.000
16  Mbps    1.250.000
100 Mbps      200.000
1   Gbps       20.000
2   Gbps       10.000
10  Gbps        2.000

Rapid Spanning Tree Protocol (RSTP) RSTP takes 5-6 seconds to update and re-configure the new network topology/ routes.

RSTP disables those links that are not part of the spanning tree, leaving a single active path between any two network nodes.

The number of states a port can be in has been reduced to three instead of STP's original five.
RSTP bridge port roles:
    Root       - A forwarding port that is the best port from non-root bridge to root bridge
    Designated - A forwarding port for every LAN segment
    Alternate  - An alternate path to the root bridge. This path is different from using the root port
    Backup     - A backup/redundant path to a segment where another bridge port already connects
    Disabled   - Not strictly part of STP, a network administrator can manually disable a port
RSTP switch port states:
    Discarding - No user data is sent over the port
    Learning   - The port is not forwarding frames yet, but is populating its MAC-address-table
    Forwarding - The port is fully operational


The Protocol Identifier is encoded in Octets 1 and 2. It takes the value 0000 0000 0000 0000.
The Protocol Version Identifier is encoded in Octet 3. It takes the value 0000 0010.
The BPDU Type is encoded in Octet 4. This field takes the value 0000 0010. This denotes a Rapid Spanning Tree BPDU.
The Topology Change flag is encoded in Bit 1 of Octet 5.
The Proposal flag is encoded in Bit 2 of Octet 5.
The Port Role is encoded in Bits 3 and 4 of Octet 5.
The Learning flag is encoded in Bit 5 of Octet 5.
The Forwarding flag is encoded in Bit 6 of Octet 5.
The Agreement flag is encoded in Bit 7 of Octet 5.
The Topology Change Acknowledgment flag is encoded in Bit 8 of Octet 5 as zero.
The Root Identifier is encoded in Octets 6 through 13.
The Root Path Cost is encoded in Octets 14 through 17.
The Bridge Identifier is encoded in Octets 18 through 25.
The Port Identifier is encoded in Octets 26 and 27.
The Message Age timer value is encoded in Octets 28 and 29.
The Max Age timer value is encoded in Octets 30 and 31.
The Hello Time timer value is encoded in Octets 32 and 33.
The Forward Delay timer value is encoded in Octets 34 and 35.
The Version 1 Length value is encoded in Octet 36. It takes the value 0000 0000, which indicates that there is no Version 1 protocol information present.

Cabeçalho Ethernet:
MAC destination . . . . . (48) 01:80:C2:00:00:00
MAC source  . . . . . . . (48) FC:B0:C4:62:CE:F4
Ethertype . . . . . . . . (16) 0x0027  EtherType DESCONHECIDO

00000030                    01 80  C2 00 00 00 FC B0 C4 62  |      .........b|
00000030                                       FC B0 C4 62  |      .........b|
00000040  CE F4                                             |...'BB.....<....|
00000040        00 27                                       |...'BB.....<....|
00000040              42 42 03 00  00 02 02 3C              |...'BB.....<....|
00000040                                       80 00 FC B0  |...'BB.....<....|
00000050  C4 62 CE F4                                       |.b...........b..|
00000050              00 00 00 00                           |.b...........b..|
00000050                           80 00 FC B0 C4 62 CE F4  |.b...........b..|
00000060  80 01                                             |................|
00000060        00 00 14 00 02 00  0F 00 00 00 00 00 00 00  |................|
00000070  00 00                                             |..              |

21:07:18.375431 STP 802.1w, Rapid STP, Flags [Learn, Forward], bridge-id 8000.fc:b0:c4:62:ce:f4.8001, length 43
        message-age 0.00s, max-age 20.00s, hello-time 2.00s, forwarding-delay 15.00s
        root-id 8000.fc:b0:c4:62:ce:f4, root-pathcost 0, port-role Designated

*/


struct stphdr {
   unsigned short int p_identifier;     // Protocol Identifier
   unsigned char p_version;             // Protocol Version Identifier
   unsigned char bpdu_type;             // BPDU Type
   unsigned char flags;                   // 
   unsigned char root_id[8];         // 
   unsigned long int path_cost;  //
   unsigned char bridge_id[10];     // 
   unsigned short int age_message;     //
   unsigned short int age_max;     //
   unsigned short int time_hello;     //
   unsigned short int delay;     //
}  __attribute__((packed)) *stp_hdr = 0x00000000 ;


int rede_stp() {
   int falta;
   
   stp_hdr = (struct stphdr *)cache_pos;
   
   printf("\n\nCabeçalho STP\n");

   printf("Protocol Identifier . . . . . .(16)  0x%04X  \n", stp_hdr->p_identifier);
  
   printf("Protocol Version Identifier . .(08)  0x%02X     ", stp_hdr->p_version);
   if (stp_hdr->p_version == 0x02) printf("RST\n");
   else { printf("Desconhecido\n"); return 1;}    // (0x00 Config & TCN / 0x02 RST / 0x03 MSTP / 0x04 SPT  BPDU) 
   
   printf("BPDU Type . . . . . . . . . . .(08)  0x%02X     ", stp_hdr->bpdu_type);
   if (stp_hdr->p_version == 0x02) printf("Rapid Spanning Tree BPDU\n");
   else { printf("Desconhecido\n"); return 1;}     // (0x00 Config BPDU, 0x80 TCN BPDU, 0x02 RST BPDU)
   
   printf("flags . . . . . . . . . . . . .(08)  0x%02X       ", stp_hdr->flags);
   if (stp_hdr->flags & 0x01)  printf(" ; change topology");
   if (stp_hdr->flags & 0x02)  printf(" ; proposal");
   if (stp_hdr->flags & 0x04 || stp_hdr->flags & 0x08)  printf(" ; port role Designated");
/*
     3-4 : 00 (unused) or
           01 for Port Role Alternate/Backup in RST/MST/SPT BPDU
           10 for Port Role Root in RST/MST/SPT BPDU
           11 for Port Role Designated in RST/MST/SPT BPDU
*/
   if (stp_hdr->flags & 0x10)  printf(" ; learning"); 
   if (stp_hdr->flags & 0x20)  printf(" ; forwarding");
   if (stp_hdr->flags & 0x40)  printf(" ; agreement");
   if (stp_hdr->flags & 0x80)  printf(" ; Topology Change Acknowledgment");
   printf("\n");

   printf("Root Identifier . . . . . . . .(64)  %02X%02X.%02X:%02X:%02X:%02X:%02X:%02X\n", \
                    stp_hdr->root_id[0], stp_hdr->root_id[1], stp_hdr->root_id[2], stp_hdr->root_id[3], stp_hdr->root_id[4], stp_hdr->root_id[5], stp_hdr->root_id[6], stp_hdr->root_id[7]);
/*
   bits  : usage
    1-4  : Root Bridge Priority
   5-16  : Root Bridge System ID Extension
   17-64 : Root Bridge MAC Address
*/


   printf("path_cost . . . . . . . . . . .(32)  0x%08X      \n", (unsigned int)stp_hdr->path_cost);
   printf("Bridge Identifier . . . . . . .(80)  %02X%02X.%02X:%02X:%02X:%02X:%02X:%02X.%02X%02X\n", \
                    stp_hdr->bridge_id[0], stp_hdr->bridge_id[1], \
                   stp_hdr->bridge_id[2], stp_hdr->bridge_id[3], stp_hdr->bridge_id[4], stp_hdr->bridge_id[5], stp_hdr->bridge_id[6], stp_hdr->bridge_id[7], \
                   stp_hdr->bridge_id[8], stp_hdr->bridge_id[9]);
/*
   bits  : usage
    1-4  : Bridge Priority 
   5-16  : Bridge System ID Extension
   17-64 : Bridge MAC Address
  8. Port ID           2 bytes
*/

   printf("age_message . . . . . . . . . .(16)  0x%04X  \n", stp_hdr->age_message);
   printf("age_max . . . . . . . . . . . .(16)  0x%04X  \n", stp_hdr->age_max);
   printf("time_hello  . . . . . . . . . .(16)  0x%04X  \n", stp_hdr->time_hello);
   printf("delay . . . . . . . . . . . . .(16)  0x%04X  \n", stp_hdr->delay);

/*
  9. Message Age:      2 bytes in 1/256 secs
 10. Max Age:          2 bytes in 1/256 secs
 11. Hello Time:       2 bytes in 1/256 secs
 12. Forward Delay:    2 bytes in 1/256 secs
 13. version 1 Length: 1 byte (0x00 no ver 1 protocol info present. RST, MST, SPT BPDU only)
 14. version 3 Length: 2 bytes (MST, SPT BPDU only)
*/
   
   total = total + sizeof(struct stphdr);
   cache_pos = cache_pos + sizeof(struct stphdr);
   
   falta = pcap_packet_hdr.incl_len - (cache_pos - cache);
   
   if (falta) {
      printf("\n");
      hexdump_string(total, (unsigned char *)cache_pos, falta);
      total = total + falta;
   }
   
   return 0;
}

