import:
OriginalFirstThunk_kernel32:             dd THUNK_DATA32_orig ; RVA to original unbound IAT
TimeDateStamp_kernel32:                  dd 0x00000000     ; 0 if not bound, -1 if bound, and real date\time stamp
ForwarderChain_kernel32:                 dd 0xFFFFFFFF     ; -1 if no forwarders
Name_kernel32:                           dd DllName        ; RVA to DLL name
FirstThunk_kernel32:                     dd THUNK_DATA32   ; RVA to IAT (if bound this IAT has actual addresses)

OriginalFirstThunk_terminador:  dd 0x00000000 ; 
TimeDateStamp_terminador:       dd 0x00000000 ; 
ForwarderChain_terminador:      dd 0x00000000 ; 
Name_terminador:                dd 0x00000000 ; 
FirstThunk_terminador:          dd 0x00000000 ; 

DllName:                        db "kernel32.dll", 0x00
align   0x04,db 0x00

THUNK_DATA32_orig:
AddressOfData_WriteConsoleA_orig:    dd 0x00000230  ; RVA to function name "WriteConsoleA"
AddressOfData_GetStdHandle_orig:     dd 0x00000240  ; RVA to function name "GetStdHandle"
AddressOfData_terminator_orig:       dd 0x00000000  ; 

THUNK_DATA32:
AddressOfData_WriteConsoleA:    dd 0x00000230  ; RVA to function name "WriteConsoleA"
AddressOfData_GetStdHandle:     dd 0x00000240  ; RVA to function name "GetStdHandle"
AddressOfData_terminator:       dd 0x00000000  ; 

IMPORT_BY_NAME:
Hint_WriteConsoleA:             dw 0x0001 ;
Name_WriteConsoleA:             db "WriteConsoleA", 0x00 ;

Hint_GetStdHandle:              dw 0x0002 ;
Name_GetStdHandle:              db "GetStdHandle", 0x00 ;

align   0x20,db 0x00

import_size equ $ - import

