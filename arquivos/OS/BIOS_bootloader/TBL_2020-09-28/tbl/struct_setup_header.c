// /usr/src/linux-headers-3.19.0-15-generic/arch/x86/include/uapi/asm/bootparam.h
struct setup_header {
   unsigned char  setup_sects;            // 0x0000  The size of the setup in sectors
   unsigned short root_flags;             // 0x0001  If the root is mounted readonly. deprecated; use the "ro" or "rw" options on the command line instead.
   unsigned int   syssize;                // 0x0003  The size of the protected-mode code in units of 16-byte paragraphs.
   unsigned short ram_size;               // 0x0007  DO NOT USE - for bootsect.S use only
   unsigned short vid_mode;               // 0x0009  Video mode control. "normal" (meaning 0xFFFF), "ext" (meaning 0xFFFE) or "ask" (meaning 0xFFFD).
   unsigned short root_dev;               // 0x000B  Default root device number. deprecated, use the "root=" option on the command line instead.
   unsigned short boot_flag;              // 0x000D  0xAA55 magic number
   unsigned short jump;                   // 0x000F  Jump to end of header. 0xEB followed by a signed offset relative to byte 0x0011.
   unsigned int   header;                 // 0x0011  Magic signature "HdrS"
   unsigned short version;                // 0x0015  Boot protocol version supported
   unsigned int   realmode_swtch;         // 0x0017  A 16-bit real mode subroutine invoked immediately before entering protected mode.
   unsigned short start_sys;              // 0x001B  The load-low segment (0x1000) (obsolete)
   unsigned short kernel_version;         // 0x001D  Points to kernel version string
   unsigned char  type_of_loader;         // 0x001F  Boot loader identifier;. Ver 0x11  Minimal Linux Bootloader <http:     //sebastian-plotz.blogspot.de>
   unsigned char  loadflags;              // 0x0020  Boot protocol option flags
   unsigned short setup_move_size;        // 0x0021  Move to high memory size. Isso é para versões menores que 0x0203.
   unsigned int   code32_start;           // 0x0023  A 32-bit routine *jumped* to after the transition to protected mode, before the kernel is uncompressed.
                      // if a bootloader loads a relocatable kernel at a nonstandard address it will have to modify this field to point to the load address.
   unsigned int   ramdisk_image;          // 0x0027  initrd load address (set by boot loader)
   unsigned int   ramdisk_size;           // 0x002B  initrd size (set by boot loader)
   unsigned int   bootsect_kludge;        // 0x002F  DO NOT USE - for bootsect.S use only
   unsigned short heap_end_ptr;           // 0x0030  offset (from the beginning of the real-mode code) of the end of the setup stack/heap, minus 0x0200.
   unsigned char  ext_loader_ver;         // 0x0032  Extended boot loader version
   unsigned char  ext_loader_type;        // 0x0033  Extended boot loader ID
   unsigned int   cmd_line_ptr;           // 0x0034  Points to the kernel command line
   unsigned int   initrd_addr_max;        // 0x0038  The highest address of initrd
   
   unsigned int   kernel_alignment;       // 0x0030  Physical addr alignment required for kernel
   unsigned char  relocatable_kernel;     // 0x0034  If this field is nonzero, the protected-mode part of the kernel can be loaded at any address
   unsigned char  min_alignment;          // 0x0035  Minimum alignment. kernel_alignment = 1 << min_alignment
   unsigned short xloadflags;             // 0x0036  XLF_KERNEL_64 | XLF_CAN_BE_LOADED_ABOVE_4G | XLF_EFI_HANDOVER_32 | XLF_EFI_HANDOVER_64 | XLF_EFI_KEXEC
   unsigned int  cmdline_size;           // 0x0038  Maximum size of the kernel command line
   unsigned int  hardware_subarch;       // 0x003C  Hardware subarchitecture. 0x00000000 = The default x86/PC environment
   unsigned long long hardware_subarch_data;  // 0x0040  Subarchitecture-specific data. unused for the default x86/PC
   unsigned int  payload_offset;         // 0x0048  payload offset from the beginning of the protected-mode code
                                          /*  The payload may be compressed.
                                           *  The format should be determined using the standard magic numbers.
                                           *  gzip (magic numbers 1F 8B or 1F 9E)
                                           *  bzip2 (magic number 42 5A)
                                           *  LZMA (magic number 5D 00)
                                           *  XZ (magic number FD 37)
                                           *  LZ4 (magic number 02 21)
                                           *  The uncompressed payload is currently always ELF (magic number 7F 45 4C 46).
                                           */
   unsigned int   payload_length;         // 0x004C  Length of kernel payload
   unsigned long long setup_data;         // 0x0050  pointer to NULL terminated single linked list of struct setup_data
   unsigned long long pref_address;       // 0x0058  Preferred loading address. bootloader should load the kernel at this address if possible.
   unsigned int   init_size;              // 0x0060  Linear memory required during initialization
   unsigned int   handover_offset;        // 0x0064  Boot loaders using the EFI handover protocol to boot the kernel should jump to this offset.
} __attribute__ ((packed));

