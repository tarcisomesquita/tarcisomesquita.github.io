
/*
Returns the length of str.
A string is as long as the amount of characters between the beginning of the string and the terminating null character.

This should not be confused with the size of the array that holds the string. For example:
char mystr[100]="test string";
defines an array of characters with a size of 100 chars, but the C string with which mystr has been initialized has a length of only 11 characters. Therefore, while sizeof(mystr) evaluates to 100, strlen(mystr) returns 11.
*/


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern unsigned int strlen(const char *str);

int main(int argc, char **argv)
{
   return strlen(argv[1]);
}

