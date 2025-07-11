// tirado de WinNT.h

struct _IMAGE_DOS_HEADER {      // DOS .EXE header
   unsigned short int   e_magic;                     // Magic number
   unsigned short int   e_cblp;                      // Bytes on last page of file
   unsigned short int   e_cp;                        // Pages in file
   unsigned short int   e_crlc;                      // Relocations
   unsigned short int   e_cparhdr;                   // Size of header in paragraphs
   unsigned short int   e_minalloc;                  // Minimum extra paragraphs needed
   unsigned short int   e_maxalloc;                  // Maximum extra paragraphs needed
   unsigned short int   e_ss;                        // Initial (relative) SS value
   unsigned short int   e_sp;                        // Initial SP value
   unsigned short int   e_csum;                      // Checksum
   unsigned short int   e_ip;                        // Initial IP value
   unsigned short int   e_cs;                        // Initial (relative) CS value
   unsigned short int   e_lfarlc;                    // File address of relocation table
   unsigned short int   e_ovno;                      // Overlay number
   unsigned short int   e_res[4];                    // Reserved unsigned short ints
   unsigned short int   e_oemid;                     // OEM identifier (for e_oeminfo)
   unsigned short int   e_oeminfo;                   // OEM information; e_oemid specific
   unsigned short int   e_res2[10];                  // Reserved unsigned short ints
   unsigned int         e_lfanew;                    // File address of new exe header
} *dos_hdr = 0x00000000;

unsigned char *nt_hdr = 0x00000000;
 
struct _IMAGE_FILE_HEADER {
   unsigned short int   Machine;
   unsigned short int   NumberOfSections;
   unsigned       int   TimeDateStamp;
   unsigned       int   PointerToSymbolTable;
   unsigned       int   NumberOfSymbols;
   unsigned short int   SizeOfOptionalHeader;
   unsigned short int   Characteristics;
} *file_hdr = 0x00000000;

struct _IMAGE_DATA_DIRECTORY {
   unsigned       int   VirtualAddress;
   unsigned       int   Size;
};

struct _IMAGE_OPTIONAL_HEADER {
   // Standard fields.
   unsigned short int   Magic;
   unsigned char        MajorLinkerVersion;
   unsigned char        MinorLinkerVersion;
   unsigned       int   SizeOfCode;
   unsigned       int   SizeOfInitializedData;
   unsigned       int   SizeOfUninitializedData;
   unsigned       int   AddressOfEntryPoint;
   unsigned       int   BaseOfCode;
   unsigned       int   BaseOfData;
   
   // NT additional fields.
   unsigned       int   ImageBase;
   unsigned       int   SectionAlignment;
   unsigned       int   FileAlignment;
   unsigned short int   MajorOperatingSystemVersion;
   unsigned short int   MinorOperatingSystemVersion;
   unsigned short int   MajorImageVersion;
   unsigned short int   MinorImageVersion;
   unsigned short int   MajorSubsystemVersion;
   unsigned short int   MinorSubsystemVersion;
   unsigned       int   Win32VersionValue;
   unsigned       int   SizeOfImage;
   unsigned       int   SizeOfHeaders;
   unsigned       int   CheckSum;
   unsigned short int   Subsystem;
   unsigned short int   DllCharacteristics;
   unsigned       int   SizeOfStackReserve;
   unsigned       int   SizeOfStackCommit;
   unsigned       int   SizeOfHeapReserve;
   unsigned       int   SizeOfHeapCommit;
   unsigned       int   LoaderFlags;
   unsigned       int   NumberOfRvaAndSizes;
   struct _IMAGE_DATA_DIRECTORY DataDirectory[16];
} *img_opt_hdr = 0x00000000;

struct _IMAGE_OPTIONAL_HEADER64 {
   unsigned short int   Magic;
   unsigned char        MajorLinkerVersion;
   unsigned char        MinorLinkerVersion;
   unsigned       int   SizeOfCode;
   unsigned       int   SizeOfInitializedData;
   unsigned       int   SizeOfUninitializedData;
   unsigned       int   AddressOfEntryPoint;
   unsigned       int   BaseOfCode;
   unsigned long  int   ImageBase;
   unsigned       int   SectionAlignment;
   unsigned       int   FileAlignment;
   unsigned short int   MajorOperatingSystemVersion;
   unsigned short int   MinorOperatingSystemVersion;
   unsigned short int   MajorImageVersion;
   unsigned short int   MinorImageVersion;
   unsigned short int   MajorSubsystemVersion;
   unsigned short int   MinorSubsystemVersion;
   unsigned       int   Win32VersionValue;
   unsigned       int   SizeOfImage;
   unsigned       int   SizeOfHeaders;
   unsigned       int   CheckSum;
   unsigned short int   Subsystem;
   unsigned short int   DllCharacteristics;
   unsigned long  int   SizeOfStackReserve;
   unsigned long  int   SizeOfStackCommit;
   unsigned long  int   SizeOfHeapReserve;
   unsigned long  int   SizeOfHeapCommit;
   unsigned       int   LoaderFlags;
   unsigned       int   NumberOfRvaAndSizes;
   struct _IMAGE_DATA_DIRECTORY DataDirectory[16];
} *img_opt_hdr64 = 0x00000000;


struct _IMAGE_SECTION_HEADER {
   unsigned       char  Name[8];
   unsigned       int   VirtualSize;
   unsigned       int   VirtualAddress;
   unsigned       int   SizeOfRawData;
   unsigned       int   PointerToRawData;
   unsigned       int   PointerToRelocations;
   unsigned       int   PointerToLinenumbers;
   unsigned short int   NumberOfRelocations;
   unsigned short int   NumberOfLinenumbers;
   unsigned       int   Characteristics;
} *sct_hdr = 0x00000000;

struct _IMAGE_IMPORT_DESCRIPTOR {
   unsigned       int   OriginalFirstThunk;   // RVA to original unbound IAT (PIMAGE_THUNK_DATA)
   unsigned       int   TimeDateStamp;
   unsigned       int   ForwarderChain;       // -1 if no forwarders
   unsigned       int   Name;
   unsigned       int   FirstThunk;           // RVA to IAT (if bound this IAT has actual addresses)
} *ipt_dsc = 0x00000000;

unsigned       int *thunk = 0x00000000;

/*
struct _IMAGE_THUNK_DATA32 {
   unsigned       int Function;             // PDWORD
} *thunk = 0x00000000;
*/

struct _IMAGE_IMPORT_BY_NAME {
   unsigned short int   Hint;
   char                 Name;
} *imp_by_name = 0x00000000;

