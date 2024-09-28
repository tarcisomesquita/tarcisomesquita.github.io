SECTION_HEADER: ; A quantidade de itens na tabela está em NumberOfSections no cabeçalho FILE_HEADER
Name_text:                       db '.', 't', 'e', 'x', 't', 0x00, 0x00, 0x00 ; 
VirtualSize_text:                dd 0x00000000   ; Não usado. Tamanho da sessão no arquivo.
VirtualAddress_text:             dd text   ; Posição da seção na memória a partir da base
SizeOfRawData_text:              dd text_size    ; Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_text:           dd 0x00000600   ; Posição da seção dentro do arquivo
PointerToRelocations_text:       dd 0x00000000   ;
PointerToLinenumbers_text:       dd 0x00000000   ;
NumberOfRelocations_text:        dw 0x0000       ;
NumberOfLinenumbers_text:        dw 0x0000       ;
Characteristics_text:            dd 0x60000020   ;
                                                 ; 0x000000020   Code section.
                                                 ; 0x200000000   Executable section.
                                                 ; 0x400000000   Readable section.

Name_data:                       db '.', 'd', 'a', 't', 'a', 0x00, 0x00, 0x00 ; 
VirtualSize_data:                dd 0x00000000   ; Não usado. Tamanho da sessão no arquivo.
VirtualAddress_data:             dd data   ; Posição da seção na memória a partir da base
SizeOfRawData_data:              dd data_size    ; Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_data:           dd 0x00000600   ; Posição da seção dentro do arquivo
PointerToRelocations_data:       dd 0x00000000   ;
PointerToLinenumbers_data:       dd 0x00000000   ;
NumberOfRelocations_data:        dw 0x0000       ;
NumberOfLinenumbers_data:        dw 0x0000       ;
Characteristics_data:            dd 0x400000C0   ;
                                                 ; 0x000000040   Initialized data section.
                                                 ; 0x000000080   Uninitialized data section.
                                                 ; 0x400000000   Readable section.

align   0x20,db 0x00

first_sec:
