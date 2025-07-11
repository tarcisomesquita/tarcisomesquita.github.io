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

// Receive an IPv6 router advertisement and extract
// various information stored in the ethernet frame.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>           // close()
#include <string.h>           // strcpy, memset(), and memcpy()

#include <netinet/icmp6.h>    // struct nd_router_advert, which contains icmp6_hdr, ND_ROUTER_ADVERT
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
static void *find_ancillary (struct msghdr *, int);

int
main (int argc, char **argv)
{
  int i, status, sd, on, ifindex, hoplimit;
  struct nd_router_advert *ra;
  unsigned char *inpack;
  int len;
  struct msghdr msghdr;
  struct iovec iov[2];
  unsigned char *opt, *pkt;
  char *interface, *destination;
  struct in6_addr dst;
  int rcv_ifindex;
  struct ifreq ifr;
  void *tmp;

// Allocate memory for various arrays.

  tmp = (unsigned char *) malloc (IP_MAXPACKET * sizeof (unsigned char));
  if (tmp != NULL) {
    inpack = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'inpack'.\n");
    exit (EXIT_FAILURE);
  }
  memset (inpack, 0, IP_MAXPACKET * sizeof (unsigned char));

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
    destination = tmp;}
  else {
    fprintf (stderr, "ERROR: Cannot allocate memory for array 'destination'.\n");
    exit (EXIT_FAILURE);
  }
  memset (destination, 0, sizeof (destination));

// Interface to receive packet on.
  strcpy (interface, "wlan0");

// Prepare msghdr for recvmsg().
  memset (&msghdr, 0, sizeof (msghdr));
  msghdr.msg_name = NULL;
  msghdr.msg_namelen = 0;
  memset (&iov, 0, sizeof (iov));
  iov[0].iov_base = (unsigned char *) inpack;
  iov[0].iov_len = IP_MAXPACKET;
  msghdr.msg_iov = iov;
  msghdr.msg_iovlen = 1;

  msghdr.msg_control = (unsigned char *) malloc (IP_MAXPACKET * sizeof (unsigned char));
  msghdr.msg_controllen = IP_MAXPACKET * sizeof (unsigned char);

// Request a socket descriptor sd.
  if ((sd = socket (AF_INET6, SOCK_RAW, IPPROTO_ICMPV6)) < 0) {
    perror ("Failed to get socket descriptor ");
    exit (EXIT_FAILURE);
  }

// Set flag so we receive hop limit from recvmsg.
  on = 1;
  if ((status = setsockopt (sd, IPPROTO_IPV6, IPV6_RECVHOPLIMIT, &on, sizeof (on))) < 0) {
    perror ("setsockopt to IPV6_RECVHOPLIMIT failed ");
    exit (EXIT_FAILURE);
  }

// Set flag so we receive destination address from recvmsg.
  on = 1;
  if ((status = setsockopt (sd, IPPROTO_IPV6, IPV6_RECVPKTINFO, &on, sizeof (on))) < 0) {
    perror ("setsockopt to IPV6_RECVPKTINFO failed ");
    exit (EXIT_FAILURE);
  }

// Obtain MAC address of this node.
  memset (&ifr, 0, sizeof (ifr));
  snprintf (ifr.ifr_name, sizeof (ifr.ifr_name), "%s", interface);
  if (ioctl (sd, SIOCGIFHWADDR, &ifr) < 0) {
    perror ("ioctl() failed to get source MAC address ");
    return (EXIT_FAILURE);
  }

// Retrieve interface index of this node.
  if ((ifindex = if_nametoindex (interface)) == 0) {
    perror ("if_nametoindex() failed to obtain interface index ");
    exit (EXIT_FAILURE);
  }
  printf ("\nOn this node, index for interface %s is %i\n", interface, ifindex);

// Bind socket to interface of this node.
  if (setsockopt (sd, SOL_SOCKET, SO_BINDTODEVICE, (void *) &ifr, sizeof (ifr)) < 0) {
    perror ("SO_BINDTODEVICE failed");
    exit (EXIT_FAILURE);
  }

