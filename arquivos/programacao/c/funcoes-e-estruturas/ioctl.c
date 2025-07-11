/*
The GNU system can handle most input/output operations on many different devices and objects with read, write and lseek. However, most devices also have a few peculiar operations which do not fit into this model. Such as:
    Changing the character font used on a terminal.
    Telling a magnetic tape system to rewind or fast forward. (Since they cannot move in byte increments, lseek is inapplicable).
    Ejecting a disk from a drive.
    Playing an audio track from a CD-ROM drive.
    Maintaining routing tables for a network.
    Definir o número de IP de uma placa de rede.
Although some such objects such as sockets and terminals have special functions of their own, it would not be practical to create functions for all these cases.
Instead these minor operations, known as IOCTLs, are assigned code numbers and multiplexed through the ioctl function, defined in sys/ioctl.h. The code numbers themselves are defined in many different headers.
*/

// Perform the I/O control operation specified by REQUEST on FD.
// One argument may follow; its presence and type depend on REQUEST.
// Return value depends on REQUEST.  Usually -1 indicates error.

// #include<sys/ioctl.h> // = = = = = = = = = = = = = = = = = =
extern int ioctl (int __fd, unsigned long int __request, ...);

/* IOCTLs for SCSI.  */
#define SCSI_IOCTL_SEND_COMMAND		1	/* Send a command to the SCSI host.  */
#define SCSI_IOCTL_TEST_UNIT_READY	2	/* Test if unit is ready.  */
#define SCSI_IOCTL_BENCHMARK_COMMAND	3
#define SCSI_IOCTL_SYNC			4	/* Request synchronous parameters.  */
#define SCSI_IOCTL_START_UNIT		5
#define SCSI_IOCTL_STOP_UNIT		6
#define SCSI_IOCTL_DOORLOCK		0x5380	/* Lock the eject mechanism.  */
#define SCSI_IOCTL_DOORUNLOCK		0x5381	/* Unlock the mechanism.  */


// #include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdout;	
extern struct _IO_FILE *stderr;	
extern int fprintf(FILE *stream, const char *formatted_output, ...);


//#include<string.h>
const char *strchr(const char *, int);
extern int strncmp(const char * s1,const char * s2, long unsigned int num);


// #include <sys/socket.h>
extern int socket(int __domain, int __type, int __protocol);


// #include<bits/socket.h> // = = = = = = = = = = = = = = = = = =
struct sockaddr
{
   unsigned short int sa_family; // address family and length.
   char sa_data[14];             // Address data.
};

// #include<net/if.h> // = = = = = = = = = = = = = = = = = =
struct ifmap // Device mapping structure.
{
   unsigned long int mem_start;
   unsigned long int mem_end;
   unsigned short int base_addr;
   unsigned char irq;
   unsigned char dma;
   unsigned char port;
};

struct ifreq  // Interface request structure used for socket ioctl's
{
   union
   {
      char ifrn_name[16]; // Interface name, e.g. "en0".
   } ifr_ifrn;
   
   union
   {
      struct sockaddr ifru_addr;       // 
      struct sockaddr ifru_dstaddr;
      struct sockaddr ifru_broadaddr;
      struct sockaddr ifru_netmask;
      struct sockaddr ifru_hwaddr;
      short int ifru_flags;
      int ifru_ivalue;
      int ifru_mtu;
      struct ifmap ifru_map;
      char ifru_slave[16];
      char ifru_newname[16];
      char *ifru_data;
   } ifr_ifru;
};
# define ifr_name	ifr_ifrn.ifrn_name	// interface name
# define ifr_hwaddr	ifr_ifru.ifru_hwaddr	// MAC address
# define ifr_addr	ifr_ifru.ifru_addr	// address
# define ifr_dstaddr	ifr_ifru.ifru_dstaddr	// other end of p-p lnk
# define ifr_broadaddr	ifr_ifru.ifru_broadaddr	// broadcast address
# define ifr_netmask	ifr_ifru.ifru_netmask	// interface net mask
# define ifr_flags	ifr_ifru.ifru_flags	// flags
# define ifr_metric	ifr_ifru.ifru_ivalue	// metric
# define ifr_mtu	ifr_ifru.ifru_mtu	// mtu
# define ifr_map	ifr_ifru.ifru_map	// device map
# define ifr_slave	ifr_ifru.ifru_slave	// slave device
# define ifr_data	ifr_ifru.ifru_data	// for use by interface
# define ifr_ifindex	ifr_ifru.ifru_ivalue    // interface index
# define ifr_bandwidth	ifr_ifru.ifru_ivalue	// link bandwidth
# define ifr_qlen	ifr_ifru.ifru_ivalue	// queue length
# define ifr_newname	ifr_ifru.ifru_newname	// New name


