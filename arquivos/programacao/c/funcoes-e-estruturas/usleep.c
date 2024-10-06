

// Sleep USECONDS microseconds, or until a signal arrives that is not blocked or ignored.

#include <unistd.h>
extern int usleep (__useconds_t __useconds);

exemplo:
      usleep(10000); // Limitador de execução


