

; Exemplo 2
;
; limpa a tela
; passagem de parâmetros por linha de Comando
; imprime o que foi passado
; muda de linha
;
; os parâmetros são pegos do stack
;
;
; compilar com : nasm -f elf prog.s
; linkar com   : ld -s -o prog prog.o
;
;        align=0

Section .text
Global   _start

line:
db 0x0a
lenline equ $ - line

clrs:
db 0x08
clslen  equ $ - clrs

clrs2:
db 0x54
clslen2  equ $ - clrs

_start:

                mov eax, 4             ; write
                mov ebx, 1             ; stdout [fd]
                mov ecx, clrs        
                mov edx, clslen
                int 0x80                  ; syscall

; início do processamento

                pop eax  ; testa argc, para verificar se existem parametros
                dec eax  ; 
                jz  exit ; se não existem, sai do programa
                pop ecx
                                               ; note q argv [0] é sempre o nome do programa.
                                               ; como não queremos que ele apareça,
                                               ; faremos o stackpointer andar [o índice do stack] até argv [1]

mainloop:     ; Loop executado até que todos os argumentos sejam impressos

                pop ecx   ; pega parametro
                or  ecx, ecx             ; testa se é zero [NULL]
                jz exit    ; ecx        ; goto exit

                mov esi, ecx
                xor edx, edx

strlen:
                inc edx                   ; esta é uma versão simples de strlen, que conta cada caractere
                lodsb
                or al, al
                jnz strlen
                dec edx

                mov eax, 4             ; write
                mov ebx, 1             ; stdout
                int 0x80                  ; syscall

; pula linha após escrever

                mov eax, 4
                mov ebx, 1
                mov ecx,  line
                mov edx, lenline
                int 0x80

                jmp mainloop     ; continua

exit:
                mov eax, 1          ; final do programa
                int 0x80               ; syscall
;
; Fim do código

