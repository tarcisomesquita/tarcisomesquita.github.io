
;  $ /media/SD/www/programacao/Assembly/compiladores/NASM/nasm.elf -f bin -o tdebug.elf tdebug.asm ; chmod +x tdebug.elf ; ./tdebug.elf



                            BITS 32

                            org 0x08048000

ehdr:

e_ident_0_3:                db 0x7F, "ELF"  ;
e_ident_4:                  db 0x01         ; 32-bit objects
e_ident_5:                  db 0x01         ; Litle Endian
e_ident_6:                  db 0x01         ; Current version
e_ident_7:                  db 0x00         ; unspecified OS
e_ident_8:          times 8 db 0x00         ; não é usado
e_type:                     dw 0x0002       ; Executable file
e_machine:                  dw 0x0003       ; Intel 80386
e_version:                  dd 0x00000001   ; Current version
e_entry:                    dd _start       ; onde começam as instruções ; 54 80 04 08
e_phoff:                    dd phdr - $$    ; File offset in bytes of Program Header table
e_shoff:                    dd shdr - $$    ; File offset in bytes of Section Header table
e_flags:                    dd 0x00000000   ; The 32-bit Intel Architecture defines no flags
e_ehsize:                   dw 0x0034       ; Tamanho do Elf Header
e_phentsize:                dw 0x0020       ; Tamanho de uma linha da tabela Program Header
e_phnum:                    dw 0x0001       ; Quantas linhas tem a tabela Program Header.
e_shentsize:                dw 0x0028       ; Tamanho de uma linha da tabela Section Header
e_shnum:                    dw 0x0000       ; Quantas linhas tem a tabela Section Header.
e_shstrndx:                 dw 0x0002       ; Qual linha da tabela Section Header contém o offset da Section .shstrtab


phdr:

p_type____1:                dd 0x00000001   ; loadable segment
p_offset__1:                dd _start - $$  ; offset from the beginning of the file at which the first byte of segment reside.
p_vaddr___1:                dd _start       ; virtual adress at which the first byte of segment resides in memory.
p_paddr___1:                dd _start       ; Reserved for segment's physical address
p_filesz__1:                dd loadsize     ; how many bytes to load of the file into memory
p_memsz___1:                dd loadsize     ; how large the memory segment needs to be
p_flags___1:                dd 0x00000005   ; what permissions to give the memory segment (1=executar, 2=escrever, 4=ler)
p_align___1:                dd 0x00001000   ; alignment requirements for the memory segment


shdr: ; Desativado. Está aqui apenas para marcar o lugar da Section Header table.



_start:    ; the program start here

%include "estado_inicial.asm"

;                            mov bl, 45
;                            xor eax, eax
;                            inc eax
;                            int 0x80

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

; codigo teste

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

; escreve os registradores

PUSHA ; Push AX, CX, DX, BX, original SP, BP, SI, and DI.
PUSHF
PUSH CS
PUSH DS
PUSH SS
PUSH ES
PUSH FS
PUSH dados


MOV ECX, qlinha
CALL imprime_uma_letra
CALL imprime_linha
MOV ECX, qlinha
CALL imprime_uma_letra
CALL imprime_uma_letra

MOV ECX, [ESP]
CALL imprime_cabeca   ; CS
POP EAX
PUSH ESI
MOV  EDX, [ESP+20]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; EAX
POP EAX
PUSH ESI
MOV  EDX, [ESP+56]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; ESP
POP EAX
PUSH ESI
MOV  EDX, [ESP+40]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 23 res
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,23
JC    bit23
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next23
bit23:
MOV ECX, um
CALL imprime_uma_letra
next23:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 15 res
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,15
JC    bit15
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next15
bit15:
MOV ECX, um
CALL imprime_uma_letra
next15:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 7 res
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,7
JC    bit7
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next7
bit7:
MOV ECX, um
CALL imprime_uma_letra
next7:


MOV ECX, [ESP]
CALL imprime_cabeca   ; DS
POP EAX
PUSH ESI
MOV  EDX, [ESP+16]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; ECX
POP EAX
PUSH ESI
MOV  EDX, [ESP+52]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; EBP
POP EAX
PUSH ESI
MOV  EDX, [ESP+36]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 22 res
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,22
JC    bit22
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next22
bit22:
MOV ECX, um
CALL imprime_uma_letra
next22:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 14 NT
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,14
JC    bit14
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next14
bit14:
MOV ECX, um
CALL imprime_uma_letra
next14:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 6 ZF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,6
JC    bit6
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next6
bit6:
MOV ECX, um
CALL imprime_uma_letra
next6:


