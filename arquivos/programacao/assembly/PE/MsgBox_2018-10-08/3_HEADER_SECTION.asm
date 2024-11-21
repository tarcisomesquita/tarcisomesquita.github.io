section_header:
Name_0:                      .byte '.', 't', 'e', 'x', 't', 0x00, 0x00, 0x00     # 0x01A8 
VirtualSize_0:               .long 0x00000026     # 0x01B0 Tamanho da sessão no arquivo.
VirtualAddress_0:            .long 0x00001000     # 0x01B4 Posição da seção na memória a partir da base
SizeOfRawData_0:             .long 0x00000200     # 0x01B8 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_0:          .long 0x00000400     # 0x01BC Posição da seção dentro do arquivo
PointerToRelocations_0:      .long 0x00000000     # 0x01C0 
PointerToLinenumbers_0:      .long 0x00000000     # 0x01C4 
NumberOfRelocations_0:       .word 0x0000         # 0x01C8 
NumberOfLinenumbers_0:       .word 0x0000         # 0x01CA 
Characteristics_0:           .long 0x60000020     # 0x01CC 
                                               #        0x00000020   Code section.
                                               #        0x20000000   Executable section.
                                               #        0x40000000   Readable section.

Name_1:                      .byte '.', 'r', 'd', 'a', 't', 'a', 0x00, 0x00     # 0x01D0 
VirtualSize_1:               .long 0x00000092     # 0x01D8 Tamanho da sessão no arquivo.
VirtualAddress_1:            .long 0x00002000     # 0x01DC Posição da seção na memória a partir da base
SizeOfRawData_1:             .long 0x00000200     # 0x01E0 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_1:          .long 0x00000600     # 0x01E4 Posição da seção dentro do arquivo
PointerToRelocations_1:      .long 0x00000000     # 0x01E8 
PointerToLinenumbers_1:      .long 0x00000000     # 0x01EC 
NumberOfRelocations_1:       .word 0x0000         # 0x01F0 
NumberOfLinenumbers_1:       .word 0x0000         # 0x01F2 
Characteristics_1:           .long 0x40000040     # 0x01F4 
                                               #        0x00000040   Initialized data section.
                                               #        0x40000000   Readable section.

Name_2:                      .byte '.', 'd', 'a', 't', 'a', 0x00, 0x00, 0x00     # 0x01F8 
VirtualSize_2:               .long 0x0000007F     # 0x0200 Tamanho da sessão no arquivo.
VirtualAddress_2:            .long 0x00003000     # 0x0204 Posição da seção na memória a partir da base
SizeOfRawData_2:             .long 0x00000200     # 0x0208 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_2:          .long 0x00000800     # 0x020C Posição da seção dentro do arquivo
PointerToRelocations_2:      .long 0x00000000     # 0x0210 
PointerToLinenumbers_2:      .long 0x00000000     # 0x0214 
NumberOfRelocations_2:       .word 0x0000         # 0x0218 
NumberOfLinenumbers_2:       .word 0x0000         # 0x021A 
Characteristics_2:           .long 0xC0000040     # 0x021C 
                                               #        0x00000040   Initialized data section.
                                               #        0x40000000   Readable section.
                                               #        0x80000000   Writeable section.

