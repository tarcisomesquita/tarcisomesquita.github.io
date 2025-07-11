// parece que o melhor é estudar algum software para ver a estrutura. Pode ser o driver ou o tcpdump.
/*
struct frame_control {
   unsigned char proto_version:2;
   unsigned char type:2;
   unsigned char subtype:4;
   unsigned char toDS:1;
   unsigned char fromDS:1;
   unsigned char moreFrag:1;
   unsigned char retry:1;
   unsigned char powerManagement:1;
   unsigned char moreData:1;
   unsigned char wep:1;
   unsigned char order:1;
};

struct sequence_control {
   unsigned short int sequence_number:12;
   unsigned short int fragment_number:4;
};

// This is an 802.11 wlan frame header.
struct wlanhdr {
   struct frame_control fc;
   unsigned short int duration;
   unsigned char mac1[6];
   unsigned char mac2[6];
   unsigned char mac3[6];
   struct sequence_control sc;
   unsigned char mac4[6];
} *wlan_hdr = 0x00000000;

char s1[] = "Transmission between stations in the same BSS";
char s2[] = "Transmission from AP to station";
char s3[] = "Transmission from station to AP";
char s4[] = "Trasmissão de uma estação para outra estação conectada a outro AP";

// linux-4.6/include/linux/ieee80211.h
// Link-id information element
struct ieee80211_tdls_lnkie {
   unsigned char ie_type; // Link Identifier IE
   unsigned char ie_len;
   unsigned char bssid[6];
   unsigned char init_sta[6];
   unsigned char resp_sta[6];
} __packed;

struct ieee80211_mgmt {
   unsigned short int frame_control;
   unsigned short int duration;
   unsigned char da[6];
   unsigned char sa[6];
   unsigned char bssid[6];
   unsigned short int seq_ctrl;
   union {
      struct {
         unsigned short int auth_alg;
         unsigned short int auth_transaction;
         unsigned short int status_code;
         // possibly followed by Challenge text
         unsigned char variable[0];
      } __packed auth;
      struct {
         unsigned short int reason_code;
      } __packed deauth;
      struct {
         unsigned short int capab_info;
         unsigned short int listen_interval;
         // followed by SSID and Supported rates
         unsigned char variable[0];
      } __packed assoc_req;
      struct {
         unsigned short int capab_info;
         unsigned short int status_code;
         unsigned short int aid;
         // followed by Supported rates
         unsigned char variable[0];
      } __packed assoc_resp, reassoc_resp;
      struct {
         unsigned short int capab_info;
         unsigned short int listen_interval;
         unsigned char current_ap[6];
         // followed by SSID and Supported rates
         unsigned char variable[0];
      } __packed reassoc_req;
      struct {
         unsigned short int reason_code;
      } __packed disassoc;
      struct {
         unsigned long int timestamp;
         unsigned short int beacon_int;
         unsigned short int capab_info;
         // followed by some of SSID, Supported rates, FH Params, DS Params, CF Params, IBSS Params, TIM
         unsigned char variable[0];
      } __packed beacon;
      struct {
         // only variable items: SSID, Supported rates
         unsigned char variable[0];
      } __packed probe_req;
      struct {
         unsigned long int timestamp;
         unsigned short int beacon_int;
         unsigned short int capab_info;
         // followed by some of SSID, Supported rates, FH Params, DS Params, CF Params, IBSS Params
         unsigned char variable[0];
      } __packed probe_resp;
      struct {
         unsigned char category;
         union {
            struct {
               unsigned char action_code;
               unsigned char dialog_token;
               unsigned char status_code;
               unsigned char variable[0];
            } __packed wme_action;
            struct{
               unsigned char action_code;
               unsigned char variable[0];
            } __packed chan_switch;
            struct{
               unsigned char action_code;
               struct ieee80211_ext_chansw_ie data;
               unsigned char variable[0];
            } __packed ext_chan_switch;
            struct{
               unsigned char action_code;
               unsigned char dialog_token;
               unsigned char element_id;
               unsigned char length;
               struct ieee80211_msrment_ie msr_elem;
            } __packed measurement;
            struct{
               unsigned char action_code;
               unsigned char dialog_token;
               unsigned short int capab;
               unsigned short int timeout;
               unsigned short int start_seq_num;
            } __packed addba_req;
            struct{
               unsigned char action_code;
               unsigned char dialog_token;
               unsigned short int status;
               unsigned short int capab;
               unsigned short int timeout;
            } __packed addba_resp;
            struct{
               unsigned char action_code;
               unsigned short int params;
               unsigned short int reason_code;
            } __packed delba;
            struct {
               unsigned char action_code;
               unsigned char variable[0];
            } __packed self_prot;
            struct{
               unsigned char action_code;
               unsigned char variable[0];
            } __packed mesh_action;
            struct {
               unsigned char action;
               unsigned char trans_id[WLAN_SA_QUERY_TR_ID_LEN];
            } __packed sa_query;
            struct {
               unsigned char action;
               unsigned char smps_control;
            } __packed ht_smps;
            struct {
               unsigned char action_code;
               unsigned char chanwidth;
            } __packed ht_notify_cw;
            struct {
               unsigned char action_code;
               unsigned char dialog_token;
               unsigned short int capability;
               unsigned char variable[0];
            } __packed tdls_discover_resp;
            struct {
               unsigned char action_code;
               unsigned char operating_mode;
            } __packed vht_opmode_notif;
            struct {
               unsigned char action_code;
               unsigned char membership[WLAN_MEMBERSHIP_LEN];
               unsigned char position[WLAN_USER_POSITION_LEN];
            } __packed vht_group_notif;
            struct {
               unsigned char action_code;
               unsigned char dialog_token;
               unsigned char tpc_elem_id;
               unsigned char tpc_elem_length;
               struct ieee80211_tpc_report_ie tpc;
            } __packed tpc_report;
         } u;
      } __packed action;
   } u;
} __packed __aligned(2);


*/

