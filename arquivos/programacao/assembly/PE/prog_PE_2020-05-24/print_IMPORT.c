int print_import(unsigned int PointerToRawData, unsigned int VirtualAddress) {
   unsigned int  *trunk;
   char *name_l, terminar[]="null", label[200];
   struct _IMAGE_IMPORT_DESCRIPTOR *ipt_dsc_L;
   
   printf("ImportTable:\n");
   ipt_dsc = (struct _IMAGE_IMPORT_DESCRIPTOR *)(buffer + offset);
   ipt_dsc_L = ipt_dsc;
   for ( ; ; ) {
      if (ipt_dsc_L->Name == 0x00000000) name_l = terminar;
      else name_l = (char *)(buffer + PointerToRawData + (ipt_dsc_L->Name - VirtualAddress));
      sprintf(label, "OFT_%s:", name_l);
      
      if (ipt_dsc_L->OriginalFirstThunk == 0x00000000) {
         printf("%-35s .long 0x%08X     # 0x%04X \n", label, ipt_dsc_L->OriginalFirstThunk, offset);
      }
      else {
         printf("%-35s .long 0x%08X     # 0x%04X \n", label, ipt_dsc_L->OriginalFirstThunk, offset);
      }
      offset += 4;
      
      sprintf(label, "Date_%s:", name_l);
      printf("%-35s .long 0x%08X     # 0x%04X \n", label, ipt_dsc_L->TimeDateStamp, offset);
      offset += 4;
      
      sprintf(label, "Chain_%s:", name_l);
      printf("%-35s .long 0x%08X     # 0x%04X \n", label, ipt_dsc_L->ForwarderChain, offset);
      offset += 4;
      
      sprintf(label, "Name_%s:", name_l);
      printf("%-35s .long 0x%08X     # 0x%04X \n", label, ipt_dsc_L->Name, offset);
      offset += 4;
      
      sprintf(label, "FT_%s:", name_l);
      printf("%-35s .long 0x%08X     # 0x%04X \n", label, ipt_dsc_L->FirstThunk, offset);
      offset += 4;
      
      printf("\n");
      
      if (ipt_dsc_L->Name == 0x00000000) break;
      ipt_dsc_L++;
   }
   
   printf("# Nome das bibliotecas\n");
   ipt_dsc_L = ipt_dsc;
   for ( ; ; ) {
      if (ipt_dsc_L->Name == 0x00000000) break;
      
      name_l = (char *)(buffer + PointerToRawData + (ipt_dsc_L->Name - VirtualAddress));
      offset = PointerToRawData + (ipt_dsc_L->Name - VirtualAddress);
      
      sprintf(label, "_%s:", name_l);
      printf("%-29s", label);
      
      sprintf(label, ".string \"%s\"", name_l);
      printf("%-30s# 0x%04X\n", label, offset);
      
      ipt_dsc_L++;
   }
   printf("\n");
   
   // trunk
   ipt_dsc_L = ipt_dsc;
   for ( ; ; ) {
      if (ipt_dsc_L->Name == 0x00000000) break;
      
      name_l = (char *)(buffer + PointerToRawData + (ipt_dsc_L->Name - VirtualAddress));
      sprintf(label, "trunk_%s:", name_l);
      printf("%-29s\n", label);
      
      offset = PointerToRawData + (ipt_dsc_L->OriginalFirstThunk - VirtualAddress);
      trunk = (unsigned int *)(buffer + offset);
      
      for ( ; ; ) {
         imp_by_name = (struct _IMAGE_IMPORT_BY_NAME *)(buffer + PointerToRawData + (*trunk - VirtualAddress));
         
         if (*trunk == 0x00000000) {
            sprintf(label, "%s_%s:", name_l, terminar);
            printf("%-35s .long 0x%08X     # 0x%04X\n", label, *trunk, offset);
            break;
         }
         else {
            sprintf(label, "%s_%s:", name_l, &(imp_by_name->Name));
            printf("%-35s .long 0x%08X     # 0x%04X\n", label, *trunk, offset);
         }
         
         trunk++; 
         offset = offset + 4;
      }
      
      printf("\n");
      ipt_dsc_L++;
   }
   
   // imprime Hint
   ipt_dsc_L = ipt_dsc;
   for ( ; ; ) {
      if (ipt_dsc_L->Name == 0x00000000) break;
      
      name_l = (char *)(buffer + PointerToRawData + (ipt_dsc_L->Name - VirtualAddress));
      trunk = (unsigned int *)(buffer + PointerToRawData + (ipt_dsc_L->OriginalFirstThunk - VirtualAddress));
      
      for ( ; ; ) {
         offset = PointerToRawData + (*trunk - VirtualAddress);
         imp_by_name = (struct _IMAGE_IMPORT_BY_NAME *)(buffer + offset);
         
         if (*trunk == 0x00000000) break;
         else {
            sprintf(label, "%s_%s_Hint:", name_l, &(imp_by_name->Name));
            printf("%-33s .word 0x%04X                      # 0x%04X\n", label, imp_by_name->Hint, offset);
            
            sprintf(label, "%s_%s_Name:", name_l, &(imp_by_name->Name));
            printf("%-33s .string ", label);
            sprintf(label, "\"%s\"", &(imp_by_name->Name));
            printf("%-25s # 0x%04X\n\n", label, offset + 2);
         }
         
         trunk++;
      }
      
      ipt_dsc_L++;
   }
   
   printf("\n");
   return 0;
}

