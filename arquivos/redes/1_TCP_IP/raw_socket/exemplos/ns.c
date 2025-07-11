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

// Send an IPv6 ICMP neighbor solicitation packet.
// Change hoplimit and specify interface using ancillary
// data method.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <netinet/icmp6.h>    // struct nd_neighbor_solicit, which contains icmp6_hdr, ND_NEIGHBOR_SOLICIT
#include <netinet/in.h>       // IPPROTO_IPV6, IPPROTO_ICMPV6
#include <netinet/ip.h>       // IP_MAXPACKET (65535)
#include <arpa/inet.h>        // inet_pton() and inet_ntop()
#include <netdb.h>            // struct addrinfo
#include <sys/ioctl.h>        // macro ioctl is defined
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl. Here, we need SIOCGIFHWADDR
#include <bits/socket.h>      // structs msghdr and cmsghdr
#include <net/if.h>           // struct ifreq

// Taken from <linux/ipv6.h>, also in <netinet/in.h>
struct in6_pktinfo {
        struct in6_addr ipi6_addr;
        int             ipi6_ifindex;
};

// Function prototypes
unsigned short int checksum (unsigned short int *, int);

int
main (int argc, char **argv)
{
  int NS_HDRLEN = sizeof (struct nd_neighbor_solicit);  // Length of NS message header
  int optlen = 8; // Option Type (1 byte) + Length (1 byte) + Length of MAC address (6 bytes)

  int i, sd, status, ifindex, cmsglen, hoplimit, psdhdrlen;
  struct addrinfo hints;
  struct addrinfo *res;
  struct sockaddr_in6 *ipv6, src, dst, dstsnmc;
  struct nd_neighbor_solicit *ns;
  socklen_t srclen;
  unsigned char *outpack, *options, *psdhdr;
  struct msghdr msghdr;
  struct ifreq ifr;
  struct cmsghdr *cmsghdr1, *cmsghdr2;
  struct in6_pktinfo *pktinfo;
  struct iovec iov[2];
  char *target, *source, *interface;
  void *tmp;

// Allocate memory for various arrays.

  tmp = (char *) malloc (20 * sizeof (char));
  if (tmp != NULL) {
    interface = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'interface'.\n");
    exit (EXIT_FAILURE);
  }
  memset (interface, 0, sizeof (interface));

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    target = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'target'.\n");
    exit (EXIT_FAILURE);
  }
  memset (target, 0, 40 * sizeof (char));

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    source = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'source'.\n");
    exit (EXIT_FAILURE);
  }
  memset (source, 0, 40 * sizeof (char));

  tmp = (unsigned char *) malloc (IP_MAXPACKET * sizeof (unsigned char));
  if (tmp != NULL) {
    outpack = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'outpack'.\n");
    exit (EXIT_FAILURE);
  }
  memset (outpack, 0, IP_MAXPACKET * sizeof (unsigned char));

  tmp = (unsigned char *) malloc (optlen * sizeof (unsigned char));
  if (tmp != NULL) {
    options = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'options'.\n");
    exit (EXIT_FAILURE);
  }
  memset (options, 0, optlen * sizeof (unsigned char));

  tmp = (unsigned char *) malloc (IP_MAXPACKET * sizeof (unsigned char));
  if (tmp != NULL) {
    psdhdr = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'psdhdr'.\n");
    exit (EXIT_FAILURE);
  }
  memset (psdhdr, 0, IP_MAXPACKET * sizeof (unsigned char));

// Interface to send packet through.
  strcpy (interface, "wlan0");

// Source (node sending solicitation) IPv6 unicast address, or
// the IPv6 unspecified address (::).
// You need to fill this out.
  strcpy (source, "::");

// Target (which must be link-local) hostname or IPv6 address (node we're requesting an advertisement from).
// You need to fill this out.
  strcpy (target, "");

// Fill out hints for getaddrinfo().
  memset (&hints, 0, sizeof (struct addrinfo));
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = hints.ai_flags | AI_CANONNAME;

// Resolve source using getaddrinfo().
  if ((status = getaddrinfo (source, NULL, &hints, &res)) != 0) {
    fprintf (stderr, "getaddrinfo() failed: %s\n", gai_strerror (status));
    return (EXIT_FAILURE);
  }
  memcpy (&src, res->ai_addr, res->ai_addrlen);
  srclen = res->ai_addrlen;
  memcpy (psdhdr, src.sin6_addr.s6_addr, 16);  // Copy to checksum pseudo-header
  freeaddrinfo (res);