// Structure used in SIOCGIFCONF request.
// Used to retrieve interface configuration for machine
// useful for programs which must know all networks accessible).
struct ifconf
{
   int ifc_len;  // Size of buffer.
   union
   {
      char *ifcu_buf;
      struct ifreq *ifcu_req;
   } ifc_ifcu;
};
# define ifc_buf	ifc_ifcu.ifcu_buf	// Buffer address.
# define ifc_req	ifc_ifcu.ifcu_req	// Array of structures.


int get_all_device_names(char *devs) {
   int devnum = 0;
   unsigned char *p, *q, *dq;
   int i, fd;
   int num_ifreq;
   struct ifreq *pIfr;
   struct ifconf Ifc;
   static struct ifreq IfcBuf[48];
   
   Ifc.ifc_len = sizeof(IfcBuf);
   Ifc.ifc_ifcu.ifcu_buf = (char *) IfcBuf;
   
   if ((fd = socket(2, 2, 0)) < 0) {
      fprintf(stderr, "socket()");
      return(1);
   }
   
   if (ioctl(fd, 0x8912, &Ifc) < 0) {
      fprintf(stderr, "ioctl SIOCGIFCONF");
      return(1);
   }

   num_ifreq = Ifc.ifc_len / sizeof(struct ifreq);
  
   dq = (unsigned char *)devs;
   
   for (pIfr=Ifc.ifc_ifcu.ifcu_req, i=0; i<num_ifreq; pIfr++, i++) {
      q = dq;
      p = (unsigned char *)pIfr->ifr_ifrn.ifrn_name;
      if (strncmp("lo", (char *)p, 2) == 0)
         continue;
      
      if (strchr((char *)p, ':') != 0x00)
         continue;
     
      devnum++;
      while (*p)
         *q++ = *p++;
     
      *q = 0;
      if (devnum >= 48) {
         fprintf(stderr, "Too many network devices.  Limit is %d", 48);
         return(1);
      }
      dq += 256;
   }
   return devnum;
}

int main() {
   int i, devnum;
   unsigned char devs[48][256];
   
   fprintf(stdout, "\nEste programa imprime dados sobre as interfaces que estão com conexão estabelecida.\n\n");
   
   devnum = 0;
   devnum = get_all_device_names((char *)&devs);
   
   for(i = 0; i < devnum; i++) fprintf(stdout, "devs[%d] = %s\n", i, devs[i]);
   
   return 0;
}

#define CDROMPAUSE		0x5301 /* Pause Audio Operation */ 
#define CDROMRESUME		0x5302 /* Resume paused Audio Operation */
#define CDROMPLAYMSF		0x5303 /* Play Audio MSF (struct cdrom_msf) */
#define CDROMPLAYTRKIND		0x5304 /* Play Audio Track/index 
                                           (struct cdrom_ti) */
#define CDROMREADTOCHDR		0x5305 /* Read TOC header 
                                           (struct cdrom_tochdr) */
#define CDROMREADTOCENTRY	0x5306 /* Read TOC entry 
                                           (struct cdrom_tocentry) */
#define CDROMSTOP		0x5307 /* Stop the cdrom drive */
#define CDROMSTART		0x5308 /* Start the cdrom drive */
#define CDROMEJECT		0x5309 /* Ejects the cdrom media */
#define CDROMVOLCTRL		0x530a /* Control output volume 
                                           (struct cdrom_volctrl) */
#define CDROMSUBCHNL		0x530b /* Read subchannel data 
                                           (struct cdrom_subchnl) */
#define CDROMREADMODE2		0x530c /* Read CDROM mode 2 data (2336 Bytes) 
                                           (struct cdrom_read) */
#define CDROMREADMODE1		0x530d /* Read CDROM mode 1 data (2048 Bytes)
                                           (struct cdrom_read) */
