
/*
I also need a definition of program_name; set_program_name copies the filename component of path into the exported data, program_name. 
*/



/* EXEMPLO */

//#include<stddef.h>
#define NULL ((void *)0)


//#include<string.h>
extern char *basename(const char *);


const char *program_name = NULL;

void set_program_name(const char *path)
{
  if (!program_name)
    program_name = xstrdup (basename(path));
}

