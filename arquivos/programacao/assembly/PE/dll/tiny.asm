
; arquivo 'tiny.exe'

DOS_HEADER:          ; os únicos valores úteis aqui são e_magic e e_lfanew
e_magic:                     dw "MZ"         ; 0x0000 Magic number
e_cblp:                      dw 0x0000       ; 0x0002 Bytes on last page of file
e_cp:                        dw 0x0000       ; 0x0004 Pages in file (1kiB ?)
e_crlc:                      dw 0x0000       ; 0x0006 Relocations
e_cparhdr:                   dw 0x0000       ; 0x0008 Size of header in paragraphs (16 bytes)
e_minalloc:                  dw 0x0000       ; 0x000A Minimum extra paragraphs needed
e_maxalloc:                  dw 0x0000       ; 0x000C Maximum extra paragraphs needed
e_ss:                        dw 0x0000       ; 0x000E Initial (relative) SS value
e_sp:                        dw 0x0000       ; 0x0010 Initial SP value
e_csum:                      dw 0x0000       ; 0x0012 Checksum
e_ip:                        dw 0x0000       ; 0x0014 Initial IP value
e_cs:                        dw 0x0000       ; 0x0016 Initial (relative) CS value
e_lfarlc:                    dw 0x0000       ; 0x0018 File address of relocation table
e_ovno:                      dw 0x0000       ; 0x001A Overlay number
e_res:              times  4 dw 0x0000       ; 0x001C Reserved words
e_oemid:                     dw 0x0000       ; 0x0024 OEM identifier (for e_oeminfo)
e_oeminfo:                   dw 0x0000       ; 0x0026 OEM information; e_oemid specific
e_res2:             times 10 dw 0x0000       ; 0x0028 Reserved words
e_lfanew:                    dd 0x00000040   ; 0x003C File address of

NT_HEADER:
Signature:                  db "P", "E", 0x00, 0x00

FILE_HEADER:
Machine:                     dw 0x014c       ; Intel 386 compatible processors
NumberOfSections:            dw 0x0001       ; número de seções contidas no aplicativo (entradas em SECTION_HEADER)
TimeDateStamp:               dd 0x00000000   ; the time it was linked (number of seconds since 00:00 January 1, 1970)
PointerToSymbolTable:        dd 0x00000000   ; 
NumberOfSymbols:             dd 0x00000000   ; 
SizeOfOptionalHeader:        dw 0x00E0       ; 0xE0 = 224 bytes the size of the optional header
Characteristics:             dw 0x0103       ; indica se o arquivo é um EXE, DLL ou OCX.
                                             ; 0x0001 Relocation info stripped from file.
                                             ; 0x0002 EXECUTABLE
                                             ; 0x0100 Machine is based on a 32-bit-word architecture.

OPTIONAL_HEADER32:
Magic:                       dw 0x010B       ; 0x010B PE32
MajorLinkerVersion:          db 0x00         ; The linker major version number.
MinorLinkerVersion:          db 0x00         ; The linker minor version number.
SizeOfCode:                  dd 0x00000004   ; size of the code (text) section, or the sum of all code sections
SizeOfInitializedData:       dd 0x00000000   ; 
SizeOfUninitializedData:     dd 0x00000000   ; 
AddressOfEntryPoint:         dd 0x00000160   ; endereço RVA (Relative Virtual Address) da primeira instrução a ser executada
BaseOfCode:                  dd 0x00000160   ; 
BaseOfData:                  dd 0x00000164   ; 

