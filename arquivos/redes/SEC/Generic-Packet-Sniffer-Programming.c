#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<features.h>
#include<linux/if_packet.h>
#include<linux/if_ether.h>
#include<errno.h>
#include<sys/ioctl.h>
#include<net/if.h>


int CreateRawSocket(int protocol_to_sniff) {
   int rawsock;
   
   rawsock = socket(PF_PACKET, SOCK_RAW, htons(protocol_to_sniff));
   if(rawsock == -1) {
      perror("Error creating raw socket: ");
      exit(-1);
   }
   
   return rawsock;
}


int BindRawSocketToInterface(char *device, int rawsock, int protocol) {
   struct sockaddr_ll sll;
   struct ifreq ifr;
   
   bzero(&sll, sizeof(sll));
   bzero(&ifr, sizeof(ifr));
   
   /* First Get the Interface Index  */
   strncpy((char *)ifr.ifr_name, device, IFNAMSIZ);
   if ((ioctl(rawsock, SIOCGIFINDEX, &ifr)) == -1) {
      printf("Error getting Interface index !\n");
      exit(-1);
   }
   
   /* Bind our raw socket to this interface */
   sll.sll_family = AF_PACKET;
   sll.sll_ifindex = ifr.ifr_ifindex;
   sll.sll_protocol = htons(protocol); 

   
   if ((bind(rawsock, (struct sockaddr *)&sll, sizeof(sll)))== -1) {
      perror("Error binding raw socket to interface\n");
      exit(-1);
   }
   
   return 1;
}

void PrintPacketInHex(unsigned char *packet, int len) {
   unsigned char *p = packet;
   
   printf("\n\n---------Packet---Starts----\n\n");
   
   while (len--) {
      printf("%.2x ", *p);
      p++;
   }
   
   printf("\n\n--------Packet---Ends-----\n\n");
}


int main(int argc, char **argv) {
   int raw;
   unsigned char packet_buffer[2048]; 
   int len;
   int packets_to_sniff;
   struct sockaddr_ll packet_info;
   int packet_info_size = sizeof(packet_info);
   
   raw = CreateRawSocket(ETH_P_IP);  // create the raw socket
   
   BindRawSocketToInterface(argv[1], raw, ETH_P_IP); // Bind socket to interface
   
   packets_to_sniff = atoi(argv[2]); // Get number of packets to sniff from user
   
   // Start Sniffing and print Hex of every packet
   while (packets_to_sniff--) {
      if ((len = recvfrom(raw, packet_buffer, 2048, 0, (struct sockaddr*)&packet_info, &packet_info_size)) == -1) {
         perror("Recv from returned -1: ");
         exit(-1);
      }
      else {
         PrintPacketInHex(packet_buffer, len); // Packet has been received successfully !!
      }
   }
   
   return 0;
}
