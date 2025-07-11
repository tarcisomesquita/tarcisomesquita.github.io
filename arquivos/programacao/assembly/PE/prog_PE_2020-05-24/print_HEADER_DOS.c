int print_HEADER_DOS() {
   unsigned char *c;
   
   dos_hdr = (struct _IMAGE_DOS_HEADER *)buffer;
   
   printf("dos_header:\n");
   
   c = (unsigned char *)&dos_hdr->e_magic;
   printf("e_magic:                     .ascii \"%c%c\"          # 0x%04X Magic number\n", c[0], c[1], offset);
   offset += 2; 
   printf("e_cblp:                      .word 0x%04X         # 0x%04X Bytes on last page of file\n", dos_hdr->e_cblp, offset);
   offset += 2; 
   printf("e_cp:                        .word 0x%04X         # 0x%04X Pages in file (1kiB ?)\n", dos_hdr->e_cp, offset);
   offset += 2; 
   printf("e_crlc:                      .word 0x%04X         # 0x%04X Relocations\n", dos_hdr->e_crlc, offset);
   offset += 2; 
   printf("e_cparhdr:                   .word 0x%04X         # 0x%04X Size of header in paragraphs (16 bytes)\n", dos_hdr->e_cparhdr, offset);
   offset += 2; 
   printf("e_minalloc:                  .word 0x%04X         # 0x%04X Minimum extra paragraphs needed\n", dos_hdr->e_minalloc, offset);
   offset += 2; 
   printf("e_maxalloc:                  .word 0x%04X         # 0x%04X Maximum extra paragraphs needed\n", dos_hdr->e_maxalloc, offset);
   offset += 2; 
   printf("e_ss:                        .word 0x%04X         # 0x%04X Initial (relative) SS value\n", dos_hdr->e_ss, offset);
   offset += 2; 
   printf("e_sp:                        .word 0x%04X         # 0x%04X Initial SP value\n", dos_hdr->e_sp, offset);
   offset += 2; 
   printf("e_csum:                      .word 0x%04X         # 0x%04X Checksum\n", dos_hdr->e_csum, offset);
   offset += 2; 
   printf("e_ip:                        .word 0x%04X         # 0x%04X Initial IP value\n", dos_hdr->e_ip, offset);
   offset += 2; 
   printf("e_cs:                        .word 0x%04X         # 0x%04X Initial (relative) CS value\n", dos_hdr->e_cs, offset);
   offset += 2; 
   printf("e_lfarlc:                    .word 0x%04X         # 0x%04X File address of relocation table\n", dos_hdr->e_lfarlc, offset);
   offset += 2; 
   printf("e_ovno:                      .word 0x%04X         # 0x%04X Overlay number\n", dos_hdr->e_ovno, offset);
   offset += 2; 
   if (dos_hdr->e_res[0] == 0x0000 &&
      dos_hdr->e_res[1] == 0x0000 &&
      dos_hdr->e_res[2] == 0x0000 &&
      dos_hdr->e_res[3] == 0x0000
     ) printf("e_res:              .rept  4 .word 0x0000 ; .endr # 0x%04X Reserved words\n", offset);
   else return 1;
   offset += 4*2; 
   printf("e_oemid:                     .word 0x%04X         # 0x%04X OEM identifier (for e_oeminfo)\n", dos_hdr->e_oemid, offset);
   offset += 2; 
   printf("e_oeminfo:                   .word 0x%04X         # 0x%04X OEM information; e_oemid specific\n", dos_hdr->e_oeminfo, offset);
   offset += 2; 
   if(dos_hdr->e_res2[0] == 0x0000 &&
      dos_hdr->e_res2[1] == 0x0000 &&
      dos_hdr->e_res2[2] == 0x0000 &&
      dos_hdr->e_res2[3] == 0x0000 &&
      dos_hdr->e_res2[4] == 0x0000 &&
      dos_hdr->e_res2[5] == 0x0000 &&
      dos_hdr->e_res2[6] == 0x0000 &&
      dos_hdr->e_res2[7] == 0x0000 &&
      dos_hdr->e_res2[8] == 0x0000 &&
      dos_hdr->e_res2[9] == 0x0000
     ) printf("e_res2:             .rept 10 .word 0x0000 ; .endr # 0x%04X Reserved words\n", offset);
   else return 1;
   offset += 10*2; 
   printf("e_lfanew:                    .long 0x%08X     # 0x%04X File address of\n", (unsigned int)dos_hdr->e_lfanew, offset);
   offset += 4; 
   
   printf("\n");
   
   return 0;
}

