BITS 32

text:
push      byte 0x00
push      _written
push      byte 0x0d
push      hello_string
push      byte -0x0B  ; 0xF5 = -0x0B
call dword near [dword cs: 0x00100000 + AddressOfData_GetStdHandle ] ; 
push      eax
call dword near [dword cs: 0x00100000 + AddressOfData_WriteConsoleA ] ; 
ret       

align   0x20,db 0x00

text_size equ $ - text


