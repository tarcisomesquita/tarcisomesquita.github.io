
;  $ ./prog_nasm -f bin 1_1_elf_header.asm -o 1_1_elf_header ; chmod +x 1_1_elf_header ; ./1_1_elf_header ; echo $?
;  $ 45

;  $ wc -c 1_1_elf_header
;  91 1_1_elf_header


                            BITS 32

                            org 0x08048000

ehdr:

e_ident_0_3:                db 0x7F, "ELF"  ;
e_ident_4:                  db 0x01         ; 32-bit objects
e_ident_5:                  db 0x01         ; Litle Endian
e_ident_6:                  db 0x01         ; Current version
e_ident_7:                  db 0x00         ; unspecified OS
e_ident_8:          times 8 db 0x00         ; não é usado
e_type:                     dw 0x0002       ; Executable file
e_machine:                  dw 0x0003       ; Intel 80386
e_version:                  dd 0x00000001   ; Current version
e_entry:                    dd _start       ; onde começam as instruções ; 54 80 04 08
e_phoff:                    dd phdr - $$    ; File offset in bytes of Program Header table
e_shoff:                    dd shdr - $$    ; File offset in bytes of Section Header table
e_flags:                    dd 0x00000000   ; The 32-bit Intel Architecture defines no flags
e_ehsize:                   dw 0x0034       ; Tamanho do Elf Header
e_phentsize:                dw 0x0020       ; Tamanho de uma linha da tabela Program Header
e_phnum:                    dw 0x0001       ; Quantas linhas tem a tabela Program Header.
e_shentsize:                dw 0x0028       ; Tamanho de uma linha da tabela Section Header
e_shnum:                    dw 0x0000       ; Quantas linhas tem a tabela Section Header.
e_shstrndx:                 dw 0x0002       ; Qual linha da tabela Section Header contém o offset da Section .shstrtab


phdr:

p_type____1:                dd 0x00000001   ; loadable segment
p_offset__1:                dd _start - $$  ; offset from the beginning of the file at which the first byte of segment reside.
p_vaddr___1:                dd _start       ; virtual adress at which the first byte of segment resides in memory.
p_paddr___1:                dd _start       ; Reserved for segment's physical address
p_filesz__1:                dd loadsize     ; how many bytes to load of the file into memory
p_memsz___1:                dd loadsize     ; how large the memory segment needs to be
p_flags___1:                dd 0x00000005   ; what permissions to give the memory segment (1=executar, 2=escrever, 4=ler)
p_align___1:                dd 0x00001000   ; alignment requirements for the memory segment


shdr: ; Desativado. Está aqui apenas para marcar o lugar da Section Header table.

  
_start:   ; the program start here
  
                            mov bl, 45
                            xor eax, eax
                            inc eax
                            int 0x80

                   loadsize equ $ - _start