#define CDROMREADAUDIO		0x530e /* (struct cdrom_read_audio) */
#define CDROMEJECT_SW		0x530f /* enable(1)/disable(0) auto-ejecting */
#define CDROMMULTISESSION	0x5310 /* Obtain the start-of-last-session 
                                           address of multi session disks 
                                           (struct cdrom_multisession) */
#define CDROM_GET_MCN		0x5311 /* Obtain the "Universal Product Code" 
                                           if available (struct cdrom_mcn) */
#define CDROM_GET_UPC		CDROM_GET_MCN  /* This one is deprecated, 
                                          but here anyway for compatibility */
#define CDROMRESET		0x5312 /* hard-reset the drive */
#define CDROMVOLREAD		0x5313 /* Get the drive's volume setting 
                                          (struct cdrom_volctrl) */
#define CDROMREADRAW		0x5314	/* read data in raw mode (2352 Bytes)
                                           (struct cdrom_read) */
/* 
 * These ioctls are used only used in aztcd.c and optcd.c
 */
#define CDROMREADCOOKED		0x5315	/* read data in cooked mode */
#define CDROMSEEK		0x5316  /* seek msf address */
  
/*
 * This ioctl is only used by the scsi-cd driver.  
   It is for playing audio in logical block addressing mode.
 */
#define CDROMPLAYBLK		0x5317	/* (struct cdrom_blk) */

/* 
 * These ioctls are only used in optcd.c
 */
#define CDROMREADALL		0x5318	/* read all 2646 bytes */

/* 
 * These ioctls are (now) only in ide-cd.c for controlling 
 * drive spindown time.  They should be implemented in the
 * Uniform driver, via generic packet commands, GPCMD_MODE_SELECT_10,
 * GPCMD_MODE_SENSE_10 and the GPMODE_POWER_PAGE...
 *  -Erik
 */
#define CDROMGETSPINDOWN        0x531d
#define CDROMSETSPINDOWN        0x531e

/* 
 * These ioctls are implemented through the uniform CD-ROM driver
 * They _will_ be adopted by all CD-ROM drivers, when all the CD-ROM
 * drivers are eventually ported to the uniform CD-ROM driver interface.
 */
#define CDROMCLOSETRAY		0x5319	/* pendant of CDROMEJECT */
#define CDROM_SET_OPTIONS	0x5320  /* Set behavior options */
#define CDROM_CLEAR_OPTIONS	0x5321  /* Clear behavior options */
#define CDROM_SELECT_SPEED	0x5322  /* Set the CD-ROM speed */
#define CDROM_SELECT_DISC	0x5323  /* Select disc (for juke-boxes) */
#define CDROM_MEDIA_CHANGED	0x5325  /* Check is media changed  */
#define CDROM_DRIVE_STATUS	0x5326  /* Get tray position, etc. */
#define CDROM_DISC_STATUS	0x5327  /* Get disc type, etc. */
#define CDROM_CHANGER_NSLOTS    0x5328  /* Get number of slots */
#define CDROM_LOCKDOOR		0x5329  /* lock or unlock door */
#define CDROM_DEBUG		0x5330	/* Turn debug messages on/off */
#define CDROM_GET_CAPABILITY	0x5331	/* get capabilities */

/* Note that scsi/scsi_ioctl.h also uses 0x5382 - 0x5386.
 * Future CDROM ioctls should be kept below 0x537F
 */

/* This ioctl is only used by sbpcd at the moment */
#define CDROMAUDIOBUFSIZ        0x5382	/* set the audio buffer size */
					/* conflict with SCSI_IOCTL_GET_IDLUN */

/* DVD-ROM Specific ioctls */
#define DVD_READ_STRUCT		0x5390  /* Read structure */
#define DVD_WRITE_STRUCT	0x5391  /* Write structure */
#define DVD_AUTH		0x5392  /* Authentication */

#define CDROM_SEND_PACKET	0x5393	/* send a packet to the drive */
#define CDROM_NEXT_WRITABLE	0x5394	/* get next writable block */
#define CDROM_LAST_WRITTEN	0x5395	/* get last block written on disc */


