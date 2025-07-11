
/* Return the length of the null-terminated string STR.  Scan for
   the null terminator quickly by testing four bytes at a time.
*/

unsigned int strlen (const char *str)
{
   const char *char_ptr;
   const unsigned long int *longword_ptr;
   unsigned long int longword, himagic, lomagic;

   // align CHAR_PTR on a longword boundary.  
   for (char_ptr = str; ((unsigned long int) char_ptr & (sizeof(longword) - 1)) != 0; ++char_ptr)
   {
      if (*char_ptr == '\0')
      {
         return(char_ptr - str);
      }
   }

   // the theory applies equally well to 8-byte longwords.
   
   longword_ptr = (unsigned long int *) char_ptr;
   himagic = 0x80808080;
   lomagic = 0x01010101;
   
   // teste if any of the four bytes in the longword in question are zero.
   for(;;)
   {
      longword = *longword_ptr++;
      
      if(((longword - lomagic) & ~longword & himagic) != 0)
      {
         const char *cp = (const char *) (longword_ptr - 1);
         
         if(cp[0] == 0)
            return(cp - str);
         if(cp[1] == 0)
            return(cp - str + 1);
         if(cp[2] == 0)
            return(cp - str + 2);
         if(cp[3] == 0)
            return(cp - str + 3);
      }
   }
}

