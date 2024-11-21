# clear ; rm -f ./teste.o && as --64 -o teste.o teste.asm && objdump -d -M intel --wide teste.o | tr '\t' ';' | sed '1,7d; s/^\([^;]*\);\([^;]*\);\([^;]*\)$/\3                              \1 \2/; s/^\(.\{1,33\}\) */\1# /; s/ *$//'

.intel_syntax noprefix

.text

.quad 1


