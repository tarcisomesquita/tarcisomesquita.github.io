extern void tbl_printf(const char *format,...);
extern int console_getkey(void);

extern int gateA20(void);
extern int get_diskinfo();
extern int devread_my(int sector, int byte_len, char *buf);

extern int big_linux_boot();

#include "struct_setup_header.c"

   unsigned int len_initrd  = 512*2*40*1024;
   unsigned int len_vmlinuz = 512*2*10*1024;
   char parameters[] = "boot=casper locale=pt_BR persistent"; // for no parameters, an empty string (or better yet, to the string "auto".)
   unsigned char setup_sects;
   unsigned int data_len = 0;
   struct setup_header *lh;

/*
          ~                        ~
          |  Protected-mode kernel |
00100000  +------------------------+
          |  I/O memory hole       |
   A0000  +------------------------+
          |  Reserved for BIOS     |   Leave as much as possible unused
          ~                        ~
          |  Command line          |
   20000  +------------------------+  X+10000
          |  Stack/heap            |     For use by the kernel real-mode code.
   18000  +------------------------+  X+08000
          |  Kernel setup          |     The kernel real-mode code.
          |  Kernel boot sector    |     The kernel legacy boot sector.
   10000  +------------------------+  X
          |        FREE            |
   0D000  +------------------------+
          |  cache do devread_my.c |
   05000  +------------------------+
          |  stage 2               |
   02000  +------------------------+
          |  Stack protectec mode  |
   01000  +------------------------+
          |  Stack real mode       |
   00600  +------------------------+ 
          |  BIOS use only         |
   00000  +------------------------+

... where the address X is as low as the design of the boot loader permits.
*/

#define ADDRESS_X 0x00010000


void mainc(void) {
   
   tbl_printf("> cmain()\n"); console_getkey();
   
   // We need to call this somewhere before trying to put data above 1 MB, since without calling it, address line 20 will be wired to 0.
   if(gateA20()) return;
   
   if(get_diskinfo()) return;
   
   devread_my(2 + 20, 1024, (char *)ADDRESS_X);
   
   lh = (struct setup_header *)(ADDRESS_X + 0x01F1);
   
   #define BOOTSEC_SIGNATURE 0xAA55
   if (lh->boot_flag != BOOTSEC_SIGNATURE) { tbl_printf("lh->boot_flag != BOOTSEC_SIGNATURE\n"); return;}
   
   #define LINUX_MAX_SETUP_SECTS 64
   if (lh->setup_sects > LINUX_MAX_SETUP_SECTS) { tbl_printf("lh->setup_sects > LINUX_MAX_SETUP_SECTS\n"); return;}
   
   #define LINUX_MAGIC_SIGNATURE 0x53726448 // "HdrS"
   if (lh->header != LINUX_MAGIC_SIGNATURE) { tbl_printf("lh->header != LINUX_MAGIC_SIGNATURE\n"); return;}
   
   if (lh->version < 0x0203) { tbl_printf("lh->version < 0x0203)\n");return;}
   
   #define LINUX_FLAG_BIG_KERNEL 0x1
   if (! (lh->loadflags & LINUX_FLAG_BIG_KERNEL)) { tbl_printf("! big_linux\n"); return; }
   
   lh->vid_mode = 0xFFFF; // "normal" (meaning 0xFFFF), "ext" (meaning 0xFFFE) or "ask" (meaning 0xFFFD).
   
   lh->type_of_loader = 0xFF; // 0xFF = undefined
   
   lh->heap_end_ptr = 10000 - 0x200; // o - 0x200 é exigido em linux-3.17.4/Documentation/x86/boot.txt
   
   lh->loadflags = 0x80 | 0x00 | 0x00 | 0x01;
/*
  This field is a bitmask.

  Bit 0 (read):	LOADED_HIGH
	- If 0, the protected-mode code is loaded at 0x00010000.
	- If 1, the protected-mode code is loaded at 0x00100000.

  Bit 5 (write): QUIET_FLAG
	- If 0, print early messages.
	- If 1, suppress early messages.

  Bit 6 (write): KEEP_SEGMENTS
	- If 0, reload the segment registers in the 32bit entry point.
	- If 1, do not reload the segment registers in the 32bit entry point.
		Assume that %cs %ds %ss %es are all set to flat segments with a base of 0 (or the equivalent for their environment).

  Bit 7 (write): CAN_USE_HEAP
	Set this bit to 1 to indicate that the value entered in the heap_end_ptr is valid.
        If this field is clear, some setup code functionality will be disabled.
*/
   
   lh->cmd_line_ptr = (unsigned int)(ADDRESS_X + 0x10000);
   {
      char *src;
      char *dest;
      
      src = parameters;
      dest = (char *)lh->cmd_line_ptr;
      
      while (dest < (char *)lh->cmd_line_ptr + 0xFF && *src) *(dest++) = *(src++);
      
      *dest = 0;
   }
   
   setup_sects = lh->setup_sects;
   if (! setup_sects) { tbl_printf("! setup_sects\n"); return; }
   
   setup_sects++;                // parece que a contagem do setup_sects começa do zero
   data_len = setup_sects << 9;
   if (data_len > len_vmlinuz || data_len < 0) { tbl_printf("data_len > len_vmlinuz || data_len < 0\n"); return; }
   
   devread_my(2 + 20 + 1024/0x200, (int)(data_len - 1024), (char *)(ADDRESS_X + 1024));
   
   #define LINUX_BZIMAGE_ADDR 0x00100000
   devread_my(2 + 20 +  data_len/0x200, len_vmlinuz - data_len, (char *)LINUX_BZIMAGE_ADDR);
   
   lh->ramdisk_size  = len_initrd;
   lh->ramdisk_image = LINUX_BZIMAGE_ADDR + len_vmlinuz;
   devread_my(2 + 20 + 2*10*1024, len_initrd, (char *)lh->ramdisk_image);
   
   big_linux_boot();
   
   return;
}

