; clear ; rm 4_SECTION_text.bin teste-orig.bin ; /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o 4_SECTION_text.bin 4_SECTION_text.asm && dd if=testes.exe of=teste-orig.bin bs=1 skip=$((0x400)) count=$(echo $(wc -c 4_SECTION_text.bin) | cut -d' ' -f1) conv=notrunc && echo "" && diff -s 4_SECTION_text.bin teste-orig.bin ; if [ $? -ne 0 ] ; then hexdump -C 4_SECTION_text.bin > 4_SECTION_text.bin.txt ; echo "" >> 4_SECTION_text.bin.txt ; hexdump -C teste-orig.bin >> 4_SECTION_text.bin.txt ; gedit 4_SECTION_text.bin.txt ; else echo "" ; fi

; /media/SD/www/linguas/Assembly/compiladores/NASM/ndisasm.elf -b 32 -o $((0x00401000)) -e $((0x400)) testes.exe > teste_text.asm

; echo -e -n \\x89\\xe5\\x8b\\xec > teste.bin && /media/SD/www/linguas/Assembly/compiladores/NASM/ndisasm.elf -b 32 teste.bin > teste2.asm
; echo -e -n \\x33\\xc0\\x31\\xc0 > teste.bin && /media/SD/www/linguas/Assembly/compiladores/NASM/ndisasm.elf -b 32 teste.bin > teste2.asm

BITS 32
ORG 0x00401000

x00401000:

push byte 0x00
call dword x00401076  ; kernel32.GetModuleHandleA
mov [0x00403000],eax

push byte 0x00                  ; Param
push dword 0x0040102b           ; 
push byte 0x00                  ; Owner
push dword 0x03e9               ; Template
push dword [dword 0x00403000]   ; Inst
call dword x00401064            ; user32.DialogBoxParamA

push eax                        ; ExitCode
call dword x00401070            ; kernel32.ExitProcess

x0040102b:
push ebp
dw 0xEC8B                      ; mov ebp,esp  pode ser 89E5 ou 8BEC
cmp dword [ebp+0x0c],0x0111
jnz x0040104D
mov eax,[ebp+0x10]
cmp eax,0x03ea
jnz x0040105D

push byte 0x00         ; Result
push dword [ebp+0x8]   ; Wnd
call dword x0040106A   ; user32.EndDialog

jmp short x0040105D

x0040104D:
cmp dword [ebp+0x0c],byte 0x10
jnz x0040105D

push byte 0x00         ; Result
push dword [ebp+0x8]   ; Wnd
call dword x0040106A   ; user32.EndDialog

x0040105D:
dw  0xC033 ; xor eax,eax pode der 33C0 ou 31C0
leave
ret 0x10
int3

x00401064: jmp dword near [dword 0x00402010]
x0040106A: jmp dword near [dword 0x0040200c]
x00401070: jmp dword near [dword 0x00402004]
x00401076: jmp dword near [dword 0x00402000]

align   0x200,db 0          ; pad with 0s rather than NOPs

