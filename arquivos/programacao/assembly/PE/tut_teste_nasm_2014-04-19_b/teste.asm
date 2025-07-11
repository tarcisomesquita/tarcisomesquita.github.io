; clear ; rm teste.bin teste-orig.bin ; /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o teste.bin teste.asm && dd if=testes.exe of=teste-orig.bin bs=1 count=$(echo $(wc -c teste.bin) | cut -d' ' -f1) conv=notrunc && echo "" && diff -s teste.bin teste-orig.bin ; if [ $? -ne 0 ] ; then hexdump -C teste.bin > teste.bin.txt ; echo "" >> teste.bin.txt ; hexdump -C teste-orig.bin >> teste.bin.txt ; gedit teste.bin.txt ; else echo "" ; fi

; echo -e -n \\x4e > teste.bin && dd if=teste.bin of=testes.exe bs=1 seek=$((0x43)) conv=notrunc

; echo -e -n \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00 >  teste.bin
; echo -e -n \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00 >> teste.bin
; echo -e -n \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00 >> teste.bin
; echo -e -n \\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00\\x00 >> teste.bin
; dd if=teste.bin of=testes.exe bs=1 seek=$((0x80)) conv=notrunc

; echo -e -n \\x02 > teste.bin && dd if=teste.bin of=testes.exe bs=1 seek=$((0xd6)) conv=notrunc

; echo -e -n \\x00\\x00\\x00\\x00 > teste.bin && dd if=teste.bin of=testes.exe bs=1 seek=$((0x118)) conv=notrunc

%include "1_HEADER_DOS.asm"
%include "2_HEADER_NT.asm"
%include "3_HEADER_SECTION.asm"
;%include "testes-section-txt.asm"
; %include "4_SECTION_text.asm"

