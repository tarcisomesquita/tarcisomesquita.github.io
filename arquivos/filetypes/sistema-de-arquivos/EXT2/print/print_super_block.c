// Structure of the super block
struct ext2_super_block {
   unsigned int s_inodes_count;      // Inodes count
   unsigned int s_blocks_count;      // Blocks count
   unsigned int s_r_blocks_count;    // Reserved blocks count
   unsigned int s_free_blocks_count; // Free blocks count
   unsigned int s_free_inodes_count; // Free inodes count
   unsigned int s_first_data_block;  // First Data Block
   unsigned int s_log_block_size;    // Block size
   unsigned int s_log_frag_size;     // Fragment size
   unsigned int s_blocks_per_group;  // # Blocks per group
   unsigned int s_frags_per_group;   // # Fragments per group
   unsigned int s_inodes_per_group;  // # Inodes per group
   unsigned int s_mtime;             // Mount time
   unsigned int s_wtime;             // Write time
   unsigned short s_mnt_count;       // Mount count
   unsigned short s_max_mnt_count;   // Maximal mount count
   unsigned short s_magic;           // Magic signature
   unsigned short s_state;           // File system state
   unsigned short s_errors;          // Behaviour when detecting errors
   unsigned short s_minor_rev_level; // minor revision level
   unsigned int s_lastcheck;         // time of last check
   unsigned int s_checkinterval;     // max. time between checks
   unsigned int s_creator_os;        // OS
   unsigned int s_rev_level;         // Revision level
   unsigned short s_def_resuid;      // Default uid for reserved blocks
   unsigned short s_def_resgid;      // Default gid for reserved blocks
   
   // These fields are for EXT2_DYNAMIC_REV superblocks only.
   unsigned int s_first_ino;         // First non-reserved inode
   unsigned short s_inode_size;      // size of inode structure
   unsigned short s_block_group_nr;  // block group # of this superblock
   unsigned int s_feature_compat;    // compatible feature set
   unsigned int s_feature_incompat;  // incompatible feature set
   unsigned int s_feature_ro_compat; // readonly-compatible feature set
   unsigned char s_uuid[16];         // 128-bit uuid for volume
   char s_volume_name[16];           // volume name
   char s_last_mounted[64];          // directory where last mounted
   unsigned int s_algorithm_usage_bitmap; // For compression
   
   // Performance hints.  Directory preallocation should only happen if the EXT2_COMPAT_PREALLOC flag is on.
   unsigned char s_prealloc_blocks;  // Nr of blocks to try to preallocate
   unsigned char s_prealloc_dir_blocks; // Nr to preallocate for dirs
   unsigned short s_padding1;
   
   // Journaling support valid if EXT3_FEATURE_COMPAT_HAS_JOURNAL set.
   unsigned char s_journal_uuid[16]; // uuid of journal superblock
   unsigned int s_journal_inum;      // inode number of journal file
   unsigned int s_journal_dev;       // device number of journal file
   unsigned int s_last_orphan;       // start of list of inodes to delete
   unsigned int s_hash_seed[4];      // HTREE hash seed
   unsigned char s_def_hash_version; // Default hash version to use
   unsigned char s_reserved_char_pad;
   unsigned short s_reserved_word_pad;
   unsigned int s_default_mount_opts;
   unsigned int s_first_meta_bg;     // First metablock block group
   unsigned int s_reserved[190];     // Padding to the end of the block
} *super_block = 0x00000000;

