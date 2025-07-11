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
e_lfanew:                    .long 0x00000040     # 0x003C File address of

nt_header:
Signature:                   .byte 'P', 'E', 0x00, 0x00     # 0x0040  

file_header:
Machine:                     .word 0x8664         # 0x0044 IMAGE_FILE_MACHINE_AMD64
NumberOfSections:            .word 0x0002         # 0x0046 número de seções contidas no aplicativo (entradas em SECTION_HEADER)
TimeDateStamp:               .long 0x00000000     # 0x0048 linked in 31/12/1969 21:0:0 -10800
PointerToSymbolTable:        .long 0x00000000     # 0x004C 
NumberOfSymbols:             .long 0x00000000     # 0x0050 
SizeOfOptionalHeader:        .word 0x00F0         # 0x0054 0x00F0 = 240 bytes the size of the optional header
Characteristics:             .word 0x022F         # 0x0056 indica se o arquivo é um EXE, DLL ou OCX.
                                                           # 0x0001 IMAGE_FILE_RELOCS_STRIPPED
                                                           # 0x0002 IMAGE_FILE_EXECUTABLE_IMAGE
                                                           # 0x0004 IMAGE_FILE_LINE_NUMS_STRIPPED
                                                           # 0x0008 IMAGE_FILE_LOCAL_SYMS_STRIPPED
                                                           # 0x0020 Application can handle > 2GB addresses.
                                                           # 0x0200 IMAGE_FILE_DEBUG_STRIPPED

optional_header64:
Magic:                       .word 0x020B         # 0x0058 0x020B=PE64
MajorLinkerVersion:          .byte 0x00           # 0x005A The linker major version number.
MinorLinkerVersion:          .byte 0x00           # 0x005B The linker minor version number.
SizeOfCode:                  .long 0x00000200     # 0x005C size of the code (text) section, or the sum of all code sections
SizeOfInitializedData:       .long 0x00000200     # 0x0060 
SizeOfUninitializedData:     .long 0x00000000     # 0x0064 
AddressOfEntryPoint:         .long 0x00001000     # 0x0068 endereço RVA (Relative Virtual Address) da primeira instrução a ser executada
BaseOfCode:                  .long 0x00001000     # 0x006C 

ImageBase:                   .quad 0x0000000000400000     # 0x0070 posição no espaço relativo da memória que o Windows carregará o aplicativo.
SectionAlignment:            .long 0x00001000     # 0x0078 alinhamento de cada uma das seções (4kB)
FileAlignment:               .long 0x00000200     # 0x007C alinhamento das seções no arquivo em disco (512 B)
MajorOperatingSystemVersion: .word 0x0000         # 0x0080 
MinorOperatingSystemVersion: .word 0x0000         # 0x0082 
MajorImageVersion:           .word 0x0000         # 0x0084 
MinorImageVersion:           .word 0x0000         # 0x0086 
MajorSubsystemVersion:       .word 0x000A         # 0x0088 # Windows 10
MinorSubsystemVersion:       .word 0x0000         # 0x008A 
Win32VersionValue:           .long 0x00000000     # 0x008C 
SizeOfImage:                 .long 0x00003000     # 0x0090 Tamanho carregado na memória. Incluindo todos os cabeçalhos.
SizeOfHeaders:               .long 0x00000200     # 0x0094 Sum of size of the DOS Header, PE Header and Object Table
CheckSum:                    .long 0x00000000     # 0x0098 only for trusted services
Subsystem:                   .word 0x0003         # 0x009C The Windows character subsystem (a consele app)
DllCharacteristics:          .word 0x0000         # 0x009E 
SizeOfStackReserve:          .quad 0x0000000000001000     # 0x00A0 defaults to 0x100000 (1MB). Tamanho máximo que a pilha poderá ter.
SizeOfStackCommit:           .quad 0x0000000000001000     # 0x00A8 defaults to 0x1000 bytes (1 page)
SizeOfHeapReserve:           .quad 0x0000000000000000     # 0x00B0 Parece que isso aqui é para as outras thread criados por este processo.
SizeOfHeapCommit:            .quad 0x0000000000000000     # 0x00B8 
LoaderFlags:                 .long 0x00000000     # 0x00C0 
NumberOfRvaAndSizes:         .long 0x00000010     # 0x00C4 especifica o número de diretório de dados

