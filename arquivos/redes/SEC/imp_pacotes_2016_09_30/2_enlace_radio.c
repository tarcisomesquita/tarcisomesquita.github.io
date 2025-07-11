/*
module mac80211 allows packets injection in Monitor Mode

Packet format:
 [ radiotap header  ]
 [ ieee80211 header ]
 [ payload ]

Here is an example valid radiotap header defining some parameters

   0x00, 0x00, // <-- radiotap version
   0x0b, 0x00, // <- radiotap header length
   0x04, 0x0c, 0x00, 0x00, // <-- bitmap
   0x6c, // <-- rate
   0x0c, //<-- tx power
   0x01 //<-- antenna

The ieee80211 header follows immediately afterwards, looking for example like this:
   0x08, 0x01, 0x00, 0x00,
   0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
   0x13, 0x22, 0x33, 0x44, 0x55, 0x66,
   0x13, 0x22, 0x33, 0x44, 0x55, 0x66,
   0x10, 0x86

Then lastly there is the payload.

After composing the packet contents, it is sent by send()-ing it to a logical mac80211 interface that is in Monitor mode.

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
*/

struct ieee80211_radiotap_header {
   unsigned char it_version;       // Version 0. Only increases
   unsigned char it_pad;
   unsigned short int it_len;      // length of the whole header in bytes, including it_version, it_pad, it_len, and data fields.
   unsigned       int it_present;  // bitmap telling which fields are present.
                                   // Set bit 31 (0x80000000) to extend the bitmap by another 32 bits.
} *radio_hdr = 0x00000000;