MOV ECX, [ESP]
CALL imprime_cabeca   ; SS
POP EAX
PUSH ESI
MOV  EDX, [ESP+12]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; EDX
POP EAX
PUSH ESI
MOV  EDX, [ESP+48]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; ESI
POP EAX
PUSH ESI
MOV  EDX, [ESP+32]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 21 ID
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,21
JC    bit21
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next21
bit21:
MOV ECX, um
CALL imprime_uma_letra
next21:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 13 IO
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,13
JC    bit13
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next13
bit13:
MOV ECX, um
CALL imprime_uma_letra
next13:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 5 res
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,5
JC    bit5
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next5
bit5:
MOV ECX, um
CALL imprime_uma_letra
next5:


MOV ECX, [ESP]
CALL imprime_cabeca   ; ES
POP EAX
PUSH ESI
MOV  EDX, [ESP+8]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; EBX
POP EAX
PUSH ESI
MOV  EDX, [ESP+44]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; EDI
POP EAX
PUSH ESI
MOV  EDX, [ESP+28]
CALL ror

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 20 VIP
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,20
JC    bit20
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next20
bit20:
MOV ECX, um
CALL imprime_uma_letra
next20:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 12 IO
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,12
JC    bit12
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next12
bit12:
MOV ECX, um
CALL imprime_uma_letra
next12:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 4 AF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,4
JC    bit4
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next4
bit4:
MOV ECX, um
CALL imprime_uma_letra
next4:


MOV ECX, [ESP]
CALL imprime_cabeca   ; FS
POP EAX
PUSH ESI
MOV  EDX, [ESP+4]
CALL ror



MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 19 VIF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,19
JC    bit19
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next19
bit19:
MOV ECX, um
CALL imprime_uma_letra
next19:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 11 OF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,11
JC    bit11
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next11
bit11:
MOV ECX, um
CALL imprime_uma_letra
next11:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 3 res
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,3
JC    bit3
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next3
bit3:
MOV ECX, um
CALL imprime_uma_letra
next3:


MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 18 AC
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,18
JC    bit18
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next18
bit18:
MOV ECX, um
CALL imprime_uma_letra
next18:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 10 DF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,10
JC    bit10
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next10
bit10:
MOV ECX, um
CALL imprime_uma_letra
next10:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 2 PF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,2
JC    bit2
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next2
bit2:
MOV ECX, um
CALL imprime_uma_letra
next2:


MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 17 VM
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,17
JC    bit17
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next17
bit17:
MOV ECX, um
CALL imprime_uma_letra
next17:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 9 IF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,9
JC    bit9
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next9
bit9:
MOV ECX, um
CALL imprime_uma_letra
next9:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 1 res
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,1
JC    bit1
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next1
bit1:
MOV ECX, um
CALL imprime_uma_letra
next1:



MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 16 RF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,16
JC    bit16
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next16
bit16:
MOV ECX, um
CALL imprime_uma_letra
next16:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 8 TF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,8
JC    bit8
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next8
bit8:
MOV ECX, um
CALL imprime_uma_letra
next8:

MOV ECX, [ESP]
CALL imprime_cabeca   ; bit 0 CF
POP EAX
PUSH ESI
MOV  ECX, [ESP+24]
BT    ECX,0
JC    bit0
MOV ECX, zero
CALL imprime_uma_letra
JMP SHORT next0
bit0:
MOV ECX, um
CALL imprime_uma_letra
next0:




MOV ECX, qlinha
CALL imprime_uma_letra
CALL imprime_uma_letra
CALL imprime_linha
MOV ECX, qlinha
CALL imprime_uma_letra

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
; escreve a pilha

MOV ECX, [ESP]
CALL imprime_cabeca   ; letras
POP EAX
PUSH ESI
MOV ECX, qlinha
CALL imprime_uma_letra

POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX
POP EAX

;MOV  EDX, ESP
;CALL ror

AND ESP, 0xFFFFFFF0

MOV EBP, ESP
ADD EBP, 96

outravez:

MOV  EDX, ESP
CALL ror
MOV ECX, espaco
CALL imprime_uma_letra
MOV ECX, espaco
CALL imprime_uma_letra

MOV  EDX, [ESP]
CALL ror2
MOV ECX, espaco
CALL imprime_uma_letra
MOV ECX, espaco
CALL imprime_uma_letra

