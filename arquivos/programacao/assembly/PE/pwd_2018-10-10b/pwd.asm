# clear ; rm -f ./pwd.exe && as --64 -o pwd.o pwd.asm && objcopy -O binary pwd.o pwd.exe && diff -q -s pwd.exe pwd_orig.exe 

# nc -vv -n -l -p 8080 < pwd.exe 
# objdump -d -M intel --wide pwd.exe | tr '\t' ';' | sed '1,7d; s/^\([^;]*\);\([^;]*\);\([^;]*\)$/\3                              \1 \2/; s/^\(.\{1,33\}\) */\1# /; s/ *$//'

.intel_syntax noprefix

.text

.include "1_HEADER_DOS.asm"

.include "2_HEADER_NT.asm"

.include "3_HEADER_SECTION.asm"

.align 0x200, 0x00

.include "4_SECTION_text.asm"

.include "4_SECTION_rdata.asm"

.include "4_SECTION_data.asm"