/*
// bits of it_present
enum ieee80211_radiotap_type {
   IEEE80211_RADIOTAP_TSFT = 0,
   IEEE80211_RADIOTAP_FLAGS = 1,
   IEEE80211_RADIOTAP_RATE = 2,
   IEEE80211_RADIOTAP_CHANNEL = 3,
   IEEE80211_RADIOTAP_FHSS = 4,
   IEEE80211_RADIOTAP_DBM_ANTSIGNAL = 5,
   IEEE80211_RADIOTAP_DBM_ANTNOISE = 6,
   IEEE80211_RADIOTAP_LOCK_QUALITY = 7,
   IEEE80211_RADIOTAP_TX_ATTENUATION = 8,
   IEEE80211_RADIOTAP_DB_TX_ATTENUATION = 9,
   IEEE80211_RADIOTAP_DBM_TX_POWER = 10,
   IEEE80211_RADIOTAP_ANTENNA = 11,
   IEEE80211_RADIOTAP_DB_ANTSIGNAL = 12,
   IEEE80211_RADIOTAP_DB_ANTNOISE = 13,
   IEEE80211_RADIOTAP_RX_FLAGS = 14,
   IEEE80211_RADIOTAP_TX_FLAGS = 15,
   IEEE80211_RADIOTAP_RTS_RETRIES = 16,
   IEEE80211_RADIOTAP_DATA_RETRIES = 17,

   IEEE80211_RADIOTAP_MCS = 19,
   IEEE80211_RADIOTAP_AMPDU_STATUS = 20,
   IEEE80211_RADIOTAP_VHT = 21,

   // valid in every it_present bitmap, even vendor namespaces
   IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE = 29,
   IEEE80211_RADIOTAP_VENDOR_NAMESPACE = 30,
   IEEE80211_RADIOTAP_EXT = 31
};


Name                                 Data type    Units          Comments
----                                 ---------    -----          --------
IEEE80211_RADIOTAP_TSFT              __le64       microseconds   Time Synchronization Function
IEEE80211_RADIOTAP_FLAGS             u8           bitmap         Properties of transmitted and received frames.
IEEE80211_RADIOTAP_RATE              u8           500kb/s        Tx/Rx data rate
IEEE80211_RADIOTAP_CHANNEL           2 x __le16   MHz, bitmap    Tx/Rx frequency in MHz, followed by flags (see below).

IEEE80211_RADIOTAP_FHSS              __le16       see below      Frequency-hopping radios, the hop set (first byte) and pattern (second byte).
IEEE80211_RADIOTAP_DBM_ANTSIGNAL     s8           dBm            RF signal power at the antenna
IEEE80211_RADIOTAP_DBM_ANTNOISE      s8           dBm            RF noise power at the antenna
IEEE80211_RADIOTAP_LOCK_QUALITY      __le16       unitless       Signal Quality

IEEE80211_RADIOTAP_TX_ATTENUATION    __le16       unitless       Transmit power relative to power set at factory calibration. 0 is max power.
IEEE80211_RADIOTAP_DB_TX_ATTENUATION __le16       decibels (dB)  Transmit power relative to power set at factory calibration. 0 is max power.
IEEE80211_RADIOTAP_DBM_TX_POWER      s8           dBm            Transmit power
IEEE80211_RADIOTAP_ANTENNA           u8                          Antenna for this packet. The first antenna is antenna 0.

IEEE80211_RADIOTAP_DB_ANTSIGNAL      u8           decibel (dB)   RF signal power at the antenna
IEEE80211_RADIOTAP_DB_ANTNOISE       u8           decibel (dB)   RF noise power at the antenna
IEEE80211_RADIOTAP_RX_FLAGS          __le16       bitmap         Properties of received frames
IEEE80211_RADIOTAP_TX_FLAGS          __le16       bitmap         Properties of transmitted frames

IEEE80211_RADIOTAP_RTS_RETRIES       u8           data           Number of rts retries a transmitted frame used.
IEEE80211_RADIOTAP_DATA_RETRIES      u8           data           Number of unicast retries a transmitted frame used.

IEEE80211_RADIOTAP_MCS   u8, u8, u8               unitless       Contains a bitmap of known fields/flags, the flags, and the MCS index.
IEEE80211_RADIOTAP_AMPDU_STATUS   u32, u16, u8, u8   unitless    Contains the AMPDU information for the subframe.
IEEE80211_RADIOTAP_VHT   u16, u8, u8, u8[4], u8, u8, u16

-------------------------
it_present:  0xA000402F
it_present:  0x00000820

00000020                           00 00_24 00_2f 40 00 a0_ |..........$./@..|
00000030  20 08 00 00_00 00 00 00_ bd de a9 81 11 00 00 00_ | ...............|
00000040  10_02_6c 09 a0 00_d5_00 _00 00_d5_00_80 00 00 00  |..l.............|
                               ^ padding

 - the arguments must be aligned to a boundary of the argument size using padding.
   So a u16 argument must start on the next u16 boundary if it isn't already on one, a u32 must start on the next u32 boundary and so on.

-------------------------

// For IEEE80211_RADIOTAP_FLAGS
#define	IEEE80211_RADIOTAP_F_CFP	0x01	// sent/received during CFP
#define	IEEE80211_RADIOTAP_F_SHORTPRE	0x02	// sent/received with short preamble
#define	IEEE80211_RADIOTAP_F_WEP	0x04	// sent/received with WEP encryption
#define	IEEE80211_RADIOTAP_F_FRAG	0x08	// sent/received with fragmentation
#define	IEEE80211_RADIOTAP_F_FCS	0x10	// frame includes FCS
#define	IEEE80211_RADIOTAP_F_DATAPAD	0x20	// frame has padding between 802.11 header and payload (to 32-bit boundary)
#define IEEE80211_RADIOTAP_F_BADFCS	0x40	// bad FCS

// Channel flags.
#define   IEEE80211_CHAN_TURBO     0x0010   // Turbo channel
#define   IEEE80211_CHAN_CCK       0x0020   // CCK channel
#define   IEEE80211_CHAN_OFDM      0x0040   // OFDM channel
#define   IEEE80211_CHAN_2GHZ      0x0080   // 2 GHz spectrum channel.
#define   IEEE80211_CHAN_5GHZ      0x0100   // 5 GHz spectrum channel
#define   IEEE80211_CHAN_PASSIVE   0x0200   // Only passive scan allowed
#define   IEEE80211_CHAN_DYN       0x0400   // Dynamic CCK-OFDM channel
#define   IEEE80211_CHAN_GFSK      0x0800   // GFSK channel (FHSS PHY)
#define   IEEE80211_CHAN_GSM       0x1000   // GSM (900 MHz)
#define   IEEE80211_CHAN_STURBO    0x2000   // Static Turbo
#define   IEEE80211_CHAN_HALF      0x4000   // Half channel (10 MHz wide)
#define   IEEE80211_CHAN_QUARTER   0x8000   // Quarter channel (5 MHz wide)

// IEEE80211_RADIOTAP_RX_FLAGS
#define IEEE80211_RADIOTAP_F_RX_BADPLCP 0x0002   // frame has bad PLCP

// For IEEE80211_RADIOTAP_TX_FLAGS
#define IEEE80211_RADIOTAP_F_TX_FAIL    0x0001   // failed due to excessive retries
#define IEEE80211_RADIOTAP_F_TX_CTS     0x0002   // used cts 'protection'
#define IEEE80211_RADIOTAP_F_TX_RTS     0x0004   // used rts/cts handshake
#define IEEE80211_RADIOTAP_F_TX_NOACK   0x0008   // don't expect an ack

*/

int enlace_radio() {
   unsigned int *present;
   
   radio_hdr = (struct ieee80211_radiotap_header *)cache_pos;
   
   printf("\nCabeçalho Radio Tape:\n");
   printf("version:     0x%02X, 0x%02X\n", radio_hdr->it_version, radio_hdr->it_pad);
   printf("length:      0x%04X\n", radio_hdr->it_len);
   present = &radio_hdr->it_present;
   for ( ; ; ) {
      printf("it_present:  0x%08X\n", *present);
      if (0x80000000 & *present) present++;
      else break;
   }
   printf("Termine isso aqui.\n");

   total = total + radio_hdr->it_len;
   cache_pos = cache_pos + radio_hdr->it_len;
   
   if (enlace_wlan()) return 1;
   
   return 0;
}

