
// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


// #include <sys/socket.h>
extern int socket(int __domain, int __type, int __protocol);


// #include <bits/socket.h>
//TYPE  Processes communicate only between sockets of the same type.
enum __socket_type
{
  SOCK_STREAM = 1,		// Sequenced, reliable, connection-based byte streams.  
                                // A stream operates much like a telephone conversation.
                                // Used in the Internet domain with TCP. 
  SOCK_DGRAM = 2,		// Connectionless, unreliable datagrams of fixed maximum length.  
                                // Used in the Internet domain with UDP.
};

//PROTOCOL
// Protocol families.  
#define	PF_INET		2	// IP protocol family.  

//DOMAIN
// Address families.  
#define	AF_INET		PF_INET


//PROTOCOL
// #include <netinet/in.h>
// Standard well-defined IP protocols.
enum
{
   IPPROTO_IP = 0,	   // Dummy protocol for TCP.  
   IPPROTO_TCP = 6,	   // Transmission Control Protocol.  
   IPPROTO_UDP = 17,	   // User Datagram Protocol.  
};


// #include <asm/socket.h>
/* For setsockopt(2) */
#define SOL_SOCKET	1
#define SO_REUSEADDR	2


#define EADDRINUSE		WSAEADDRINUSE

// estabelece uma conexão entre o endereço remoto rad:rp e o local lad:lp
int doconnect (struct in_addr *rad, unsigned short rp, struct in_addr *lad, unsigned short lp)
{
  register int nnetfd;
  register int rr;
  int x, y;
  unsigned short int o_udpmode = 0;
  struct sockaddr_in *lclend = 0x00000000;
  struct sockaddr_in *remend = 0x00000000;


  errno = 0;

  // grab a socket; set opts
  if (o_udpmode)
    nnetfd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  else
    nnetfd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
  
  if (nnetfd < 0)
    fprintf(stdout,"Can't get socket\n");

  x = 1;
  rr = setsockopt (nnetfd, SOL_SOCKET, SO_REUSEADDR, &x, sizeof (x));
  if (rr == -1)
    fprintf(stdout,"nnetfd reuseaddr failed\n");

  // fill in all the right sockaddr crud
  lclend->sin_family = AF_INET;
  remend->sin_family = AF_INET;

  // if lad/lp, do appropriate binding
  if (lad)
    memcpy (&lclend->sin_addr.s_addr, lad, sizeof (struct in_addr));
  if (lp)
    lclend->sin_port = htons (lp);
  rr = 0;
  if (lad || lp) {
    x = (int) lp;
/* try a few times for the local bind, a la ftp-data-port... */
    for (y = 4; y > 0; y--) {
      rr = bind (nnetfd, (SA *)lclend, sizeof (SA));
      if (rr == 0)
	break;
      if (errno != EADDRINUSE)
	break;
      else {
	holler ("retrying local %s:%d", inet_ntoa (lclend->sin_addr), lp);
	sleep (1);
	errno = 0;			/* clear from sleep */
      } /* if EADDRINUSE */
    } /* for y counter */
  } /* if lad or lp */
  if (rr)
    bail ("Can't grab %s:%d with bind",
	inet_ntoa(lclend->sin_addr), lp);

  if (o_listen)
    return (nnetfd);			/* thanks, that's all for today */

  memcpy (&remend->sin_addr.s_addr, rad, sizeof (struct in_addr));
  remend->sin_port = htons (rp);

/* rough format of LSRR option and explanation of weirdness.
-Option comes after IP-hdr dest addr in packet, padded to *4, and ihl > 5.
-IHL is multiples of 4, i.e. real len = ip_hl << 2.
-	type 131	1	; 0x83: copied, option class 0, number 3
-	len		1	; of *whole* option!
-	pointer		1	; nxt-hop-addr; 1-relative, not 0-relative
-	addrlist...	var	; 4 bytes per hop-addr
-	pad-to-32	var	; ones, i.e. "NOP"
-
-If we want to route A -> B via hops C and D, we must add C, D, *and* B to the
-options list.  Why?  Because when we hand the kernel A -> B with list C, D, B
-the "send shuffle" inside the kernel changes it into A -> C with list D, B and
-the outbound packet gets sent to C.  If B wasn't also in the hops list, the
-final destination would have been lost at this point.
-
-When C gets the packet, it changes it to A -> D with list C', B where C' is
-the interface address that C used to forward the packet.  This "records" the
-route hop from B's point of view, i.e. which address points "toward" B.  This
-is to make B better able to return the packets.  The pointer gets bumped by 4,
-so that D does the right thing instead of trying to forward back to C.
-
-When B finally gets the packet, it sees that the pointer is at the end of the
-LSRR list and is thus "completed".  B will then try to use the packet instead
-of forwarding it, i.e. deliver it up to some application.
-
-Note that by moving the pointer yourself, you could send the traffic directly
-to B but have it return via your preconstructed source-route.  Playing with
-this and watching "tcpdump -v" is the best way to understand what's going on.
-
-Only works for TCP in BSD-flavor kernels.  UDP is a loss; udp_input calls
-stripoptions() early on, and the code to save the srcrt is notdef'ed.
-Linux is also still a loss at 1.3.x it looks like; the lsrr code is { }...
-*/


/* if any -g arguments were given, set up source-routing.  We hit this after
   the gates are all looked up and ready to rock, any -G pointer is set,
   and gatesidx is now the *number* of hops */
  if (gatesidx) {		/* if we wanted any srcrt hops ... */
/* don't even bother compiling if we can't do IP options here! */
/* #ifdef IP_OPTIONS */

    if (! optbuf) {		/* and don't already *have* a srcrt set */
      char * opp;		/* then do all this setup hair */
      optbuf = Hmalloc (48);
      opp = optbuf;
      *opp++ = IPOPT_LSRR;					/* option */
      *opp++ = (char)
	(((gatesidx + 1) * sizeof (struct in_addr)) + 3) & 0xff;		/* length */
      *opp++ = gatesptr;					/* pointer */
/* opp now points at first hop addr -- insert the intermediate gateways */
      for ( x = 0; x < gatesidx; x++) {
	memcpy (opp, gates[x]->iaddrs, sizeof (struct in_addr));
	opp += sizeof (struct in_addr);
      }
/* and tack the final destination on the end [needed!] */
      memcpy (opp, rad, sizeof (struct in_addr));
      opp += sizeof (struct in_addr);
      *opp = IPOPT_NOP;			/* alignment filler */
    } /* if empty optbuf */
/* calculate length of whole option mess, which is (3 + [hops] + [final] + 1),
   and apply it [have to do this every time through, of course] */
    x = ((gatesidx + 1) * sizeof (struct in_addr)) + 4;
    rr = setsockopt (nnetfd, IPPROTO_IP, IP_OPTIONS, optbuf, x);
    if (rr == -1)
      bail ("srcrt setsockopt fuxored");
  } /* if gatesidx */

/* wrap connect inside a timer, and hit it */
  arm (1, o_wait);
  if (setjmp (jbuf) == 0) {
    rr = connect (nnetfd, (SA *)remend, sizeof (SA));
  } else {				/* setjmp: connect failed... */
    rr = -1;
    errno = ETIMEDOUT;			/* fake it */
  }
  arm (0, 0);
  if (rr == 0)
    return (nnetfd);
  close (nnetfd);			/* clean up junked socket FD!! */
  return (-1);
} /* doconnect */

