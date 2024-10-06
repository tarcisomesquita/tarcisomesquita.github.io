
/* Return the canonical absolute name of file NAME.
   If RESOLVED is null, the result is malloc'd;
   returns null with `errno' set to ENAMETOOLONG;
   returns the name in RESOLVED if the name fits in fewer than PATH_MAX chars
*/

// #include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *realpath (const char *name, char *resolved);

extern int printf(char *, ...);

int main()
{
   char program[] = "teste";
   char *p;
   char buffer[16384];
   
   p = realpath(program, buffer);
   printf("0x%08X\n", (unsigned int)p);
   printf("%s\n", p);
   return(0);
}



