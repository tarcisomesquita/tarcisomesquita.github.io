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

// Send an IPv6 UDP packet via raw socket at the link layer (ethernet frame).
// Need to have destination MAC address.
// Includes some UDP data.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <netdb.h>            // struct addrinfo
#include <sys/types.h>        // needed for socket()
#include <sys/socket.h>       // needed for socket()
#include <netinet/in.h>       // IPPROTO_RAW, IPPROTO_UDP
#include <netinet/ip.h>       // IP_MAXPACKET (which is 65535)
#include <netinet/ip6.h>      // struct ip6_hdr
#include <netinet/udp.h>      // struct udphdr
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <sys/ioctl.h>        // macro ioctl is defined
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl.
#include <net/if.h>           // struct ifreq
#include <linux/if_ether.h>   // ETH_P_IP = 0x0800, ETH_P_IPV6 = 0x86DD
#include <linux/if_packet.h>  // struct sockaddr_ll (see man 7 packet)
#include <net/ethernet.h>

#include <errno.h>            // errno, perror()

// Define some constants.
#define IP6_HDRLEN 40         // IPv6 header length
#define UDP_HDRLEN  8         // UDP header length, excludes data

// Function prototypes
unsigned short int checksum (unsigned short int *, int);
unsigned short int udp6_checksum (struct ip6_hdr, struct udphdr, unsigned char *, int);

int
main (int argc, char **argv)
{
  int i, status, datalen, frame_length, sd, bytes;
  char *interface, *target, *src_ip, *dst_ip;
  struct ip6_hdr iphdr;
  struct udphdr udphdr;
  unsigned char *data, *src_mac, *dst_mac, *ether_frame;
  struct addrinfo hints, *res;
  struct sockaddr_in6 *ipv6;
  struct sockaddr_ll device;
  struct ifreq ifr;
  void *tmp;

// Allocate memory for various arrays.

  tmp = (unsigned char *) malloc (6 * sizeof (unsigned char));
  if (tmp != NULL) {
    src_mac = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'src_mac'.\n");
    exit (EXIT_FAILURE);
  }
  memset (src_mac, 0, 6);

  tmp = (unsigned char *) malloc (6 * sizeof (unsigned char));
  if (tmp != NULL) {
    dst_mac = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'dst_mac'.\n");
    exit (EXIT_FAILURE);
  }
  memset (dst_mac, 0, 6);

  // Maximum UDP payload size = 65535 - IPv6 header (40 bytes) - UDP header (8 bytes)
  tmp = (unsigned char *) malloc ((IP_MAXPACKET - IP6_HDRLEN - UDP_HDRLEN) * sizeof (unsigned char));
  if (tmp != NULL) {
    data = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'data'.\n");
    exit (EXIT_FAILURE);
  }
  memset (data, 0, IP_MAXPACKET - IP6_HDRLEN - UDP_HDRLEN);

  tmp = (unsigned char *) malloc (IP_MAXPACKET * sizeof (unsigned char));
  if (tmp != NULL) {
    ether_frame = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'ether_frame'.\n");
    exit (EXIT_FAILURE);
  }
  memset (ether_frame, 0, IP_MAXPACKET);

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    interface = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'interface'.\n");
    exit (EXIT_FAILURE);
  }
  memset (interface, 0, 40);

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    target = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'target'.\n");
    exit (EXIT_FAILURE);
  }
  memset (target, 0, 40);

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    src_ip = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'src_ip'.\n");
    exit (EXIT_FAILURE);
  }
  memset (src_ip, 0, 40);

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    dst_ip = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'dst_ip'.\n");
    exit (EXIT_FAILURE);
  }
  memset (dst_ip, 0, 40);

// Interface to send packet through.
  strcpy (interface, "wlan0");

// Submit request for a socket descriptor to lookup interface.
  if ((sd = socket (AF_INET6, SOCK_RAW, IPPROTO_RAW)) < 0) {
    perror ("socket() failed to get socket descriptor for using ioctl() ");
    exit (EXIT_FAILURE);
  }

// Use ioctl() to lookup interface and get MAC address.
  memset (&ifr, 0, sizeof (ifr));
  snprintf (ifr.ifr_name, sizeof (ifr.ifr_name), "%s", interface);
  if (ioctl (sd, SIOCGIFHWADDR, &ifr) < 0) {
    perror ("ioctl() failed to get source MAC address ");
    return (EXIT_FAILURE);
  }
  close (sd);

// Copy source MAC address.
  memcpy (src_mac, ifr.ifr_hwaddr.sa_data, 6);

// Report source MAC address to stdout.
  printf ("MAC address for interface %s is ", interface);
  for (i=0; i<5; i++) {
    printf ("%02x:", src_mac[i]);
  }
  printf ("%02x\n", src_mac[5]);

// Resolve interface index.
  if ((device.sll_ifindex = if_nametoindex (interface)) == 0) {
    perror ("if_nametoindex() failed to obtain interface index ");
    exit (EXIT_FAILURE);
  }
  printf ("Index for interface %s is %i\n", interface, device.sll_ifindex);

// Set destination MAC address: you need to fill these out
  dst_mac[0] = 0xff;
  dst_mac[1] = 0xff;
  dst_mac[2] = 0xff;
  dst_mac[3] = 0xff;
  dst_mac[4] = 0xff;
  dst_mac[5] = 0xff;

// Source IPv6 address: you need to fill this out
  strcpy (src_ip, "2002::1");

// Destination URL or IPv6 address
  strcpy (target, "ipv6.google.com");

// Fill out hints for getaddrinfo().
  memset (&hints, 0, sizeof (hints));
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = hints.ai_flags | AI_CANONNAME;

