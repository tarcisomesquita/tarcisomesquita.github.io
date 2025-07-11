// gcc -Wall -static access.c -o access.elf && objdump -M intel -d access.elf > access.asm

// #include<unistd.h>
// Values for the second argument to access. These may be OR'd together.
#define   R_OK   4      // Test for read permission.
#define   W_OK   2      // Test for write permission.
#define   X_OK   1      // Test for execute permission.
#define   F_OK   0      // Test for existence.

// #include<unistd.h>
// Test for access to NAME using the real UID and real GID.
// Return 0 if OK, -1 if NOT OK
extern int access(const char *name, int type);

int main() {
   if(access("/media/SD/linguas/linguagem_c/programas/autocompletar/2_Coletor_de_sequencias/ideia_coletor_de_sequencias.html", R_OK)) return -1;
   return 0;
}

/*
.LC0:
   .string   "/media/SD/linguas/linguagem_c/programas/autocompletar/2_Coletor_de_sequencias/ideia_coletor_de_sequencias.html"

   mov    DWORD PTR [esp+4], 4
   mov    DWORD PTR [esp], OFFSET FLAT:.LC0
   call   access

access:
   mov    edx,ebx
   mov    ecx,DWORD PTR [esp+0x8]
   mov    ebx,DWORD PTR [esp+0x4]
   mov    eax,0x21
   int    0x80
   mov    ebx,edx
   cmp    eax,0xfffff001
   jae    syscall_error
   ret    

syscall_error:
   neg    eax
   mov    ecx,DWORD PTR gs:0x0
   mov    DWORD PTR [ecx-0x18],eax
   mov    eax,0xffffffff
   ret    
*/
