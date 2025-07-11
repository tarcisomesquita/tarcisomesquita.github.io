nt_header:
Signature:                   .byte 'P', 'E', 0x00, 0x00     # 0x0080  

file_header:
Machine:                     .word 0x014C         # 0x0084 IMAGE_FILE_MACHINE_I386
NumberOfSections:            .word 0x0003         # 0x0086 número de seções contidas no aplicativo (entradas em SECTION_HEADER)
TimeDateStamp:               .long 0x00000000     # 0x0088 linked in 19/1/2010 16:10:8 -7200
PointerToSymbolTable:        .long 0x00000000     # 0x008C 
NumberOfSymbols:             .long 0x00000000     # 0x0090 
SizeOfOptionalHeader:        .word 0x00E0         # 0x0094 0x00E0 = 224 bytes the size of the optional header
Characteristics:             .word 0x030F         # 0x0096 indica se o arquivo é um EXE, DLL ou OCX.
                                               #        0x0001 IMAGE_FILE_RELOCS_STRIPPED
                                               #        0x0002 IMAGE_FILE_EXECUTABLE_IMAGE
                                               #        0x0004 IMAGE_FILE_LINE_NUMS_STRIPPED
                                               #        0x0008 IMAGE_FILE_LOCAL_SYMS_STRIPPED
                                               #        0x0100 IMAGE_FILE_32BIT_MACHINE
                                               #        0x0200 IMAGE_FILE_DEBUG_STRIPPED

optional_header32:
Magic:                       .word 0x010B         # 0x0098 0x010B=PE32
MajorLinkerVersion:          .byte 0x00           # 0x009A The linker major version number.
MinorLinkerVersion:          .byte 0x00           # 0x009B The linker minor version number.
SizeOfCode:                  .long 0x00000200     # 0x009C size of the code (text) section, or the sum of all code sections
SizeOfInitializedData:       .long 0x00000400     # 0x00A0 
SizeOfUninitializedData:     .long 0x00000000     # 0x00A4 
AddressOfEntryPoint:         .long 0x00001050     # 0x00A8 endereço RVA (Relative Virtual Address) da primeira instrução a ser executada
BaseOfCode:                  .long 0x00001000     # 0x00AC 
BaseOfData:                  .long 0x00003000     # 0x00B0 

ImageBase:                   .long 0x00400000     # 0x00B4 posição no espaço relativo da memória que o Windows carregará o aplicativo.
SectionAlignment:            .long 0x00001000     # 0x00B8 alinhamento de cada uma das seções (4kB)
FileAlignment:               .long 0x00000200     # 0x00BC alinhamento das seções no arquivo em disco (512 B)
MajorOperatingSystemVersion: .word 0x0004         # 0x00C0 
MinorOperatingSystemVersion: .word 0x0000         # 0x00C2 
MajorImageVersion:           .word 0x0000         # 0x00C4 
MinorImageVersion:           .word 0x0000         # 0x00C6 
MajorSubsystemVersion:       .word 0x0004         # 0x00C8 
MinorSubsystemVersion:       .word 0x0000         # 0x00CA 
Win32VersionValue:           .long 0x00000000     # 0x00CC 
SizeOfImage:                 .long 0x00004000     # 0x00D0 Tamanho carregado na memória. Incluindo todos os cabeçalhos.
SizeOfHeaders:               .long 0x00000200     # 0x00D4 Sum of size of the DOS Header, PE Header and Object Table
CheckSum:                    .long 0x00000000     # 0x00D8 only for trusted services
Subsystem:                   .word 0x0003         # 0x00DC The Windows character subsystem (a consele app)
DllCharacteristics:          .word 0x0000         # 0x00DE 
SizeOfStackReserve:          .long 0x00100000     # 0x00E0 defaults to 0x100000 (1MB). Tamanho máximo que a pilha poderá ter.
SizeOfStackCommit:           .long 0x00001000     # 0x00E4 defaults to 0x1000 bytes (1 page)
SizeOfHeapReserve:           .long 0x00100000     # 0x00E8 Parece que isso aqui é para as outras thread criados por este processo.
SizeOfHeapCommit:            .long 0x00001000     # 0x00EC 
LoaderFlags:                 .long 0x00000000     # 0x00F0 
NumberOfRvaAndSizes:         .long 0x00000010     # 0x00F4 especifica o número de diretório de dados


DATA_DIRECTORY:
ExportVirtualAddress:        .long 0x00000000     # 0x00F8 
ExportSize:                  .long 0x00000000     # 0x00FC 

ImportVirtualAddress:        .long 0x00002054     # 0x0100 
ImportSize:                  .long 0x00000028     # 0x0104 

ResourceVirtualAddress:      .long 0x00000000     # 0x0108 
ResourceSize:                .long 0x00000000     # 0x010C 

ExceptionVirtualAddress:     .long 0x00000000     # 0x0110 
ExceptionSize:               .long 0x00000000     # 0x0114 

CertificateVirtualAddress:   .long 0x00000000     # 0x0118 
CertificateSize:             .long 0x00000000     # 0x011C 

RelocationVirtualAddress:    .long 0x00000000     # 0x0120 
RelocationSize:              .long 0x00000000     # 0x0124 

DebugVirtualAddress:         .long 0x00000000     # 0x0128 
DebugSize:                   .long 0x00000000     # 0x012C 

ArchitectureVirtualAddress:  .long 0x00000000     # 0x0130 
ArchitectureSize:            .long 0x00000000     # 0x0134 

GlobalVirtualAddress:        .long 0x00000000     # 0x0138 
GlobalSize:                  .long 0x00000000     # 0x013C 

TLSVirtualAddress:           .long 0x00000000     # 0x0140 
TLSSize:                     .long 0x00000000     # 0x0144 

ConfigVirtualAddress:        .long 0x00000000     # 0x0148 
ConfigSize:                  .long 0x00000000     # 0x014C 

BoundVirtualAddress:         .long 0x00000000     # 0x0150 
BoundSize:                   .long 0x00000000     # 0x0154 

IATVirtualAddress:           .long 0x00002000     # 0x0158 
IATSize:                     .long 0x00000044     # 0x015C 

DelayVirtualAddress:         .long 0x00000000     # 0x0160 
DelaySize:                   .long 0x00000000     # 0x0164 

CLRVirtualAddress:           .long 0x00000000     # 0x0168 
CLRSize:                     .long 0x00000000     # 0x016C 

ReservedVirtualAddress:      .long 0x00000000     # 0x0170 
ReservedSize:                .long 0x00000000     # 0x0174 

