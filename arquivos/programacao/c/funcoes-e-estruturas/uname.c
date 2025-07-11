// clear ; gcc -Wall uname.c -o uname.elf && ./uname.elf

//#include<bits/utsname.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define _UTSNAME_LENGTH 65

//#include<sys/utsname.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
# define _UTSNAME_SYSNAME_LENGTH  _UTSNAME_LENGTH
# define _UTSNAME_NODENAME_LENGTH _UTSNAME_LENGTH
# define _UTSNAME_RELEASE_LENGTH  _UTSNAME_LENGTH
# define _UTSNAME_VERSION_LENGTH  _UTSNAME_LENGTH
# define _UTSNAME_MACHINE_LENGTH  _UTSNAME_LENGTH
# define _UTSNAME_DOMAIN_LENGTH   _UTSNAME_LENGTH

// Structure describing the system and machine.
struct utsname {
   char sysname[_UTSNAME_SYSNAME_LENGTH];   // Name of the implementation of the operating system.
   char nodename[_UTSNAME_NODENAME_LENGTH]; // Name of this node on the network.
   char release[_UTSNAME_RELEASE_LENGTH];   // Current release level of this implementation.
   char version[_UTSNAME_VERSION_LENGTH];   // Current version level of this release.
   char machine[_UTSNAME_MACHINE_LENGTH];   // Name of the hardware type the system is running on.
   char domainname[_UTSNAME_DOMAIN_LENGTH]; // Name of the domain of this node on the network.
};

// Put information about the system in name.
extern int uname(struct utsname *name);


extern int printf(char *, ...);

int main() {
   struct utsname name;
   
   uname(&name);  // syscall: uname({sys="Linux", node="ubuntu", ...}) = 0
   
   printf("\n");
   printf("sysname    = %s\n", name.sysname);
   printf("nodename   = %s\n", name.nodename);
   printf("release    = %s\n", name.release);
   printf("version    = %s\n", name.version);
   printf("machine    = %s\n", name.machine);
   printf("domainname = %s\n", name.domainname);
   printf("\n");
   
   return 0;
}

