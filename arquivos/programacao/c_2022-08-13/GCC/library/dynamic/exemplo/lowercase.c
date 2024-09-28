// print input string as lower case.


extern int tolower(int);
extern int printf(char *, ...);


int printLowercase(char *inLine) {
   char lowstring[256];
   char *inptr, *outptr;
   
   inptr = inLine;
   outptr = lowstring;
   while (*inptr) *outptr++ = tolower(*inptr++);
   *outptr++ = 0x00;
   printf("%s\n", lowstring);
   return 2;
}

