int print_HEADER_NT() {
   struct tm *agora;
   
   offset = dos_hdr->e_lfanew;
   
   nt_hdr = (unsigned char *)(buffer + offset);
   
   printf("nt_header:\n");
   printf("Signature:                   .byte \'%c\', \'%c\', 0x%02X, 0x%02X     # 0x%04X  \n\n", 
          nt_hdr[0], nt_hdr[1], nt_hdr[2], nt_hdr[3], offset);
   offset += 4;
   
   file_hdr = (struct _IMAGE_FILE_HEADER *)(buffer + offset);
   
   printf("file_header:\n");
   printf("Machine:                     .word ");
   if      (file_hdr->Machine == 0x014C) printf("0x014C         # 0x%04X IMAGE_FILE_MACHINE_I386\n", offset);
   else if (file_hdr->Machine == 0x8664) printf("0x8664         # 0x%04X IMAGE_FILE_MACHINE_AMD64\n", offset);
   else { printf("0x%04X         # 0x%04X Veja isso em winnt.h\n", (unsigned int)file_hdr->Machine, offset); return 1; }
   offset += 2;
   
   printf("NumberOfSections:            .word 0x%04X         # 0x%04X número de seções contidas no aplicativo (entradas em SECTION_HEADER)\n", 
          (unsigned int)file_hdr->NumberOfSections, offset);
   offset += 2;
   printf("TimeDateStamp:               .long 0x%08X     # 0x%04X ", (unsigned int)file_hdr->TimeDateStamp, offset);
   agora = localtime((long int *)&file_hdr->TimeDateStamp);
   printf("linked in %d/%d/%d %d:%d:%d %ld\n", agora[0].tm_mday, agora[0].tm_mon  + 1, agora[0].tm_year + 1900, \
                                               agora[0].tm_hour, agora[0].tm_min, agora[0].tm_sec, agora[0].tm_gmtoff);
   offset += 4;
   printf("PointerToSymbolTable:        .long 0x%08X     # 0x%04X \n", (unsigned int)file_hdr->PointerToSymbolTable, offset);
   offset += 4;
   printf("NumberOfSymbols:             .long 0x%08X     # 0x%04X \n", (unsigned int)file_hdr->NumberOfSymbols, offset);
   offset += 4;
   printf("SizeOfOptionalHeader:        .word 0x%04X         # 0x%04X ", (unsigned int)file_hdr->SizeOfOptionalHeader, offset);
   if (file_hdr->Machine == 0x014C) printf("0x00E0 = 224 bytes the size of the optional header\n");
   else if (file_hdr->Machine == 0x8664) printf("0x00F0 = 240 bytes the size of the optional header\n");
   else return 1;
   offset += 2;
   
   printf("Characteristics:             .word 0x%04X         # 0x%04X indica se o arquivo é um EXE, DLL ou OCX.\n", 
          (unsigned int)file_hdr->Characteristics, offset);
   offset += 2;
   if(file_hdr->Characteristics & 0x0001) printf("                                                           # 0x0001 IMAGE_FILE_RELOCS_STRIPPED\n");
   if(file_hdr->Characteristics & 0x0002) printf("                                                           # 0x0002 IMAGE_FILE_EXECUTABLE_IMAGE\n");
   if(file_hdr->Characteristics & 0x0004) printf("                                                           # "
      "0x0004 IMAGE_FILE_LINE_NUMS_STRIPPED\n");
   if(file_hdr->Characteristics & 0x0008) printf("                                                           # "
      "0x0008 IMAGE_FILE_LOCAL_SYMS_STRIPPED\n");
   if(file_hdr->Characteristics & 0x0010) printf("                                                           # 0x0010 IMAGE_FILE_AGGRESIVE_WS_TRIM\n");
   if(file_hdr->Characteristics & 0x0020) printf("                                                           # 0x0020 "
      "Application can handle > 2GB addresses.\n");
   if(file_hdr->Characteristics & 0x0080) printf("                                                           # 0x0080 Little endian\n");
   if(file_hdr->Characteristics & 0x0100) printf("                                                           # 0x0100 IMAGE_FILE_32BIT_MACHINE\n");
   if(file_hdr->Characteristics & 0x0200) printf("                                                           # 0x0200 IMAGE_FILE_DEBUG_STRIPPED\n");
   if(file_hdr->Characteristics & 0x0400) printf("                                                           # "
      "0x0400 IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP\n");
   if(file_hdr->Characteristics & 0x0800) printf("                                                           # "
      "0x0800 IMAGE_FILE_NET_RUN_FROM_SWAP\n");
   if(file_hdr->Characteristics & 0x1000) printf("                                                           # 0x1000 IMAGE_FILE_SYSTEM\n");
   if(file_hdr->Characteristics & 0x2000) printf("                                                           # 0x2000 IMAGE_FILE_DLL\n");
   if(file_hdr->Characteristics & 0x4000) printf("                                                           # 0x4000 IMAGE_FILE_UP_SYSTEM_ONLY\n");
   if(file_hdr->Characteristics & 0x8000) printf("                                                           # 0x8000 Big endian\n");
   
   printf("\n");
   
   if (file_hdr->Machine == 0x014C) {
      img_opt_hdr = (struct _IMAGE_OPTIONAL_HEADER *)(buffer + offset);
      printf("optional_header32:\n");
      printf("Magic:                       .word 0x%04X         # 0x%04X ", (unsigned int)img_opt_hdr->Magic, offset);
      if (img_opt_hdr->Magic == 0x010B) printf("0x010B=PE32\n");
      else return 1;
      
      offset += 2;
      printf("MajorLinkerVersion:          .byte 0x%02X           # 0x%04X The linker major version number.\n", 
             img_opt_hdr->MajorLinkerVersion, offset);
      offset += 1;
      printf("MinorLinkerVersion:          .byte 0x%02X           # 0x%04X The linker minor version number.\n", 
             img_opt_hdr->MinorLinkerVersion, offset);
      offset += 1;
      printf("SizeOfCode:                  .long 0x%08X     # 0x%04X size of the code (text) section, or the sum of all code sections\n", 
             (unsigned int)img_opt_hdr->SizeOfCode, offset);
      offset += 4;
      printf("SizeOfInitializedData:       .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->SizeOfInitializedData, offset);
      offset += 4;
      printf("SizeOfUninitializedData:     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->SizeOfUninitializedData, offset);
      offset += 4;
      printf("AddressOfEntryPoint:         .long 0x%08X     # 0x%04X "
             "endereço RVA (Relative Virtual Address) da primeira instrução a ser executada\n", 
             (unsigned int)img_opt_hdr->AddressOfEntryPoint, offset);
      offset += 4;
      printf("BaseOfCode:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->BaseOfCode, offset);
      offset += 4;
      printf("BaseOfData:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->BaseOfData, offset);
      offset += 4;
      printf("\n");
      
      printf("ImageBase:                   .long 0x%08X     # 0x%04X "
             "posição no espaço relativo da memória que o Windows carregará o aplicativo.\n", (unsigned int)img_opt_hdr->ImageBase, offset);
      offset += 4;
      printf("SectionAlignment:            .long 0x%08X     # 0x%04X alinhamento de cada uma das seções (4kB)\n", 
             (unsigned int)img_opt_hdr->SectionAlignment, offset);
      offset += 4;
      printf("FileAlignment:               .long 0x%08X     # 0x%04X alinhamento das seções no arquivo em disco (512 B)\n", 
             (unsigned int)img_opt_hdr->FileAlignment, offset);
      offset += 4;
      printf("MajorOperatingSystemVersion: .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr->MajorOperatingSystemVersion, offset);
      offset += 2;
      printf("MinorOperatingSystemVersion: .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr->MinorOperatingSystemVersion, offset);
      offset += 2;
      printf("MajorImageVersion:           .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr->MajorImageVersion, offset);
      offset += 2;
      printf("MinorImageVersion:           .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr->MinorImageVersion, offset);
      offset += 2;
      printf("MajorSubsystemVersion:       .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr->MajorSubsystemVersion, offset);
      offset += 2;
      printf("MinorSubsystemVersion:       .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr->MinorSubsystemVersion, offset);
      offset += 2;
      printf("Win32VersionValue:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->Win32VersionValue, offset);
      offset += 4;
      printf("SizeOfImage:                 .long 0x%08X     # 0x%04X "
             "Tamanho carregado na memória. Incluindo todos os cabeçalhos.\n", 
              (unsigned int)img_opt_hdr->SizeOfImage, offset);
      offset += 4;
      printf("SizeOfHeaders:               .long 0x%08X     # 0x%04X Sum of size of the DOS Header, PE Header and Object Table\n", 
             (unsigned int)img_opt_hdr->SizeOfHeaders, offset);
      offset += 4;
      printf("CheckSum:                    .long 0x%08X     # 0x%04X only for trusted services\n", (unsigned int)img_opt_hdr->CheckSum, offset);
      offset += 4;
      if      (img_opt_hdr->Subsystem == 1) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "Device drivers and native Windows processes\n", (unsigned int)img_opt_hdr->Subsystem, offset);
      else if (img_opt_hdr->Subsystem == 2) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "The Windows graphical user interface (GUI) subsystem\n", (unsigned int)img_opt_hdr->Subsystem, offset);
      else if (img_opt_hdr->Subsystem == 3) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "The Windows character subsystem (a console app)\n", (unsigned int)img_opt_hdr->Subsystem, offset);
      else if (img_opt_hdr->Subsystem == 7) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "The Posix character subsystem\n", (unsigned int)img_opt_hdr->Subsystem, offset);
      else if (img_opt_hdr->Subsystem == 10) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "EFI\n", (unsigned int)img_opt_hdr->Subsystem, offset);
      else {
         printf("Subsystem:                   .word 0x%04X         # 0x%04X Veja isso. Twinnt.h\n", (unsigned int)img_opt_hdr->Subsystem, offset);
         return 1;
      }
      offset += 2;
      printf("DllCharacteristics:          .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr->DllCharacteristics, offset);
      offset += 2;
      if (img_opt_hdr->DllCharacteristics == 0x0040) printf("                                               #        "
          "0x0040 DLL can be relocated at load time.\n");
      if (img_opt_hdr->DllCharacteristics == 0x0080) printf("                                               #        "
          "0x0080 Code Integrity checks are enforced.\n");
      if (img_opt_hdr->DllCharacteristics == 0x0200) printf("                                               #        "
          "0x0200 Isolation aware, but do not isolate the image.\n");
      if (img_opt_hdr->DllCharacteristics == 0x0400) printf("                                               #        "
          "0x0400 Does not use structured exception (SE) handling.\n");
      if (img_opt_hdr->DllCharacteristics == 0x0800) printf("                                               #        "
          "0x0800 Do not bind the image.\n");
      if (img_opt_hdr->DllCharacteristics == 0x2000) printf("                                               #        "
          "0x2000 A WDM driver.\n");
      printf("SizeOfStackReserve:          .long 0x%08X     # 0x%04X "
             "defaults to 0x100000 (1MB). Tamanho máximo que a pilha poderá ter.\n", (unsigned int)img_opt_hdr->SizeOfStackReserve, offset);
      offset += 4;
      printf("SizeOfStackCommit:           .long 0x%08X     # 0x%04X defaults to 0x1000 bytes (1 page)\n",
             (unsigned int)img_opt_hdr->SizeOfStackCommit, offset);
      offset += 4;
      printf("SizeOfHeapReserve:           .long 0x%08X     # 0x%04X "
             "Parece que isso aqui é para as outras thread criados por este processo.\n", 
             (unsigned int)img_opt_hdr->SizeOfHeapReserve, offset);
      offset += 4;
      printf("SizeOfHeapCommit:            .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->SizeOfHeapCommit, offset);
      offset += 4;
      printf("LoaderFlags:                 .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->LoaderFlags, offset);
      offset += 4;
      printf("NumberOfRvaAndSizes:         .long 0x%08X     # 0x%04X especifica o número de diretório de dados\n", 
             (unsigned int)img_opt_hdr->NumberOfRvaAndSizes, offset);
      offset += 4;
      if (img_opt_hdr->NumberOfRvaAndSizes != 0x00000010) {
         printf("NumberOfRvaAndSizes deveria ser 0x00000010\n");
         return 1;
      }
      
      printf("\n");
      
      printf("DATA_DIRECTORY:\n");
      
      printf("ExportVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[0].VirtualAddress, offset);
      offset += 4;
      printf("ExportSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[0].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ImportVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[1].VirtualAddress, offset);
      offset += 4;
      printf("ImportSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[1].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ResourceVirtualAddress:      .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[2].VirtualAddress, offset);
      offset += 4;
      printf("ResourceSize:                .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[2].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ExceptionVirtualAddress:     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[3].VirtualAddress, offset);
      offset += 4;
      printf("ExceptionSize:               .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[3].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("CertificateVirtualAddress:   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[4].VirtualAddress, offset);
      offset += 4;
      printf("CertificateSize:             .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[4].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("RelocationVirtualAddress:    .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[5].VirtualAddress, offset);
      offset += 4;
      printf("RelocationSize:              .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[5].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("DebugVirtualAddress:         .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[6].VirtualAddress, offset);
      offset += 4;
      printf("DebugSize:                   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[6].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ArchitectureVirtualAddress:  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[7].VirtualAddress, offset);
      offset += 4;
      printf("ArchitectureSize:            .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[7].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("GlobalVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[8].VirtualAddress, offset);
      offset += 4;
      printf("GlobalSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[8].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("TLSVirtualAddress:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[9].VirtualAddress, offset);
      offset += 4;
      printf("TLSSize:                     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[9].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ConfigVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[10].VirtualAddress, offset);
      offset += 4;
      printf("ConfigSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[10].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("BoundVirtualAddress:         .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[11].VirtualAddress, offset);
      offset += 4;
      printf("BoundSize:                   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[11].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("IATVirtualAddress:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[12].VirtualAddress, offset);
      offset += 4;
      printf("IATSize:                     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[12].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("DelayVirtualAddress:         .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[13].VirtualAddress, offset);
      offset += 4;
      printf("DelaySize:                   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[13].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("CLRVirtualAddress:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[14].VirtualAddress, offset);
      offset += 4;
      printf("CLRSize:                     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[14].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ReservedVirtualAddress:      .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[15].VirtualAddress, offset);
      offset += 4;
      printf("ReservedSize:                .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr->DataDirectory[15].Size, offset);
      offset += 4;

   }
   else if (file_hdr->Machine == 0x8664) {
      img_opt_hdr64 = (struct _IMAGE_OPTIONAL_HEADER64 *)(buffer + offset);
      printf("optional_header64:\n");
      printf("Magic:                       .word 0x%04X         # 0x%04X ", (unsigned int)img_opt_hdr64->Magic, offset);
      if (img_opt_hdr64->Magic == 0x020B) printf("0x020B=PE64\n");
      else return 1;
      
      offset += 2;
      printf("MajorLinkerVersion:          .byte 0x%02X           # 0x%04X The linker major version number.\n", 
             img_opt_hdr64->MajorLinkerVersion, offset);
      offset += 1;
      printf("MinorLinkerVersion:          .byte 0x%02X           # 0x%04X The linker minor version number.\n", 
             img_opt_hdr64->MinorLinkerVersion, offset);
      offset += 1;
      printf("SizeOfCode:                  .long 0x%08X     # 0x%04X size of the code (text) section, or the sum of all code sections\n", 
             (unsigned int)img_opt_hdr64->SizeOfCode, offset);
      offset += 4;
      printf("SizeOfInitializedData:       .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->SizeOfInitializedData, offset);
      offset += 4;
      printf("SizeOfUninitializedData:     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->SizeOfUninitializedData, offset);
      offset += 4;
      printf("AddressOfEntryPoint:         .long 0x%08X     # 0x%04X "
             "endereço RVA (Relative Virtual Address) da primeira instrução a ser executada\n", 
             (unsigned int)img_opt_hdr64->AddressOfEntryPoint, offset);
      offset += 4;
      printf("BaseOfCode:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->BaseOfCode, offset);
      offset += 4;
      printf("\n");
      
      printf("ImageBase:                   .quad 0x%016X     # 0x%04X "
             "posição no espaço relativo da memória que o Windows carregará o aplicativo.\n", 
             (unsigned int)img_opt_hdr64->ImageBase, offset);
      offset += 8;
      printf("SectionAlignment:            .long 0x%08X     # 0x%04X alinhamento de cada uma das seções (4kB)\n", 
             (unsigned int)img_opt_hdr64->SectionAlignment, offset);
      offset += 4;
      printf("FileAlignment:               .long 0x%08X     # 0x%04X alinhamento das seções no arquivo em disco (512 B)\n", 
             (unsigned int)img_opt_hdr64->FileAlignment, offset);
      offset += 4;
      printf("MajorOperatingSystemVersion: .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr64->MajorOperatingSystemVersion, offset);
      offset += 2;
      printf("MinorOperatingSystemVersion: .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr64->MinorOperatingSystemVersion, offset);
      offset += 2;
      printf("MajorImageVersion:           .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr64->MajorImageVersion, offset);
      offset += 2;
      printf("MinorImageVersion:           .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr64->MinorImageVersion, offset);
      offset += 2;
      printf("MajorSubsystemVersion:       .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr64->MajorSubsystemVersion, offset);
      offset += 2;
      printf("MinorSubsystemVersion:       .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr64->MinorSubsystemVersion, offset);
      offset += 2;
      printf("Win32VersionValue:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->Win32VersionValue, offset);
      offset += 4;
      printf("SizeOfImage:                 .long 0x%08X     # 0x%04X "
             "Tamanho carregado na memória. Incluindo todos os cabeçalhos.\n", 
              (unsigned int)img_opt_hdr64->SizeOfImage, offset);
      offset += 4;
      printf("SizeOfHeaders:               .long 0x%08X     # 0x%04X Sum of size of the DOS Header, PE Header and Object Table\n", 
             (unsigned int)img_opt_hdr64->SizeOfHeaders, offset);
      offset += 4;
      printf("CheckSum:                    .long 0x%08X     # 0x%04X only for trusted services\n", (unsigned int)img_opt_hdr64->CheckSum, offset);
      offset += 4;
      if      (img_opt_hdr64->Subsystem == 1) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "Device drivers and native Windows processes\n", (unsigned int)img_opt_hdr64->Subsystem, offset);
      else if (img_opt_hdr64->Subsystem == 2) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "The Windows graphical user interface (GUI) subsystem\n", (unsigned int)img_opt_hdr64->Subsystem, offset);
      else if (img_opt_hdr64->Subsystem == 3) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "The Windows character subsystem (a consele app)\n", (unsigned int)img_opt_hdr64->Subsystem, offset);
      else if (img_opt_hdr64->Subsystem == 7) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "The Posix character subsystem\n", (unsigned int)img_opt_hdr64->Subsystem, offset);
      else if (img_opt_hdr64->Subsystem == 10) printf("Subsystem:                   .word 0x%04X         # 0x%04X "
               "EFI\n", (unsigned int)img_opt_hdr64->Subsystem, offset);
      else {
         printf("Subsystem:                   .word 0x%04X         # 0x%04X Veja isso. winnt.h\n", (unsigned int)img_opt_hdr64->Subsystem, offset);
         return 1;
      }
      offset += 2;
      printf("DllCharacteristics:          .word 0x%04X         # 0x%04X \n", (unsigned int)img_opt_hdr64->DllCharacteristics, offset);
      offset += 2;
      if (img_opt_hdr64->DllCharacteristics == 0x0040) printf("                                               #        "
          "0x0040 DLL can be relocated at load time.\n");
      if (img_opt_hdr64->DllCharacteristics == 0x0080) printf("                                               #        "
          "0x0080 Code Integrity checks are enforced.\n");
      if (img_opt_hdr64->DllCharacteristics == 0x0200) printf("                                               #        "
          "0x0200 Isolation aware, but do not isolate the image.\n");
      if (img_opt_hdr64->DllCharacteristics == 0x0400) printf("                                               #        "
          "0x0400 Does not use structured exception (SE) handling.\n");
      if (img_opt_hdr64->DllCharacteristics == 0x0800) printf("                                               #        "
          "0x0800 Do not bind the image.\n");
      if (img_opt_hdr64->DllCharacteristics == 0x2000) printf("                                               #        "
          "0x2000 A WDM driver.\n");
      printf("SizeOfStackReserve:          .quad 0x%016X     # 0x%04X "
             "defaults to 0x100000 (1MB). Tamanho máximo que a pilha poderá ter.\n", (unsigned int)img_opt_hdr64->SizeOfStackReserve, offset);
      offset += 8;
      printf("SizeOfStackCommit:           .quad 0x%016X     # 0x%04X defaults to 0x1000 bytes (1 page)\n",
             (unsigned int)img_opt_hdr64->SizeOfStackCommit, offset);
      offset += 8;
      printf("SizeOfHeapReserve:           .quad 0x%016X     # 0x%04X "
             "Parece que isso aqui é para as outras thread criados por este processo.\n", 
             (unsigned int)img_opt_hdr64->SizeOfHeapReserve, offset);
      offset += 8;
      printf("SizeOfHeapCommit:            .quad 0x%016X     # 0x%04X \n", (unsigned int)img_opt_hdr64->SizeOfHeapCommit, offset);
      offset += 8;
      printf("LoaderFlags:                 .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->LoaderFlags, offset);
      offset += 4;
      printf("NumberOfRvaAndSizes:         .long 0x%08X     # 0x%04X especifica o número de diretório de dados\n", 
             (unsigned int)img_opt_hdr64->NumberOfRvaAndSizes, offset);
      offset += 4;
      if (img_opt_hdr64->NumberOfRvaAndSizes != 0x00000010) {
         printf("NumberOfRvaAndSizes deveria ser 0x00000010\n");
         return 1;
      }
      
      printf("\n");
      
      printf("DATA_DIRECTORY:\n");
      
      printf("ExportVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[0].VirtualAddress, offset);
      offset += 4;
      printf("ExportSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[0].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ImportVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[1].VirtualAddress, offset);
      offset += 4;
      printf("ImportSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[1].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ResourceVirtualAddress:      .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[2].VirtualAddress, offset);
      offset += 4;
      printf("ResourceSize:                .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[2].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ExceptionVirtualAddress:     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[3].VirtualAddress, offset);
      offset += 4;
      printf("ExceptionSize:               .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[3].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("CertificateVirtualAddress:   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[4].VirtualAddress, offset);
      offset += 4;
      printf("CertificateSize:             .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[4].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("RelocationVirtualAddress:    .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[5].VirtualAddress, offset);
      offset += 4;
      printf("RelocationSize:              .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[5].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("DebugVirtualAddress:         .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[6].VirtualAddress, offset);
      offset += 4;
      printf("DebugSize:                   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[6].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ArchitectureVirtualAddress:  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[7].VirtualAddress, offset);
      offset += 4;
      printf("ArchitectureSize:            .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[7].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("GlobalVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[8].VirtualAddress, offset);
      offset += 4;
      printf("GlobalSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[8].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("TLSVirtualAddress:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[9].VirtualAddress, offset);
      offset += 4;
      printf("TLSSize:                     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[9].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ConfigVirtualAddress:        .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[10].VirtualAddress, offset);
      offset += 4;
      printf("ConfigSize:                  .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[10].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("BoundVirtualAddress:         .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[11].VirtualAddress, offset);
      offset += 4;
      printf("BoundSize:                   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[11].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("IATVirtualAddress:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[12].VirtualAddress, offset);
      offset += 4;
      printf("IATSize:                     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[12].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("DelayVirtualAddress:         .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[13].VirtualAddress, offset);
      offset += 4;
      printf("DelaySize:                   .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[13].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("CLRVirtualAddress:           .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[14].VirtualAddress, offset);
      offset += 4;
      printf("CLRSize:                     .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[14].Size, offset);
      offset += 4;
      printf("\n");
      
      printf("ReservedVirtualAddress:      .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[15].VirtualAddress, offset);
      offset += 4;
      printf("ReservedSize:                .long 0x%08X     # 0x%04X \n", (unsigned int)img_opt_hdr64->DataDirectory[15].Size, offset);
      offset += 4;

   }
   else return 1;
   
   printf("\n");
   
   printf("\n");
   
   return 0;
}