// Resolve target using getaddrinfo().
  if ((status = getaddrinfo (target, NULL, &hints, &res)) != 0) {
    fprintf (stderr, "getaddrinfo() failed: %s\n", gai_strerror (status));
    return (EXIT_FAILURE);
  }
  memcpy (&dst, res->ai_addr, res->ai_addrlen);
  memcpy (&dstsnmc, res->ai_addr, res->ai_addrlen); 

// Report target's unicast address.
  ipv6 = (struct sockaddr_in6 *) res->ai_addr;
  tmp = &(ipv6->sin6_addr);
  memset (target, 0, 40);
  inet_ntop (AF_INET6, tmp, target, 40);
  printf ("Target unicast IPv6 address: %s\n", target);
  freeaddrinfo (res);

// Convert target's IPv6 unicast address to solicited-node multicast address.
// Section 2.7.1 of RFC 4291.
  dstsnmc.sin6_addr.s6_addr[0]= 255;
  dstsnmc.sin6_addr.s6_addr[1]=2;
  for (i=2; i<11; i++) {
    dstsnmc.sin6_addr.s6_addr[i] = 0;
  }
  dstsnmc.sin6_addr.s6_addr[11]=1;
  dstsnmc.sin6_addr.s6_addr[12]=255;

// Report target's solicited-node multicast address.
  ipv6 = (struct sockaddr_in6 *) &dstsnmc;
  tmp = &(ipv6->sin6_addr);
  memset (target, 0, 40);
  inet_ntop (AF_INET6, tmp, target, 40);
  printf ("Target solicited-node multicast address: %s\n", target);
  memcpy (psdhdr + 16, dstsnmc.sin6_addr.s6_addr, 16);  // Solicited-node multicast address goes into pseudo-header

// Request a socket descriptor sd.
  if ((sd = socket (AF_INET6, SOCK_RAW, IPPROTO_ICMPV6)) < 0) {
    perror ("Failed to get socket descriptor ");
    exit (EXIT_FAILURE);
  }

// Obtain soliciting node (source) MAC address.
  memset (&ifr, 0, sizeof (ifr));
  snprintf (ifr.ifr_name, sizeof (ifr.ifr_name), "%s", interface);
  if (ioctl (sd, SIOCGIFHWADDR, &ifr) < 0) {
    perror ("ioctl() failed to get source MAC address ");
    return (EXIT_FAILURE);
  }

// Copy source MAC address into options buffer.
  options[0] = 1;           // Option Type - "source link layer address" (Section 4.6 of RFC 4861)
  options[1] = optlen / 8;  // Option Length - units of 8 octets (RFC 4861)
  for (i=0; i<6; i++) {
    options[i+2] = (unsigned char) ifr.ifr_addr.sa_data[i];
  }

// Report soliciting node MAC address to stdout.
  printf ("MAC address for interface %s is ", interface);
  for (i=0; i<5; i++) {
    printf ("%02x:", options[i+2]);
  }
  printf ("%02x\n", options[5+2]);

// Bind the socket descriptor to the source address if not site-local or link-local.
  if (!(psdhdr[0] == 0xfe)) {
    if (bind (sd, (struct sockaddr *) &src, srclen) < 0) {
      perror ("Failed to bind the socket descriptor to the source address ");
      exit (EXIT_FAILURE);
    }
  }

// Retrieve source interface index.
  if ((ifindex = if_nametoindex (interface)) == 0) {
    perror ("if_nametoindex() failed to obtain interface index ");
    exit (EXIT_FAILURE);
  }
  printf ("Soliciting node's index for interface %s is %i\n", interface, ifindex);

// Define first part of buffer outpack to be a neighbor solicit struct.
  ns = (struct nd_neighbor_solicit *) outpack;
  memset (ns, 0, sizeof (*ns));

// Populate icmp6_hdr portion of neighbor solicit struct.
  ns->nd_ns_hdr.icmp6_type = ND_NEIGHBOR_SOLICIT;  // 135 (RFC 4861)
  ns->nd_ns_hdr.icmp6_code = 0;              // zero for neighbor solicitation (RFC 4861)
  ns->nd_ns_hdr.icmp6_cksum = htons(0);      // zero when calculating checksum
  ns->nd_ns_reserved = htonl(0);             // Reserved - must be set to zero (RFC 4861)
  ns->nd_ns_target = dst.sin6_addr;          // Target address (NOT MULTICAST) (as type in6_addr)