MOV  EDX, [ESP+4]
CALL ror2
MOV ECX, espaco
CALL imprime_uma_letra
MOV ECX, espaco
CALL imprime_uma_letra

MOV ECX, espaco
CALL imprime_uma_letra

MOV  EDX, [ESP+8]
CALL ror2
MOV ECX, espaco
CALL imprime_uma_letra
MOV ECX, espaco
CALL imprime_uma_letra

MOV  EDX, [ESP+12]
CALL ror2

MOV ECX, espaco
CALL imprime_uma_letra

MOV ECX, espaco
CALL imprime_uma_letra

MOV ECX, espaco
CALL imprime_uma_letra


CALL imprime_caracter

ADD ESP, 4

MOV ECX, espaco
CALL imprime_uma_letra

CALL imprime_caracter

ADD ESP, 4

MOV ECX, espaco
CALL imprime_uma_letra

MOV ECX, espaco
CALL imprime_uma_letra

CALL imprime_caracter

ADD ESP, 4

MOV ECX, espaco
CALL imprime_uma_letra

CALL imprime_caracter

ADD ESP, 4

MOV ECX, qlinha
CALL imprime_uma_letra

CMP ESP, EBP
JNZ outravez

MOV ECX, qlinha
CALL imprime_uma_letra


; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


                mov ebx, 0  ; imprime 0
                mov eax, 0x00000001  ; função exit
                int 0x80    ; syscall

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

imprime_cabeca:        ; recebe o offset da string em ECX
                       ; devolve o offset da próxima string em ESI
CLD
XOR EDX,EDX
MOV ESI, ECX

stringlen:
INC EDX  
LODSB
OR AL, AL
JNZ stringlen

DEC EDX

MOV EAX, 0x00000004   ; write
MOV EBX, 0x00000001   ; stdout
INT 0x80   ; syscall

RET

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

imprime_uma_letra:

PUSHF
PUSHA

MOV EAX, 0x00000004   ; write
MOV EBX, 0x00000001   ; stdout
MOV EDX, 1   ; quantidade de caracteres
INT 0x80   ; syscall

POPA
POPF
RET
; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

imprime_caracter:

PUSHF
PUSHA

MOV ECX,[ESP+40]
AND ECX, 0x000000FF
CMP ECX, 0x20
JL pulo1
CMP ECX, 0x7E
JG pulo1
JMP SHORT pulu1
pulo1:
MOV ECX, 0x2E
pulu1:
PUSH ECX
MOV ECX,ESP
CALL imprime_uma_letra
POP ECX

MOV ECX,[ESP+41]
AND ECX, 0x000000FF
CMP ECX, 0x20
JL pulo2
CMP ECX, 0x7E
JG pulo2
JMP SHORT pulu2
pulo2:
MOV ECX, 0x2E
pulu2:
PUSH ECX
MOV ECX,ESP
CALL imprime_uma_letra
POP ECX

MOV ECX,[ESP+42]
AND ECX, 0x000000FF
CMP ECX, 0x20
JL pulo3
CMP ECX, 0x7E
JG pulo3
JMP SHORT pulu3
pulo3:
MOV ECX, 0x2E
pulu3:
PUSH ECX
MOV ECX,ESP
CALL imprime_uma_letra
POP ECX

MOV ECX,[ESP+43]
AND ECX, 0x000000FF
CMP ECX, 0x20
JL pulo4
CMP ECX, 0x7E
JG pulo4
JMP SHORT pulu4
pulo4:
MOV ECX, 0x2E
pulu4:
PUSH ECX
MOV ECX,ESP
CALL imprime_uma_letra
POP ECX

POPA
POPF
RET

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

imprime_linha:

PUSHF
PUSHA

MOV ECX, linha
MOV EAX, 0x00000004   ; write
MOV EBX, 0x00000001   ; stdout
MOV EDX, 78   ; quantidade de caracteres
INT 0x80   ; syscall

POPA
POPF
RET

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

ror:

PUSHF
PUSHA

MOV EBP, EDX

ROR   EDX,28
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,24
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,20
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,16
CALL  imprime_letra


MOV ECX, espaco
CALL  imprime_uma_letra

MOV   EDX, EBP
ROR   EDX,12
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,8
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,4
CALL  imprime_letra

MOV   EDX, EBP
CALL  imprime_letra

POPA
POPF
RET

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

ror2:

PUSHF
PUSHA

MOV EBP, EDX
ROR   EDX,4
CALL  imprime_letra

MOV   EDX, EBP
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,12
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,8
CALL  imprime_letra

MOV ECX, espaco
CALL  imprime_uma_letra

