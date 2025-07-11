

//#include<stdarg.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)


//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//extern int printf(char *, ...);
struct _IO_FILE;
typedef struct _IO_FILE FILE;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int vfprintf (FILE *s, const char *format, va_list arg);
extern int fprintf(FILE *saida, const char *string_com_formatos, ...);
extern int fflush(FILE *__stream);
extern FILE *fopen(const char *__restrict __filename, const char *__restrict __modes);
extern int ferror(FILE *__stream);
extern int feof(FILE *__stream);
extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);
extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...);
extern int fclose(FILE *__stream);


int printf(const char *format, ...)
{
   va_list arg;
   int done;
   va_start(arg,format);
   done = vfprintf(stdout, format, arg);
   va_end(arg);
   return done;
}


//#include<signal.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
typedef void (*__sighandler_t)(int);
extern __sighandler_t signal(int __sig, __sighandler_t __handler);
extern int kill(int __pid, int __sig);


//#include<bits/signum.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define	SIGHUP		1	/* Hangupsignum (POSIX).  */
#define	SIGINT		2	/* Interrupt (ANSI).  */
#define	SIGTERM		15	/* Termination (ANSI).  */
#define	SIGCHLD		17	/* Child status has changed (POSIX).  */


//#include<getopt.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int opterr;
extern int optind;
extern char *optarg;
extern int optopt;
extern int getopt(int ___argc, char *const *___argv, const char *__shortopts);


//#include<sys/cdefs.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define __STRING(x)	#x


//#include"/usr/lib/gcc/i486-linux-gnu/4.3/include/stddef.h" // = = = = = = = = = = = = = = = = = =
typedef long unsigned int size_t;


//#include<stddef.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define NULL ((void *)0)


//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0
extern void exit(int );
extern void abort(void);
extern int atoi(const char *);
extern int setenv(const char *name, const char *value, int replace);
extern void *malloc(size_t __size);
extern void free (void *__ptr);


//#include <string.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int strncmp(const char * s1,const char * s2, size_t num);
extern char *strstr(const char *__haystack, __const char *__needle);
extern size_t strlen(const char *);
extern void *memset(void *__s, int __c, size_t __n);


//#include<unistd.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int getpid(void);
extern int getppid(void);


//#include<time.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
struct timespec
{
   long int tv_sec;
   long int tv_nsec;
};


//#include<bits/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define	__S_IEXEC	0100	/* Execute by owner.  */
struct stat
{
   unsigned long long int st_dev;
   unsigned short int __pad1;
   unsigned long int st_ino;
   unsigned int st_mode;
   unsigned int st_nlink;
   unsigned int st_uid;
   unsigned int st_gid;
   unsigned long long int st_rdev;
   unsigned short int __pad2;
   long int st_size;
   long int st_blksize;
   long int st_blocks;
   struct timespec st_atim;
   struct timespec st_mtim;
   struct timespec st_ctim;
   unsigned long int __unused4;
   unsigned long int __unused5;
};

//#include<sys/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int stat(const char *__restrict __file, struct stat *__restrict __buf);
#define	S_IXUSR	__S_IEXEC	/* Execute by owner.  */
/* Read, write, and execute by owner.  */
#define	S_IXGRP	(S_IXUSR >> 3)	/* Execute by group.  */
/* Read, write, and execute by group.  */
#define	S_IXOTH	(S_IXGRP >> 3)	/* Execute by others.  */

//#include<assert.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void __assert_fail(const char *assertion, const char *file, unsigned int line, const char *function);


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


#define PACKAGE "dhttpd"
#define VERSION "0.0-alpha-0.1"
#define SERVER_VERSION PACKAGE "/" VERSION

unsigned int debug = 0;


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

typedef struct vhost vhost_t;