void print_super_block() {
   int i, n;
   
   printf("\n\n; Super bloco\n\n");
   printf("s_inodes_count:             dd 0x%08X    ; 0x00000400 Inodes count\n", super_block->s_inodes_count);
   printf("s_blocks_count:             dd 0x%08X    ; 0x00000404 Blocks count\n", super_block->s_blocks_count);
   printf("s_r_blocks_count:           dd 0x%08X    ; 0x00000408 Reserved blocks count\n", super_block->s_r_blocks_count);
   printf("s_free_blocks_count:        dd 0x%08X    ; 0x0000040C Free blocks count\n", super_block->s_free_blocks_count);
   printf("s_free_inodes_count:        dd 0x%08X    ; 0x00000410 Free inodes count\n", super_block->s_free_inodes_count);
   printf("s_first_data_block:         dd 0x%08X    ; 0x00000414 First Data Block\n", super_block->s_first_data_block);
   printf("s_log_block_size:           dd 0x%08X    ; 0x00000418 Block size\n", super_block->s_log_block_size);
   printf("s_log_frag_size:            dd 0x%08X    ; 0x0000041C Fragment size\n", super_block->s_log_frag_size);
   printf("s_blocks_per_group:         dd 0x%08X    ; 0x00000420 # Blocks per group\n", super_block->s_blocks_per_group);
   printf("s_frags_per_group:          dd 0x%08X    ; 0x00000424 # Fragments per group\n", super_block->s_frags_per_group);
   printf("s_inodes_per_group:         dd 0x%08X    ; 0x00000428 # Inodes per group\n", super_block->s_inodes_per_group);
   printf("s_mtime:                    dd 0x%08X    ; 0x0000042C Mount time\n", super_block->s_mtime);
   printf("s_wtime:                    dd 0x%08X    ; 0x00000430 Write time\n", super_block->s_wtime);
   printf("s_mnt_count:                dw 0x%04X        ; 0x00000434 Mount count\n", super_block->s_mnt_count);
   printf("s_max_mnt_count:            dw 0x%04X        ; 0x00000436 Maximal mount count\n", super_block->s_max_mnt_count);
   printf("s_magic:                    dw 0x%04X        ; 0x00000438 Magic signature\n", super_block->s_magic);
   printf("s_state:                    dw 0x%04X        ; 0x0000043A File system state\n", super_block->s_state);
   printf("s_errors:                   dw 0x%04X        ; 0x0000043C Behaviour when detecting errors\n", super_block->s_errors);
   printf("s_minor_rev_level:          dw 0x%04X        ; 0x0000043E minor revision level\n", super_block->s_minor_rev_level);
   printf("s_lastcheck:                dd 0x%08X    ; 0x00000440 time of last check\n", super_block->s_lastcheck);
   printf("s_checkinterval:            dd 0x%08X    ; 0x00000444 max. time between checks\n", super_block->s_checkinterval);
   printf("s_creator_os:               dd 0x%08X    ; 0x00000448 OS\n", super_block->s_creator_os);
   printf("s_rev_level:                dd 0x%08X    ; 0x0000044C Revision level\n", super_block->s_rev_level);
   printf("s_def_resuid:               dw 0x%04X        ; 0x00000450 Default uid for reserved blocks\n", super_block->s_def_resuid);
   printf("s_def_resgid:               dw 0x%04X        ; 0x00000452 Default gid for reserved blocks\n", super_block->s_def_resgid);
   
   // These fields are for EXT2_DYNAMIC_REV superblocks only.
   printf("s_first_ino:                dd 0x%08X    ; 0x00000454 # First non-reserved inode\n", super_block->s_first_ino);
   printf("s_inode_size:               dw 0x%04X        ; 0x00000458 size of inode structure\n", super_block->s_inode_size);
   printf("s_block_group_nr:           dw 0x%04X        ; 0x0000045A block group # of this superblock\n", super_block->s_block_group_nr);
   printf("s_feature_compat:           dd 0x%08X    ; 0x0000045C compatible feature set\n", super_block->s_feature_compat);
   printf("s_feature_incompat:         dd 0x%08X    ; 0x00000460 incompatible feature set\n", super_block->s_feature_incompat);
   printf("s_feature_ro_compat:        dd 0x%08X    ; 0x00000464 readonly-compatible feature set\n", super_block->s_feature_ro_compat);
   
   printf("s_uuid:                     db ");
   for (i=0; i<16 ; i++) {
      printf("0x%02X", super_block->s_uuid[i]);
      if (i < 15) printf(", ");
   }
   printf(" ; 0x00000468 volume uuid\n");
   printf("s_volume_name:              db \"%s\" ; 0x00000478 volume name\n", super_block->s_volume_name);
   n = strlen(super_block->s_volume_name);
   n = 16 - n;
   printf("     times 0x%02X             db 0x00\n", n);
   
   printf("s_last_mounted:             db \"%s\" ; 0x00000488 directory where last mounted\n", super_block->s_last_mounted);
   n = strlen(super_block->s_last_mounted);
   n = 64 - n;
   printf("     times 0x%02X             db 0x00\n", n);
   
   printf("s_algorithm_usage_bitmap:   dd 0x%08X    ; 0x000004C8 For compression\n", super_block->s_algorithm_usage_bitmap);
   
   // Performance hints.  Directory preallocation should only happen if the EXT2_COMPAT_PREALLOC flag is on.
   printf("s_prealloc_blocks:          db 0x%02X          ; 0x000004CC Nr of blocks to try to preallocate\n", super_block->s_prealloc_blocks);
   printf("s_prealloc_dir_blocks:      db 0x%02X          ; 0x000004CD Nr to preallocate for dirs\n", super_block->s_prealloc_dir_blocks);
   printf("s_padding1:                 dw 0x%04X        ; 0x000004CE \n", super_block->s_padding1);
   
   // Journaling support valid if EXT3_FEATURE_COMPAT_HAS_JOURNAL set.
   printf("s_journal_uuid:             db ");
   for (i=0; i<16 ; i++) {
      printf("0x%02X", super_block->s_journal_uuid[i]);
      if (i < 15) printf(", ");
   }
   printf(" ; 0x000004D0 journal uuid\n");
   printf("s_journal_inum:             dd 0x%08X    ; 0x000004E0 inode number of journal file\n", super_block->s_journal_inum);
   printf("s_journal_dev:              dd 0x%08X    ; 0x000004E4 device number of journal file\n", super_block->s_journal_dev);
   printf("s_last_orphan:              dd 0x%08X    ; 0x000004E8 start of list of inodes to delete\n", super_block->s_last_orphan);
   printf("s_hash_seed:                dd ");
   for (i=0; i<4 ; i++) {
      printf("0x%08X", super_block->s_hash_seed[i]);
      if (i < 3) printf(", ");
   }
   printf(" ; 0x000004EC HTREE hash seed\n");
   
   printf("s_def_hash_version:         db 0x%02X          ; 0x000004FC Default hash version to use\n", super_block->s_def_hash_version);
   printf("s_reserved_char_pad:        db 0x%02X          ; 0x000004FD \n", super_block->s_reserved_char_pad);
   printf("s_reserved_word_pad:        dw 0x%04X        ; 0x000004FE \n", super_block->s_reserved_word_pad);
   printf("s_default_mount_opts:       dd 0x%08X    ; 0x00000500 \n", super_block->s_default_mount_opts);
   printf("s_first_meta_bg:            dd 0x%08X    ; 0x00000404 First metablock block group\n", super_block->s_first_meta_bg);
   printf("s_reserved:   times 190     dd 0x00000000    ; 0x00000408 Padding to the end of the block\n");
   
   return;
}

