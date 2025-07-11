NT_HEADER:
Signature:                   db "P", "E", 0x00, 0x00

FILE_HEADER:
Machine:                     dw 0x014C       ; on which machine the binary is supposed to run
                                             ; 0x014c Intel 386 or later processors and compatible processors
NumberOfSections:            dw 0x0002       ; número de seções contidas no aplicativo (entradas em SECTION_HEADER)
TimeDateStamp:               dd 0x00000000   ; the time it was linked (number of seconds since 00:00 January 1, 1970)
PointerToSymbolTable:        dd 0x00000000   ; 
NumberOfSymbols:             dd 0x00000000   ; 
SizeOfOptionalHeader:        dw 0x00E0       ; 0xE0 = 224 bytes the size of the optional header
Characteristics:             dw 0x0102       ; indica se o arquivo é um EXE, DLL ou OCX.
                                             ; 0x0002 EXECUTABLE
                                             ; 0x0100 Machine is based on a 32-bit-word architecture.

OPTIONAL_HEADER32: ; 224 bytes, sendo que os últimos 128 são reservados para o diretório de dados.
Magic:                       dw 0x010B       ; 0x010B PE32
MajorLinkerVersion:          db 0x00         ; The linker major version number.
MinorLinkerVersion:          db 0x00         ; The linker minor version number.
SizeOfCode:                  dd text_size    ; size of the code (text) section, or the sum of all code sections
SizeOfInitializedData:       dd data_size    ; data section size
SizeOfUninitializedData:     dd 0x00000000   ; we don't have a BSS
AddressOfEntryPoint:         dd text   ;? endereço RVA (Relative Virtual Address) da primeira instrução a ser executada
BaseOfCode:                  dd text   ;? 
BaseOfData:                  dd data   ;? 
ImageBase:                   dd 0x00100000   ; This will be the virtual address of the first byte of the file (DOS Header). This must be a multiple of 64K.
                                             ; The section alignment is the same in the file and in RAM (32 bytes); this helps to keep the task easy
SectionAlignment:            dd 0x00000020   ; alinhamento das seções na memória (32 B)
FileAlignment:               dd 0x00000020   ; alinhamento das seções no arquivo em disco (32 B)
MajorOperatingSystemVersion: dw 0x0004       ; NT 4.0
MinorOperatingSystemVersion: dw 0x0000       ; 
MajorImageVersion:           dw 0x0000       ; 
MinorImageVersion:           dw 0x0000       ; 
MajorSubsystemVersion:       dw 0x0004       ; Win32 4.0
MinorSubsystemVersion:       dw 0x0000       ; 
Win32VersionValue:           dd 0x00000000   ; 
SizeOfImage:                 dd sum_size_sec ; Tamanho carregado na memória. Incluindo todos os cabeçalhos. Multiplo de "SectionAlignment"
SizeOfHeaders:               dd first_sec    ; Sum of size of the DOS Header, PE Header and Object Table
CheckSum:                    dd 0x00000000   ; only for trusted services
Subsystem:                   dw 0x0003       ; 03 The Windows character subsystem (a consele app)
DllCharacteristics:          dw 0x0000       ; Not is a dll
SizeOfStackReserve:          dd 0x00100000   ; defaults to 0x100000 (1MB). Tamanho máximo que a pilha poderá ter.
SizeOfStackCommit:           dd 0x00001000   ; defaults to 0x1000 bytes (1 page de 4 kiB) 
                                             ; at program startup, the 'committed' amount is actually allocated in RAM.
                                             ; Depois, a pilha é incrementada por 'committed' value, se precisar
SizeOfHeapReserve:           dd 0x00100000   ; Parece que isso aqui é para as outras thread criados por este processo. (fork)
SizeOfHeapCommit:            dd 0x00001000   ; 
LoaderFlags:                 dd 0x00000000   ; 
NumberOfRvaAndSizes:         dd 0x00000010   ; especifica o número de diretório de dados

DATA_DIRECTORY: ; Contém o Relative Virtual Address of tables.

VirtualAddress_Export:        dd 0x00000000   ;
Size_Export:                  dd 0x00000000   ;

VirtualAddress_Import:        dd import   ; ?
Size_Import:                  dd import_size   ; ?

VirtualAddress_Resource:      dd 0x00000000   ;
Size_Resource:                dd 0x00000000   ;

VirtualAddress_Exception:     dd 0x00000000   ;
Size_Exception:               dd 0x00000000   ;

VirtualAddress_Certificate:   dd 0x00000000   ;
Size_Certificate:             dd 0x00000000   ;

VirtualAddress_Relocation:    dd 0x00000000   ;
Size_Relocation:              dd 0x00000000   ;

VirtualAddress_Debug:         dd 0x00000000   ;
Size_Debug:                   dd 0x00000000   ;

VirtualAddress_Architecture:  dd 0x00000000   ;
Size_Architecture:            dd 0x00000000   ;

VirtualAddress_Global:        dd 0x00000000   ;
Size_Global:                  dd 0x00000000   ;

VirtualAddress_TLS:           dd 0x00000000   ;
Size_TLS:                     dd 0x00000000   ;

VirtualAddress_Config:        dd 0x00000000   ;
Size_Config:                  dd 0x00000000   ;

VirtualAddress_Bound:         dd 0x00000000   ;
Size_Bound:                   dd 0x00000000   ;

VirtualAddress_IAT:           dd 0x00000000   ;
Size_IAT:                     dd 0x00000000   ;

VirtualAddress_Delay:         dd 0x00000000   ;
Size_Delay:                   dd 0x00000000   ;

VirtualAddress_CLR:           dd 0x00000000   ;
Size_CLR:                     dd 0x00000000   ;

VirtualAddress_Reserved:      dd 0x00000000   ;
Size_Reserved:                dd 0x00000000   ;

