/*  Copyright (C) 2011  P.D. Buchan (pdbuchan@yahoo.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Receive an IPv4 router advertisement and extract
// various information stored in the ethernet frame.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <netinet/in.h>       // IPPROTO_RAW, IPPROTO_IP, IPPROTO_ICMP
#include <netinet/ip.h>       // struct ip and IP_MAXPACKET (which is 65535)
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <sys/types.h>        // needed for socket()
#include <sys/socket.h>       // needed for socket()
#include <netinet/ip_icmp.h>  // ICMP_ROUTERADVERT
#include <linux/if_ether.h>   // ETH_P_IP = 0x0800, ETH_P_ALL = 0x0003
#include <net/ethernet.h>

#include <errno.h>            // errno, perror()

// Define a struct for an IPv4 ICMP router advertisement header
typedef struct _ra_hdr ra_hdr;
struct _ra_hdr {
  unsigned char icmp_type;
  unsigned char icmp_code;
  unsigned short int icmp_cksum;
  unsigned char num_addrs;
  unsigned char entry_size;
  unsigned short int lifetime;
  unsigned char addrs[2040];
};

// Define some constants.
#define IP4_HDRLEN 20         // IPv4 header length
#define ICMP_HDRLEN 8         // IPv4 ICMP header length excluding data

int
main (int argc, char **argv)
{
  int i, offset, sd, status;
  unsigned char *ether_frame;
  struct ip *iphdr;
  ra_hdr *rahdr;
  char *src_ip, *dst_ip;
  void *tmp;

// Allocate memory for various arrays.

  tmp = (unsigned char *) malloc (IP_MAXPACKET);
  if (tmp != NULL) {
    ether_frame = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'ether_frame'.\n");
    exit (EXIT_FAILURE);
  }
  memset (ether_frame, 0, IP_MAXPACKET);

  tmp = (unsigned char *) malloc (16);
  if (tmp != NULL) {
    src_ip = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'src_ip'.\n");
    exit (EXIT_FAILURE);
  }
  memset (src_ip, 0, 16);

  tmp = (unsigned char *) malloc (16);
  if (tmp != NULL) {
    dst_ip = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'dst_ip'.\n");
    exit (EXIT_FAILURE);
  }
  memset (dst_ip, 0, 16);

// Submit request for a raw socket descriptor.
  if ((sd = socket (PF_PACKET, SOCK_RAW, htons (ETH_P_ALL))) < 0) {
    perror ("socket() failed ");
    exit (EXIT_FAILURE);
  }

// Listen for incoming ethernet frame from socket sd.
// We expect a router advertisment ethernet frame of the form:
//     MAC (6 bytes) + MAC (6 bytes) + ethernet type (2 bytes)
//     + ethernet data (IPv4 header + RA header)
// Keep at it until we get a router advertisement.
  iphdr = (struct ip *) (ether_frame + 6 + 6 +2);
  rahdr = (ra_hdr *) (ether_frame + 6 + 6 + 2 + IP4_HDRLEN);
  while (((((ether_frame[12]) << 8) + ether_frame[13]) != ETH_P_IP) || (iphdr->ip_p != IPPROTO_ICMP) ||
         (rahdr->icmp_type != ICMP_ROUTERADVERT)) {
    if ((status = recv (sd, ether_frame, IP_MAXPACKET, 0)) < 0) {
      if (errno == EINTR) {
        memset (ether_frame, 0, IP_MAXPACKET);
        continue;  // Something weird happened, but let's try again.
      } else {
        perror ("recv() failed:");
        exit (EXIT_FAILURE);
      }
    }
  }
  close (sd);

// Print out contents of received ethernet frame.
  printf ("\nEthernet frame header:\n");
  printf ("Destination MAC (this node): ");
  for (i=0; i<5; i++) {
    printf ("%02x:", ether_frame[i]);
  }
  printf ("%02x\n", ether_frame[5]);
  printf ("Source MAC: ");
  for (i=0; i<5; i++) {
    printf ("%02x:", ether_frame[i+6]);
  }
  printf ("%02x\n", ether_frame[11]);
  // Next is ethernet type code (ETH_P_IP for IPv4 packets).
  // http://www.iana.org/assignments/ethernet-numbers
  printf ("Ethernet type code (2048 = IPv4): %u\n", ((ether_frame[12]) << 8) + ether_frame[13]);
  printf ("\nEthernet data (IPv4 header + Router Advertisement header)\n");
  printf ("IPv4 transport layer protocol (1 = ICMP): %u\n", iphdr->ip_p);
  inet_ntop (AF_INET, &(iphdr->ip_src), src_ip, 16);
  printf ("Source IPv4 address: %s\n", src_ip);
  inet_ntop (AF_INET, &(iphdr->ip_dst), dst_ip, 16);
  printf ("Destination IPv4 address: %s\n", dst_ip);
  printf ("ICMP message type (9 = router advertisement): %u\n", rahdr->icmp_type);
  printf ("ICMP message code: %u\n", rahdr->icmp_code);
  printf ("Number of IPv4 addresses associated with router: %u\n", rahdr->num_addrs);
  printf ("Router address entry size (in units of 32 bit words): %u\n", rahdr->entry_size);
  printf ("Lifetime of validity of router advertisement (seconds): %u\n", ntohs (rahdr->lifetime));
  offset = 6 + 6 + 2 + IP4_HDRLEN + ICMP_HDRLEN;  // Start of list of addresses and preference levels within ethernet frame
  for (i=0; i<rahdr->num_addrs; i++) {
    printf ("Router %i IPv4 address: %u:%u:%u:%u\n", 
     i, ether_frame[offset + (i * rahdr->entry_size * 4) + 0],
        ether_frame[offset + (i * rahdr->entry_size * 4) + 1],
        ether_frame[offset + (i * rahdr->entry_size * 4) + 2],
        ether_frame[offset + (i * rahdr->entry_size * 4) + 3]);
    printf ("Router %i preference level: %u\n", i,  ((ether_frame[offset + (i * rahdr->entry_size * 4) + 4]) << 24) +
     ((ether_frame[offset + (i * rahdr->entry_size * 4) + 5]) << 16) +
     ((ether_frame[offset + (i * rahdr->entry_size * 4) + 6]) << 8) +
     ether_frame[offset + (i * rahdr->entry_size * 4) + 7]);
    offset += rahdr->entry_size * 4;
  }

  free (ether_frame);
  free (src_ip);
  free (dst_ip);

  return (EXIT_SUCCESS);
}
