SECTION_HEADER:
Name_0:                      .byte '.', 't', 'e', 'x', 't', 0x00, 0x00, 0x00   # 0x0188 
VirtualSize_0:               .long text_f - text_i   # 0x0190 Tamanho da sessão no arquivo.
VirtualAddress_0:            .long 0x00001000   # 0x0194 Posição da seção na memória a partir da base
SizeOfRawData_0:             .long 0x00401200   #text         # 0x0198 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_0:          .long 0x00000200   # 0x019C Posição da seção dentro do arquivo
PointerToRelocations_0:      .long 0x00000000   # 0x01A0 
PointerToLinenumbers_0:      .long 0x00000000   # 0x01A4 
NumberOfRelocations_0:       .word 0x0000       # 0x01A8 
NumberOfLinenumbers_0:       .word 0x0000       # 0x01AA 
Characteristics_0:           .long 0x60000020   # 0x01AC 
                                             #        0x00000020   Code section.
                                             #        0x20000000   Executable section.
                                             #        0x40000000   Readable section.

Name_1:                      .byte '.', 'i', 'd', 'a', 't', 'a', 0x00, 0x00   # 0x01B0 
VirtualSize_1:               .long idata_f - idata_i   # 0x01B8 Tamanho da sessão no arquivo.
VirtualAddress_1:            .long 0x00002000   # 0x01BC Posição da seção na memória a partir da base
SizeOfRawData_1:             .long 0x00000200   # 0x01C0 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_1:          .long 0x00000400   # 0x01C4 Posição da seção dentro do arquivo
PointerToRelocations_1:      .long 0x00000000   # 0x01C8 
PointerToLinenumbers_1:      .long 0x00000000   # 0x01CC 
NumberOfRelocations_1:       .word 0x0000       # 0x01D0 
NumberOfLinenumbers_1:       .word 0x0000       # 0x01D2 
Characteristics_1:           .long 0xC0000040   # 0x01D4 
                                             #        0x00000040   Initialized data section.
                                             #        0x40000000   Readable section.
                                             #        0x80000000   Writeable section.

