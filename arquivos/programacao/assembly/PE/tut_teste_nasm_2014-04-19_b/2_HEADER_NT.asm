

NT_HEADER:
Signature:                   db "P", "E", 0x00, 0x00

FILE_HEADER:
Machine:                     dw 0x014C       ; on which machine the binary is supposed to run
                                             ; 0000h Unknown
                                             ; 0x0000 applicable to any machine type
                                             ; 0x014c Intel 386 or later processors and compatible processors
                                             ; 0x014D 80486
                                             ; 0x014E PentiumTM
                                             ; 0x0166 MIPS little endian
                                             ; 0x0169 MIPS little-endian WCE v2
                                             ; 0x01a2 Hitachi SH3
                                             ; 0x01a3 Hitachi SH3 DSP
                                             ; 0x01a6 Hitachi SH4 
                                             ; 0x01a8 Hitachi SH5
                                             ; 0x01c0 ARM little endian
                                             ; 0x01c2 Thumb
                                             ; 0x01d3 Matsushita AM33
                                             ; 0x01f0 Power PC little endian
                                             ; 0x01f1 Power PC with floating point support
                                             ; 0x0200 IA64 Intel Itanium processor family
                                             ; 0x0266 MIPS16
                                             ; 0x0366 MIPS
                                             ; 0x0466 MIPS16 with FPU
                                             ; 0x0ebc EFI byte code
                                             ; 0x8664 x64
                                             ; 0x9041 Mitsubishi M32R little endian

NumberOfSections:            dw 0x0004       ; número de seções contidas no aplicativo (entradas em SECTION_HEADER)
TimeDateStamp:               dd 0x4648fef3   ; the time it was linked (number of seconds since 00:00 January 1, 1970)
PointerToSymbolTable:        dd 0x00000000   ; 
NumberOfSymbols:             dd 0x00000000   ; 
SizeOfOptionalHeader:        dw 0x00E0       ; 0xE0 = 224 bytes the size of the optional header
Characteristics:             dw 0x0102       ; indica se o arquivo é um EXE, DLL ou OCX.
                                             ; 0x0001 Image. File does not contain base relocations
                                             ;        must be loaded at its preferred base address
                                             ; 0x0002 EXECUTABLE
                                             ; 0x0004 should be zero
                                             ; 0x0008 should be zero
                                             ; 0x0010 must be zero.
                                             ; 0x0020 Application can handle > 2GB addresses.
                                             ; 0x0040 This flag is reserved for future use.
                                             ; 0x0080 Little endian
                                             ; 0x0100 Machine is based on a 32-bit-word architecture.
                                             ; 0x0200 Debugging information is removed from the image file.
                                             ; 0x0400 If the image is on removable media, fully load it and
                                             ;        copy it to the swap file.
                                             ; 0x0800 If the image is on network media, fully load it and 
                                             ;        copy it to the swap file.
                                             ; 0x1000 The image file is a system file, not a user program.
                                             ; 0x2000 The image file is a dynamic-link library (DLL).
                                             ; 0x4000 The file should be run only on a uniprocessor machine.
                                             ; 0x8000 Big endian

OPTIONAL_HEADER32: ; 224 bytes, sendo que os últimos 128 são reservados para o diretório de dados.
Magic:                       dw 0x010B       ; 0x010b PE32
                                             ; 0x020b PE32+  64 bits
                                             ; 0x0107 ROM image
MajorLinkerVersion:          db 0x05         ; The linker major version number.
MinorLinkerVersion:          db 0x0C         ; The linker minor version number.
;SizeOfCode:                  dd code_size    ; size of the code (text) section, or the sum of all code sections
SizeOfCode:                  dd 0x00000200   ; size of the code (text) section, or the sum of all code sections
SizeOfInitializedData:       dd 0x00000600   ; 
SizeOfUninitializedData:     dd 0x00000000   ; 
AddressOfEntryPoint:         dd 0x00001000   ; endereço RVA (Relative Virtual Address) da primeira instrução a ser executada
BaseOfCode:                  dd 0x00001000   ; 
BaseOfData:                  dd 0x00002000   ; 
ImageBase:                   dd 0x00400000   ; This will be the virtual address of the first byte of the file (DOS Header). This must be a multiple of 64K.
SectionAlignment:            dd 0x00001000   ; alinhamento de cada uma das seções (4kB)
FileAlignment:               dd 0x00000200   ; alinhamento das seções no arquivo em disco (512 B)
MajorOperatingSystemVersion: dw 0x0004       ; 
MinorOperatingSystemVersion: dw 0x0000       ; 
MajorImageVersion:           dw 0x0004       ; 
MinorImageVersion:           dw 0x0000       ; 
MajorSubsystemVersion:       dw 0x0004       ; 
MinorSubsystemVersion:       dw 0x0000       ; 
Win32VersionValue:           dd 0x00000000   ; 
SizeOfImage:                 dd 0x000041D8   ; Tamanho carregado na memória. Incluindo todos os cabeçalhos. Multiplo de "SectionAlignment"
SizeOfHeaders:               dd 0x00000600   ; Sum of size of the DOS Header, PE Header and Object Table
CheckSum:                    dd 0x00000000   ; only for trusted services
Subsystem:                   dw 0x0002       ; 00 An unknown subsystem
                                             ; 01 Device drivers and native Windows processes
                                             ; 02 The Windows graphical user interface (GUI) subsystem
                                             ; 03 The Windows character subsystem (a consele app)
                                             ; 07 The Posix character subsystem
                                             ; 09 Windows CE
                                             ; 10 An Extensible Firmware Interface (EFI) application
                                             ; 11 An EFI driver with boot services
                                             ; 12 An EFI driver with run-time services
                                             ; 13 An EFI ROM image
                                             ; 14 XBOX
                                             ;
DllCharacteristics:          dw 0x0000       ; 0x0001 Reserved, must be zero. Call when DLL is 
                                             ;        first loaded into a process's address space
                                             ; 0x0002 SECTION_HEADERReserved, must be zero. Call when a thread terminates
                                             ; 0x0004 Reserved, must be zero. Call when a thread starts up
                                             ; 0x0008 Reserved, must be zero. Call when DLL exits
                                             ; 0x0040 DLL can be relocated at load time.
                                             ; 0x0Config080 Code Integrity checks are enforced.
                                             ; 0x0100 Image is NX compatible.
                                             ; 0x0200 Isolation aware, but do not isolate the image.
                                             ; 0x0400 Does not use structured exception (SE) handling. 
                                             ;        No SE handler may be called in this image.
                                             ; 0x0800 Do not bind the image.
                                             ; 0x1000 Reserved, must be zero.
                                             ; 0x2000 A WDM driver.
                                             ; 0x8000 Terminal Server aware.
                                             ;
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
DATA_DIRECTORY: ; Contém o Relative Virtual Address of tables.

ExportVirtualAddress:        dd 0x00000000   ;
ExportSize:                  dd 0x00000000   ;

ImportVirtualAddress:        dd 0x00002018   ;
ImportSize:                  dd 0x0000003c   ;

ResourceVirtualAddress:      dd 0x00004000   ;
ResourceSize:                dd 0x000001d8   ;

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

IATVirtualAddress:           dd 0x00002000   ;
IATSize:                     dd 0x00000018   ;

DelayVirtualAddress:         dd 0x00000000   ;
DelaySize:                   dd 0x00000000   ;

CLRVirtualAddress:           dd 0x00000000   ;
CLRSize:                     dd 0x00000000   ;

ReservedVirtualAddress:      dd 0x00000000   ;
ReservedSize:                dd 0x00000000   ;

