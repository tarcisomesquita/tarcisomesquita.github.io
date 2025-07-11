
/* Set the user ID of the calling process to UID.
   If the calling process is the super-user, set the real and effective user IDs, and the saved set-user-ID to UID;
   if not, the effective user ID is set to UID.  */

#include<unistd.h>
extern int setuid (__uid_t __uid);

