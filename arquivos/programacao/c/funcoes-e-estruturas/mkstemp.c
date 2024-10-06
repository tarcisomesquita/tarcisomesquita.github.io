
/* Generate a unique temporary file name from TEMPLATE.
   The last six characters of TEMPLATE must be "XXXXXX";
   they are replaced with a string that makes the filename unique.
   Returns a file descriptor open on the file for reading and writing,
   or -1 if it cannot create a uniquely-named file.
*/

// #include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int mkstemp(char *template);

int main()
{
   char template[] = "template.txtXXXXXX";
   mkstemp(template);
   
   return(0);
}