// Resolve target using getaddrinfo().
  if ((status = getaddrinfo (target, NULL, &hints, &res)) != 0) {
    fprintf (stderr, "getaddrinfo() failed: %s\n", gai_strerror (status));
    exit (EXIT_FAILURE);
  }
  ipv6 = (struct sockaddr_in6 *) res->ai_addr;
  tmp = &(ipv6->sin6_addr);
  inet_ntop (AF_INET6, tmp, dst_ip, 40);
  freeaddrinfo (res);

// Fill out sockaddr_ll.
  device.sll_family = AF_PACKET;
  memcpy (device.sll_addr, src_mac, 6);
  device.sll_halen = htons (6);

// UDP data
  datalen = 4;
  data[0] = 'T';
  data[1] = 'e';
  data[2] = 's';
  data[3] = 't';

// IPv6 header

// IPv6 version (4 bits), Traffic class (8 bits), Flow label (20 bits)
  iphdr.ip6_flow = htonl ((6 << 28) | (0 << 20) | 0);

// Payload length (16 bits): UDP header + UDP data
  iphdr.ip6_plen = htons (UDP_HDRLEN + datalen);

// Next header (8 bits): 17 for UDP
  iphdr.ip6_nxt = IPPROTO_UDP;

// Hop limit (8 bits): default to maximum value
  iphdr.ip6_hops = 255;

// Source IPv6 address (128 bits)
  inet_pton (AF_INET6, src_ip, &iphdr.ip6_src);

// Destination IPv6 address (128 bits)
  inet_pton (AF_INET6, dst_ip, &iphdr.ip6_dst);

// UDP header

// Source port number (16 bits): pick a number
  udphdr.source = htons (4950);

// Destination port number (16 bits): pick a number
  udphdr.dest = htons (4950);

// Length of UDP datagram (16 bits): UDP header + UDP data
  udphdr.len = htons (UDP_HDRLEN + datalen);

// UDP checksum (16 bits)
  udphdr.check = udp6_checksum (iphdr, udphdr, data, datalen);

// Fill out ethernet frame header.

// Ethernet frame length = ethernet header (MAC + MAC + ethernet type) + ethernet data (IP header + UDP header + UDP data)
  frame_length = 6 + 6 + 2 + IP6_HDRLEN + UDP_HDRLEN + datalen;

// Destination and Source MAC addresses
  memcpy (ether_frame, dst_mac, 6);
  memcpy (ether_frame + 6, src_mac, 6);

// Next is ethernet type code (ETH_P_IPV6 for IPv6).
// http://www.iana.org/assignments/ethernet-numbers
  ether_frame[12] = ETH_P_IPV6 / 256;
  ether_frame[13] = ETH_P_IPV6 % 256;

// Next is ethernet frame data (IPv6 header + UDP header + UDP data).

// IPv6 header
  memcpy (ether_frame + 14, &iphdr, IP6_HDRLEN);

// UDP header
  memcpy (ether_frame + 14 + IP6_HDRLEN, &udphdr, UDP_HDRLEN);

// UDP data
  memcpy (ether_frame + 14 + IP6_HDRLEN + UDP_HDRLEN, data, datalen);

// Submit request for a raw socket descriptor.
  if ((sd = socket (PF_PACKET, SOCK_RAW, htons (ETH_P_ALL))) < 0) {
    perror ("socket() failed ");
    exit (EXIT_FAILURE);
  }

// Send ethernet frame to socket.
  if ((bytes = sendto (sd, ether_frame, frame_length, 0, (struct sockaddr *) &device, sizeof (device))) <= 0) {
    perror ("sendto() failed");
    exit (EXIT_FAILURE);
  }

// Close socket descriptor.
  close (sd);

// Free allocated memory.
  free (src_mac);
  free (dst_mac);
  free (data);
  free (ether_frame);
  free (interface);
  free (target);
  free (src_ip);
  free (dst_ip);

  return (EXIT_SUCCESS);
}

// Checksum function
unsigned short int
checksum (unsigned short int *addr, int len)
{
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

// Build IPv6 UDP pseudo-header and call checksum function (Section 8.1 of RFC 2460).
unsigned short int
udp6_checksum (struct ip6_hdr iphdr, struct udphdr udphdr, unsigned char *payload, int payloadlen)
{
  char buf[IP_MAXPACKET];
  char *ptr;
  int chksumlen = 0;
  int i;

  ptr = &buf[0];  // ptr points to beginning of buffer buf

  // Copy source IP address into buf (128 bits)
  memcpy (ptr, &iphdr.ip6_src.s6_addr, sizeof (iphdr.ip6_src.s6_addr));
  ptr += sizeof (iphdr.ip6_src.s6_addr);
  chksumlen += sizeof (iphdr.ip6_src.s6_addr);

  // Copy destination IP address into buf (128 bits)
  memcpy (ptr, &iphdr.ip6_dst.s6_addr, sizeof (iphdr.ip6_dst.s6_addr));
  ptr += sizeof (iphdr.ip6_dst.s6_addr);
  chksumlen += sizeof (iphdr.ip6_dst.s6_addr);

  // Copy UDP length into buf (32 bits)
  memcpy (ptr, &udphdr.len, sizeof (udphdr.len));
  ptr += sizeof (udphdr.len);
  chksumlen += sizeof (udphdr.len);

  // Copy zero field to buf (24 bits)
  *ptr = 0; ptr++;
  *ptr = 0; ptr++;
  *ptr = 0; ptr++;
  chksumlen += 3;

  // Copy next header field to buf (8 bits)
  memcpy (ptr, &iphdr.ip6_nxt, sizeof (iphdr.ip6_nxt));
  ptr += sizeof (iphdr.ip6_nxt);
  chksumlen += sizeof (iphdr.ip6_nxt);

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
