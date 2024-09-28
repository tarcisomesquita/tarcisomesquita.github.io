#include "print_IMPORT.c"

int print_SECOES() {
   unsigned      int  i;
   struct _IMAGE_SECTION_HEADER *sct_hdr_L;
   
   sct_hdr_L = sct_hdr;
   for (i=0; i < file_hdr->NumberOfSections; i++) {
      if (file_hdr->Machine == 0x014C) {
         if (img_opt_hdr->DataDirectory[1].VirtualAddress >= sct_hdr_L->VirtualAddress && 
             img_opt_hdr->DataDirectory[1].VirtualAddress < (sct_hdr_L->VirtualAddress + sct_hdr_L->VirtualSize) ) {
            offset = sct_hdr_L->PointerToRawData + img_opt_hdr->DataDirectory[1].VirtualAddress - sct_hdr_L->VirtualAddress;
            if (print_import(sct_hdr_L->PointerToRawData, sct_hdr_L->VirtualAddress)) return 1;
         }
      }
      else if (file_hdr->Machine == 0x8664) {
         if (img_opt_hdr64->DataDirectory[1].VirtualAddress >= sct_hdr_L->VirtualAddress && 
             img_opt_hdr64->DataDirectory[1].VirtualAddress < (sct_hdr_L->VirtualAddress + sct_hdr_L->VirtualSize) ) {
            offset = sct_hdr_L->PointerToRawData + img_opt_hdr64->DataDirectory[1].VirtualAddress - sct_hdr_L->VirtualAddress;
            if (print_import(sct_hdr_L->PointerToRawData, sct_hdr_L->VirtualAddress)) return 1;
         }
      }
      else return 1;
      
      sct_hdr_L++;
   }
   
   return 0;
}

