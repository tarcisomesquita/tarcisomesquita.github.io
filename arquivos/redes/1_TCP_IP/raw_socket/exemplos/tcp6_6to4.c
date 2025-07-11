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

// Send an IPv6 TCP SYN packet
// through an IPv4 tunnel (6to4).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <netinet/ip.h>       // struct ip and IP_MAXPACKET (which is 65535)
#include <netinet/in.h>       // IPPROTO_RAW, IPPROTO_IP, IPPROTO_IPV6, IPPROTO_TCP
#include <netinet/ip6.h>      // struct ip6_hdr
#define __FAVOR_BSD           // Use BSD format of tcp header
#include <netinet/tcp.h>      // struct tcphdr
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <netdb.h>            // struct addrinfo
#include <sys/ioctl.h>        // macro ioctl is defined
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl. Here, we need SIOCGIFHWADDR
#include <net/if.h>           // struct ifreq

// Define some constants.
#define IP4_HDRLEN 20      // IPv4 header length
#define IP6_HDRLEN 40      // IPv6 header length
#define TCP_HDRLEN 20      // TCP header length, excludes options data

// Function prototypes
unsigned short int checksum (unsigned short int *, int);
unsigned short int tcp6_checksum (struct ip6_hdr, struct tcphdr);

int
main (int argc, char **argv)
{
  int i, on, status, sd;
  unsigned short int *ip4_flags, *tcp_flags;
  struct ip *ip4hdr;
  struct ip6_hdr *ip6hdr;
  struct tcphdr *tcphdr;
  struct addrinfo hints;
  struct addrinfo *res;
  struct sockaddr_in sin;
  struct sockaddr_in6 *ipv6, src, dst;
  socklen_t srclen;
  unsigned char *outpack;
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

  tmp = (unsigned char *) malloc (16 * sizeof (char));
  if (tmp != NULL) {
    tcp_flags = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'tcp_flags'.\n");
    exit (EXIT_FAILURE);
  }
  memset (tcp_flags, 0, 4);

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
  ip4hdr->ip_len = htons (TCP_HDRLEN + IP4_HDRLEN + IP6_HDRLEN);

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

// Define next part of buffer outpack to be an IPv6 header.
  ip6hdr = (struct ip6_hdr *) (outpack + IP4_HDRLEN);

// IPv6 header

// IPv6 version (4 bits), Traffic class (8 bits), Flow label (20 bits)
  ip6hdr->ip6_flow = htonl ((6 << 28) | (0 << 20) | 0);

// Payload length (16 bits)
  ip6hdr->ip6_plen = htons (TCP_HDRLEN);

// Next header (8 bits) - 6 for TCP
  ip6hdr->ip6_nxt = IPPROTO_TCP;

// Hop limit  (8 bits) - use 255 (RFC 4861)
  ip6hdr->ip6_hops = 255;

// Source IPv6 address (128 bits)
  inet_pton (AF_INET6, src_ip, &ip6hdr->ip6_src);

// Destination IPv6 address (128 bits)
  inet_pton (AF_INET6, dst_ip, &ip6hdr->ip6_dst);

// TCP header

// Define next part of buffer outpack to be a tcphdr struct.
  tcphdr = (struct tcphdr *) (outpack + IP4_HDRLEN + IP6_HDRLEN);

// Source port number (16 bits)
  tcphdr->th_sport = htons (60);

// Destination port number (16 bits)
  tcphdr->th_dport = htons (80);

// Sequence number (32 bits)
  tcphdr->th_seq = htonl (0);

// Acknowledgement number (32 bits): 0 in first packet of SYN/ACK process
  tcphdr->th_ack = htonl (0);

// Reserved (4 bits): should be 0
  tcphdr->th_x2 = 0;

// Data offset (4 bits): size of TCP header in 32-bit words
  tcphdr->th_off = TCP_HDRLEN / 4;

// Flags (8 bits)

  // FIN flag (1 bit)
  tcp_flags[0] = 0;

  // SYN flag (1 bit): set to 1
  tcp_flags[1] = 1;

  // RST flag (1 bit)
  tcp_flags[2] = 0;

  // PSH flag (1 bit)
  tcp_flags[3] = 0;

  // ACK flag (1 bit)
  tcp_flags[4] = 0;

  // URG flag (1 bit)
  tcp_flags[5] = 0;

  // ECE flag (1 bit)
  tcp_flags[6] = 0;

  // CWR flag (1 bit)
  tcp_flags[7] = 0;

  tcphdr->th_flags = 0;
  for (i=0; i<8; i++) {
    tcphdr->th_flags += (tcp_flags[i] << i);
  }

// Window size (16 bits)
  tcphdr->th_win = htons (65535);

// Urgent pointer (16 bits): 0 (only valid if URG flag is set)
  tcphdr->th_urp = htons (0);

// TCP checksum (16 bits)
  tcphdr->th_sum = tcp6_checksum (*ip6hdr, *tcphdr);

  memset (&sin, 0, sizeof (sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = ip4hdr->ip_dst.s_addr;

  if (sendto (sd, outpack, IP4_HDRLEN + IP6_HDRLEN + TCP_HDRLEN, 0, (struct sockaddr *) &sin, sizeof (struct sockaddr)) < 0)  {
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
  free (tcp_flags);
  free (outpack);

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

// Build IPv6 TCP pseudo-header and call checksum function (Section 8.1 of RFC 2460).
unsigned short int
tcp6_checksum (struct ip6_hdr iphdr, struct tcphdr tcphdr)
{
  unsigned long int lvalue;
  char buf[IP_MAXPACKET], cvalue;
  char *ptr;
  int chksumlen = 0;

  ptr = &buf[0];  // ptr points to beginning of buffer buf

  // Copy source IP address into buf (128 bits)
  memcpy (ptr, &iphdr.ip6_src, sizeof (iphdr.ip6_src));
  ptr += sizeof (iphdr.ip6_src);
  chksumlen += sizeof (iphdr.ip6_src);

  // Copy destination IP address into buf (128 bits)
  memcpy (ptr, &iphdr.ip6_dst, sizeof (iphdr.ip6_dst));
  ptr += sizeof (iphdr.ip6_dst);
  chksumlen += sizeof (iphdr.ip6_dst);

  // Copy TCP length to buf (32 bits)
  lvalue = htonl (sizeof (tcphdr));
  memcpy (ptr, &lvalue, sizeof (lvalue));
  ptr += sizeof (lvalue);
  chksumlen += sizeof (lvalue);

  // Copy zero field to buf (24 bits)
  *ptr = 0; ptr++;
  *ptr = 0; ptr++;
  *ptr = 0; ptr++;
  chksumlen += 3;

  // Copy next header field to buf (8 bits)
  memcpy (ptr, &iphdr.ip6_nxt, sizeof (iphdr.ip6_nxt));
  ptr += sizeof (iphdr.ip6_nxt);
  chksumlen += sizeof (iphdr.ip6_nxt);

  // Copy TCP source port to buf (16 bits)
  memcpy (ptr, &tcphdr.th_sport, sizeof (tcphdr.th_sport));
  ptr += sizeof (tcphdr.th_sport);
  chksumlen += sizeof (tcphdr.th_sport);

  // Copy TCP destination port to buf (16 bits)
  memcpy (ptr, &tcphdr.th_dport, sizeof (tcphdr.th_dport));
  ptr += sizeof (tcphdr.th_dport);
  chksumlen += sizeof (tcphdr.th_dport);

  // Copy sequence number to buf (32 bits)
  memcpy (ptr, &tcphdr.th_seq, sizeof (tcphdr.th_seq));
  ptr += sizeof (tcphdr.th_seq);
  chksumlen += sizeof (tcphdr.th_seq);

  // Copy acknowledgement number to buf (32 bits)
  memcpy (ptr, &tcphdr.th_ack, sizeof (tcphdr.th_ack));
  ptr += sizeof (tcphdr.th_ack);
  chksumlen += sizeof (tcphdr.th_ack);

  // Copy data offset to buf (4 bits) and
  // copy reserved bits to buf (4 bits)
  cvalue = (tcphdr.th_off << 4) + tcphdr.th_x2;
  memcpy (ptr, &cvalue, sizeof (cvalue));
  ptr += sizeof (cvalue);
  chksumlen += sizeof (cvalue);

  // Copy TCP flags to buf (8 bits)
  memcpy (ptr, &tcphdr.th_flags, sizeof (tcphdr.th_flags));
  ptr += sizeof (tcphdr.th_flags);
  chksumlen += sizeof (tcphdr.th_flags);

  // Copy TCP window size to buf (16 bits)
  memcpy (ptr, &tcphdr.th_win, sizeof (tcphdr.th_win));
  ptr += sizeof (tcphdr.th_win);
  chksumlen += sizeof (tcphdr.th_win);

  // Copy TCP checksum to buf (16 bits)
  // Zero, since we don't know it yet
  *ptr = 0; ptr++;
  *ptr = 0; ptr++;
  chksumlen += 2;

  // Copy urgent pointer to buf (16 bits)
  memcpy (ptr, &tcphdr.th_urp, sizeof (tcphdr.th_urp));
  ptr += sizeof (tcphdr.th_urp);
  chksumlen += sizeof (tcphdr.th_urp);

  return checksum ((unsigned short int *) buf, chksumlen);
}
