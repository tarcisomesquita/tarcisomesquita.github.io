DOS_HEADER:          ; o únicos valores úteis aqui são e_magic e e_lfanew
e_magic:                    dw "MZ"         ; 0x0000 Magic number
e_cblp:                     dw 0x0000       ; 0x0002 Bytes on last page of file
e_cp:                       dw 0x0000       ; 0x0004 Pages in file (1kiB ?)
e_crlc:                     dw 0x0000       ; 0x0006 Relocations
e_cparhdr:                  dw 0x0000       ; 0x0008 Size of header in paragraphs (16 bytes)
e_minalloc:                 dw 0x0000       ; 0x000A Minimum extra paragraphs needed
e_maxalloc:                 dw 0x0000       ; 0x000C Maximum extra paragraphs needed
e_ss:                       dw 0x0000       ; 0x000E Initial (relative) SS value
e_sp:                       dw 0x0000       ; 0x0010 Initial SP value
e_csum:                     dw 0x0000       ; 0x0012 Checksum
e_ip:                       dw 0x0000       ; 0x0014 Initial IP value
e_cs:                       dw 0x0000       ; 0x0016 Initial (relative) CS value
e_lfarlc:                   dw 0x0000       ; 0x0018 File address of relocation table
e_ovno:                     dw 0x0000       ; 0x001A Overlay number
e_res:             times  4 dw 0x0000       ; 0x001C Reserved words
e_oemid:                    dw 0x0000       ; 0x0024 OEM identifier (for e_oeminfo)
e_oeminfo:                  dw 0x0000       ; 0x0026 OEM information; e_oemid specific
e_res2:            times 10 dw 0x0000       ; 0x0028 Reserved words
e_lfanew:                   dd Signature    ; 0x003C offset ( posição ) no arquivo do cabeçalho WIN (exe).

