   .data
   .globl ret_point     ; ret_point:     .long 0x00000000;
   .globl protstack     ; protstack:     .long 0x2000 - 0x10;
   .globl current_drive ; current_drive: .long 0x00000000;
   
   .text

   .code16
   .intel_syntax noprefix

// start symbols here just to force ld quiet.
   .globl   main, start, _start
start:
_start:
main:               // "main" is loaded at 0x0000:0x2000 in stage2.
   cli
   
   xor    ax, ax
   mov    ds, ax
   mov    ss, ax
   mov    es, ax
   
   mov    ebp, 0x1000
   mov    esp, ebp
   
   sti
   
   data32 call real_to_prot
   .code32
   
   mov    current_drive, edx
   
   call   mainc
   
   call   stop

