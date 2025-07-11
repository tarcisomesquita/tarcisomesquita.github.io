# clear ; rm -f ./hello-elf-static.elf && as --64 -n -o hello-elf-static.o hello-elf-static.s && objcopy -O binary hello-elf-static.o hello-elf-static.elf && chmod +x hello-elf-static.elf && ./hello-elf-static.elf 
# objdump -d -M intel --wide hello-elf-static.elf | tr '\t' ';' | sed '1,7d; s/^\([^;]*\);\([^;]*\);\([^;]*\)$/\3                              \1 \2/; s/^\(.\{1,33\}\) */\1# /; s/ *$//'

.intel_syntax noprefix

.text

entry  = text_i - ehdr + 0x400000
msg    = msg_i  - ehdr + 0x600000
msg_nb = msg_f  - msg_i

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

ehdr:

e_ident_0_3:                .byte 0x7F, 'E', 'L', 'F' # 0x0000 
e_ident_4:                  .byte 0x02                # 0x0004 64-bit objects
e_ident_5:                  .byte 0x01                # 0x0005 Litle Endian
e_ident_6:                  .byte 0x01                # 0x0006 Current version
e_ident_7:                  .byte 0x00                # 0x0007 OS unspecified
e_ident_8_15:       .rept 8 .byte 0x00 ; .endr        # 0x0008 não é usado
e_type:                     .word 0x0002              # 0x0010 Executable file
e_machine:                  .word 0x003E              # 0x0012 x86-64
e_version:                  .long 0x00000001          # 0x0014 Current version
e_entry:                    .quad entry               # 0x0018 Entry point     # 0x00000000004000B0
e_phoff:                    .quad phdr - ehdr         # 0x0020 Program Header table
e_shoff:                    .quad shdr - ehdr         # 0x0028 Section Header table
e_flags:                    .long 0x00000000          # 0x0030 no flags
e_ehsize:                   .word 0x0040              # 0x0034 Tamanho do Elf Header
e_phentsize:                .word 0x0038              # 0x0036 Tamanho de uma linha da tabela Program Header
e_phnum:                    .word 0x0002              # 0x0038 Quantas linhas tem a tabela Program Header
e_shentsize:                .word 0x0040              # 0x003A Tamanho de uma linha da tabela Section Header
e_shnum:                    .word 0x0004              # 0x003C Quantas linhas tem a tabela Section Header.
e_shstrndx:                 .word 0x0003              # 0x003E Linha da tabela Section Header com o offset da Section .shstrtab

phdr:
p_type____00:               .long 0x00000001          # 0x0040 Loadable segment
p_flags___00:               .long 0x00000005          # 0x0044 Permissions to segment (1=executar, 2=escrever, 4=ler)
p_offset__00:               .quad 0x0000000000000000  # 0x0048 Segment file offset
p_vaddr___00:               .quad 0x0000000000400000  # 0x0050 Segment virtual address
p_paddr___00:               .quad 0x0000000000400000  # 0x0058 Segment physical address
p_filesz__00:               .quad text_f - text_i     # 0x0060 Segment size in file
p_memsz___00:               .quad text_f - text_i     # 0x0068 Segment size in memory
p_align___00:               .quad 0x0000000000200000  # 0x0070 Segment alignment, file & memory

p_type____01:               .long 0x00000001          # 0x0078 Loadable segment
p_flags___01:               .long 0x00000006          # 0x007C Permissions to segment (1=executar, 2=escrever, 4=ler)
p_offset__01:               .quad 0x0000000000000000  # 0x0080 Segment file offset
p_vaddr___01:               .quad 0x0000000000600000  # 0x0088 Segment virtual address
p_paddr___01:               .quad 0x0000000000600000  # 0x0090 Segment physical address
p_filesz__01:               .quad data_f - data_i     # 0x0098 Segment size in file
p_memsz___01:               .quad data_f - data_i     # 0x00A0 Segment size in memory
p_align___01:               .quad 0x0000000000200000  # 0x00A8 Segment alignment, file & memory

.align 0x10, 0x00

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

text_i:
mov    rdx, msg_f - msg_i       # quantidade de bytes da string
mov    rsi, msg                 # endereço da string
mov    rdi, 0x0000000000000001  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000001  # syscall write
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000000  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall

text_f:

.align 0x10, 0x00

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

data_i:
msg_i: .ascii "Hello, world!\n" ; msg_f:  # inclui 0x00 no final 
data_f:

.align 0x10, 0x00

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

shstrtab_i:
.string ".shstrtab"

_text:
.string ".text"

_data:
.string ".data"

shstrtab_f:

.align 0x10, 0x00

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

shdr:
sh_name_______00:           .long 0x00000000               # Section name (string tbl index)
sh_type_______00:           .long 0x00000000               # Section type
sh_flags______00:           .quad 0x0000000000000000       # Section flags
sh_addr_______00:           .quad 0x0000000000000000       # Section address
sh_offset_____00:           .quad 0x0000000000000000       # Section file offset
sh_size_______00:           .quad 0x0000000000000000       # Size of section in bytes
sh_link_______00:           .long 0x00000000               # Link to another section
sh_info_______00:           .long 0x00000000               # Additional section information
sh_addralign__00:           .quad 0x0000000000000000       # Section alignment
sh_entsize____00:           .quad 0x0000000000000000       # Entry size if section holds table

sh_name_______01:           .long _text - shstrtab_i       # Section name (string tbl index)
sh_type_______01:           .long 0x00000001               # Section type
sh_flags______01:           .quad 0x0000000000000006       # Section flags
sh_addr_______01:           .quad text_i - ehdr + 0x4000B0 # Section address
sh_offset_____01:           .quad text_i - ehdr            # Section file offset
sh_size_______01:           .quad text_f - text_i          # Size of section in bytes
sh_link_______01:           .long 0x00000000               # Link to another section
sh_info_______01:           .long 0x00000000               # Additional section information
sh_addralign__01:           .quad 0x0000000000000010       # Section alignment
sh_entsize____01:           .quad 0x0000000000000000       # Entry size if section holds table

sh_name_______02:           .long _data - shstrtab_i       # Section name (string tbl index)
sh_type_______02:           .long 0x00000001               # Section type
sh_flags______02:           .quad 0x0000000000000003       # Section flags
sh_addr_______02:           .quad data_i - ehdr + 0x600000 # Section address
sh_offset_____02:           .quad data_i - ehdr            # Section file offset
sh_size_______02:           .quad data_f - data_i          # Size of section in bytes
sh_link_______02:           .long 0x00000000               # Link to another section
sh_info_______02:           .long 0x00000000               # Additional section information
sh_addralign__02:           .quad 0x0000000000000010       # Section alignment
sh_entsize____02:           .quad 0x0000000000000000       # Entry size if section holds table

sh_name_______03:           .long shstrtab_i - shstrtab_i  # Section name (string tbl index)
sh_type_______03:           .long 0x00000003               # Section type
sh_flags______03:           .quad 0x0000000000000000       # Section flags
sh_addr_______03:           .quad 0x0000000000000000       # Section address
sh_offset_____03:           .quad shstrtab_i - ehdr        # Section file offset
sh_size_______03:           .quad shstrtab_f - shstrtab_i  # Size of section in bytes
sh_link_______03:           .long 0x00000000               # Link to another section
sh_info_______03:           .long 0x00000000               # Additional section information
sh_addralign__03:           .quad 0x0000000000000010       # Section alignment
sh_entsize____03:           .quad 0x0000000000000000       # Entry size if section holds table

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

