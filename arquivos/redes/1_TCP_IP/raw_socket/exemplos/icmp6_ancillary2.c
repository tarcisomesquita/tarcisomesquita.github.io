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

// Send an IPv6 ICMP echo request packet.
// Changes hoplimit and specifies interface using ancillary data method.
// Includes ICMP data.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <sys/socket.h>       // struct msghdr
#include <netinet/in.h>       // IPPROTO_IPV6, IPPROTO_ICMPV6
#include <netinet/ip.h>       // IP_MAXPACKET (which is 65535)
#include <netinet/icmp6.h>    // struct icmp6_hdr, ICMP6_ECHO_REQUEST
#include <netdb.h>            // struct addrinfo
#include <sys/ioctl.h>        // macro ioctl is defined
#include <bits/ioctls.h>      // defines values for argument "request" of ioctl.
#include <arpa/inet.h>        // inet_pton()
#include <net/if.h>           // struct ifreq

#include <errno.h>            // errno, perror()

// Taken from <linux/ipv6.h>, also in <netinet/in.h>
struct in6_pktinfo {
        struct in6_addr ipi6_addr;
        int             ipi6_ifindex;
};

// Define some constants.
#define IP6_HDRLEN 40         // IPv6 header length
#define ICMP_HDRLEN 8         // ICMP header length for echo request, excludes data

// Function prototypes
unsigned short int checksum (unsigned short int *, int);

int
main (int argc, char **argv)
{
  int status, datalen, sd, cmsglen, hoplimit, psdhdrlen;
  char *interface, *target, *source, *src_ip, *dst_ip;
  struct icmp6_hdr *icmphdr;
  unsigned char *data, *outpack, *psdhdr;
  struct addrinfo hints, *res;
  struct sockaddr_in6 src, dst;
  socklen_t srclen;
  struct ifreq ifr;
  struct msghdr msghdr;
  struct cmsghdr *cmsghdr1, *cmsghdr2;
  struct in6_pktinfo *pktinfo;
  struct iovec iov[2];
  void *tmp;

// Allocate memory for various arrays.

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    source = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'source'.\n");
    exit (EXIT_FAILURE);
  }
  memset (source, 0, 40);

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    target = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'target'.\n");
    exit (EXIT_FAILURE);
  }
  memset (target, 0, 40);

  tmp = (char *) malloc (40 * sizeof (char));
  if (tmp != NULL) {
    interface = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'interface'.\n");
    exit (EXIT_FAILURE);
  }
  memset (interface, 0, 40);

  // Maximum ICMP payload size = 65535 - IPv6 header (40 bytes) - ICMP header (8 bytes)
  tmp = (unsigned char *) malloc ((IP_MAXPACKET - IP6_HDRLEN - ICMP_HDRLEN) * sizeof (unsigned char));
  if (tmp != NULL) {
    data = tmp;
  } else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'data'.\n");
    exit (EXIT_FAILURE);
  }
  memset (data, 0, IP_MAXPACKET - IP6_HDRLEN - ICMP_HDRLEN);

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

  tmp = (unsigned char *) malloc ((IP_MAXPACKET - IP6_HDRLEN - ICMP_HDRLEN) * sizeof (unsigned char));
  if (tmp != NULL) {
    outpack = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'outpack'.\n");
    exit (EXIT_FAILURE);
  }
  memset (outpack, 0, IP_MAXPACKET - IP6_HDRLEN - ICMP_HDRLEN);

  tmp = (unsigned char *) malloc (IP_MAXPACKET * sizeof (unsigned char));
  if (tmp != NULL) {
    psdhdr = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'psdhdr'.\n");
    exit (EXIT_FAILURE);
  }
  memset (psdhdr, 0, IP_MAXPACKET);

// Interface to send packet through.
  strcpy (interface, "wlan0");

// Submit request for a socket descriptor to lookup interface.
  if ((sd = socket (AF_INET6, SOCK_RAW, IPPROTO_IPV6)) < 0) {
    perror ("socket() failed to get socket descriptor for using ioctl() ");
    exit (EXIT_FAILURE);
  }

// Use ioctl() to lookup interface.
  memset (&ifr, 0, sizeof (ifr));
  snprintf (ifr.ifr_name, sizeof (ifr.ifr_name), "%s", interface);
  if (ioctl (sd, SIOCGIFINDEX, &ifr) < 0) {
    perror ("ioctl() failed to find interface ");
    return (EXIT_FAILURE);
  }
  close (sd);
  printf ("Index for interface %s is %i\n", interface, ifr.ifr_ifindex);

