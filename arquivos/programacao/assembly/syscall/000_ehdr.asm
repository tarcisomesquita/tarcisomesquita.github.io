.intel_syntax noprefix

.text

align  = 0x1000
entry  = text_i - ehdr   + 0x400000
text   = text_f - ehdr
data   = data_f - data_i
data_m = data_i - ehdr   + 0x400000

ehdr:
e_ident_0_3:                .byte 0x7F, 'E', 'L', 'F' # 0x0000
e_ident_4:                  .byte 0x02                # 0x0004 64-bit objects
e_ident_5:                  .byte 0x01                # 0x0005 Litle Endian
e_ident_6:                  .byte 0x01                # 0x0006 Current version
e_ident_7:                  .byte 0x03                # 0x0007 OS Linux
e_ident_8_15:                                         # 0x0008 não é usado
                            .rept 8
                            .byte 0x00
                            .endr
e_type:                     .word 0x0002              # 0x0010 Executable file
e_machine:                  .word 0x003E              # 0x0012 x86-64
e_version:                  .long 0x00000001          # 0x0014 Current version
e_entry:                    .quad entry               # 0x0018 Entry point          # 0x0000000000400078
e_phoff:                    .quad phdr - ehdr         # 0x0020 Program Header table # 0x0000000000000040
e_shoff:                    .quad 0x0000000000000000  # 0x0028 Section Header table # 0x0000000000000000
e_flags:                    .long 0x00000000          # 0x0030 no flags
e_ehsize:                   .word 0x0040              # 0x0034 Tamanho do Elf Header
e_phentsize:                .word 0x0038              # 0x0036 Tamanho de uma linha da tabela Program Header
e_phnum:                    .word 0x0002              # 0x0038 Quantas linhas tem a tabela Program Header
e_shentsize:                .word 0x0040              # 0x003A Tamanho de uma linha da tabela Section Header
e_shnum:                    .word 0x0000              # 0x003C Quantas linhas tem a tabela Section Header.
e_shstrndx:                 .word 0x0000              # 0x003E Linha da tabela Section Header com o offset da Section .shstrtab

phdr:
p_type____00:               .long 0x00000001          # 0x0040 Loadable segment
p_flags___00:               .long 0x00000005          # 0x0044 Permissions to segment (1=executar, 2=escrever, 4=ler)
p_offset__00:               .quad 0x0000000000000000  # 0x0048 Segment file offset
p_vaddr___00:               .quad 0x0000000000400000  # 0x004C Segment virtual address
p_paddr___00:               .quad 0x0000000000400000  # 0x0050 Segment physical address
p_filesz__00:               .quad text                # 0x0054 Segment size in file     # 0x000000000000000C
p_memsz___00:               .quad text                # 0x0058 Segment size in memory   # 0x000000000000000C
p_align___00:               .quad align               # 0x005C Segment alignment, file & memory

p_type____01:               .long 0x00000001          # 0x0040 Loadable segment
p_flags___01:               .long 0x00000006          # 0x0044 Permissions to segment (1=executar, 2=escrever, 4=ler)
p_offset__01:               .quad data_i - ehdr       # 0x0048 Segment file offset
p_vaddr___01:               .quad data_m              # 0x004C Segment virtual address
p_paddr___01:               .quad data_m              # 0x0050 Segment physical address
p_filesz__01:               .quad data                # 0x0054 Segment size in file     # 0x000000000000000C
p_memsz___01:               .quad data                # 0x0058 Segment size in memory   # 0x000000000000000C
p_align___01:               .quad align               # 0x005C Segment alignment, file & memory


.align 0x10, 0x00
