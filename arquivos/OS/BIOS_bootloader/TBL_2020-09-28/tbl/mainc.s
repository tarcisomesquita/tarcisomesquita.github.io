   .intel_syntax noprefix
   .align 4
   .section   .rodata
   teste:   .long   0x36
   .globl   len_vmlinuz; len_vmlinuz:   .long   512*2*1024*10
   .globl   len_initrd ; len_initrd:    .long   512*2*1024*40
   .globl   parameters;  parameters:    .string   "boot=casper locale=pt_BR persistent"
.PF:   .string   "%x\n"
.LC0:   .string   "> cmain()H\n"
.LC1:   .string   "lh->boot_flag != BOOTSEC_SIGNATURE\n"
.LC2:   .string   "lh->setup_sects > LINUX_MAX_SETUP_SECTS\n"
.LC3:   .string   "lh->header != LINUX_MAGIC_SIGNATURE\n"
.LC4:   .string   "lh->version < 0x0203)\n"
.LC5:   .string   "! big_linux\n"
.LC6:   .string   "! setup_sects\n"
.LC7:   .string   "data_len > len_vmlinuz || data_len < 0\n"

   .align 4
   .data
lh:          .long 0x00000000
data_len:    .long 0x00000000
setup_sects: .byte 0x00

.set  ADDRESS_X,     0x00010000
.set  LH,            ADDRESS_X + 0x01F1
.set  LH_SETUPSECTS, LH + 0x0000
.set  LH_VIDEO,      LH + 0x0009
.set  LH_BOOTFLAG,   LH + 0x000D
.set  LH_SIGNATURE,  LH + 0x0011
.set  LH_VERSION,    LH + 0x0015
.set  LH_LOADER,     LH + 0x001F
.set  LH_FLAGS,      LH + 0x0020
.set  LH_RDISK_IMG,  LH + 0x0027
.set  LH_RDISK_SIZE, LH + 0x002B
.set  LH_HEAP,       LH + 0x0030
.set  LH_CMDLINE,    LH + 0x0034


   .align 4
   .text
   .code32
   .globl   mainc
mainc:
   push   ebp
   mov    ebp, esp
   
#   push   OFFSET FLAT:.LC0
#   call   tbl_printf
#   add    esp, 4
#   call   console_getkey
   
   call   gateA20
   cmp    eax, eax
   jne    retornar
   
   call   get_diskinfo
   cmp    eax, eax
   jne    retornar

   push   ADDRESS_X
   push   1024
   push   2 + 20
   call   devread_my        # devread_my(2 + 20, 1024, (char *)ADDRESS_X);
   add    esp, 12
   
   mov    lh, DWORD PTR LH                         # lh = (struct setup_header *)(ADDRESS_X + 0x01F1);
   
   cmp    ds:LH_BOOTFLAG, WORD PTR 0xAA55          # lh->boot_flag != BOOTSEC_SIGNATURE
   je     .L5
   push   OFFSET FLAT:.LC1
   jmp    erro

.L5:
   cmp    ds:LH_SETUPSECTS, BYTE PTR 64            # lh->setup_sects > LINUX_MAX_SETUP_SECTS
   jbe    .L6
   push   OFFSET FLAT:.LC2
   jmp    erro

.L6:
   cmp    ds:LH_SIGNATURE, DWORD PTR 0x53726448    # lh->header != LINUX_MAGIC_SIGNATURE     0x53726448 = "HdrS"
   je     .L7
   push   OFFSET FLAT:.LC3
   jmp    erro

.L7:
   cmp    ds:LH_VERSION, WORD PTR 0x0203           # lh->version < 0x0203 
   jae    .L8
   push   OFFSET FLAT:.LC4
   jmp    erro

.L8:
   test   ds:LH_FLAGS, BYTE PTR 0x01               # LINUX_FLAG_BIG_KERNEL 0x01      ! (lh->loadflags & LINUX_FLAG_BIG_KERNEL)
   jnz    .L9
   push   OFFSET FLAT:.LC5
   jmp    erro

.L9:
   mov   ds:LH_VIDEO,  WORD PTR 0xFFFF                      # lh->vid_mode = 0xFFFF
   mov   ds:LH_LOADER, BYTE PTR 0xFF                        # lh->type_of_loader = 0xFF; // 0xFF = undefined
   mov   ds:LH_HEAP,   WORD PTR 0x10000 - 0x200 # lh->heap_end_ptr = 10000 - 0x200  < --- VER ISSO
   mov   ds:LH_FLAGS,  BYTE PTR 0x80 | 0x00 | 0x00 | 0x01   # lh->loadflags = 0x80 | 0x00 | 0x00 | 0x01;
   mov   ds:LH_CMDLINE, WORD PTR OFFSET FLAT: parameters    # lh->cmd_line_ptr = parameters; 0x2860
   mov   [ADDRESS_X + 0x10000], DWORD PTR 0x00000000
   
   mov    al, BYTE PTR ds:LH_SETUPSECTS
   cmp    al, 0x00                      # if (! setup_sects) { tbl_printf("! setup_sects\n"); return; }
   jne    .L17
   push   OFFSET FLAT:.LC6
   jmp    erro

.L17:
   inc    al                    #    setup_sects++;  // parece que a contagem do setup_sects começa do zero

   mov    setup_sects, al
   
               #   if (data_len > len_vmlinuz || data_len < 0) { tbl_printf("data_len > len_vmlinuz || data_len < 0\n"); return; }
   movzx  eax, al   

   sal    eax, 9          #   data_len = setup_sects << 9;
   mov    data_len, eax
   
   cmp    eax, [len_vmlinuz]
   jbe    .L16
   push   OFFSET FLAT:.LC7

erro:
   call   tbl_printf
   add   esp, 4
   jmp   retornar

.L16:
   push   ADDRESS_X + 1024           # devread_my(2 + 20 + 1024/0x200, (int)(data_len - 1024), (char *)(ADDRESS_X + 1024));
   mov    eax, [data_len]
   sub    eax, 1024
   push   eax
   push   2 + 20 + 1024/0x200
   call   devread_my
   add    esp, 12

   push   0x00100000                 # devread_my(2 + 20 +  data_len/0x200, len_vmlinuz - data_len, (char *)LINUX_BZIMAGE_ADDR);
   mov    eax, [data_len]
   mov    edx, [len_vmlinuz]
   sub    edx, eax
   push   edx
   shr    eax, 9
   add    eax, 22
   push   eax
   call   devread_my
   add    esp, 12
   
   mov   eax, [len_vmlinuz]          # lh->ramdisk_image = LINUX_BZIMAGE_ADDR + len_vmlinuz;
   add   eax, 0x00100000       
   mov   ds:LH_RDISK_IMG, eax
   
   mov   eax,  [len_initrd]
   mov   ds:LH_RDISK_SIZE, eax       # lh->ramdisk_size  = len_initrd;
   
   push   [ds:LH_RDISK_IMG]                       # devread_my(2 + 20 + 2*10*1024, len_initrd, (char *)lh->ramdisk_image);
   push   [len_initrd]
   push   2 + 20 + 2*1024*10
   call   devread_my
   add   esp, 12

   leave
   jmp   big_linux_boot
   
retornar:
   leave
   ret

