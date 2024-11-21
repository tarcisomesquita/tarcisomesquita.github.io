; CODE   .text    Contém as instruções e o código do programa.
; RDATA  .rdata   Dados gerais ( incluindo tabela de seções ).
; DATA   .data    Variáveis inicializadas.
; RSRC   .rsrc    Resources ( textos e disposição de itens na janela ).
; BSS    .bss     Contém todas as variáveis não inicializadas (sem um valor definido) do aplicativo.


SECTION_HEADER: ; A quantidade de itens na tabela está em NumberOfSections no cabeçalho FILE_HEADER
Name1:                       db '.', 't', 'e', 'x', 't', 0x00, 0x00, 0x00 ; 
VirtualSize1:                dd 0x0000007C   ; Tamanho da sessão no arquivo.
VirtualAddress1:             dd 0x00001000   ; Posição da seção na memória a partir da base
SizeOfRawData1:              dd 0x00000200   ; Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData1:           dd 0x00000600   ; Posição da seção dentro do arquivo
PointerToRelocations1:       dd 0x00000000   ;
PointerToLinenumbers1:       dd 0x00000000   ;
NumberOfRelocations1:        dw 0x0000       ;
NumberOfLinenumbers1:        dw 0x0000       ;
Characteristics1:            dd 0x60000020   ;
                                             ; 0x000000020   Code section.
                                             ; 0x000000040   Initialized data section.
                                             ; 0x000000080   Uninitialized data section.
                                             ; 0x040000000   Section must not be cached.
                                             ; 0x080000000   Section is not pageable.
                                             ; 0x100000000   Section is shared.
                                             ; 0x200000000   Executable section.
                                             ; 0x400000000   Readable section.
                                             ; 0x800000000   Writeable section.

Name2:                       db '.', 'r', 'd', 'a', 't', 'a', 0x00, 0x00 ; 
VirtualSize2:                dd 0x000000c6   ;
VirtualAddress2:             dd 0x00002000   ;
SizeOfRawData2:              dd 0x00000200   ;
PointerToRawData2:           dd 0x00000800   ;
PointerToRelocations2:       dd 0x00000000   ;
PointerToLinenumbers2:       dd 0x00000000   ;
NumberOfRelocations2:        dw 0x0000       ;
NumberOfLinenumbers2:        dw 0x0000       ;
Characteristics2:            dd 0x40000040   ;
Name3:                       db '.', 'd', 'a', 't', 'a', 0x00, 0x00, 0x00 ; 
VirtualSize3:                dd 0x00000004   ;
VirtualAddress3:             dd 0x00003000   ;
SizeOfRawData3:              dd 0x00000000   ;
PointerToRawData3:           dd 0x00000000   ;
PointerToRelocations3:       dd 0x00000000   ;
PointerToLinenumbers3:       dd 0x00000000   ;
NumberOfRelocations3:        dw 0x0000       ;
NumberOfLinenumbers3:        dw 0x0000       ;
Characteristics3:            dd 0xc0000040   ;
Name4:                       db '.', 'r', 's', 'r', 'c', 0x00, 0x00, 0x00 ; 
VirtualSize4:                dd 0x000001d8   ;
VirtualAddress4:             dd 0x00004000   ;
SizeOfRawData4:              dd 0x00000200   ;
PointerToRawData4:           dd 0x00000a00   ;
PointerToRelocations4:       dd 0x00000000   ;
PointerToLinenumbers4:       dd 0x00000000   ;
NumberOfRelocations4:        dw 0x0000       ;
NumberOfLinenumbers4:        dw 0x0000       ;
Characteristics4:            dd 0x40000040   ;

align   0x200,db 0          ; pad with 0s rather than NOPs

