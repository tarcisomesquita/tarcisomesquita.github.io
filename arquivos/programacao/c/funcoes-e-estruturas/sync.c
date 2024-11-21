
// Make all changes done to all files actually appear on disk.

//#include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern void sync (void);

int main()
{
  /* First of all, call sync so that all in-core data is scheduled to be
     actually written to disks. This is very important because GRUB does
     not use ordinary stdio interface but raw devices.  */

   sync();
   return(0);
}