struct ieee80211_mgmt {
   unsigned short int frame_control;
   unsigned short int duration;
   unsigned char da[6];
   unsigned char sa[6];
   unsigned char bssid[6];
   unsigned short int seq_ctrl;
   union {
      struct {
         unsigned long int timestamp;
         unsigned short int beacon_int;
         unsigned short int capab_info;
         // followed by some of SSID, Supported rates, FH Params, DS Params, CF Params, IBSS Params, TIM
         unsigned char variable[0];
      } beacon;
   } u;
} *wlan_hdr = 0x00000000;

int enlace_wlan() {
   wlan_hdr = (struct ieee80211_mgmt *)cache_pos;
   
   printf("\nCabeçalho 802.11:\n");
   printf("frame_control:  0x%04X\n", wlan_hdr->frame_control);
   printf("duration:       0x%04X\n", wlan_hdr->duration);
   
   printf("DA:             %02X:%02X:%02X:%02X:%02X:%02X\n", wlan_hdr->da[0], wlan_hdr->da[1], wlan_hdr->da[2], 
                                                             wlan_hdr->da[3], wlan_hdr->da[4], wlan_hdr->da[5]);
   printf("SA:             %02X:%02X:%02X:%02X:%02X:%02X\n", wlan_hdr->sa[0], wlan_hdr->sa[1], wlan_hdr->sa[2], 
                                                             wlan_hdr->sa[3], wlan_hdr->sa[4], wlan_hdr->sa[5]);
   printf("BSSID:          %02X:%02X:%02X:%02X:%02X:%02X\n", wlan_hdr->bssid[0], wlan_hdr->bssid[1], wlan_hdr->bssid[2], 
                                                             wlan_hdr->bssid[3], wlan_hdr->bssid[4], wlan_hdr->bssid[5]);
   printf("seq_ctrl:       0x%04X\n", wlan_hdr->seq_ctrl);
   //unsigned short int seq_ctrl;

   return 1;
}

