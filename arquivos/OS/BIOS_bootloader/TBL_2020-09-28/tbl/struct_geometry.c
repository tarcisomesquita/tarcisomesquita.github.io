struct geometry {
   unsigned int cylinders;      // The number of cylinders
   unsigned int heads;          // The number of heads
   unsigned int sectors;        // The number of sectors per track
   unsigned int total_sectors;  // The total number of sectors
   unsigned int sector_size;    // Device sector size
   unsigned int flags;          // Flags
};

#define SECTOR_SIZE   0x200

// Drive Mode.
#define CHS_MODE                      0
#define LBA_MODE                      1
#define BIOSDISK_FLAG_LBA_EXTENSION   1

