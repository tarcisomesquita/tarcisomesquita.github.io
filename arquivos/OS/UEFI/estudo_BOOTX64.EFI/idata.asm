idata_i:
ImportTable:
OFT_msvcrt.dll:                     .long msvcrt.dll__write - idata_i + 0x2000     # 0x0400 
Date_msvcrt.dll:                    .long 0x00000000     # 0x0404 
Chain_msvcrt.dll:                   .long 0x00000000     # 0x0408 
Name_msvcrt.dll:                    .long _msvcrt.dll - idata_i + 0x2000     # 0x040C 
FT_msvcrt.dll:                      .long _msvcrt.dll__write - idata_i + 0x2000    # 0x0410 

OFT_null:                           .long 0x00000000     # 0x0414 
Date_null:                          .long 0x00000000     # 0x0418 
Chain_null:                         .long 0x00000000     # 0x041C 
Name_null:                          .long 0x00000000     # 0x0420 
FT_null:                            .long 0x00000000     # 0x0424 

trunk_msvcrt.dll:            
msvcrt.dll__write:                  .long msvcrt.dll__write_Hint - idata_i + 0x2000     # 0x0428
msvcrt.dll_null:                    .long 0x00000000     # 0x042C

.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

_trunk_msvcrt.dll:            
_msvcrt.dll__write:                  .long msvcrt.dll__write_Hint - idata_i + 0x2000     # 0x0428
_msvcrt.dll_null:                    .long 0x00000000     # 0x042C

# Nome das bibliotecas
_msvcrt.dll:                 .string "msvcrt.dll"          # 0x0458
.align 0x8, 0x00

msvcrt.dll__write_Hint:           .word 0x03D8                      # 0x0448
msvcrt.dll__write_Name:           .string "_write"                  # 0x044A

.align 0x200, 0x00
idata_f:

