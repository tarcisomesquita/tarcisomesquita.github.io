// void *dlopen(const char *filename, int flag); // Opens dynamic library and return handle
// char *dlerror(void);                          // Returns string describing the last error.
// void *dlsym(void *handle, char *symbol);      // Return pointer to symbol's load point.
// int  dlclose (void *handle);                  // Close the dynamic library handle.

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void  *FunctionLib;      // Handle to shared lib file
int   (*Function)();     // Pointer to loaded routine
const char *dlError;     // Pointer to error string

int main(int argc, char **argv) {
   int   rc;            //  return codes
   char HelloMessage[] = "HeLlO WoRlD";
   
   printf("Original message: \"%s\"\n\n", HelloMessage);

   FunctionLib = dlopen("/home/ubuntu/Desktop/exemplo/UPPERCASE.so", RTLD_LAZY); // Open Dynamic Loadable Libary with absolute path
   if(dlerror()) return 1;
   
   Function = dlsym(FunctionLib, "printUPPERCASE");                              // Find the function
   if(dlerror()) return 2;
   
   (*Function)(HelloMessage);                                                    // Execute function
   
   if(dlclose(FunctionLib)) return 3;                                            // Close the shared library handle (unload printUPPERCASE)
   
   
   
   FunctionLib = dlopen("lowercase.so", RTLD_LAZY);                              // Open Dynamic Loadable Libary using LD_LIBRARY path
   if(dlerror()) return 4;

   Function    = dlsym( FunctionLib, "printLowercase");                          // Find the function
   if(dlerror()) return 4;
   
   (*Function)(HelloMessage);                                                    // Execute function
   
   if(dlclose(FunctionLib)) return 5;                                            // Close the shared library handle (unload printLowercase)
   
   return 0;
}