// Source IPv6 address: you need to fill this out
  strcpy (source, "2002::1");

// Destination URL or IPv6 address
  strcpy (target, "ipv6.google.com");

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
  memcpy (psdhdr + 16, dst.sin6_addr.s6_addr, 16);  // Copy to checksum pseudo-header
  freeaddrinfo (res);

// Define first part of buffer outpack to be an ICMPV6 struct.
  icmphdr = (struct icmp6_hdr *) outpack;
  memset (icmphdr, 0, ICMP_HDRLEN);

// Populate icmphdr portion of buffer outpack.
  icmphdr->icmp6_type = ICMP6_ECHO_REQUEST;
  icmphdr->icmp6_code = 0;
  icmphdr->icmp6_cksum = 0;
  icmphdr->icmp6_id = htons (5);
  icmphdr->icmp6_seq = htons (300);

// ICMP data
  datalen = 4;
  data[0] = 'T';
  data[1] = 'e';
  data[2] = 's';
  data[3] = 't';

// Append ICMP data.
  memcpy (outpack + ICMP_HDRLEN, data, datalen);

// Need a pseudo-header for checksum calculation. Define length. (RFC 2460)
// Length = source IP (16 bytes) + destination IP (16 bytes)
//        + upper layer packet length (4 bytes) + zero (3 bytes)
//        + next header (1 byte)
  psdhdrlen = 16 + 16 + 4 + 3 + 1 + ICMP_HDRLEN + datalen;

// Compose the msghdr structure.
  memset (&msghdr, 0, sizeof (msghdr));
  msghdr.msg_name = &dst;             // pointer to socket address structure
  msghdr.msg_namelen = sizeof (dst);  // size of socket address structure

  memset (&iov, 0, sizeof (iov));
  iov[0].iov_base = (unsigned char *) outpack;
  iov[0].iov_len = ICMP_HDRLEN + datalen;
  msghdr.msg_iov = iov;   // scatter/gather array
  msghdr.msg_iovlen = 1;  // number of elements in scatter/gather array

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

// Change hop limit to 255.
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
  pktinfo->ipi6_ifindex = ifr.ifr_ifindex;

// Compute ICMPv6 checksum (RFC 2460).
// psdhdr[0 to 15] = source IPv6 address, set earlier.
// psdhdr[16 to 31] = destination IPv6 address, set earlier.
  psdhdr[32] = 0;  // Length should not be greater than 65535 (i.e., 2 bytes)
  psdhdr[33] = 0;  // Length should not be greater than 65535 (i.e., 2 bytes)
  psdhdr[34] = (ICMP_HDRLEN + datalen)  / 256;  // Upper layer packet length
  psdhdr[35] = (ICMP_HDRLEN + datalen)  % 256;  // Upper layer packet length
  psdhdr[36] = 0;  // Must be zero
  psdhdr[37] = 0;  // Must be zero
  psdhdr[38] = 0;  // Must be zero
  psdhdr[39] = IPPROTO_ICMPV6;
  memcpy (psdhdr + 40, outpack, ICMP_HDRLEN + datalen);
  icmphdr->icmp6_cksum = checksum ((unsigned short int *) psdhdr, psdhdrlen);

  printf ("Checksum: %x\n", ntohs (icmphdr->icmp6_cksum));

// Request a socket descriptor sd.
  if ((sd = socket (AF_INET6, SOCK_RAW, IPPROTO_ICMPV6)) < 0) {
    fprintf (stderr, "Failed to get socket descriptor.\n");
    exit (EXIT_FAILURE);
  }

// Bind the socket descriptor to the source address.
  if (bind (sd, (struct sockaddr *) &src, srclen) != 0) {
    fprintf (stderr, "Failed to bind the socket descriptor to the source address.\n");
    exit (EXIT_FAILURE);
  }

// Send packet.
  if (sendmsg (sd, &msghdr, 0) < 0) {
    perror ("sendmsg() failed ");
    exit (EXIT_FAILURE);
  }
  close (sd);

// Free allocated memory.
  free (target);
  free (interface);
  free (data);
  free (src_ip);
  free (dst_ip);
  free (outpack);
  free (psdhdr);
  free (msghdr.msg_control);

  return (EXIT_SUCCESS);
}

// IP checksum function
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
