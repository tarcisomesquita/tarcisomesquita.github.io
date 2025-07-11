nt_header:
Signature:                   .byte 'P', 'E', 0x00, 0x00   # 0x0080 

file_header:
Machine:                     .word 0x014c       # 0x0084 IMAGE_FILE_MACHINE_AMD64
NumberOfSections:            .word 0x0003       # 0x0086 número de seções contidas no aplicativo (entradas em SECTION_HEADER)
TimeDateStamp:               .long 0x00000000   # 0x0088 linked in 29/10/2017 3:14:38 0
PointerToSymbolTable:        .long 0x00000000   # 0x008C 
NumberOfSymbols:             .long 0x00000000   # 0x0090 
SizeOfOptionalHeader:        .word 0x00E0         # 0x00C4 0x00E0 = 224 bytes the size of the optional header
Characteristics:             .word 0x010F         # 0x00C6 indica se o arquivo é um EXE, DLL ou OCX.
                                               #        0x0001 IMAGE_FILE_RELOCS_STRIPPED
                                               #        0x0002 IMAGE_FILE_EXECUTABLE_IMAGE
                                               #        0x0004 IMAGE_FILE_LINE_NUMS_STRIPPED
                                               #        0x0008 IMAGE_FILE_LOCAL_SYMS_STRIPPED
                                               #        0x0100 IMAGE_FILE_32BIT_MACHINE

optional_header32:
Magic:                       .word 0x010B         # 0x00C8 0x010B=PE32
MajorLinkerVersion:          .byte 0x00           # 0x00CA The linker major version number.
MinorLinkerVersion:          .byte 0x00           # 0x00CB The linker minor version number.
SizeOfCode:                  .long 0x00000200     # 0x00CC size of the code (text) section, or the sum of all code sections
SizeOfInitializedData:       .long 0x00000400     # 0x00D0 
SizeOfUninitializedData:     .long 0x00000000     # 0x00D4 
AddressOfEntryPoint:         .long 0x00001000     # 0x00D8 endereço RVA (Relative Virtual Address) da primeira instrução a ser executada
BaseOfCode:                  .long 0x00001000     # 0x00DC 
BaseOfData:                  .long 0x00002000     # 0x00E0 

ImageBase:                   .long 0x00400000     # 0x00E4 posição no espaço relativo da memória que o Windows carregará o aplicativo.
SectionAlignment:            .long 0x00001000     # 0x00E8 alinhamento de cada uma das seções (4kB)
FileAlignment:               .long 0x00000200     # 0x00EC alinhamento das seções no arquivo em disco (512 B)
MajorOperatingSystemVersion: .word 0x0000         # 0x00F0 
MinorOperatingSystemVersion: .word 0x0000         # 0x00F2 
MajorImageVersion:           .word 0x0000         # 0x00F4 
MinorImageVersion:           .word 0x0000         # 0x00F6 
MajorSubsystemVersion:       .word 0x0004         # 0x00F8 
MinorSubsystemVersion:       .word 0x0000         # 0x00FA 
Win32VersionValue:           .long 0x00000000     # 0x00FC 
SizeOfImage:                 .long 0x00004000     # 0x0100 Tamanho carregado na memória. Incluindo todos os cabeçalhos.
SizeOfHeaders:               .long 0x00000400     # 0x0104 Sum of size of the DOS Header, PE Header and Object Table
CheckSum:                    .long 0x00000000     # 0x0108 only for trusted services
Subsystem:                   .word 0x0002         # 0x010C The Windows graphical user interface (GUI) subsystem
DllCharacteristics:          .word 0x0000         # 0x010E 
SizeOfStackReserve:          .long 0x00100000     # 0x0110 defaults to 0x100000 (1MB). Tamanho máximo que a pilha poderá ter.
SizeOfStackCommit:           .long 0x00001000     # 0x0114 defaults to 0x1000 bytes (1 page)
SizeOfHeapReserve:           .long 0x00100000     # 0x0118 Parece que isso aqui é para as outras thread criados por este processo.
SizeOfHeapCommit:            .long 0x00001000     # 0x011C 
LoaderFlags:                 .long 0x00000000     # 0x0120 
NumberOfRvaAndSizes:         .long 0x00000010     # 0x0124 especifica o número de diretório de dados

DATA_DIRECTORY:
ExportVirtualAddress:        .long 0x00000000     # 0x0128 
ExportSize:                  .long 0x00000000     # 0x012C 

ImportVirtualAddress:        .long 0x00002010     # 0x0130 
ImportSize:                  .long 0x0000003C     # 0x0134 

ResourceVirtualAddress:      .long 0x00000000     # 0x0138 
ResourceSize:                .long 0x00000000     # 0x013C 

ExceptionVirtualAddress:     .long 0x00000000     # 0x0140 
ExceptionSize:               .long 0x00000000     # 0x0144 

CertificateVirtualAddress:   .long 0x00000000     # 0x0148 
CertificateSize:             .long 0x00000000     # 0x014C 

RelocationVirtualAddress:    .long 0x00000000     # 0x0150 
RelocationSize:              .long 0x00000000     # 0x0154 

DebugVirtualAddress:         .long 0x00000000     # 0x0158 
DebugSize:                   .long 0x00000000     # 0x015C 

ArchitectureVirtualAddress:  .long 0x00000000     # 0x0160 
ArchitectureSize:            .long 0x00000000     # 0x0164 

GlobalVirtualAddress:        .long 0x00000000     # 0x0168 
GlobalSize:                  .long 0x00000000     # 0x016C 

TLSVirtualAddress:           .long 0x00000000     # 0x0170 
TLSSize:                     .long 0x00000000     # 0x0174 

ConfigVirtualAddress:        .long 0x00000000     # 0x0178 
ConfigSize:                  .long 0x00000000     # 0x017C 

BoundVirtualAddress:         .long 0x00000000     # 0x0180 
BoundSize:                   .long 0x00000000     # 0x0184 

IATVirtualAddress:           .long 0x00002000     # 0x0188 
IATSize:                     .long 0x00000010     # 0x018C 

DelayVirtualAddress:         .long 0x00000000     # 0x0190 
DelaySize:                   .long 0x00000000     # 0x0194 

CLRVirtualAddress:           .long 0x00000000     # 0x0198 
CLRSize:                     .long 0x00000000     # 0x019C 

ReservedVirtualAddress:      .long 0x00000000     # 0x01A0 
ReservedSize:                .long 0x00000000     # 0x01A4 


