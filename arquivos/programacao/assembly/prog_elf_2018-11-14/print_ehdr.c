/*
typedef struct elf32_hdr{
  unsigned char e_ident[16];
  unsigned short int e_type;
  unsigned short int e_machine;
  unsigned       int e_version;
  unsigned       int e_entry;     // Entry point
  unsigned       int e_phoff;
  unsigned       int e_shoff;
  unsigned       int e_flags;
  unsigned short int e_ehsize;
  unsigned short int e_phentsize;
  unsigned short int e_phnum;
  unsigned short int e_shentsize;
  unsigned short int e_shnum;
  unsigned short int e_shstrndx;
} Elf32_Ehdr;

typedef struct elf64_hdr {
  unsigned char e_ident[16];     // ELF "magic number"
  unsigned short int e_type;
  unsigned short int e_machine;
  unsigned       int e_version;
  unsigned long  int e_entry;    // Entry point virtual address
  unsigned long  int e_phoff;    // Program header table file offset
  unsigned long  int e_shoff;    // Section header table file offset
  unsigned       int e_flags;
  unsigned short int e_ehsize;
  unsigned short int e_phentsize;
  unsigned short int e_phnum;
  unsigned short int e_shentsize;
  unsigned short int e_shnum;
  unsigned short int e_shstrndx;
} Elf64_Ehdr;
*/

int print_ehdr(struct elf64_hdr *ehdr) {
   printf("ehdr:\n");
   
   if ((ehdr->e_ident[0] == 0x7F) && (ehdr->e_ident[1] == 'E') && (ehdr->e_ident[2] == 'L') && (ehdr->e_ident[3] == 'F') ) {
      printf("e_ident_0_3:                .byte 0x7F, 'E', 'L', 'F' # 0x0000\n");
   }
   else {
      printf("\nERRO: arquivo não possui o formato ELF.\n\n");
      return 1;
   }
   
   if (ehdr->e_ident[4] == 0x01) {
      printf("e_ident_4:                  .byte 0x01                # 0x0004 32-bit objects\n");
   }
   else if (ehdr->e_ident[4] == 0x02) {
      printf("e_ident_4:                  .byte 0x02                # 0x0004 64-bit objects\n");
   }
   else {
      printf("\nERRO: não é 64-bit objects.\n\n");
      return 1;
   }
   
   if (ehdr->e_ident[5] == 0x01) {
      printf("e_ident_5:                  .byte 0x01                # 0x0005 Litle Endian\n");
   }
   else {
      printf("\nERRO: não é Litle Endian.\n\n");
      return 1;
   }
   
   if (ehdr->e_ident[6] == 0x01) {
      printf("e_ident_6:                  .byte 0x01                # 0x0006 Current version\n");
   }
   else {
      printf("\nERRO: não é Current version\n\n");
      return 1;
   }
   
   if (ehdr->e_ident[7] == 0x00) {
      printf("e_ident_7:                  .byte 0x00                # 0x0007 OS unspecified\n");
   }
   else if (ehdr->e_ident[7] == 0x03) {
      printf("e_ident_7:                  .byte 0x03                # 0x0007 OS Linux\n");
   }
   else {
      printf("\nERRO: não é OS Linux ou OS unspecified\n\n");
      return 1;
   }
   
   if ( (ehdr->e_ident[8] == 0x00) &&  (ehdr->e_ident[9] == 0x00) && (ehdr->e_ident[10] == 0x00) && \
       (ehdr->e_ident[11] == 0x00) && (ehdr->e_ident[12] == 0x00) &&  (ehdr->e_ident[13] == 0x00) && \
       (ehdr->e_ident[14] == 0x00) && (ehdr->e_ident[15] == 0x00) ) {
      printf("e_ident_8_15:       .rept 8 .byte 0x00 ; .endr        # 0x0008 não é usado\n");
   }
   else {
      printf("\nERRO: e_ident_8_15 está sendo usado é usado\n\n");
      return 1;
   }
   
   if (ehdr->e_type == 0x0002) {
      printf("e_type:                     .word 0x0002              # 0x0010 Executable file\n");
   }
   else if (ehdr->e_type == 0x0001) {
      printf("e_type:                     .word 0x0001              # 0x0010 Relocatable file\n");
   }
   else {
      printf("\nERRO: não é Executable ou Relocatable file\n\n");
      return 1;
   }
   
   if (ehdr->e_machine == 0x003E) {
      printf("e_machine:                  .word 0x003E              # 0x0012 x86-64\n");
   }
   else {
      printf("\nERRO: e_machine não é x86-64\n\n");
      return 1;
   }
   
   if (ehdr->e_version == 0x00000001) {
      printf("e_version:                  .long 0x00000001          # 0x0014 Current version\n");
   }
   else {
      printf("\nERRO: não é Current version\n\n");
      return 1;
   }
   
   printf("e_entry:                    .quad text                # 0x0018 Entry point          # 0x%016lX\n", (unsigned long int)ehdr->e_entry);
   
   printf("e_phoff:                    .quad phdr - ehdr         # 0x0020 Program Header table # 0x%016lX\n", (unsigned long int)ehdr->e_phoff);
   
   printf("e_shoff:                    .quad 0x0000000000000000  # 0x0028 Section Header table # 0x%016lX\n", (unsigned long int)ehdr->e_shoff);
   
   if (ehdr->e_flags == 0x00000000) {
      printf("e_flags:                    .long 0x00000000          # 0x0030 no flags\n");
   }
   else {
      printf("\nERRO: não deve ter flags\n\n");
      return 1;
   }
   
   if (ehdr->e_ehsize == 0x0040) {
      printf("e_ehsize:                   .word 0x0040              # 0x0034 Tamanho do Elf Header\n");
   }
   else {
      printf("\nERRO: e_ehsize != 0x0040\n\n");
      return 1;
   }
   
   if (ehdr->e_phentsize == 0x0038) {
      printf("e_phentsize:                .word 0x0038              # 0x0036 Tamanho de uma linha da tabela Program Header\n");
   }
   else {
      printf("\nERRO: e_phentsize != 0x0038\n\n");
      return 1;
   }
   
   printf("e_phnum:                    .word 0x%04X              # 0x0038 Quantas linhas tem a tabela Program Header\n", ehdr->e_phnum);
   
   if (ehdr->e_shentsize == 0x0040) {
      printf("e_shentsize:                .word 0x0040              # 0x003A Tamanho de uma linha da tabela Section Header\n");
   }
   else {
      printf("\nERRO: ehdr->e_shentsize != 0x0040\n\n");
      return 1;
   }
   
   printf("e_shnum:                    .word 0x%04X              # 0x003C Quantas linhas tem a tabela Section Header.\n", ehdr->e_shnum);
   
   printf("e_shstrndx:                 .word 0x%04X              # 0x003E Linha da tabela Section Header com o offset da Section .shstrtab\n", ehdr->e_shstrndx);
   
   printf("\n");
   
   return 0;
}