struct vhost
{
    char *name;
    char *doc_base,
    *index_doc;
    int log_type;
    char *log_ok, *log_err;
    FILE *log_fd_ok, *log_fd_err;
    vhost_t *next;
};


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// All globally applicable configuration 
struct config
{
    int port,		    // Port that the server socket will use
     backlog,		    // Global backlog 
     timeout,		    // Milliseconds to wait in the select 
     loop_child,	    // Amount of simultatious connections we'll take 
     script_pool,	    // Amount of workers in the script pool 
     cache_size,	    // size of cache 
     max_cache_age;	    // Age of cache entry 
    unsigned char do_fork;  // If we should fork away from the console 
    char *user,		    // Which user to run as, if running as root 
	*jail_root,	    // What the directory is to chroot to 
	*config_file,	    // Location of the configuration file 
	*php_bin,	    // Location of the PHP binary 
	*perl_bin,	    // " "             Perl   " 
	*mime_file,	    // Location of the mime definitions 
	*default_mime_type, // Default mime type 
	*bind_addr;	    // Address to bind to 
    vhost_t *vhl;	    // List of vhosts 
    unsigned int perl_available:1;
    unsigned int php_available:1;
    unsigned int use_large_access_log_buffer:1;
};

typedef struct config conf_t;
struct config  *conf;


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void parse_cmd_line(conf_t *conf, int argc, char **argv)
{
    int c;

    while ((c = getopt(argc, argv, "wbds:p:f:")) != -1) {
	switch (c) {
	case 'w':
	    /* wait for children */
	    conf->do_fork = 0;
	    break;
	case 'p':
	    /* port number */
	    conf->port = atoi(optarg);
	    break;
	case 's':
	    fprintf(stderr,
		    "Error: used -s to indicate secure port, but you didn't compile it with SSL support!\n");
	    break;
	case 'd':
	    /* debugging */
	    debug++;
	    printf("DEBUGGING\n");
	    /* silently ignore on a release */
	    break;
	case 'b':
	    /* amount of connections */
	    conf->backlog = atoi(optarg);
	    break; 
	case 'f':
	    /* location of config file */
	    conf->config_file = optarg;
	    break;
	default:
	    fprintf(stderr, "Usage: %s "
		    "[-w] "
		    "[-d] "
		    "[-f <config file>] "
		    "[-p <port number>] "
		    "[-s <ssl port number>] "
		    "[-b <max #connections)] " "\n", argv[0]);
	    exit(1);
	    break;
	}
    }
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define ERROR(x) log_err(x);
#define FATAL(x) \
    ERROR(x); \
    abort();

void log_err(const char *fmt, ...)
{ 
   va_list vars;
   FILE *output = stderr;
   
   (void)fprintf(stderr, "dhttpd: ");
   
   if(fmt)
   {
      va_start(vars, fmt);
      (void)vfprintf(output, fmt, vars);
      va_end(vars);
   }
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#define DEBUG_OUT4( a, b, c, d )	debug_out( __FILE__, __LINE__, a, b, c, d);
#define DEBUG_OUT3( a, b, c )		debug_out( __FILE__, __LINE__, a, b, c );
#define DEBUG_OUT2( a, b )		debug_out( __FILE__, __LINE__, a, b );
#define DEBUG_OUT( a )			debug_out( __FILE__, __LINE__, a );

void debug_out(const char *file, const int line, const char *format, ...)
{
   va_list vars;
   
   (void)fprintf(stderr, "%s:%d; ", file, line);
   
   if(format)
   {
      va_start(vars, format);
      (void)vfprintf(stderr, format, vars);
      va_end(vars);
   }
   fflush(stdout);
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void close_sockets()
{
   int i;
//t   for(i = 0; i < conf->backlog; i++)
//t      if(get_conn_at(i))
//t         clean_conn(get_conn_at(i));
//t   CLOSE(server_socket);
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void main_shutdown(int i)
{
   if(debug)
      DEBUG_OUT("Caught terminal signal, shutting down..\n");
   if (i != 666)
      close_sockets();
//t   close_logs(conf);
//t   free_config(conf);
   exit(0);
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void child_died(int sig)
{
    if(sig != SIGCHLD)		/* Sanity check */
	return;
	DEBUG_OUT("Child died. Spawning another one\n");
    if(sig)
	conf->loop_child = -2;    
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/* Clean all connections, and abort */
void a_lot_of_panic()
{
   int i, j;
   const char foo[]="PANIC!"; 
   
   for(j = 0; j < sizeof(foo); j++)
      for (i = 0; i < 80; i++)
         (void)fprintf(stderr, "%c", foo[j]);
   (void)fprintf(stderr, "\n");
   
//t   for(i = 0; i < conf->backlog; i++)
//t      clean_conn(get_conn_at(i));
   
//t   CLOSE(server_socket);
   
   abort();
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/* Maximum length of a string. Used to parse files */
#define MAX_STR_LENGTH 256

#define MALLOC( a, b )		\
	if ((a = malloc(b)) == NULL ) { \
		DEBUG_OUT2("Couldn't allocate enough memory for %s\n", #a); \
		a_lot_of_panic( ); \
	} else { memset(a, 0, b); }

/* Set some defaults in the configuration struct and allocate any memory for options */
void set_defaults(struct config *conf)
{
    /* Set some variables to sensible defaults */
    conf->port = 80;
    conf->backlog = 10; 
    conf->script_pool = 10;
    conf->do_fork = 1;
    conf->cache_size = 32;
    conf->max_cache_age = 60;
    conf->use_large_access_log_buffer =
	conf->php_available = 
	conf->perl_available = 0;

    /* Request some space */
    MALLOC(conf->jail_root, MAX_STR_LENGTH);
    MALLOC(conf->user, MAX_STR_LENGTH);
    MALLOC(conf->mime_file, MAX_STR_LENGTH);
    MALLOC(conf->default_mime_type, MAX_STR_LENGTH);
    MALLOC(conf->php_bin, MAX_STR_LENGTH);
    MALLOC(conf->perl_bin, MAX_STR_LENGTH);
    MALLOC(conf->bind_addr, MAX_STR_LENGTH);
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

void loop(conf_t *conf)
{
    int reuse_addr = 1, i = 0, ss = 0;
    char portstr[6];
    char *listen_on = ((void *)0);
    int forkret = 0;
    int gai_err;
/*t
    struct addrinfo ai;
    struct addrinfo *aip = &ai, *aip0;
    memset(&ai, 0, sizeof(ai));
    signal(15, ((__sighandler_t) 0));
    signal(1, ((__sighandler_t) 0));
    signal(2, ((__sighandler_t) 0));
    signal(13, ((__sighandler_t) 1));
    if (debug)
 debug_out( "children.c", 828, "Using port %d\n", conf->port );;
    aip->ai_flags = 0x0001;
    aip->ai_family = 0;
    aip->ai_socktype = SOCK_STREAM;
    i = 0;
 portstr[5] = '\0';
 if (i == 0)
     ultostr(conf->port, portstr);
 if (strncasecmp(conf->bind_addr, "any", 3) != 0 &&
  strncasecmp(conf->bind_addr, "all", 3) != 0)
     listen_on = conf->bind_addr;
 if ((gai_err = getaddrinfo(listen_on, portstr, &ai, &aip0)) != 0) {
     debug_out( "children.c", 854, "Error: %s (%s)\n", gai_strerror(gai_err), listen_on );;
     return;
 }
 if (debug)
     debug_out( "children.c", 861, "Setting up sockets\n" );;
 for (aip = aip0; aip; aip = aip->ai_next) {
     if ((ss = socket(aip->ai_family, aip->ai_socktype, aip->ai_protocol)) == -1) {
  perror("socket");
  continue;
     }
     if (setsockopt(ss, 1, 2, &reuse_addr,
   sizeof(reuse_addr)) == -1) {
  perror("setsockopt");
  continue;
     }
     if (debug > 1)
  debug_out( "children.c", 887, "Binding to address: %s\n", aip->ai_canonname );;
     if (bind(ss, aip->ai_addr, aip->ai_addrlen) == -1) {
  if (conf->loop_child != -3) {
      perror("bind()");
      log_err("Couldn't bind to port %s, aborting\n", portstr);
      debug_out( "children.c", 895, "Tip: you can use -p <portnumber> to " "use another port\n" );;
  }
   else if (debug)
    debug_out( "children.c", 900, "Skiping bind for family %d\n", aip->ai_family );;
  close(ss);
  continue;
     }
     if (listen(ss, conf->backlog) == -1) {
  perror("listen()");
  log_err("Couldn't listen, continuing\n");;
  close(ss);
  continue;
     }
     if (debug)
  debug_out( "children.c", 915, "Accepting connections for family %d\n", aip->ai_family );;
     conf->loop_child = 0;
     switch (forkret = fork()) {
     case 0:
  init_cache();
  switch (i) {
  case 0:
      if (debug)
   debug_out( "children.c", 934, "Going into normal socket poll\n" );;
      server_socket = ss;
      if ((aip->ai_family & 2) == 2) {
   children[0] = forkret;
   while (do_select(INET) > 0);
      } else if ((aip->ai_family & 10) == 10) {
   children[1] = forkret;
   while (do_select(INET6) > 0);
      } else
   log_err("Only IPv4 and IPv6 in dhttpd, sorry\n");;
      if (debug)
   debug_out( "children.c", 949, "Got back from do_select\n" );;
      break;
  default:
      log_err("PANIC: unknown socket\n");;
      break;
  }
  break;
     case -1:
  log_err("PANIC: cannot fork\n");;
  break;
     default:
  conf->loop_child = 0;
     }
 }
 freeaddrinfo(aip0);
    signal(15, main_shutdown);
    signal(2, main_shutdown);
    signal(1, restart);
    if (forkret > 0) {
 while (!our_child_died());
 close(ss);
    }
    if (debug)
 debug_out( "children.c", 1009, "loop finished\n" );;
*/
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

#define __ASSERT_VOID_CAST (void)

#define __ASSERT_FUNCTION	__PRETTY_FUNCTION__

#define assert(expr)							\
  ((expr)								\
   ? __ASSERT_VOID_CAST (0)						\
   : __assert_fail (__STRING(expr), __FILE__, __LINE__, __ASSERT_FUNCTION))

#define _DIAGASSERT assert

/*
 * Copy src to string dst of size siz.  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz == 0).
 * Returns strlen(src); if retval >= siz, truncation occurred.
 */
size_t strlcpy(char *dst, const char *src, size_t siz)
{
	char *d = dst;
	const char *s = src;
	size_t n = siz;

	_DIAGASSERT(dst != NULL);
	_DIAGASSERT(src != NULL);

	/* Copy as many bytes as will fit */
	if (n != 0 && --n != 0) {
		do {
			if ((*d++ = *s++) == 0)
				break;
		} while (--n != 0);
	}

	/* Not enough room in dst, add NUL and traverse rest of src */
	if (n == 0) {
		if (siz != 0)
			*d = '\0';		/* NUL-terminate dst */
		while (*s++)
			;
	}

	return(s - src - 1);	/* count does not include NUL */
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

int dstrncmp(const char *a, const char *b, const int c)
{
   int i;
   
   for(i = 0; i < c && a[i] && b[i]; i++)
      if(a[i] != b[i])
         return(1);
   
   if(((!a[i]) && (!b[i])) || (i == c))
      return(0);
   return(1);
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/* Log types */
enum {
    COMBINED = 0, COMMON, EXTENDED
};


void set_vh_defaults(struct vhost *vh)
{
    MALLOC(vh->name, MAX_STR_LENGTH);
    MALLOC(vh->doc_base, MAX_STR_LENGTH);
    MALLOC(vh->index_doc, MAX_STR_LENGTH);	
    MALLOC(vh->log_ok, MAX_STR_LENGTH);
    MALLOC(vh->log_err, MAX_STR_LENGTH);
    vh->log_fd_ok = vh->log_fd_err = NULL;
    vh->log_type = COMBINED;
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/*
 * Determins if a char matches a set of chars
 *
 * delims must be NUL-terminated!
 *
 * Returns:
 * 1 on match
 * 0 on no matches
 */
int matches_delim(const char m, const char *delims) {
    int i = 0;

    if (delims == NULL)
	return 0;

    for (i = 0; delims[i] != '\0'; i++)
	if (m == delims[i])
	    return 1;

    return 0;
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

enum { FIRST, SECOND, THIRD };

/*
 * Parses a name-value pair in the following format
 * <name><delims><value>
 *
 * Returns:
 * 0 on success
 * -1 on format error
 * -2 on internal error
 */
int parse_name_value(const char *line, char *name, const int max_name, 
	char *value, const int max_value, char *delims) {
    int i = 0, state = FIRST, name_len = 0, value_len = 0, len;

    if ((line == NULL) || (delims == NULL))
	return -1; 
    
    /* Little length play so we can also parse just a name, or value */
    if (name == NULL)
       name_len = max_name;
    if (value == NULL)
	value_len = max_value;

    len = strlen(line);

    /*
     * Little state machine. This one works with three states. One for the 
     * first word, one for the spaces inbetween, and the last for the value.
     * It will try to fill the two given arguments (name, value) with the
     * parsed result, truncated if the found value is greater than `max_name'
     * or `max_value'.
     */
    /* Yes, it's <=, because we need to NUL-terminate the result. */
    for (i = 0; i <= len; i++) {
	if (state == FIRST) {
	    if (matches_delim(line[i], delims)) {
		if (name != NULL)
		    name[name_len] = '\0';
		state = SECOND;
		continue;
	    }

	    if (name_len < max_name - 1 && name != NULL)
	    	name[name_len++] = line[i];
	    continue;
	} else if (state == SECOND) {
	    if (!matches_delim(line[i], delims))
		i--, state = THIRD; /* XXX: Looks ugly, but if it doesn't 
				       matches then we need to rewind one char 
				     */
	    continue;
	} else if (state == THIRD) {
	    if (line[i] == '\r' || line[i] == '\n' || line[i] == '\0' || 
		    i == len) {
		value[value_len] = '\0'; 
		return 0; /* Nothing left to parse */
	    }

	    if (value_len < max_value - 1)
	    	value[value_len++] = line[i];
	    continue;
	}

	return -2;
    }

    return -2;
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


int log_get_type(const char *log) 
{
    if (dstrncmp(log, "common", 6) == 0) {
	return COMMON;
    } else if (dstrncmp(log, "extended", 8) == 0) {
	return EXTENDED;
    } 
    return COMBINED;
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


/* Parse states */
enum
{
   NONE, GLOBAL, VHOST, QOS
};

/* Maximum length of a line. Used to parse files */
#define MAX_LINE_LENGTH 256


/* Parses the config file */
void parse_config_file(struct config *conf)
{
   FILE *fl;
   char *cfg_line = NULL, *name, *value, *vh;
   int linecount = 0, state = NONE;
   struct vhost *vhl;
   char *cfg_file;
   char no_cfg = 0;
   size_t len = MAX_STR_LENGTH;
   
   if(conf == NULL)
   {
      FATAL("conf stuct == NULL, should not happen!\n");
   }
   
   cfg_file = conf->config_file;
   /* Check if no config file was specified and switch to dhttpd.conf */
   if(cfg_file == NULL)
   {
      MALLOC(conf->config_file, 13);
      strlcpy(conf->config_file, "dhttpd.conf", 13);
      no_cfg = 1;
      cfg_file = conf->config_file;
   }
   
   /* Open file(or stdin if config_file == --) */
   fl = dstrncmp(cfg_file, "--", 2) == 0 ? stdin : fopen(cfg_file, "r");
   
   if(debug)
      DEBUG_OUT2("cfg: Parsing %s\n", cfg_file);
   
   /* Check if file is open */
   if(fl == NULL || ferror(fl))
   {
      FATAL("Couldn't open config file!\n"); 
      /* Config file opening error is fatal */
   }
   
   /* Allocate some memory */
   MALLOC(cfg_line, MAX_LINE_LENGTH);
   MALLOC(vh, MAX_STR_LENGTH);
   MALLOC(name, MAX_STR_LENGTH);
   MALLOC(value, MAX_STR_LENGTH);
   MALLOC(vhl, sizeof(struct vhost));
   conf->vhl = vhl;
   
   /* Read config file */
   while (!feof(fl) && (cfg_line = fgets(cfg_line, len, fl)) != NULL)
   {
      ++linecount;
      
      /* Skip lines beginning with '#' and empty ones */
      if(cfg_line[0] == '#' || cfg_line[0] == '\n' || cfg_line[0] == '\0')
         continue;
      
      if(state == NONE)
      {
         if(strstr(cfg_line, "<global>") != NULL)
         {
            state = GLOBAL;
            continue;
	 }
         else if(sscanf(cfg_line, "<vhost:%[^>]>", vh) == 1)
         {
            /* "<vhost:%[^>]>" */
            if(debug) 
               DEBUG_OUT2("cfg: Encountered vhost: %s\n", vh);
            
            set_vh_defaults(vhl);
            strlcpy(vhl->name, vh, MAX_STR_LENGTH);
            state = VHOST;
            continue;
	 }
         else if(strstr(cfg_line, "<QoS>"))
         {
            if(debug)
               DEBUG_OUT("cfg: Encountered QoS\n");
            ERROR("Warning: found QoS section in your config file, but compiled without QoS support!\n");
            continue;
            /* HAVE_QOS */
	 } 
      }
      else if(state == GLOBAL)
      {
         if(strstr(cfg_line, "</global>") != NULL)
         {
            state = NONE;   /* End of global configuring */
            continue;
         }
      }
      else if(state == VHOST)
      {
         if(strstr(cfg_line, "</vhost>") != NULL)
         {
            MALLOC(vhl->next, sizeof(struct vhost));
            vhl = vhl->next;
            state = NONE;   /* We've reached the end of this vhost */
            continue;
         } 
      }
      else
      {
         DEBUG_OUT2("cfg: Ignoring bogus line: %s\n", cfg_line);
         continue;
      }
      
      /* Get name / value pair */
      if (parse_name_value(cfg_line, name, MAX_STR_LENGTH, value, MAX_STR_LENGTH, "= ") != 0)
      {
         /* If we couldn't extract a pair, continue to next line */
         DEBUG_OUT3("cfg: unexpected line at line %d: %s!\n", linecount, cfg_line);
         continue;
      }
      
      /* Some debug output */
      if(debug)
         DEBUG_OUT3("cfg: (%s,%s)\n", name, value);
      
      /* Do what must be done */
     if(state == GLOBAL)
     {
        if(dstrncmp(name, "port", 4) == 0)
           conf->port = atoi(value);
        else if(dstrncmp(name, "debug", 5) == 0)
           debug = atoi(value);
        else if(dstrncmp(name, "https_port", 10) == 0)
        {
           ERROR("Defined https port, but compiled without https support, ignoring...\n");
        }
        else if (dstrncmp(name, "timeout", 7) == 0)
		conf->timeout = atoi(value);
	    else if (dstrncmp(name, "max_connections", 15) == 0)
		conf->backlog = atoi(value);
	    else if (dstrncmp(name, "script_pool", 11) == 0)
		conf->script_pool = atoi(value);
	    else if (dstrncmp(name, "jail_root", 9) == 0)
		strlcpy(conf->jail_root, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "user", 4) == 0)
		strlcpy(conf->user, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "perl_bin", 8) == 0)
		strlcpy(conf->perl_bin, value, MAX_STR_LENGTH);	    
	    else if (dstrncmp(name, "php_bin", 7) == 0)
		strlcpy(conf->php_bin, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "mime_file", 9) == 0)
		strlcpy(conf->mime_file, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "default_mime_type", 15) == 0)
		strlcpy(conf->default_mime_type, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "large_access_log_buffer", 21) == 0)
		conf->use_large_access_log_buffer = 1;
	    else if (dstrncmp(name, "cache_size", 10) == 0)
		conf->cache_size = atoi(value);
	    else if (dstrncmp(name, "max_cache_age", 15) == 0)
		conf->max_cache_age = atoi(value);
	    else if (dstrncmp(name, "listen_on", 9) == 0)
		strlcpy(conf->bind_addr, value, MAX_STR_LENGTH);
	    else
		DEBUG_OUT2("cfg: Unknown entity at line %d\n", linecount);
      }
      else if(state == VHOST)
      {
	    if (dstrncmp(name, "index_document", 12) == 0)
		strlcpy(vhl->index_doc, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "document_base", 11) == 0)
		strlcpy(vhl->doc_base, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "access_log", 10) == 0)
		strlcpy(vhl->log_ok, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "error_log", 9) == 0)
		strlcpy(vhl->log_err, value, MAX_STR_LENGTH);
	    else if (dstrncmp(name, "log_type", 8) == 0)
		vhl->log_type = log_get_type(value);
	    else
		DEBUG_OUT2("cfg: Unknown entity at line %d\n", linecount);
      }
      
      memset(name, 0, MAX_STR_LENGTH);
      memset(value, 0, MAX_STR_LENGTH);
   }
   
   if(debug)
      DEBUG_OUT("cfg: Parsing completed\n");
   
   /*free(vhl);*/
   free(cfg_line);
   free(vh);
   free(name);
   free(value);
   
   if(no_cfg)
      free(cfg_file);
   
   /* Let's close the file, since we don't need it */
   fclose(fl);
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


/* Creates and configures a child process */
int make_child(struct config *conf)
{
   struct vhost *vhp;
   struct stat sb;
   int default_vhost_detected = 0;
   
   /* Parse configuration file */
   parse_config_file(conf);

    for (vhp = conf->vhl; vhp != NULL; vhp = vhp->next) {
	if(debug)
	    DEBUG_OUT2("Vhost: %s\n", vhp->name);
	if(vhp->name != NULL && strncmp(vhp->name, "default", 7) == 0) 
	    default_vhost_detected = 1;
    }
    
    /* 
     * Some configuration checking 
     */
    /* Check if Perl and PHP executables are present and executable to us */
    if (stat(conf->perl_bin, &sb) == -1) {
	ERROR("Couldn't find perl location: unable to execute Perl CGI!\n");
    } else if (sb.st_mode & S_IXOTH) 
	conf->perl_available = 1;
    else 
	ERROR("Is your Perl installation valid? Can't execute perl!\n");

    if (stat(conf->php_bin, &sb) == -1) {
	ERROR("Couldn't find php location: unable to execute PHP CGI!\n");
    } else if (sb.st_mode & S_IXOTH)
	conf->php_available = 1;
    else 
	ERROR("Is your PHP installation valid? Can't execute php!\n");

    /*
     * Some rather fatal things, we NEED to be right.
     */
    if (!default_vhost_detected) {
	FATAL("No default vhost! You monkey! Fix your config; aborting!\n");
	return -1;
    }

    if (strstr(conf->default_mime_type, "/") == NULL) {
	FATAL("No default mime type! Fix your config; aborting!\n");
	return -1;
    }

    if (strlen(conf->bind_addr) < 3) {
	FATAL("You have forgotten to list where we should listen on!\n");
	return -1;
    }


    /* Open the log files */
//t    open_logs(conf);

    if (debug) {
	DEBUG_OUT("Config:\n");
	DEBUG_OUT2("- port: %d\n", conf->port);
	DEBUG_OUT2("- backlog: %d\n", conf->backlog);
	DEBUG_OUT2("- timeout: %d\n", conf->timeout);
	DEBUG_OUT2("- do_fork: %d\n", conf->do_fork);
    }

//t    parse_mime_file(conf);

    if (!conf->do_fork)
	loop(conf);
    else {
	switch ((conf->loop_child = fork())) {
	case -1:		/* We've got an error */
//t	    perror("fork()");
	    return 0;
	case 0:		/* We're the child */
	    do {
		if(conf->loop_child == -2)
		    conf->loop_child = -3;
		loop(conf);
	    } while(conf->loop_child == -2);	/* SIGCHLD ? */
	    if(debug)
		DEBUG_OUT("Loop done\n");
	    return 1;
	}
    }


    return 0;
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/* Kills all childs, and spawns a new one. This is not elegant at all. */
void restart(int i)
{
    if (debug)
	DEBUG_OUT2("Killing ppid: %d\n", getppid());

    /* Kill all the processes in our process group */
    kill(0, SIGTERM);

    if (debug)
	DEBUG_OUT("Spawning new offspring\n");

    /* Spawn a new child */
    make_child(conf);
}


//  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =


int main(int argc, char **argv)
{
   conf_t config;
   
   conf = &config;
   set_defaults(conf);
   
   printf("Starting and initializing DHD v%s\n", VERSION);
   
   signal(SIGTERM, main_shutdown);
   signal(SIGINT, main_shutdown);
   signal(SIGHUP, restart);
   signal(SIGCHLD, child_died);
   
   conf->config_file = NULL;
   parse_cmd_line(conf, argc, argv);
   
   if(debug)
      DEBUG_OUT("Debugging information will be outputted\n");
   
   if(debug)
      DEBUG_OUT2("Parent PID is: %d\n", getpid());
   
   /* Set up non specific static CGI environment vars.
    *
    * See: http://hoohoo.ncsa.uiuc.edu/cgi/env.html */
   setenv("SERVER_SOFTWARE", SERVER_VERSION, 1);
   setenv("SERVER_NAME", "localhost", 1);
   setenv("GATEWAY_INTERFACE", "CGI/1.1", 1);
   
   /* while (make_child(conf)); */
   make_child(conf);
   
   main_shutdown(666);		/* Clean up when children finish */
   return(0);
}

