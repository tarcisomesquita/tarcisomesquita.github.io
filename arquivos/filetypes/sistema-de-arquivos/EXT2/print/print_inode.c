
// Structure of an inode on the disk
struct ext2_inode {
   unsigned short i_mode;        // File mode
   unsigned short i_uid;         // Low 16 bits of Owner Uid
   unsigned int i_size;          // Size in bytes
   unsigned int i_atime;         // Access time
   unsigned int i_ctime;         // Creation time
   unsigned int i_mtime;         // Modification time
   unsigned int i_dtime;         // Deletion Time
   unsigned short i_gid;         // Low 16 bits of Group Id
   unsigned short i_links_count; // Links count
   unsigned int i_blocks;        // Blocks count
   unsigned int i_flags;         // File flags
   union {
      struct {
         unsigned int l_i_reserved1;
      } linux1;
      struct {
         unsigned int h_i_translator;
      } hurd1;
      struct {
         unsigned int m_i_reserved1;
      } masix1;
   } osd1; // OS dependent 1
   unsigned int i_block[(((12 + 1) + 1) + 1)];// Pointers to blocks
   unsigned int i_generation;    // File version (for NFS)
   unsigned int i_file_acl;      // File ACL
   unsigned int i_dir_acl;       // Directory ACL
   unsigned int i_faddr;         // Fragment address
   union {
      struct {
         unsigned char l_i_frag;       // Fragment number
         unsigned char l_i_fsize;      // Fragment size
         unsigned short i_pad1;
         unsigned short l_i_uid_high;  // these 2 fields   
         unsigned short l_i_gid_high;  // were reserved2[0]
         unsigned int l_i_reserved2;
      } linux2;
      struct {
         unsigned char h_i_frag;       // Fragment number
         unsigned char h_i_fsize;      // Fragment size
         unsigned short h_i_mode_high;
         unsigned short h_i_uid_high;
         unsigned short h_i_gid_high;
         unsigned int h_i_author;
      } hurd2;
      struct {
         unsigned char m_i_frag;       // Fragment number
         unsigned char m_i_fsize;      // Fragment size
         unsigned short m_pad1;
         unsigned int m_i_reserved2[2];
      } masix2;
   } osd2; // OS dependent 2
} *inode = 0x00000000;

void print_inode() {
   int i; //, n;
   
   printf("\n\n; Inode\n\n");
   printf("i_mode:              dw 0x%04X        ; File mode\n", inode->i_mode);
   printf("i_uid:               dw 0x%04X        ; Low 16 bits of Owner Uid\n", inode->i_uid);
   printf("i_size:              dd 0x%08X    ; Size in bytes\n", inode->i_size);
   printf("i_atime:             dd 0x%08X    ; Access time\n", inode->i_atime);
   printf("i_ctime:             dd 0x%08X    ; Creation time\n", inode->i_ctime);
   printf("i_mtime:             dd 0x%08X    ; Modification time\n", inode->i_mtime);
   printf("i_dtime:             dd 0x%08X    ; Deletion Time\n", inode->i_dtime);
   printf("i_gid:               dw 0x%04X        ; Low 16 bits of Group Id\n", inode->i_gid);
   printf("i_links_count:       dw 0x%04X        ; Links count\n", inode->i_links_count);
   printf("i_blocks:            dd 0x%08X    ; Blocks count\n", inode->i_blocks);
   printf("i_flags:             dd 0x%08X    ; File flags\n", inode->i_flags);
   printf("osd1:                dd 0x%08X    ; OS dependent 1\n", inode->osd1.linux1.l_i_reserved1);
   for (i=0; i<15 ; i++)  printf("i_block_%02d:          dd 0x%08X    ; Pointers to blocks\n", i, inode->i_block[i]);
   printf("i_generation:        dd 0x%08X    ; File version (for NFS)\n", inode->i_generation);
   printf("i_file_acl:          dd 0x%08X    ; File ACL\n", inode->i_file_acl);
   printf("i_dir_acl:           dd 0x%08X    ; Directory ACL\n", inode->i_dir_acl);
   printf("i_faddr:             dd 0x%08X    ; Fragment address\n", inode->i_faddr);
   printf("l_i_frag:            db 0x%02X          ; Fragment number\n", inode->osd2.linux2.l_i_frag);
   printf("l_i_fsize:           db 0x%02X          ; Fragment size\n", inode->osd2.linux2.l_i_fsize);
   printf("i_pad1:              dw 0x%04X        ; \n", inode->osd2.linux2.i_pad1);
   printf("l_i_uid_high:        dw 0x%04X        ; these 2 fields\n", inode->osd2.linux2.l_i_uid_high);
   printf("l_i_gid_high:        dw 0x%04X        ; were reserved2[0]\n", inode->osd2.linux2.l_i_gid_high);
   printf("l_i_reserved2:       dd 0x%08X    ; \n", inode->osd2.linux2.l_i_reserved2);
   
   return;
}

