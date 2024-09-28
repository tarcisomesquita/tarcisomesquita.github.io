section_header:
Name_0:                      .byte '.', 't', 'e', 'x', 't', 0x00, 0x00, 0x00     # 0x0178 
VirtualSize_0:               .long 0x000001FC     # 0x0180 Tamanho da sessão no arquivo.
VirtualAddress_0:            .long 0x00001000     # 0x0184 Posição da seção na memória a partir da base
SizeOfRawData_0:             .long 0x00000200     # 0x0188 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_0:          .long 0x00000200     # 0x018C Posição da seção dentro do arquivo
PointerToRelocations_0:      .long 0x00000000     # 0x0190 
PointerToLinenumbers_0:      .long 0x00000000     # 0x0194 
NumberOfRelocations_0:       .word 0x0000         # 0x0198 
NumberOfLinenumbers_0:       .word 0x0000         # 0x019A 
Characteristics_0:           .long 0x60300020     # 0x019C 
                                               #        0x00000020   Code section.
                                               #        0x20000000   Executable section.
                                               #        0x40000000   Readable section.

Name_1:                      .byte '.', 'r', 'd', 'a', 't', 'a', 0x00, 0x00     # 0x01A0 
VirtualSize_1:               .long 0x000001AA     # 0x01A8 Tamanho da sessão no arquivo.
VirtualAddress_1:            .long 0x00002000     # 0x01AC Posição da seção na memória a partir da base
SizeOfRawData_1:             .long 0x00000200     # 0x01B0 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_1:          .long 0x00000400     # 0x01B4 Posição da seção dentro do arquivo
PointerToRelocations_1:      .long 0x00000000     # 0x01B8 
PointerToLinenumbers_1:      .long 0x00000000     # 0x01BC 
NumberOfRelocations_1:       .word 0x0000         # 0x01C0 
NumberOfLinenumbers_1:       .word 0x0000         # 0x01C2 
Characteristics_1:           .long 0x40300040     # 0x01C4 
                                               #        0x00000040   Initialized data section.
                                               #        0x40000000   Readable section.

Name_2:                      .byte '.', 'd', 'a', 't', 'a', 0x00, 0x00, 0x00     # 0x01C8 
VirtualSize_2:               .long 0x0000004C     # 0x01D0 Tamanho da sessão no arquivo.
VirtualAddress_2:            .long 0x00003000     # 0x01D4 Posição da seção na memória a partir da base
SizeOfRawData_2:             .long 0x00000200     # 0x01D8 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_2:          .long 0x00000600     # 0x01DC Posição da seção dentro do arquivo
PointerToRelocations_2:      .long 0x00000000     # 0x01E0 
PointerToLinenumbers_2:      .long 0x00000000     # 0x01E4 
NumberOfRelocations_2:       .word 0x0000         # 0x01E8 
NumberOfLinenumbers_2:       .word 0x0000         # 0x01EA 
Characteristics_2:           .long 0xC0300040     # 0x01EC 
                                               #        0x00000040   Initialized data section.
                                               #        0x40000000   Readable section.
                                               #        0x80000000   Writeable section.