// Append options to end of neighbor solicit struct.
  memcpy (outpack + NS_HDRLEN, options, optlen);

// Need a pseudo-header for checksum calculation. Define length. (RFC 2460)
// Length = source IP (16 bytes) + destination IP (16 bytes)
//        + upper layer packet length (4 bytes) + zero (3 bytes)
//        + next header (1 byte)
  psdhdrlen = 16 + 16 + 4 + 3 + 1 + NS_HDRLEN + optlen;

// Prepare msghdr for sendmsg().
  memset (&msghdr, 0, sizeof (msghdr));
  msghdr.msg_name = &dstsnmc;  // Destination IPv6 address (solicited node multicast) (as struct sockaddr_in6)
  msghdr.msg_namelen = sizeof (dstsnmc);
  memset (&iov, 0, sizeof (iov));
  iov[0].iov_base = (unsigned char *) outpack;  // Point msghdr to buffer outpack
  iov[0].iov_len = NS_HDRLEN + optlen;
  msghdr.msg_iov = iov;                 // scatter/gather array
  msghdr.msg_iovlen = 1;                // number of elements in scatter/gather array

// Tell msghdr we're adding cmsghdr data to change hop limit and specify interface.
// Allocate some memory for our cmsghdr data.
  cmsglen = CMSG_SPACE (sizeof (int)) + CMSG_SPACE (sizeof (struct in6_pktinfo));
  tmp = (unsigned char *) malloc (cmsglen * sizeof (unsigned char));
  if (tmp != NULL) {
    msghdr.msg_control = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'msghdr.msg_control'.\n");
    exit (EXIT_FAILURE);
  }
  memset (msghdr.msg_control, 0, cmsglen);
  msghdr.msg_controllen = cmsglen;

// Change hop limit to 255 as required for neighbor solicitation (RFC 4861).
  hoplimit = 255;
  cmsghdr1 = CMSG_FIRSTHDR (&msghdr);
  cmsghdr1->cmsg_level = IPPROTO_IPV6;
  cmsghdr1->cmsg_type = IPV6_HOPLIMIT;  // We want to change hop limit
  cmsghdr1->cmsg_len = CMSG_LEN (sizeof (int));
  *((int *) CMSG_DATA (cmsghdr1)) = hoplimit;

// Specify source interface index for this packet via cmsghdr data.
  cmsghdr2 = CMSG_NXTHDR (&msghdr, cmsghdr1);
  cmsghdr2->cmsg_level = IPPROTO_IPV6;
  cmsghdr2->cmsg_type = IPV6_PKTINFO;  // We want to specify interface here
  cmsghdr2->cmsg_len = CMSG_LEN (sizeof (struct in6_pktinfo));
  pktinfo = (struct in6_pktinfo *) CMSG_DATA (cmsghdr2);
  pktinfo->ipi6_ifindex = ifindex;

// Compute ICMPv6 checksum (RFC 2460).
// psdhdr[0 to 15] = source IPv6 address, set earlier.
// psdhdr[16 to 31] = destination IPv6 address, set earlier.
  psdhdr[32] = 0;  // Length should not be greater than 65535 (i.e., 2 bytes)
  psdhdr[33] = 0;  // Length should not be greater than 65535 (i.e., 2 bytes)
  psdhdr[34] = (NS_HDRLEN + optlen)  / 256;  // Upper layer packet length
  psdhdr[35] = (NS_HDRLEN + optlen)  % 256;  // Upper layer packet length
  psdhdr[36] = 0;  // Must be zero
  psdhdr[37] = 0;  // Must be zero
  psdhdr[38] = 0;  // Must be zero
  psdhdr[39] = IPPROTO_ICMPV6;
  memcpy (psdhdr + 40, outpack, NS_HDRLEN + optlen);
  ns->nd_ns_hdr.icmp6_cksum = checksum ((unsigned short int *) psdhdr, psdhdrlen);

  printf ("Checksum: %x\n", ntohs (ns->nd_ns_hdr.icmp6_cksum));

// Send packet.
  if (sendmsg (sd, &msghdr, 0) < 0) {
    perror ("sendmsg() failed ");
    exit (EXIT_FAILURE);
  }
  close (sd);

// Free allocated memory.
  free (interface);
  free (target);
  free (source);
  free (outpack);
  free (options);
  free (psdhdr);
  free (msghdr.msg_control);

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
