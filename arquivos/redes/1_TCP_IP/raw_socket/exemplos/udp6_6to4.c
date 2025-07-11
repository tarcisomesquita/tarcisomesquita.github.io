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

// Send an IPv6 UDP echo request packet
// through an IPv4 tunnel (6to4).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <netinet/ip.h>       // struct ip and IP_MAXPACKET (which is 65535)
#include <netinet/in.h>       // IPPROTO_RAW, IPPROTO_IP, IPPROTO_IPV6, IPPROTO_UDP
#include <netinet/ip6.h>      // struct ip6_hdr
#include <netinet/udp.h>      // struct udphdr
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <netdb.h>            // struct addrinfo
#include <sys/ioctl.h>        // macro ioctl is defined
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl. Here, we need SIOCGIFHWADDR
#include <net/if.h>           // struct ifreq

// Define some constants.
#define IP4_HDRLEN 20      // IPv4 header length
#define IP6_HDRLEN 40      // IPv6 header length
#define UDP_HDRLEN  8      // UDP header length, excludes data

// Function prototypes
unsigned short int checksum (unsigned short int *, int);
unsigned short int udp6_checksum (struct ip6_hdr, struct udphdr, unsigned char *, int);

int
main (int argc, char **argv)
{
  int on, status, datalen, sd;
  unsigned short int *ip4_flags;
  struct ip *ip4hdr;
  struct ip6_hdr *ip6hdr;
  struct udphdr *udphdr;
  struct addrinfo hints;
  struct addrinfo *res;
  struct sockaddr_in sin;
  struct sockaddr_in6 *ipv6, src, dst;
  socklen_t srclen;
  unsigned char *outpack, *data;
  char *target4, *target6, *source4, *source6, *src_ip, *dst_ip;
  void *tmp;

// Allocate memory for various arrays.

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    target4 = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'target4'.\n");
    exit (EXIT_FAILURE);
  }
  memset (target4, 0, 40 * sizeof (char));

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    target6 = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'target6'.\n");
    exit (EXIT_FAILURE);
  }
  memset (target6, 0, 40 * sizeof (char));

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    source4 = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'source4'.\n");
    exit (EXIT_FAILURE);
  }
  memset (source4, 0, 40 * sizeof (char));

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    source6 = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'source6'.\n");
    exit (EXIT_FAILURE);
  }
  memset (source6, 0, 40 * sizeof (char));

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

  tmp = (unsigned char *) malloc (IP_MAXPACKET * sizeof (unsigned char));
  if (tmp != NULL) {
    outpack = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'outpack'.\n");
    exit (EXIT_FAILURE);
  }
  memset (outpack, 0, IP_MAXPACKET * sizeof (unsigned char));

  tmp = (unsigned char *) malloc (4 * sizeof (unsigned char));
  if (tmp != NULL) {
    ip4_flags = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'ip4_flags'.\n");
    exit (EXIT_FAILURE);
  }
  memset (ip4_flags, 0, 4 * sizeof (unsigned char));

  // Maximum UDP payload size = 65535 - IPv6 header (40 bytes) - UDP header (8 bytes)
  tmp = (unsigned char *) malloc (IP_MAXPACKET - IP6_HDRLEN - UDP_HDRLEN);
  if (tmp != NULL) {
    data = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'data'.\n");
    exit (EXIT_FAILURE);
  }
  memset (data, 0, IP_MAXPACKET - IP6_HDRLEN - UDP_HDRLEN);

// Source IPv4 address: you need to fill this out
  strcpy (source4, "192.168.1.116");

// Source IPv6 address: you need to fill this out
  strcpy (source6, "2002::1");

// IPv4 target as the 6to4 anycast address (do not change)
  strcpy (target4, "192.88.99.1");

// Target URL or IPv6 address.
  strcpy (target6, "ipv6.google.com");

// Fill out hints for getaddrinfo().
  memset (&hints, 0, sizeof (hints));
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = hints.ai_flags | AI_CANONNAME;

// Resolve source using getaddrinfo().
  if ((status = getaddrinfo (source6, NULL, &hints, &res)) != 0) {
    fprintf (stderr, "getaddrinfo() failed: %s\n", gai_strerror (status));
    return (EXIT_FAILURE);
  }
  memcpy (&src, res->ai_addr, res->ai_addrlen);
  srclen = res->ai_addrlen;
  ipv6 = (struct sockaddr_in6 *) res->ai_addr;
  tmp = &(ipv6->sin6_addr);
  inet_ntop (AF_INET6, tmp, src_ip, 40);
  freeaddrinfo (res);

// Resolve target using getaddrinfo().
  if ((status = getaddrinfo (target6, NULL, &hints, &res)) != 0) {
    fprintf (stderr, "getaddrinfo() failed: %s\n", gai_strerror (status));
    return (EXIT_FAILURE);
  }
  memcpy (&dst, res->ai_addr, res->ai_addrlen);
  ipv6 = (struct sockaddr_in6 *) res->ai_addr;
  tmp = &(ipv6->sin6_addr);
  inet_ntop (AF_INET6, tmp, dst_ip, 40);
  freeaddrinfo (res);