// Listen for incoming message from socket sd.
// Keep at it until we get a router advertisement.
  ra = (struct nd_router_advert *) inpack;
  while (ra->nd_ra_hdr.icmp6_type != ND_ROUTER_ADVERT) {
    if ((len = recvmsg (sd, &msghdr, 0)) < 0) {
      perror ("recvmsg failed ");
      return (EXIT_FAILURE);
    }
  }

// Ancillary data
  printf ("\nIPv6 header data:\n");
  opt = find_ancillary (&msghdr, IPV6_HOPLIMIT);
  if (opt == NULL) {
    fprintf (stderr, "Unknown hop limit\n");
    exit (EXIT_FAILURE);
  }
  hoplimit = *(unsigned int *) opt;
  printf ("Hop limit: %u\n", hoplimit);

  opt = find_ancillary (&msghdr, IPV6_PKTINFO);
  if (opt == NULL) {
    fprintf (stderr, "Unkown destination address\n");
    exit (EXIT_FAILURE);
  }
  dst = ((struct in6_pktinfo *) opt)->ipi6_addr;
  inet_ntop (AF_INET6, &dst, destination, 40);
  printf ("Destination address: %s\n", destination);

  rcv_ifindex = ((struct in6_pktinfo *) opt)->ipi6_ifindex;
  printf ("Destination interface index: %i\n", rcv_ifindex);

// ICMPv6 header and options data
  printf ("\nICMPv6 header data:\n");
  printf ("Type (134 = router advertisement): %u\n", ra->nd_ra_hdr.icmp6_type);
  printf ("Code: %u\n", ra->nd_ra_hdr.icmp6_code);
  printf ("Checksum: %x\n", ntohs (ra->nd_ra_hdr.icmp6_cksum));
  printf ("Hop limit recommended by this router (0 is no recommendation): %u\n", ra->nd_ra_curhoplimit);
  printf ("Managed address configuration flag: %u\n", ra->nd_ra_flags_reserved >> 7);
  printf ("Other stateful configuration flag: %u\n", (ra->nd_ra_flags_reserved >> 6) & 1);
  printf ("Mobile home agent flag: %u\n", (ra->nd_ra_flags_reserved >> 5) & 1);
  printf ("Router lifetime as default router (s): %u\n", ntohs (ra->nd_ra_router_lifetime));
  printf ("Reachable time (ms): %u\n", ntohl (ra->nd_ra_reachable));
  printf ("Retransmission time (ms): %u\n", ntohl (ra->nd_ra_retransmit));

  printf ("\nOptions:\n");  // Contents here are consistent with ra6.c, but others are possible
  pkt = (unsigned char *) inpack;
  printf ("Type: %u\n", pkt[sizeof (struct nd_router_advert)]);
  printf ("Length: %u (units of 8 octets)\n", pkt[sizeof (struct nd_router_advert) + 1]);
  printf ("MAC address: ");
  for (i=2; i<7; i++) {
    printf ("%02x:", pkt[sizeof (struct nd_router_advert) + i]);
  }
  printf ("%02x\n", pkt[sizeof (struct nd_router_advert) + 7]);

  close (sd);

  free (inpack);
  free (interface);
  free (destination);
  free (msghdr.msg_control);

  return (EXIT_SUCCESS);
}

static void *
find_ancillary (struct msghdr *msg, int cmsg_type)
{
  struct cmsghdr *cmsg = NULL;

  for (cmsg = CMSG_FIRSTHDR (msg); cmsg != NULL; cmsg = CMSG_NXTHDR (msg, cmsg)) {
    if ((cmsg->cmsg_level == IPPROTO_IPV6) && (cmsg->cmsg_type == cmsg_type)) {
      return (CMSG_DATA (cmsg));
    }
  }

  return (NULL);
}