DATA_DIRECTORY:
ExportVirtualAddress:        .long 0x00000000     # 0x00C8 
ExportSize:                  .long 0x00000000     # 0x00CC 

ImportVirtualAddress:        .long 0x00002000     # 0x00D0 
ImportSize:                  .long 0x00000050     # 0x00D4 

ResourceVirtualAddress:      .long 0x00000000     # 0x00D8 
ResourceSize:                .long 0x00000000     # 0x00DC 

ExceptionVirtualAddress:     .long 0x00000000     # 0x00E0 
ExceptionSize:               .long 0x00000000     # 0x00E4 

CertificateVirtualAddress:   .long 0x00000000     # 0x00E8 
CertificateSize:             .long 0x00000000     # 0x00EC 

RelocationVirtualAddress:    .long 0x00000000     # 0x00F0 
RelocationSize:              .long 0x00000000     # 0x00F4 

DebugVirtualAddress:         .long 0x00000000     # 0x00F8 
DebugSize:                   .long 0x00000000     # 0x00FC 

ArchitectureVirtualAddress:  .long 0x00000000     # 0x0100 
ArchitectureSize:            .long 0x00000000     # 0x0104 

GlobalVirtualAddress:        .long 0x00000000     # 0x0108 
GlobalSize:                  .long 0x00000000     # 0x010C 

TLSVirtualAddress:           .long 0x00000000     # 0x0110 
TLSSize:                     .long 0x00000000     # 0x0114 

ConfigVirtualAddress:        .long 0x00000000     # 0x0118 
ConfigSize:                  .long 0x00000000     # 0x011C 

BoundVirtualAddress:         .long 0x00000000     # 0x0120 
BoundSize:                   .long 0x00000000     # 0x0124 

IATVirtualAddress:           .long 0x00000000     # 0x0128 
IATSize:                     .long 0x00000000     # 0x012C 

DelayVirtualAddress:         .long 0x00000000     # 0x0130 
DelaySize:                   .long 0x00000000     # 0x0134 

CLRVirtualAddress:           .long 0x00000000     # 0x0138 
CLRSize:                     .long 0x00000000     # 0x013C 

ReservedVirtualAddress:      .long 0x00000000     # 0x0140 
ReservedSize:                .long 0x00000000     # 0x0144 


section_header:
Name_0:                      .byte '.', 't', 'e', 'x', 't', 0x00, 0x00, 0x00     # 0x0148 
VirtualSize_0:               .long text_f - text_i# 0x0150 Tamanho da sessão no arquivo.
VirtualAddress_0:            .long 0x00001000     # 0x0154 Posição da seção na memória a partir da base
SizeOfRawData_0:             .long 0x00000200     # 0x0158 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_0:          .long 0x00000200     # 0x015C Posição da seção dentro do arquivo
PointerToRelocations_0:      .long 0x00000000     # 0x0160 
PointerToLinenumbers_0:      .long 0x00000000     # 0x0164 
NumberOfRelocations_0:       .word 0x0000         # 0x0168 
NumberOfLinenumbers_0:       .word 0x0000         # 0x016A 
Characteristics_0:           .long 0x60000020     # 0x016C 
                                                           # 0x00000020   Code section.
                                                           # 0x20000000   Executable section.
                                                           # 0x40000000   Readable section.

Name_1:                      .byte '.', 'i', 'd', 'a', 't', 'a', 0x00, 0x00     # 0x0170 
VirtualSize_1:               .long idata_f - idata_i# 0x0178 Tamanho da sessão no arquivo.
VirtualAddress_1:            .long 0x00002000     # 0x017C Posição da seção na memória a partir da base
SizeOfRawData_1:             .long 0x00000200     # 0x0180 Tamanho da sessão no arquivo incluindo alinhamento.
PointerToRawData_1:          .long 0x00000400     # 0x0184 Posição da seção dentro do arquivo
PointerToRelocations_1:      .long 0x00000000     # 0x0188 
PointerToLinenumbers_1:      .long 0x00000000     # 0x018C 
NumberOfRelocations_1:       .word 0x0000         # 0x0190 
NumberOfLinenumbers_1:       .word 0x0000         # 0x0192 
Characteristics_1:           .long 0xC0000040     # 0x0194 
                                                           # 0x00000040   Initialized data section.
                                                           # 0x40000000   Readable section.
                                                           # 0x80000000   Writeable section.

