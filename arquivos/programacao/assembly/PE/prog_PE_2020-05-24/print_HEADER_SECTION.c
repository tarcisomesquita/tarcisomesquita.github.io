int print_HEADER_SECTION() {
   unsigned int i, n;
   struct _IMAGE_SECTION_HEADER *sct_hdr_L;
   
   sct_hdr = (struct _IMAGE_SECTION_HEADER *)(buffer + offset);
   sct_hdr_L = sct_hdr;
   
   printf("section_header:\n");
   for (i=0; i < file_hdr->NumberOfSections; i++) {
      printf("Name_%u:                      .byte ", i);
      for (n=0; n < 8; n++) {
         if (sct_hdr_L->Name[n]) printf("\'%c\'", sct_hdr_L->Name[n]);
         else printf("0x00");
         if (n == 7) printf("     # 0x%04X \n", offset);
         else        printf(", ");
      }
      offset += 8;
      printf("VirtualSize_%u:               .long 0x%08X     # 0x%04X Tamanho da sessão no arquivo.\n", 
             i, (unsigned int)sct_hdr_L->VirtualSize, offset);
      offset += 4;
      printf("VirtualAddress_%u:            .long 0x%08X     # 0x%04X Posição da seção na memória a partir da base\n", 
             i, (unsigned int)sct_hdr_L->VirtualAddress, offset);
      offset += 4;
      printf("SizeOfRawData_%u:             .long 0x%08X     # 0x%04X Tamanho da sessão no arquivo incluindo alinhamento.\n", 
             i, (unsigned int)sct_hdr_L->SizeOfRawData, offset);
      offset += 4;
      printf("PointerToRawData_%u:          .long 0x%08X     # 0x%04X Posição da seção dentro do arquivo\n", 
             i, (unsigned int)sct_hdr_L->PointerToRawData, offset);
      offset += 4;
      printf("PointerToRelocations_%u:      .long 0x%08X     # 0x%04X \n", i, (unsigned int)sct_hdr_L->PointerToRelocations, offset);
      offset += 4;
      printf("PointerToLinenumbers_%u:      .long 0x%08X     # 0x%04X \n", i, (unsigned int)sct_hdr_L->PointerToLinenumbers, offset);
      offset += 4;
      printf("NumberOfRelocations_%u:       .word 0x%04X         # 0x%04X \n", i, (unsigned int)sct_hdr_L->NumberOfRelocations, offset);
      offset += 2;
      printf("NumberOfLinenumbers_%u:       .word 0x%04X         # 0x%04X \n", i, (unsigned int)sct_hdr_L->NumberOfLinenumbers, offset);
      offset += 2;
      printf("Characteristics_%u:           .long 0x%08X     # 0x%04X \n", i, (unsigned int)sct_hdr_L->Characteristics, offset);
      offset += 4;
      if (sct_hdr_L->Characteristics & 0x00000020) printf("                                                           # "
          "0x00000020   Code section.\n");
      if (sct_hdr_L->Characteristics & 0x00000040) printf("                                                           # "
          "0x00000040   Initialized data section.\n");
      if (sct_hdr_L->Characteristics & 0x00000080) printf("                                                           # "
          "0x00000080   Uninitialized data section.\n");
      if (sct_hdr_L->Characteristics & 0x00000200) printf("                                                           # "
          "0x00000200   Section contains comments or some other type of information.\n");
      if (sct_hdr_L->Characteristics & 0x01000000) printf("                                                           # "
          "0x01000000   Section contains extended relocations.\n");
      if (sct_hdr_L->Characteristics & 0x02000000) printf("                                                           # "
          "0x02000000   Section can be discarded.\n");
      if (sct_hdr_L->Characteristics & 0x04000000) printf("                                                           # "
          "0x04000000   Section must not be cached.\n");
      if (sct_hdr_L->Characteristics & 0x08000000) printf("                                                           # "
          "0x08000000   Section is not pageable.\n");
      if (sct_hdr_L->Characteristics & 0x10000000) printf("                                                           # "
          "0x10000000   Section is shared.\n");
      if (sct_hdr_L->Characteristics & 0x20000000) printf("                                                           # "
          "0x20000000   Executable section.\n");
      if (sct_hdr_L->Characteristics & 0x40000000) printf("                                                           # "
          "0x40000000   Readable section.\n");
      if (sct_hdr_L->Characteristics & 0x80000000) printf("                                                           # "
          "0x80000000   Writeable section.\n");
      
      printf("\n");
      sct_hdr_L++;
   }
   
   return 0;
}

