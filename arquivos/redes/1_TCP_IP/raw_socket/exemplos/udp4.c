
// Send an IPv4 UDP packet via raw socket.

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <netdb.h>            // struct addrinfo
#include <sys/types.h>        // needed for socket()
#include <sys/socket.h>       // needed for socket()
#include <netinet/in.h>       // IPPROTO_RAW, IPPROTO_IP, IPPROTO_UDP
#include <netinet/ip.h>       // struct ip and 0xFFFF (which is 65535)
#include <netinet/udp.h>      // struct udphdr
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <sys/ioctl.h>        // macro ioctl is defined
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl.
#include <net/if.h>           // struct ifreq

#include <errno.h>            // errno, perror()
*/

// Define some constants.
#define IP4_HDRLEN 20         // IPv4 header length
#define UDP_HDRLEN  8         // UDP header length, excludes data


// #include <netinet/in.h>
enum {
   IPPROTO_IP = 0,        // Dummy protocol for TCP. 
   IPPROTO_UDP = 17,      // User Datagram Protocol. 
   IPPROTO_RAW = 255     // Raw IP packets. 
};

struct in_addr {
   unsigned int s_addr; // Internet address
};

extern unsigned short int htons(unsigned short int hostshort);


// #include<sys/types.h>
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));


//#include<netinet/ip.h>
struct ip {
   unsigned int ip_hl:4;            // header length
   unsigned int ip_v:4;             // version
   u_int8_t ip_tos;                 // type of service
   unsigned short int ip_len;       // total length
   unsigned short int ip_id;        // identification
   unsigned short int ip_off;       // fragment offset field
#define   IP_RF   0x8000            // reserved fragment flag
#define   IP_DF   0x4000            // dont fragment flag
#define   IP_MF   0x2000            // more fragments flag
#define   IP_OFFMASK   0x1fff       // mask for fragmenting bits
   u_int8_t ip_ttl;                 // time to live
   u_int8_t ip_p;                   // protocol
   unsigned short int ip_sum;       // checksum
   struct in_addr ip_src, ip_dst;   // source and dest address
};


/*
// Checksum function
unsigned short int
checksum (unsigned short int *addr, int len) {
   int nleft = len;
   int sum = 0;
   unsigned short int *w = addr;
   unsigned short int answer = 0;
   
   while (nleft > 1) {
      sum += *w++;
      nleft -= sizeof (unsigned short int);
   }
   
   if (nleft == 1) {
      *(unsigned char *) (&answer) = *(unsigned char *) w;
      sum += answer;
   }
   
   sum = (sum >> 16) + (sum & 0xFFFF);
   sum += (sum >> 16);
   answer = ~sum;
   return (answer);
}

// Build IPv4 UDP pseudo-header and call checksum function.
unsigned short int
udp4_checksum (struct ip iphdr, struct udphdr udphdr, unsigned char *payload, int payloadlen) {
   char buf[0xFFFF];
   char *ptr;
   int chksumlen = 0;
   int i;
   
   ptr = &buf[0];  // ptr points to beginning of buffer buf
   
   // Copy source IP address into buf (32 bits)
   memcpy (ptr, &iphdr.ip_src.s_addr, sizeof (iphdr.ip_src.s_addr));
   ptr += sizeof (iphdr.ip_src.s_addr);
   chksumlen += sizeof (iphdr.ip_src.s_addr);
   
   // Copy destination IP address into buf (32 bits)
   memcpy (ptr, &iphdr.ip_dst.s_addr, sizeof (iphdr.ip_dst.s_addr));
   ptr += sizeof (iphdr.ip_dst.s_addr);
   chksumlen += sizeof (iphdr.ip_dst.s_addr);
   
   // Copy zero field to buf (8 bits)
   *ptr = 0; ptr++;
   chksumlen += 1;
   
   // Copy IP protocol version to buf (8 bits)
   memcpy (ptr, &iphdr.ip_p, sizeof (iphdr.ip_p));
   ptr += sizeof (iphdr.ip_p);
   chksumlen += sizeof (iphdr.ip_p);
   
   // Copy UDP length to buf (16 bits)
   memcpy (ptr, &udphdr.len, sizeof (udphdr.len));
   ptr += sizeof (udphdr.len);
   chksumlen += sizeof (udphdr.len);
   
   // Copy UDP source port to buf (16 bits)
   memcpy (ptr, &udphdr.source, sizeof (udphdr.source));
   ptr += sizeof (udphdr.source);
   chksumlen += sizeof (udphdr.source);
   
   // Copy UDP destination port to buf (16 bits)
   memcpy (ptr, &udphdr.dest, sizeof (udphdr.dest));
   ptr += sizeof (udphdr.dest);
   chksumlen += sizeof (udphdr.dest);
   
   // Copy UDP length again to buf (16 bits)
   memcpy (ptr, &udphdr.len, sizeof (udphdr.len));
   ptr += sizeof (udphdr.len);
   chksumlen += sizeof (udphdr.len);
   
   // Copy UDP checksum to buf (16 bits)
   // Zero, since we don't know it yet
   *ptr = 0; ptr++;
   *ptr = 0; ptr++;
   chksumlen += 2;
   
   // Copy payload to buf
   memcpy (ptr, payload, payloadlen);
   ptr += payloadlen;
   chksumlen += payloadlen;
   
   // Pad to the next 16-bit boundary
   for (i=0; i<payloadlen%2; i++, ptr++) {
      *ptr = 0;
      ptr++;
      chksumlen++;
   }
   
   return checksum ((unsigned short int *) buf, chksumlen);
}
*/


