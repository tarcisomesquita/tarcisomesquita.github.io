O_NT_HEADER = nt_header - dos_header

dos_header:
e_magic:                     .ascii "MZ"          # 0x0000 Magic number
e_cblp:                      .word 0x0000         # 0x0002 Bytes on last page of file
e_cp:                        .word 0x0000         # 0x0004 Pages in file (1kiB ?)
e_crlc:                      .word 0x0000         # 0x0006 Relocations
e_cparhdr:                   .word 0x0000         # 0x0008 Size of header in paragraphs (16 bytes)
e_minalloc:                  .word 0x0000         # 0x000A Minimum extra paragraphs needed
e_maxalloc:                  .word 0x0000         # 0x000C Maximum extra paragraphs needed
e_ss:                        .word 0x0000         # 0x000E Initial (relative) SS value
e_sp:                        .word 0x0000         # 0x0010 Initial SP value
e_csum:                      .word 0x0000         # 0x0012 Checksum
e_ip:                        .word 0x0000         # 0x0014 Initial IP value
e_cs:                        .word 0x0000         # 0x0016 Initial (relative) CS value
e_lfarlc:                    .word 0x0000         # 0x0018 File address of relocation table
e_ovno:                      .word 0x0000         # 0x001A Overlay number
e_res:              .rept  4 .word 0x0000 ; .endr # 0x001C Reserved words
e_oemid:                     .word 0x0000         # 0x0024 OEM identifier (for e_oeminfo)
e_oeminfo:                   .word 0x0000         # 0x0026 OEM information; e_oemid specific
e_res2:             .rept 10 .word 0x0000 ; .endr # 0x0028 Reserved words
e_lfanew:                    .long O_NT_HEADER    # 0x003C File address of

.align 0x10, 0x00