ImageBase:                   dd 0x00400000   ; posição no espaço relativo da memória que o Windows carregará o aplicativo.
SectionAlignment:            dd 0x00000001   ; alinhamento de cada uma das seções (4kB)
FileAlignment:               dd 0x00000001   ; alinhamento das seções no arquivo em disco (512 B)
MajorOperatingSystemVersion: dw 0x0000       ; 
MinorOperatingSystemVersion: dw 0x0000       ; 
MajorImageVersion:           dw 0x0000       ; 
MinorImageVersion:           dw 0x0000       ; 
MajorSubsystemVersion:       dw 0x0004       ; 
MinorSubsystemVersion:       dw 0x0000       ; 
Win32VersionValue:           dd 0x00000000   ; 
SizeOfImage:                 dd 0x00000164   ; Tamanho carregado na memória. Incluindo todos os cabeçalhos. Multiplo de "SectionAlignment"
SizeOfHeaders:               dd 0x00000160   ; Sum of size of the DOS Header, PE Header and Object Table
CheckSum:                    dd 0x00000000   ; only for trusted services
Subsystem:                   dw 0x0002       ; The Windows graphical user interface (GUI) subsystem
DllCharacteristics:          dw 0x0000       ; 
SizeOfStackReserve:          dd 0x00100000   ; defaults to 0x100000 (1MB). Tamanho máximo que a pilha poderá ter.
SizeOfStackCommit:           dd 0x00001000   ; defaults to 0x1000 bytes (1 page)
                                             ; at program startup, the 'committed' amount is actually allocated in RAM.
                                             ; Depois, a pilha é incrementada por 'committed' value, se precisar
SizeOfHeapReserve:           dd 0x00100000   ; Parece que isso aqui é para as outras thread criados por este processo. (fork)
SizeOfHeapCommit:            dd 0x00001000   ; 
LoaderFlags:                 dd 0x00000000   ; 
NumberOfRvaAndSizes:         dd 0x00000010   ; especifica o número de diretório de dados

; An RVA is a virtual address that is relative to the Image Base.
; An RVA in the PE Header that has a value of zero indicates the field isn't used.

DATA_DIRECTORY:
ExportVirtualAddress:        dd 0x00000000   ; 
ExportSize:                  dd 0x00000000   ; 

ImportVirtualAddress:        dd 0x00000000   ; 
ImportSize:                  dd 0x00000000   ; 

ResourceVirtualAddress:      dd 0x00000000   ; 
ResourceSize:                dd 0x00000000   ; 

ExceptionVirtualAddress:     dd 0x00000000   ; 
ExceptionSize:               dd 0x00000000   ; 

CertificateVirtualAddress:   dd 0x00000000   ; 
CertificateSize:             dd 0x00000000   ; 

RelocationVirtualAddress:    dd 0x00000000   ; 
RelocationSize:              dd 0x00000000   ; 

DebugVirtualAddress:         dd 0x00000000   ; 
DebugSize:                   dd 0x00000000   ; 

ArchitectureVirtualAddress:  dd 0x00000000   ; 
ArchitectureSize:            dd 0x00000000   ; 

GlobalVirtualAddress:        dd 0x00000000   ; 
GlobalSize:                  dd 0x00000000   ; 

TLSVirtualAddress:           dd 0x00000000   ; 
TLSSize:                     dd 0x00000000   ; 

ConfigVirtualAddress:        dd 0x00000000   ; 
ConfigSize:                  dd 0x00000000   ; 

BoundVirtualAddress:         dd 0x00000000   ; 
BoundSize:                   dd 0x00000000   ; 

IATVirtualAddress:           dd 0x00000000   ; 
IATSize:                     dd 0x00000000   ; 

DelayVirtualAddress:         dd 0x00000000   ; 
DelaySize:                   dd 0x00000000   ; 

CLRVirtualAddress:           dd 0x00000000   ; 
CLRSize:                     dd 0x00000000   ; 

ReservedVirtualAddress:      dd 0x00000000   ; 
ReservedSize:                dd 0x00000000   ; 


SECTION_HEADER:
Name_0:                      db '.', 't', 'e', 'x', 't', 0x00, 0x00, 0x00;
VirtualSize_0:               dd 0x00000004   ; Tamanho da sessão no arquivo.
VirtualAddress_0:            dd 0x00000160   ; Posição da seção na memória a partir da base
SizeOfRawData_0:             dd 0x00000004   ; Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_0:          dd 0x00000160   ; Posição da seção dentro do arquivo
PointerToRelocations_0:      dd 0x00000000   ; 
PointerToLinenumbers_0:      dd 0x00000000   ; 
NumberOfRelocations_0:       dw 0x0000       ; 
NumberOfLinenumbers_0:       dw 0x0000       ; 
Characteristics_0:           dd 0x60000020   ; 
                                             ; 0x00000020   Code section.
                                             ; 0x20000000   Executable section.
                                             ; 0x40000000   Readable section.