int main (int argc, char **argv) {
   struct ip iphdr;
/*
   int status, datalen, sd;
   const int on = 1;
   char *interface, *target, *src_ip, *dst_ip;
   struct udphdr udphdr;
   unsigned char *ip_flags, *data, *packet;
   struct addrinfo hints, *res;
   struct sockaddr_in *ipv4, sin;
   struct ifreq ifr;
   void *tmp;
   
   // 0xFFFF é o tamanho máximo de um pacote IP.
   
   tmp = (unsigned char *) malloc(0xFFFF * sizeof (unsigned char));
   if (tmp != NULL) {
      packet = tmp;
   }
   else {
      fprintf(stderr, "ERROR: Cannot allocate memory for array 'packet'.\n");
      return 1;
   }
   memset(packet, 0, 0xFFFF);
   
   // Maximum UDP payload size = 65535 - IPv4 header (20 bytes) - UDP header (8 bytes)
   tmp = (unsigned char *)malloc((0xFFFF - IP4_HDRLEN - UDP_HDRLEN) * sizeof(unsigned char));
   if (tmp != NULL) {
      data = tmp;
   }
   else {
      fprintf(stderr, "ERROR: Cannot allocate memory for array 'data'.\n");
      return 1;
   }
   memset(data, 0, 0xFFFF - IP4_HDRLEN - UDP_HDRLEN);
   
   tmp = (char *) malloc(40 * sizeof (char));
   if (tmp != NULL) {
      interface = tmp;
   }
   else {
      fprintf(stderr, "ERROR: Cannot allocate memory for array 'interface'.\n");
      return 1;
   }
   memset(interface, 0, 40);
   
   tmp = (char *) malloc(40 * sizeof (char));
   if (tmp != NULL) {
      target = tmp;
   }
   else {
      fprintf(stderr, "ERROR: Cannot allocate memory for array 'target'.\n");
      return 1;
   }
   memset(target, 0, 40);
   
   tmp = (char *) malloc(16 * sizeof (char));
   if (tmp != NULL) {
      src_ip = tmp;
   }
   else {
      fprintf(stderr, "ERROR: Cannot allocate memory for array 'src_ip'.\n");
      return 1;
   }
   memset(src_ip, 0, 16);
   
   tmp = (char *) malloc(16 * sizeof (char));
   if (tmp != NULL) {
      dst_ip = tmp;
   }
   else {
      fprintf(stderr, "ERROR: Cannot allocate memory for array 'dst_ip'.\n");
      return 1;
   }
   memset(dst_ip, 0, 16);
   
   tmp = (unsigned char *) malloc(4 * sizeof (char));
   if (tmp != NULL) {
      ip_flags = tmp;
   }
   else {
      fprintf(stderr, "ERROR: Cannot allocate memory for array 'ip_flags'.\n");
      return 1;
   }
   memset(ip_flags, 0, 4);
   
   // Interface to send packet through.
   strcpy(interface, "wlan0");
   
   // Submit request for a socket descriptor to lookup interface.
   if ((sd = socket (AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
      perror ("socket() failed to get socket descriptor for using ioctl() ");
      return 1;
   }
   
   // Use ioctl() to lookup interface.
   memset(&ifr, 0, sizeof(ifr));
   snprintf (ifr.ifr_name, sizeof (ifr.ifr_name), "%s", interface);
   if (ioctl (sd, SIOCGIFINDEX, &ifr) < 0) {
      perror ("ioctl() failed to find interface ");
      return (EXIT_FAILURE);
   }
   close (sd);
   printf ("Index for interface %s is %i\n", interface, ifr.ifr_ifindex);
   
   // Source IPv4 address: you need to fill this out
   strcpy(src_ip, "192.168.1.116");
   
   // Destination URL or IPv4 address
   strcpy(target, "www.google.com");
   
   // Fill out hints for getaddrinfo().
   memset(&hints, 0, sizeof (struct addrinfo));
   hints.ai_family = AF_INET;
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags = hints.ai_flags | AI_CANONNAME;
   
   // Resolve target using getaddrinfo().
   if ((status = getaddrinfo (target, NULL, &hints, &res)) != 0) {
      fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror (status));
      return 1;
   }
   ipv4 = (struct sockaddr_in *) res->ai_addr;
   tmp = &(ipv4->sin_addr);
   inet_ntop (AF_INET, tmp, dst_ip, 16);
   freeaddrinfo (res);
   
   // UDP data
   datalen = 4;
   data[0] = 'T';
   data[1] = 'e';
   data[2] = 's';
   data[3] = 't';
   
*/
   // IPv4 header
   
   iphdr.ip_hl = IP4_HDRLEN / sizeof (unsigned long int);   // IPv4 header length (4 bits): Number of 32-bit words in header = 5
   iphdr.ip_v = 4;   // Internet Protocol version (4 bits): IPv4
   iphdr.ip_tos = 0;   // Type of service (8 bits)
   iphdr.ip_len = htons(IP4_HDRLEN + UDP_HDRLEN + datalen);   // Total length of datagram (16 bits): IP header + UDP header + datalen
   iphdr.ip_id = htons(0);   // ID sequence number (16 bits): unused, since single datagram
   
   // Flags, and Fragmentation offset (3, 13 bits): 0 since single datagram
   ip_flags[0] = 0;   // Zero (1 bit)
   ip_flags[1] = 0;   // Do not fragment flag (1 bit)
   ip_flags[2] = 0;   // More fragments following flag (1 bit)
   ip_flags[3] = 0;   // Fragmentation offset (13 bits)
   iphdr.ip_off = htons((ip_flags[0] << 15) + (ip_flags[1] << 14) + (ip_flags[2] << 13) +  ip_flags[3]);
   
   iphdr.ip_ttl = 255;   // Time-to-Live (8 bits): default to maximum value
   iphdr.ip_p = IPPROTO_UDP;   // Transport layer protocol (8 bits): 17 for UDP
   
   inet_pton(AF_INET, src_ip, &(iphdr.ip_src));   // Source IPv4 address (32 bits)
   
   // Destination IPv4 address (32 bits)
   inet_pton(AF_INET, dst_ip, &iphdr.ip_dst);
   
   // IPv4 header checksum (16 bits): set to 0 when calculating checksum
   iphdr.ip_sum = 0;
   iphdr.ip_sum = checksum ((unsigned short int *) &iphdr, IP4_HDRLEN);
   
/*
   // UDP header
   
   // Source port number (16 bits): pick a number
   udphdr.source = htons(4950);
   
   // Destination port number (16 bits): pick a number
   udphdr.dest = htons(4950);
   
   // Length of UDP datagram (16 bits): UDP header + UDP data
   udphdr.len = htons(UDP_HDRLEN + datalen);
   
   // UDP checksum (16 bits)
   udphdr.check = udp4_checksum (iphdr, udphdr, data, datalen);
   
   // Prepare packet.
   
   // First part is an IPv4 header.
   memcpy (packet, &iphdr, IP4_HDRLEN);
   
   // Next part of packet is upper layer protocol header.
   memcpy ((packet + IP4_HDRLEN), &udphdr, UDP_HDRLEN);
   
   // Finally, add the UDP data.
   memcpy (packet + IP4_HDRLEN + UDP_HDRLEN, data, datalen);
   
   // The kernel is going to prepare layer 2 information (ethernet frame header) for us.
   // For that, we need to specify a destination for the kernel in order for it
   // to decide where to send the raw datagram. We fill in a struct in_addr with
   // the desired destination IP address, and pass this structure to the sendto() function.
   memset(&sin, 0, sizeof (struct sockaddr_in));
   sin.sin_family = AF_INET;
   sin.sin_addr.s_addr = iphdr.ip_dst.s_addr;
   
   // Submit request for a raw socket descriptor.
   if ((sd = socket (AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
      perror ("socket() failed ");
      return 1;
   }
   
   // Set flag so socket expects us to provide IPv4 header.
   if (setsockopt (sd, IPPROTO_IP, IP_HDRINCL, &on, sizeof (on)) < 0) {
      perror ("setsockopt() failed to set IP_HDRINCL ");
      return 1;
   }
   
   // Bind socket to interface index.
   if (setsockopt (sd, SOL_SOCKET, SO_BINDTODEVICE, &ifr, sizeof (ifr)) < 0) {
      perror ("setsockopt() failed to bind to interface ");
      return 1;
   }
   
   // Send packet.
   if (sendto (sd, packet, IP4_HDRLEN + UDP_HDRLEN + datalen, 0, (struct sockaddr *) &sin, sizeof (struct sockaddr)) < 0) {
      perror ("sendto() failed ");
      return 1;
   }
   
   // Close socket descriptor.
   close (sd);
   
   // Free allocated memory.
   free (data);
   free (packet);
   free (interface);
   free (target);
   free (src_ip);
   free (dst_ip);
   free (ip_flags);
*/
   
   return 0;
}