// Submit request for a raw IPv4 socket descriptor.
  if ((sd = socket (AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) {
    perror ("socket() failed ");
    exit (EXIT_FAILURE);
  }

// Set flag so socket expects us to provide IPv4 header.
  on = 1;
  if (setsockopt (sd, IPPROTO_IP, IP_HDRINCL, &on, sizeof (on)) < 0) {
    perror ("setsockopt() failed to set IP_HDRINCL ");
    exit (EXIT_FAILURE);
  }

// Copy options data into options buffer.
  datalen = 4;
  data[0] = 'T';
  data[1] = 'e';
  data[2] = 's';
  data[3] = 't';

// IPv4 header (Section 3.5 of RFC 4213)

// Define first part of buffer outpack to be an IPv4 header.
  ip4hdr = (struct ip *) outpack;

// IPv4 header

// IPv4 header length (4 bits): Number of 32-bit words in header = 5
  ip4hdr->ip_hl = sizeof (struct ip) / sizeof (unsigned long int);

// Internet Protocol version (4 bits): IPv4
  ip4hdr->ip_v = 4;

// Type of service (8 bits)
  ip4hdr->ip_tos = 0;

// Total length of datagram (16 bits): IPv6 payload length + IPv4 header + IPv6 header
  ip4hdr->ip_len = htons (UDP_HDRLEN + datalen + IP4_HDRLEN + IP6_HDRLEN);

// ID sequence number (16 bits): unused, since single datagram
  ip4hdr->ip_id = htons (0);

// Flags, and Fragmentation offset (3, 13 bits): 0 since single datagram

// Zero (1 bit)
  ip4_flags[0] = 0;

// Do not fragment flag (1 bit)
  ip4_flags[1] = 1;

// More fragments following flag (1 bit)
  ip4_flags[2] = 0;

// Fragmentation offset (13 bits)
  ip4_flags[3] = 0;

  ip4hdr->ip_off = htons ((ip4_flags[0] << 15)
                        + (ip4_flags[1] << 14)
                        + (ip4_flags[2] << 13)
                         + ip4_flags[3]);

// Time-to-Live (8 bits): use maximum value
  ip4hdr->ip_ttl = 255;

// Transport layer protocol (8 bits): 41 for IPv6 (Section 3.5 of RFC 4213)
  ip4hdr->ip_p = IPPROTO_IPV6;

// Source IPv4 address (32 bits)
  inet_pton (AF_INET, source4, &ip4hdr->ip_src);

// Destination IPv4 address (32 bits)
  inet_pton (AF_INET, target4, &ip4hdr->ip_dst);

// IPv4 header checksum (16 bits) - set to 0 when calculating checksum
  ip4hdr->ip_sum = 0;
  ip4hdr->ip_sum = checksum ((unsigned short int *) ip4hdr, IP4_HDRLEN);

// IPv6 header

// Define next part of buffer outpack to be an IPv6 header.
  ip6hdr = (struct ip6_hdr *) (outpack + IP4_HDRLEN);

// IPv6 version (4 bits), Traffic class (8 bits), Flow label (20 bits)
  ip6hdr->ip6_flow = htonl ((6 << 28) | (0 << 20) | 0);

// Payload length (16 bits)
  ip6hdr->ip6_plen = htons (UDP_HDRLEN + datalen);

// Next header (8 bits) - 17 for UDP
  ip6hdr->ip6_nxt = IPPROTO_UDP;

// Hop limit  (8 bits) - use 255 (RFC 4861)
  ip6hdr->ip6_hops = 255;

// Source IPv6 address (128 bits)
  inet_pton (AF_INET6, src_ip, &ip6hdr->ip6_src);

// Destination IPv6 address (128 bits)
  inet_pton (AF_INET6, dst_ip, &ip6hdr->ip6_dst);

// UDP header

// Define next part of buffer outpack to be a udphdr struct.
  udphdr = (struct udphdr *) (outpack + IP4_HDRLEN + IP6_HDRLEN);

// Source port number (16 bits): pick a number
  udphdr->source = htons (4950);

// Destination port number (16 bits): pick a number
  udphdr->dest = htons (4950);

// Length of UDP datagram (16 bits): UDP header + UDP data
  udphdr->len = htons (UDP_HDRLEN + datalen);

// UDP checksum (16 bits)
  udphdr->check = udp6_checksum (*ip6hdr, *udphdr, data, datalen);

// Append data to end of udphdr struct.
  memcpy (outpack + IP4_HDRLEN + IP6_HDRLEN + UDP_HDRLEN, data, datalen);

  memset (&sin, 0, sizeof (sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = ip4hdr->ip_dst.s_addr;

  if (sendto (sd, outpack, IP4_HDRLEN + IP6_HDRLEN + UDP_HDRLEN + datalen, 0, (struct sockaddr *) &sin, sizeof (struct sockaddr)) < 0)  {
    perror ("sendto() failed ");
    exit (EXIT_FAILURE);
  }

  close (sd);
  free (target4);
  free (target6);
  free (source4);
  free (source6);
  free (src_ip);
  free (dst_ip);
  free (ip4_flags);
  free (outpack);
  free (data);

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
