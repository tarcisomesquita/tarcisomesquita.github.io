/*
struct Elf32_Shdr
{
   unsigned long int sh_name;		// Section name (string tbl index) 
   unsigned long int sh_type;		// Section type 
   unsigned long int sh_flags;		// Section flags 
   unsigned long int sh_addr;		// Section virtual addr at execution 
   unsigned long int sh_offset;		// Section file offset 
   unsigned long int sh_size;		// Section size in bytes 
   unsigned long int sh_link;		// Link to another section 
   unsigned long int sh_info;		// Additional section information 
   unsigned long int sh_addralign;	// Section alignment 
   unsigned long int sh_entsize;	// Entry size if section holds table 
} *shdr = 0x00000000;

typedef struct elf64_shdr {
  unsigned       int sh_name;       // Section name, index in string tbl
  unsigned       int sh_type;       // Type of section
  unsigned long  int sh_flags;      // Miscellaneous section attributes
  unsigned long  int sh_addr;       // Section virtual addr at execution
  unsigned long  int sh_offset;     // Section file offset
  unsigned long  int sh_size;       // Size of section in bytes
  unsigned       int sh_link;       // Index of another section
  unsigned       int sh_info;       // Additional section information
  unsigned long  int sh_addralign;  // Section alignment
  unsigned long  int sh_entsize;    // Entry size if section holds table
} Elf64_Shdr;

*/

/*
void le_shstrtab(FILE *fp, FILE *fp_out)
{
   if( fseek(fp,shdr[ehdr->e_shstrndx].sh_offset, SEEK_SET) )
   {
      fprintf(fp_out, "le_shstrtab: Erro em fseek. %s\n\n", strerror(errno));
      return;
   }
   
   
   shstrtab = malloc(shdr[ehdr->e_shstrndx].sh_size);
   fread((void *)shstrtab, shdr[ehdr->e_shstrndx].sh_size, 1, fp);
   
   return;
}
*/
int print_shdr(int i, unsigned int off_local, struct elf64_shdr *shdr) {
   
   printf("sh_name_______%02hu:           .long 0x%08X          # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_name, (unsigned int)off_local, \
                      "Section name (string tbl index)");
   off_local = off_local + 4;
   
   printf("sh_type_______%02hu:           .long 0x%08X          # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_type, (unsigned int)off_local, \
                      "Section type");
   off_local = off_local + 4;
   
   printf("sh_flags______%02hu:           .quad 0x%016X  # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_flags, (unsigned int)off_local, \
                      "Section flags");
   off_local = off_local + 8;
   
   printf("sh_addr_______%02hu:           .quad 0x%016X  # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_addr, (unsigned int)off_local, \
                      "Section address");
   off_local = off_local + 8;
   
   printf("sh_offset_____%02hu:           .quad 0x%016X  # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_offset, (unsigned int)off_local, \
                      "Section file offset");
   off_local = off_local + 8;
   
   printf("sh_size_______%02hu:           .quad 0x%016X  # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_size, (unsigned int)off_local, \
                      "Size of section in bytes");
   off_local = off_local + 8;
   
   printf("sh_link_______%02hu:           .long 0x%08X          # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_link, (unsigned int)off_local, \
                      "Link to another section");
   off_local = off_local + 4;
   
   printf("sh_info_______%02hu:           .long 0x%08X          # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_info, (unsigned int)off_local, \
                      "Additional section information");
   off_local = off_local + 4;
   
   printf("sh_addralign__%02hu:           .quad 0x%016X  # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_addralign, (unsigned int)off_local, \
                      "Section alignment");
   off_local = off_local + 8;
   
   printf("sh_entsize____%02hu:           .quad 0x%016X  # 0x%08X: %s\n", \
                      i, (unsigned int)shdr->sh_entsize, (unsigned int)off_local, \
                      "Entry size if section holds table");
   off_local = off_local + 8;
   
   printf("\n");
   return 0;
}

