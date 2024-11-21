# clear ; rm -f ./write.exe && as --64 -o 0_include.o 0_include.asm && objcopy -O binary 0_include.o write.exe ; rm 0_include.o 

.intel_syntax noprefix

.text

.include "header.asm"
.align 0x200, 0x00

.include "text.asm"

.include "idata.asm"

