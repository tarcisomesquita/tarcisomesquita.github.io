struct ext2_dir_entry_2 {
   unsigned int inode;      // Inode number
   unsigned short rec_len;  // Directory entry length
   unsigned char name_len;  // Name length
   unsigned char file_type;
   char name[255];          // File name
} *dir_entry = 0x00000000;


int print_dir_entry(unsigned int bloco) {
   unsigned int offset, offset_old, n;
   
   dir_entry = malloc((unsigned long int)sizeof(struct ext2_dir_entry_2));
   if (! dir_entry)  { printf("\nERRO: malloc.\n\n"); return 1; }
   dir_entry->rec_len = 0;
   
   offset = bloco * block_size;
   offset_old = offset;
   n = lseek(fd, offset, SEEK_SET);
   if (n != offset) { printf("\nERRO: lseek.\n\n"); return 1; }
   
   printf("\n");
   printf("dir_entry no bloco 0x%04X\n", bloco);
   printf("\n");
   for (;;) {
      if (dir_entry->rec_len) {
         offset = offset_old + dir_entry->rec_len;
         offset_old = offset;
         n = lseek(fd, offset, SEEK_SET);
      }
      n = read(fd, dir_entry, (unsigned long int)sizeof(struct ext2_dir_entry_2));
      if (n != (unsigned long int)sizeof(struct ext2_dir_entry_2)) { printf("\nERRO: read.\n\n"); free(dir_entry); return 1; }
      
      //  hexdump -C -s $((512*(2 + 20) + 0x204*1024)) -n $((1024)) 64MiB.bin 
      printf("inode:               dd 0x%08X    ; 0x%08X Inode number\n", dir_entry->inode, offset);
      offset += 4;
      printf("rec_len:             dw 0x%04X        ; 0x%08X Directory entry lenght\n", dir_entry->rec_len, offset);
      offset += 2;
      printf("name_len:            db 0x%02X          ; 0x%08X Name lenght\n", dir_entry->name_len, offset);
      offset += 1;
      printf("file_type:           db 0x%02X          ; 0x%08X \n", dir_entry->file_type, offset);
      offset += 1;
      printf("name:                db \"%s\"           ; 0x%08X File name\n", dir_entry->name, offset);
      printf("\n");
      
      if ((offset_old + dir_entry->rec_len - bloco * block_size) >= 0x400 ) break;
   }
   free(dir_entry);
   return 0;
}

