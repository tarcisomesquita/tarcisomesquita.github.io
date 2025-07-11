#ifndef ADDITIONAL_H
#define ADDITIONAL_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef HAVE_STRLCPY
size_t strlcpy(char *, const char *, size_t);
#endif /* HAVE_STRLCPY */
#ifndef HAVE_STRLCAT
size_t strlcat(char *, const char *, size_t);
#endif /* HAVE_STRLCAT */
#ifndef HAVE_FGETLN
char *fgetln(FILE *, size_t *);
#endif /* HAVE_FGETLN */
char *ultostr(unsigned long, char *);
int dstrncmp (const char*, const char*, int);
int dstrncmp2 (const char*, const char*, int);

#endif /* ADDITIONAL_H */