#define TCGETS		0x5401
#define TCSETS		0x5402 /* Clashes with SNDCTL_TMR_START sound ioctl */
#define TCSETSW		0x5403
#define TCSETSF		0x5404
#define TCGETA		0x5405
#define TCSETA		0x5406
#define TCSETAW		0x5407
#define TCSETAF		0x5408
#define TCSBRK		0x5409
#define TCXONC		0x540A
#define TCFLSH		0x540B
#define TIOCEXCL	0x540C
#define TIOCNXCL	0x540D
#define TIOCSCTTY	0x540E
#define TIOCGPGRP	0x540F
#define TIOCSPGRP	0x5410
#define TIOCOUTQ	0x5411
#define TIOCSTI		0x5412
#define TIOCGWINSZ	0x5413
#define TIOCSWINSZ	0x5414
#define TIOCMGET	0x5415
#define TIOCMBIS	0x5416
#define TIOCMBIC	0x5417
#define TIOCMSET	0x5418
#define TIOCGSOFTCAR	0x5419
#define TIOCSSOFTCAR	0x541A
#define FIONREAD	0x541B
#define TIOCINQ		FIONREAD
#define TIOCLINUX	0x541C
#define TIOCCONS	0x541D
#define TIOCGSERIAL	0x541E
#define TIOCSSERIAL	0x541F
#define TIOCPKT		0x5420
#define FIONBIO		0x5421
#define TIOCNOTTY	0x5422
#define TIOCSETD	0x5423
#define TIOCGETD	0x5424
#define TCSBRKP		0x5425	/* Needed for POSIX tcsendbreak() */
/* #define TIOCTTYGSTRUCT 0x5426 - Former debugging-only ioctl */
#define TIOCSBRK	0x5427  /* BSD compatibility */
#define TIOCCBRK	0x5428  /* BSD compatibility */
#define TIOCGSID	0x5429  /* Return the session ID of FD */
#define TCGETS2		_IOR('T', 0x2A, struct termios2)
#define TCSETS2		_IOW('T', 0x2B, struct termios2)
#define TCSETSW2	_IOW('T', 0x2C, struct termios2)
#define TCSETSF2	_IOW('T', 0x2D, struct termios2)
#define TIOCGRS485	0x542E
#define TIOCSRS485	0x542F
#define TIOCGPTN	_IOR('T', 0x30, unsigned int)
				/* Get Pty Number (of pty-mux device) */
#define TIOCSPTLCK	_IOW('T', 0x31, int)  /* Lock/unlock Pty */
#define TCGETX		0x5432 /* SYS5 TCGETX compatibility */
#define TCSETX		0x5433
#define TCSETXF		0x5434
#define TCSETXW		0x5435

#define FIONCLEX	0x5450
#define FIOCLEX		0x5451
#define FIOASYNC	0x5452
#define TIOCSERCONFIG	0x5453
#define TIOCSERGWILD	0x5454
#define TIOCSERSWILD	0x5455
#define TIOCGLCKTRMIOS	0x5456
#define TIOCSLCKTRMIOS	0x5457
#define TIOCSERGSTRUCT	0x5458 /* For debugging only */
#define TIOCSERGETLSR   0x5459 /* Get line status register */
#define TIOCSERGETMULTI 0x545A /* Get multiport config  */
#define TIOCSERSETMULTI 0x545B /* Set multiport config */

#define TIOCMIWAIT	0x545C	/* wait for a change on serial input line(s) */
#define TIOCGICOUNT	0x545D	/* read serial port inline interrupt counts */
#define TIOCGHAYESESP   0x545E  /* Get Hayes ESP configuration */
#define TIOCSHAYESESP   0x545F  /* Set Hayes ESP configuration */
#define FIOQSIZE	0x5460

/* Used for packet mode */
#define TIOCPKT_DATA		 0
#define TIOCPKT_FLUSHREAD	 1
#define TIOCPKT_FLUSHWRITE	 2
#define TIOCPKT_STOP		 4
#define TIOCPKT_START		 8
#define TIOCPKT_NOSTOP		16
#define TIOCPKT_DOSTOP		32

#define TIOCSER_TEMT    0x01	/* Transmitter physically empty */


/* Routing table calls.  */
#define SIOCADDRT	0x890B		/* add routing table entry	*/
#define SIOCDELRT	0x890C		/* delete routing table entry	*/
#define SIOCRTMSG	0x890D		/* call to routing system	*/

