.386 
.model flat, stdcall 
option casemap:none 
include \masm32\include\windows.inc 
include \masm32\include\kernel32.inc 
includelib \masm32\lib\kernel32.lib 
include \masm32\include\user32.inc 
includelib \masm32\lib\user32.lib 
.data 
    aap db "Fergonez",0
    piet db "Encontre o texto mocado!",0
    aap2 db "Texto mocado",0
    piet2 db "Parabéns, você o encontrou!",0
.data?
.code 
start:
    SUB eax, eax
begin:
    CMP eax, 0
    JE mof
    LEA eax, piet2
    LEA ebx, piet2
    JMP mess
mof:
    LEA eax, aap
    LEA ebx, piet
mess:
    PUSH 0
    PUSH eax
    PUSH ebx
    PUSH 0
    CALL MessageBox
    exit:
    invoke ExitProcess, 0   
end start 