MOV   EDX, EBP
ROR   EDX,20
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,16
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,28
CALL  imprime_letra

MOV   EDX, EBP
ROR   EDX,24
CALL  imprime_letra

POPA
POPF
RET

; = = = = = = = = = = = = = = = = = = = = = =

imprime:

MOV EAX, 0x00000004   ; write
MOV EBX, 0x00000001   ; stdout
MOV EDX, 0x00000001   ; quantidade de caracteres
INT 0x80   ; syscall
RET

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

imprime_letra:

BT    EDX,0x03
JC    bits_1

BT    EDX,0x02
JC    bits_01

BT    EDX,0x01
JC    bits_001

BT    EDX,0x00
JC    bits_0001

MOV ECX, zero     ; endereço da letra a ser escrita
JMP   imprime

bits_1:
BT    EDX,0x02
JC    bits_11

BT    EDX,0x01
JC    bits_101

BT    EDX,0x00
JC    bits_1001

MOV ECX, oito
JMP   imprime


bits_01:
BT    EDX,0x01
JC    bits_011

BT    EDX,0x00
JC    bits_0101

MOV ECX, quatro
JMP   imprime


bits_001:
BT    EDX,0x00
JC    bits_0011

MOV ECX, dois
JMP   imprime


bits_0001:
MOV ECX, um
JMP   imprime


bits_0011:
MOV ECX, tres
JMP   imprime


bits_0101:
MOV ECX, cinco
JMP   imprime


bits_011:
BT    EDX,0x00
JC    bits_0111

MOV ECX, seis
JMP   imprime


bits_0111:
MOV ECX, sete
JMP   imprime


bits_1001:
MOV ECX, nove
JMP   imprime


bits_101:
BT    EDX,0x00
JC    bits_1011

MOV ECX, aa
JMP   imprime


bits_1011:
MOV ECX, be
JMP   imprime


bits_11:
BT    EDX,0x01
JC    bits_111

BT    EDX,0x00
JC    bits_1101

MOV ECX, ce
JMP   imprime


bits_1101:
MOV ECX, de
JMP   imprime


bits_111:
BT    EDX,0x00
JC    bits_1111

MOV ECX, ee
JMP   imprime


bits_1111:
MOV ECX, efe
JMP   imprime


; = = = = = = = = = = = = = = = = = = = = = =

zero:
dd 0x00000030

um:
dd 0x00000031

dois:
dd 0x00000032

tres:
dd 0x00000033

quatro:
dd 0x00000034

cinco:
dd 0x00000035

seis:
dd 0x00000036

sete:
dd 0x00000037

oito:
dd 0x00000038

nove:
dd 0x00000039

aa:
dd 0x00000041

be:
dd 0x00000042

ce:
dd 0x00000043

de:
dd 0x00000044

ee:
dd 0x00000045

efe:
dd 0x00000046

qlinha:
dd 0x0000000A

; = = = = = = = = = = = = = = = = = = = = = =

espaco:
db 0x20

linha:
db "=============================================================================="

dados:

db  "CS = ", 0x00, "   EAX = ", 0x00, "   ESP = ", 0x00, "   res= ", 0x00, "   res= ", 0x00, "   SF = ", 0x00, 0x0A, "DS = ", 0x00, \
"   ECX = ", 0x00, "   EBP = ", 0x00, "   res= ", 0x00, "   NT = ", 0x00, "   ZF = ", 0x00, 0x0A, "SS = ", 0x00, \
"   EDX = ", 0x00, "   ESI = ", 0x00, "   ID = ", 0x00, "   IO = ", 0x00, "   res= ", 0x00, 0x0A, "ES = ", 0x00, \
"   EBX = ", 0x00, "   EDI = ", 0x00, "   VIP= ", 0x00, "   IO = ", 0x00, "   AF = ", 0x00, 0x0A, "FS = ", 0x00, 0x0A, \
"                                                     VIF= ", 0x00, "   OF = ", 0x00, "   res= ", 0x00, 0x0A, \
"                                                     AC = ", 0x00, "   DF = ", 0x00, "   PF = ", 0x00, 0x0A, \
"                                                     VM = ", 0x00, "   IF = ", 0x00, "   res= ", 0x00, 0x0A, \
"                                                     RF = ", 0x00, "   TF = ", 0x00, "   CF = ", 0x00, \
"           0 1  2 3   4 5  6 7    8 9  A B   C D  E F", 0x00

; = = = = = = = = = = = = = = = = = = = = = =

loadsize equ $ - $$

