# clear ; rm -f ./hello-fasm.exe && as --64 -o hello-fasm.o hello-fasm.asm && objcopy -O binary hello-fasm.o hello-fasm.exe && nc -N -l -p 8080 < hello-fasm.exe 
# objdump -d -M intel --wide hello-fasm.exe | tr '\t' ';' | sed '1,7d; s/^\([^;]*\);\([^;]*\);\([^;]*\)$/\3                              \1 \2/; s/^\(.\{1,33\}\) */\1# /; s/ *$//'

.intel_syntax noprefix

.text

.include "1_HEADER_DOS.asm"

.include "2_HEADER_NT.asm"

.include "3_HEADER_SECTION.asm"

.align 0x200, 0x00

.include "4_SECTION_text.asm"

.include "4_SECTION_idata.asm"