/* Socket configuration controls. */
#define SIOCGIFNAME	0x8910		/* get iface name		*/
#define SIOCSIFLINK	0x8911		/* set iface channel		*/
#define SIOCGIFCONF	0x8912		/* get iface list		*/
#define SIOCGIFFLAGS	0x8913		/* get flags			*/
#define SIOCSIFFLAGS	0x8914		/* set flags			*/
#define SIOCGIFADDR	0x8915		/* get PA address		*/
#define SIOCSIFADDR	0x8916		/* set PA address		*/
#define SIOCGIFDSTADDR	0x8917		/* get remote PA address	*/
#define SIOCSIFDSTADDR	0x8918		/* set remote PA address	*/
#define SIOCGIFBRDADDR	0x8919		/* get broadcast PA address	*/
#define SIOCSIFBRDADDR	0x891a		/* set broadcast PA address	*/
#define SIOCGIFNETMASK	0x891b		/* get network PA mask		*/
#define SIOCSIFNETMASK	0x891c		/* set network PA mask		*/
#define SIOCGIFMETRIC	0x891d		/* get metric			*/
#define SIOCSIFMETRIC	0x891e		/* set metric			*/
#define SIOCGIFMEM	0x891f		/* get memory address (BSD)	*/
#define SIOCSIFMEM	0x8920		/* set memory address (BSD)	*/
#define SIOCGIFMTU	0x8921		/* get MTU size			*/
#define SIOCSIFMTU	0x8922		/* set MTU size			*/
#define SIOCSIFNAME	0x8923		/* set interface name		*/
#define	SIOCSIFHWADDR	0x8924		/* set hardware address 	*/
#define SIOCGIFENCAP	0x8925		/* get/set encapsulations       */
#define SIOCSIFENCAP	0x8926
#define SIOCGIFHWADDR	0x8927		/* Get hardware address		*/
#define SIOCGIFSLAVE	0x8929		/* Driver slaving support	*/
#define SIOCSIFSLAVE	0x8930
#define SIOCADDMULTI	0x8931		/* Multicast address lists	*/
#define SIOCDELMULTI	0x8932
#define SIOCGIFINDEX	0x8933		/* name -> if_index mapping	*/
#define SIOGIFINDEX	SIOCGIFINDEX	/* misprint compatibility :-)	*/
#define SIOCSIFPFLAGS	0x8934		/* set/get extended flags set	*/
#define SIOCGIFPFLAGS	0x8935
#define SIOCDIFADDR	0x8936		/* delete PA address		*/
#define	SIOCSIFHWBROADCAST	0x8937	/* set hardware broadcast addr	*/
#define SIOCGIFCOUNT	0x8938		/* get number of devices */

#define SIOCGIFBR	0x8940		/* Bridging support		*/
#define SIOCSIFBR	0x8941		/* Set bridging options 	*/

#define SIOCGIFTXQLEN	0x8942		/* Get the tx queue length	*/
#define SIOCSIFTXQLEN	0x8943		/* Set the tx queue length 	*/


/* ARP cache control calls. */
		    /*  0x8950 - 0x8952  * obsolete calls, don't re-use */
#define SIOCDARP	0x8953		/* delete ARP table entry	*/
#define SIOCGARP	0x8954		/* get ARP table entry		*/
#define SIOCSARP	0x8955		/* set ARP table entry		*/

/* RARP cache control calls. */
#define SIOCDRARP	0x8960		/* delete RARP table entry	*/
#define SIOCGRARP	0x8961		/* get RARP table entry		*/
#define SIOCSRARP	0x8962		/* set RARP table entry		*/

/* Driver configuration calls */

#define SIOCGIFMAP	0x8970		/* Get device parameters	*/
#define SIOCSIFMAP	0x8971		/* Set device parameters	*/

/* DLCI configuration calls */

#define SIOCADDDLCI	0x8980		/* Create new DLCI device	*/
#define SIOCDELDLCI	0x8981		/* Delete DLCI device		*/

/* Device private ioctl calls.  */

/* These 16 ioctls are available to devices via the do_ioctl() device
   vector.  Each device should include this file and redefine these
   names as their own. Because these are device dependent it is a good
   idea _NOT_ to issue them to random objects and hope.  */

#define SIOCDEVPRIVATE 		0x89F0	/* to 89FF */

/*
 *	These 16 ioctl calls are protocol private
 */

#define SIOCPROTOPRIVATE 0x89E0 /* to 89EF */


