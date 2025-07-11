// print input string as UPPER case.


extern int toupper(int);
extern int printf(char *, ...);


int printUPPERCASE(char *inLine) {
   char UPstring[256];
   char *inptr, *outptr;
   
   inptr = inLine;
   outptr = UPstring;
   while (*inptr) *outptr++ = toupper(*inptr++);
   *outptr++ = 0x00;
   printf("%s\n", UPstring);
   return 1;
}