/*
// Maximum size of the ESSID and NICKN strings
#define IW_ESSID_MAX_SIZE	32

BSSID:          1C:7E:E5:C6:04:46
seq_ctrl:       0x7770

                                               ff ff ff ff  |7...7...........|
00000030  ff ff 1c 7e e5 c6 04 46  1c 7e e5 c6 04 46 70 77  |...~...F.~...Fpw|

00000040  71 81 ab f0 10 00 00 00  64 00 31 04 00 0e 53 55  |q.......d.1...SU|
00000050  50 4f 52 54 45 54 45 4c  45 43 4f 4d 01 08 82 84  |PORTETELECOM....|
00000060  8b 96 12 24 48 6c 03 01  01 32 04 0c 18 30 60 33  |...$Hl...2...0`3|
00000070  08 20 01 02 03 04 05 06  07 33 08 21 05 06 07 08  |. .......3.!....|
00000080  09 0a 0b 05 04 02 03 00  00 2a 01 00 2d 1a 6e 11  |.........*..-.n.|
00000090  17 ff 00 00 00 01 00 00  00 00 00 00 00 00 00 00  |................|
000000a0  00 00 0c 00 00 00 00 00  3d 16 01 05 00 00 00 00  |........=.......|
000000b0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
000000c0  7f 01 01 dd 1a 00 50 f2  01 01 00 00 50 f2 02 02  |......P.....P...|
000000d0  00 00 50 f2 02 00 50 f2  04 01 00 00 50 f2 02 30  |..P...P.....P..0|
000000e0  18 01 00 00 0f ac 02 02  00 00 0f ac 02 00 0f ac  |................|
000000f0  04 01 00 00 0f ac 02 00  00 dd 18 00 50 f2 02 01  |............P...|
00000100  01 00 00 03 a4 00 00 27  a4 00 00 42 43 5e 00 62  |.......'...BC^.b|
00000110  32 2f 00 0b 05 00 00 01  12 7a dd 1e 00 90 4c 33  |2/.......z....L3|
00000120  6e 11 17 ff 00 00 00 01  00 00 00 00 00 00 00 00  |n...............|
00000130  00 00 00 00 0c 00 00 00  00 00 dd 1a 00 90 4c 34  |..............L4|
00000140  01 05 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000150  00 00 00 00 00 00 dd 07  00 0c 43 07 00 00 00     |..........C....|



   if ((int)(nc_f-nc_i) < sizeof(struct wlanhdr) && end_of_file == 0 ) if (enche_cache()) return 1;
   
   if ((int)(nc_f-nc_i) < sizeof(struct wlanhdr) ) {
      fprintf(stderr, "\nERRO. O tamanho dos dados é menor que o tamanho do cabeçalho 802.11 wlan.\n\n");
      return 1;
   }
   
   if (! (wlan_hdr = malloc((long unsigned int)sizeof(struct wlanhdr)))) {
      fprintf(stderr, "\nERRO não foi possível alocar %d bytes para o struct wlanhdr.\n\n", sizeof(struct wlanhdr));
      return 1;
   }
   
   n1 = (unsigned short int *)&cache[nc_i + 0];
   wlan_hdr->fc.proto_version =   ((*n1)&0xC000)>>14;
   wlan_hdr->fc.type =            ((*n1)&0x3000)>>12;
   wlan_hdr->fc.subtype =         ((*n1)&0x0F00)>>8;
   wlan_hdr->fc.toDS =            ((*n1)&0x0080)>>7;
   wlan_hdr->fc.fromDS =          ((*n1)&0x0040)>>6;
   wlan_hdr->fc.moreFrag =        ((*n1)&0x0020)>>5;
   wlan_hdr->fc.retry =           ((*n1)&0x0010)>>4;
   wlan_hdr->fc.powerManagement = ((*n1)&0x0008)>>3;
   wlan_hdr->fc.moreData =        ((*n1)&0x0004)>>2;
   wlan_hdr->fc.wep =             ((*n1)&0x0002)>>1;
   wlan_hdr->fc.order =           ((*n1)&0x0001)>>0;
   
   n1 = (unsigned short int *)&cache[nc_i + 2];
   wlan_hdr->duration = *n1;
   
   nc_i = nc_i + 4;
   ja_imp = 4;
   
   wlan_hdr->mac1[0] = cache[nc_i + 0];
   wlan_hdr->mac1[1] = cache[nc_i + 1];
   wlan_hdr->mac1[2] = cache[nc_i + 2];
   wlan_hdr->mac1[3] = cache[nc_i + 3];
   wlan_hdr->mac1[4] = cache[nc_i + 4];
   wlan_hdr->mac1[5] = cache[nc_i + 5];
   
   wlan_hdr->mac2[0] = cache[nc_i + 6];
   wlan_hdr->mac2[1] = cache[nc_i + 7];
   wlan_hdr->mac2[2] = cache[nc_i + 8];
   wlan_hdr->mac2[3] = cache[nc_i + 9];
   wlan_hdr->mac2[4] = cache[nc_i + 10];
   wlan_hdr->mac2[5] = cache[nc_i + 11];
   
   wlan_hdr->mac3[0] = cache[nc_i + 12];
   wlan_hdr->mac3[1] = cache[nc_i + 13];
   wlan_hdr->mac3[2] = cache[nc_i + 14];
   wlan_hdr->mac3[3] = cache[nc_i + 15];
   wlan_hdr->mac3[4] = cache[nc_i + 16];
   wlan_hdr->mac3[5] = cache[nc_i + 17];

   printf("\n\nCabeçalho 802.11 wlan:\n");
   printf("version           %d%d\n", wlan_hdr->fc.proto_version&0x02>>1, wlan_hdr->fc.proto_version&0x01);
   if (wlan_hdr->fc.proto_version) {
      printf("\nERRO: A única versão existente é a 0\n\n");
      return 1;
   }
   printf("type              %d%d     %s\n", wlan_hdr->fc.type&0x02>>1, wlan_hdr->fc.type&0x01, "Management");
   if (wlan_hdr->fc.type != 00) {
      printf("\nainda não implementei isso\n\n");
      return 1;
   }
   printf("subtype           %d%d%d%d   %s\n", wlan_hdr->fc.subtype&0x08>>3, wlan_hdr->fc.subtype&0x04>>2, \
                                          wlan_hdr->fc.subtype&0x02>>1, wlan_hdr->fc.subtype&0x01, "Association request");
   if (wlan_hdr->fc.subtype != 00) {
      printf("\nainda não implementei isso\n\n");
      return 1;
   }
   
   if (wlan_hdr->fc.toDS == 0) {
      if (wlan_hdr->fc.fromDS == 0) sprintf(s, "%s", s1);
      else  sprintf(s, "%s", s2);
   }
   else {
      if (wlan_hdr->fc.fromDS == 0) sprintf(s, "%s", s3);
      else  sprintf(s, "%s", s4);
   }
   printf("toDS              %d      %s\n", wlan_hdr->fc.toDS, s);
   printf("fromDS            %d      \n", wlan_hdr->fc.fromDS);
   
   if (wlan_hdr->fc.moreFrag == 1) {
      printf("moreFrag          %d      %s\n", wlan_hdr->fc.moreFrag, "Tem mais fragmentos nos próximos pacotes.\n\nAinda não implementei isso.\n\n");
      return 1;
   }
   else printf("moreFrag          %d      \n", wlan_hdr->fc.moreFrag);
   
   if (wlan_hdr->fc.retry == 1) {
      printf("retry             %d      %s\n", wlan_hdr->fc.retry, "pacote retransmitido");
   }
   else printf("retry             %d      \n", wlan_hdr->fc.retry);
   
   if (wlan_hdr->fc.powerManagement == 1) {
      printf("powerManagement   %d      %s\n", wlan_hdr->fc.powerManagement, "the sending station is in power-save mode");
   }
   else printf("powerManagement   %d      \n", wlan_hdr->fc.powerManagement);
   
   if (wlan_hdr->fc.moreData == 1) {
      printf("moreData          %d      %s\n", wlan_hdr->fc.moreData, "AP has more frames to send\n\nAinda não implementei isso\n\n");
      return 1;
   }
   else printf("moreData          %d      \n", wlan_hdr->fc.moreData);
   
   if (wlan_hdr->fc.wep == 1) {
      printf("wep               %d      %s\n", wlan_hdr->fc.wep, "encryption and authentication are used");
   }
   else printf("wep               %d      \n", wlan_hdr->fc.wep);
   
   if (wlan_hdr->fc.order == 1) {
      printf("order             %d      %s\n", wlan_hdr->fc.order, "all received data frames must be processed in order");
   }
   else printf("order             %d      \n", wlan_hdr->fc.order);
   
   
   printf("\n");
   if (wlan_hdr->duration != 0) {
      printf("duration          %d      %s\n", wlan_hdr->duration, "indicates how microsecond station need wait because medium is in use");
   }
   else printf("duration          %d      \n", wlan_hdr->duration);
   
   //return 1;
   {
      if ((int)(nc_f-nc_i) < (int)(pcap_packet_hdr->incl_len-0) && end_of_file == 0 ) if (enche_cache()) return 1;
      
      if ((int)(nc_f-nc_i) < (int)(pcap_packet_hdr->incl_len-0)) {
      fprintf(stderr, "\nERRO. O tamanho dos dados é menor que o tamanho capturado do pacote. (802.11)\n\n");
      return 1;
      }
      
      fprintf(stdout, "\n");
      hexdump_string(stdout, file_offset, cache, nc_i, (pcap_packet_hdr->incl_len - ja_imp));
      nc_i = nc_i + (pcap_packet_hdr->incl_len - ja_imp);
   }

   free(wlan_hdr);
   return 0;
}
*/
/*
   fprintf(stdout, "\nFrame Control = %02X %02X %02X %02X\n", cache[nc_i + 0], cache[nc_i + 1], cache[nc_i + 2], cache[nc_i + 3]);
   if (cache[nc_i + 0] == 0x80 && cache[nc_i + 1] == 0x00 && cache[nc_i + 2] == 0x00 && cache[nc_i + 3] == 0x00) {
      fprintf(stdout, "MAC1 = %02X:%02X:%02X:%02X:%02X:%02X\n", \
             cache[nc_i + 4], cache[nc_i + 5], cache[nc_i + 6], cache[nc_i + 7], cache[nc_i + 8], cache[nc_i + 9]);
      fprintf(stdout, "MAC2 = %02X:%02X:%02X:%02X:%02X:%02X\n", \
             cache[nc_i + 10], cache[nc_i + 11], cache[nc_i + 12], cache[nc_i + 13], cache[nc_i + 14], cache[nc_i + 15]);
      fprintf(stdout, "MAC3 = %02X:%02X:%02X:%02X:%02X:%02X\n", \
             cache[nc_i + 16], cache[nc_i + 17], cache[nc_i + 18], cache[nc_i + 19], cache[nc_i + 20], cache[nc_i + 21]);
      
      nc_i = nc_i + 22;
      ja_imp = 22;
   }
   else {
      nc_i = nc_i + 4;
      ja_imp = 4;
   }


      2                 2              6         6         6           6           6      0-2312      4   tamanho em bytes
 +---------------+-------------+---------------+---------------+---------------+------------------+---------------+------------+----------------------+
 | Frame Control | Duration ID | MAC address 1 | MAC address 2 | MAC address 3 | Sequence control | MAC address 4 | Frame body | Frame Check Sequence |
 +---------------+-------------+---------------+---------------+---------------+------------------+---------------+------------+----------------------+
   MAC frame structure   printf("versão   %02d\n\n", wlan_hdr->fc.proto_version);


If two wireless LAN users are sending packets to one another but each is using a different access point, the 802.11 MAC address of both access points and both clients will be present in the four address fields.


    2           2       4       1     1      1      1    1    1     1   1     tamanho em bits
 +----------+------+---------+----+------+------+-------+-------+------+-----+-------+
 | Protocol | Type | Subtype | To | From | More | Retry | Power | More | WEP | Order |
 | version  |      |         | DS | DS   | Frag |       | mgmt  | Data |     |       |
 +----------+------+---------+----+------+------+-------+-------+------+-----+-------+
   Frame Control structure
2013/02/27  01:36:15.479956  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

Pcap_Packet_Header:
ts_sec:        0x512D630F   ; number of seconds elapsed since 00:00:00 on January 1, 1970
ts_usec:       0x000752D4   ; tempo em microsegundos
incl_len:        00269   ; quantidade de bytes capturados
orig_len:        00269   ; quantidade de bytes que o pacote possuia

00000020               80 00 00 00 FF FF FF FF  |     ........|
00000030  FF FF F0 7D 68 E7 68 E6  F0 7D 68 E7 68 E6 00 9F  |...}h.h..}h.h...|
00000040  69 91 88 22 1A 00 00 00  64 00 31 04 00 04 48 41  |i.."....d.1...HA|
00000050  4C 4C 01 08 82 84 8B 96  12 24 48 6C 03 01 04 32  |LL.......$Hl...2|
00000060  04 0C 18 30 60 33 08 20  01 02 03 04 05 06 07 33  |...0`3. .......3|
00000070  08 21 05 06 07 08 09 0A  0B 05 04 01 03 00 00 2A  |.!.............*|

*/

