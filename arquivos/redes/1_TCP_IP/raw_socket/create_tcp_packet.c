
// constructs a raw TCP packet:

// Raw sockets require root privileges
// Use wireshark to check the output.

#include<stdio.h>
#include<netinet/tcp.h> // Provides declarations for tcp header
#include<netinet/ip.h>  // Provides declarations for ip header


unsigned short csum(unsigned short *buf, int nwords) { // Checksum calculation function
   unsigned long sum;
   
   for(sum = 0; nwords > 0; nwords--) sum += *buf++;
   
   sum =(sum >> 16) +(sum & 0xffff);
   sum +=(sum >> 16);
   
   return ~sum;
}
   
int main(void) {
   unsigned long int i;
   int s = socket(PF_INET, SOCK_RAW, IPPROTO_TCP);                       // Create a raw socket
   char datagram[4096];                                                  // Datagram to represent the packet
   struct iphdr *iph =(struct iphdr *) datagram;                         // IP header
   struct tcphdr *tcph =(struct tcphdr *)(datagram + sizeof(struct ip)); // TCP header
   struct sockaddr_in sin;
   
   sin.sin_family = AF_INET;
   sin.sin_port = htons(8080);
   sin.sin_addr.s_addr = inet_addr("127.0.0.1");
   
   memset(datagram, 0, 4096); // zero out the buffer
   
   // Fill in the IP Header
   iph->ihl = 5;
   iph->version = 4;
   iph->tos = 0;
   iph->tot_len = sizeof(struct ip) + sizeof(struct tcphdr);
   iph->id = htonl(54321); // Id of this packet
   iph->frag_off = 0;
   iph->ttl = 255;
   iph->protocol = 6;
   iph->check = 0;  // Set to 0 before calculating checksum
   iph->saddr = inet_addr("1.2.3.4"); // Spoof the source ip address
   iph->daddr = sin.sin_addr.s_addr;
   
   // TCP Header
   tcph->source = htons(1234);
   tcph->dest = htons(85);
   tcph->seq = random();
   tcph->ack_seq = 0;
   tcph->doff = 0;  // first and only tcp segment
   tcph->syn = 1;
   tcph->window = htonl(65535); // maximum allowed window size
   tcph->check = 0; // if you set a checksum to zero, your kernel's IP stack should fill in the correct checksum during transmission
   tcph->urg_ptr = 0;
   iph->check = csum((unsigned short *) datagram, iph->tot_len >> 1); // IP checksum
   
   // IP_HDRINCL to tell the kernel that headers are included in the packet
   {
    int one = 1;
    const int *val = &one;
    if(setsockopt(s, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) // make sure the kernel uses the raw headers
       printf("Warning: Cannot set HDRINCL!\n");
   }
   
   for (i = 0; i < 3 ; i++) {
    // Send the packet
    if(sendto(s,                       // our socket
              datagram,                // the buffer containing headers and data
              iph->tot_len,            // total length of our datagram
              0,                       // routing flags, normally always 0
             (struct sockaddr *) &sin, // socket addr, just like in
              sizeof(sin)) < 0)        // a normal send()
       printf("error\n");
    else
       printf(".");
   }
   
   return 0;
}

