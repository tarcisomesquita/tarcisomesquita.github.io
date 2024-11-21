/*
typedef struct elf64_phdr {
  unsigned       int p_type;
  unsigned       int p_flags;
  unsigned long  int p_offset; // Segment file offset
  unsigned long  int p_vaddr;  // Segment virtual address
  unsigned long  int p_paddr;  // Segment physical address
  unsigned long  int p_filesz; // Segment size in file
  unsigned long  int p_memsz;  // Segment size in memory
  unsigned long  int p_align;  // Segment alignment, file & memory
} Elf64_Phdr;

// sh_type
#define SHT_NULL 0
#define SHT_PROGBITS 1
#define SHT_SYMTAB 2
#define SHT_STRTAB 3
#define SHT_RELA 4
#define SHT_HASH 5
#define SHT_DYNAMIC 6
#define SHT_NOTE 7
#define SHT_NOBITS 8
#define SHT_REL 9
#define SHT_SHLIB 10
#define SHT_DYNSYM 11
#define SHT_NUM 12
#define SHT_LOPROC 0x70000000
#define SHT_HIPROC 0x7fffffff
#define SHT_LOUSER 0x80000000
#define SHT_HIUSER 0xffffffff

// sh_flags
#define SHF_WRITE 0x1
#define SHF_ALLOC 0x2
#define SHF_EXECINSTR 0x4
#define SHF_MASKPROC 0xf0000000

*/

int print_phdr(int i, unsigned int off_local, struct elf64_phdr *phdr) {
   if(phdr->p_type == 0x00000001) {
      printf("p_type____%02hu:               .long 0x%08X          # 0x%04X %s\n", i, phdr->p_type, off_local, "Loadable segment");
   }
   else if(phdr->p_type == 0x70000001) {
      printf("p_type____%02hu:               .long 0x%08X          # 0x%04X %s\n", i, phdr->p_type, off_local, \
                      "describes the location of a program’s unwind tables");
   }
   else {
     printf("p_type____%02hu:               .long 0x%08X          # 0x%04X %s\n", i, phdr->p_type, off_local, \
                      " NOT loadable segment");
   }
   off_local = off_local + 4;

   printf("p_flags___%02hu:               .long 0x%08X          # 0x%04X%s\n", i, phdr->p_flags, off_local, \
                      " Permissions to segment (1=executar, 2=escrever, 4=ler)");
   off_local = off_local + 4;
   
   printf("p_offset__%02hu:               .quad 0x%016lX  # 0x%04X%s\n", i, (unsigned long int)phdr->p_offset, off_local, \
                      " Segment file offset");
   off_local = off_local + 8;
   
   printf("p_vaddr___%02hu:               .quad 0x%016lX  # 0x%04X%s\n", i, (unsigned long int)phdr->p_vaddr, off_local, \
                      " Segment virtual address");
   off_local = off_local + 8;
   
   printf("p_paddr___%02hu:               .quad 0x%016lX  # 0x%04X%s\n", i, (unsigned long int)phdr->p_paddr, off_local, \
                      " Segment physical address");
   off_local = off_local + 8;
   
   printf("p_filesz__%02hu:               .quad loadsize            # 0x%04X%s     # 0x%016lX\n", i, off_local, \
                      " Segment size in file", (unsigned long int)phdr->p_filesz);
   off_local = off_local + 8;
   
   printf("p_memsz___%02hu:               .quad loadsize            # 0x%04X%s   # 0x%016lX\n", i, off_local, \
                      " Segment size in memory", (unsigned long int)phdr->p_memsz);
   off_local = off_local + 8;
   
   printf("p_align___%02hu:               .quad 0x%016lX  # 0x%04X%s\n", i, (unsigned long int)phdr->p_align, off_local, \
                      " Segment alignment, file & memory");
   off_local = off_local + 8;
   
   printf("\n");
   
   return 0;
}

