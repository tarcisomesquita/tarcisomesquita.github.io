

//#include<bits/libc-lock.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
# define PTFAVAIL(NAME) __libc_pthread_functions_init

/* Start critical region with cleanup.  */
#define __libc_cleanup_region_start(DOIT, FCT, ARG) \
  { struct _pthread_cleanup_buffer _buffer;				      \
    int _avail;								      \
    if (DOIT) {								      \
      _avail = PTFAVAIL (_pthread_cleanup_push_defer);			      \
      if (_avail) {							      \
	__libc_ptf_call_always (_pthread_cleanup_push_defer, (&_buffer, FCT,  \
							      ARG));	      \
      } else {								      \
	_buffer.__routine = (FCT);					      \
	_buffer.__arg = (ARG);						      \
      }									      \
    } else {								      \
      _avail = 0;							      \
    }



