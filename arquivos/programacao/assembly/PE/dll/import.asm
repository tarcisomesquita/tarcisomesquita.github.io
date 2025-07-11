; int main() { return 42; }

; /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o import.exe import.asm 
; @echo off & import.exe & echo %errorlevel% & echo on

BITS 32

DOS_HEADER:
e_magic:                    dw "MZ"         ; Magic number
e_cblp:                     dw 0x0000       ; Bytes on last page of file
e_cp:                       dw 0x0000       ; Pages in file
e_crlc:                     dw 0x0000       ; Relocations
e_cparhdr:                  dw 0x0000       ; Size of header in paragraphs
e_minalloc:                 dw 0x0000       ; Minimum extra paragraphs neededNumberOfSections:            dw 0x0001       ; número de seções contidas no aplicativo (entradas em SECTION_HEADER)

e_maxalloc:                 dw 0x0000       ; Maximum extra paragraphs needed
e_ss:                       dw 0x0000       ; Initial (relative) SS value
e_sp:                       dw 0x0000       ; Initial SP value
e_csum:                     dw 0x0000       ; Checksum
e_ip:                       dw 0x0000       ; Initial IP value
e_cs:                       dw 0x0000       ; Initial (relative) CS value
e_lfarlc:                   dw 0x0000       ; File address of relocation table
e_ovno:                     dw 0x0000       ; Overlay number
e_res:             times  4 dw 0x0000       ; Reserved words
e_oemid:                    dw 0x0000       ; OEM identifier (for e_oeminfo)
e_oeminfo:                  dw 0x0000       ; OEM information; e_oemid specific
e_res2:            times 10 dw 0x0000       ; Reserved words
e_lfanew:                   dd Signature    ; offset ( posição ) no arquivo do cabeçalho WIN (exe).

NT_HEADER:
Signature:                   dd "PE"

FILE_HEADER:
Machine:                     dw 0x014C       ; Intel 386
NumberOfSections:            dw 0x0001       ; número de seções contidas no aplicativo
TimeDateStamp:               dd 0x00000000   ; the time it was linked
PointerToSymbolTable:        dd 0x00000000   ; 
NumberOfSymbols:             dd 0x00000000   ; 
SizeOfOptionalHeader:        dw 0x00E0       ; the size of the optional header
Characteristics:             dw 0x0103       ; indica se o arquivo é um EXE, DLL ou OCX. (no relocations, executable, 32 bit)

OPTIONAL_HEADER32:
Magic:                       dw 0x010B       ; PE32
MajorLinkerVersion:          db 0x00         ; 
MinorLinkerVersion:          db 0x00         ; 
SizeOfCode:                  dd codesize     ;
SizeOfInitializedData:       dd 0x00000000   ; 
SizeOfUninitializedData:     dd 0x00000000   ; 
AddressOfEntryPoint:         dd code         ; endereço RVA (Relative Virtual Address) da primeira instrução a ser executada
BaseOfCode:                  dd code         ; 
BaseOfData:                  dd filesize     ; 
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
SizeOfImage:                 dd filesize     ; Tamanho total do arquivo PE após carregado na memória
SizeOfHeaders:               dd hdrsize      ; 
CheckSum:                    dd 0x00000000   ; 
Subsystem:                   dw 0x0002       ; Win32 GUI
DllCharacteristics:          dw 0x0000       ; 
SizeOfStackReserve:          dd 0x00100000   ; 
SizeOfStackCommit:           dd 0x00001000   ; 
SizeOfHeapReserve:           dd 0x00100000   ; 
SizeOfHeapCommit:            dd 0x00001000   ; 
LoaderFlags:                 dd 0x00000000   ; 
NumberOfRvaAndSizes:         dd 0x00000010   ; especifica o número de diretório de dados

DATA_DIRECTORY:
ExportVirtualAddress:        dd 0x00000000   ; 
ExportSize:                  dd 0x00000000   ; 

ImportVirtualAddress:        dd idata        ; 
ImportSize:                  dd idatasize    ; 

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


db ".text", 0, 0, 0           ; Name
dd codesize                   ; VirtualSize
dd hdrsize                    ; VirtualAddress
dd codesize                   ; SizeOfRawData
dd code                       ; PointerToRawData
dd 0                          ; PointerToRelocations UNUSED
dd 0                          ; PointerToLinenumbers UNUSED
dw 0                          ; NumberOfRelocations UNUSED
dw 0                          ; NumberOfLinenumbers UNUSED
dd 0x60000020                 ; Characteristics (code, execute, read) UNUSED

hdrsize equ $ - $$

code:
push byte 42
pop eax
ret

; Import table (array of IMAGE_IMPORT_DESCRIPTOR structures)
idata:
dd ilt                                    ; OriginalFirstThunk UNUSED
dd 0                                      ; TimeDateStamp UNUSED
dd 0                                      ; ForwarderChain UNUSED
dd kernel32                               ; Name
dd iat                                    ; FirstThunk

; empty IMAGE_IMPORT_DESCRIPTOR structure
dd 0                                      ; OriginalFirstThunk UNUSED
dd 0                                      ; TimeDateStamp UNUSED
dd 0                                      ; ForwarderChain UNUSED
dd 0                                      ; Name UNUSED
dd 0                                      ; FirstThunk

idatasize equ $ - idata


; Loader read the ordinal from the lookup table and replace the entry in the address table with the function address.

iat:
; Import Address Table. (IMAGE_THUNK_DATA structures)
dd 0x80000001                             ; Import function 1 by ordinal
dd 0

; Import Lookup Table. (IMAGE_THUNK_DATA structures)
ilt:
dd 0x80000001                             ; Import function 1 by ordinal
dd 0

kernel32:
db "KERNEL32.dll", 0


codesize equ $ - code
filesize equ $ - $$

