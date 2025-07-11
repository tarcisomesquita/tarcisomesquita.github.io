#ifndef TYPES_H
#define TYPES_H

#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>

# ifdef HAVE_CONFIG_H
#  include <config.h>
# endif /* HAVE_CONFIG_H */

#ifdef HAVE_PERL
#include <pthread.h>

#include <EXTERN.h>
#include <perl.h>
#endif /* HAVE_PERL */

#ifdef HAVE_QOS
#include <qos/qos.h>
#endif

 /* Do this so we won't have to in other files */
#if  !defined(HAVE_STRLCAT) || !defined(HAVE_STRNCPY) || !defined(HAVE_FGETLN)
#include "additional.h"
#endif /* missing funcs.. */
 
# ifdef HAVE_OPENSSL
#  include <openssl/ssl.h>
# endif /* HAVE_OPENSSL */


/* Types of children we can create */
enum {
    INET = 1, INET6 = 2, SINET = 4, SINET6 = 8
};

/* Connnection states */
enum {
    NEED_ACCEPT, QUEUED, READ, PARSED, FOUND, PROCESSED, EXECUTING, SENT, CLOSE, FAULT
};

/* Parse states */
enum {
    NONE, GLOBAL, VHOST, QOS
};

/* Types of server interpretable scripts */
enum {
    PLAINTEXT, EX_PERL, EX_PHP, EX_RUBY, EX_PYTHON, EX_CGI, EX_MISC
};

/* HTTP Methods */
enum {
    GET = 0, HEAD, POST, PUT, OPTIONS, DELETE, TRACE, CONNECT, UNKNOWN
    
};


#ifndef RELEASE
# ifndef HAVE_WARN
#  define warn printf
# endif
# ifdef HAVE_SETPROCTITLE
#  define SETTITLE1( a )    \
    setproctitle("%s, %d: %s", __FILE__, __LINE__, a);
#  define SETTITLE  \
    setproctitle("%s, %d: %s", __FILE__, __LINE__, strerror(errno));
# else
#  define SETTITLE1( a )    \
    warn("%s, %d: %s", __FILE__, __LINE__, a);
#  define SETTITLE  \
    warn("%s, %d", __FILE__, __LINE__);
# endif
#else
# define SETTITLE ;
# define SETTITLE1( a ) ;
#endif

/* Portability defines */
#ifndef HAVE_SETLINEBUF
#define setlinebuf(x) setvbuf(x, (char *)NULL, _IOLBF, 0);
#endif


/* Sockets */
#ifdef HAVE_QOS
#define CLOSE	    close_qos
#define SOCKET	    socket_qos
#define ACCEPT	    accept_qos
#define SEND	    send_qos
#define RECV	    recv_qos
#else
#define CLOSE	    close
#define SOCKET	    socket
#define ACCEPT	    accept
#define SEND	    send
#define RECV	    recv
#endif

/* Memory allocation help macros */
#define ALLOC_CHK( a )		\
	if (a == NULL) { \
	    DEBUG_OUT2("Couldn't allocate enough memory for %s\n", #a); \
	    abort ( ); \
	}

/* XXX XXX XXX XXX XXX Need to declare panic function XXX XXX XXX XXX XXX */
void a_lot_of_panic(void);

#ifndef RELEASE
#define MALLOC( a, b )		\
	if ((a = malloc(b)) == NULL ) { \
		DEBUG_OUT2("Couldn't allocate enough memory for %s\n", #a); \
		a_lot_of_panic( ); \
	} else { memset(a, 0, b); }
#else
#define MALLOC( a, b ) a = malloc(b)
#endif

#define FREE( a )		\
	if (a == NULL) { \
		if( debug )  \
			DEBUG_OUT2("%s not allocated!?\n", #a ); \
	} else { \
		if( debug ) \
			DEBUG_OUT2("freeing %s\n", #a ); \
		free( a ); \
	}

/* Should be defined, define for ancient UN*X */
#ifndef S_ISDIR
#define S_ISDIR(mode)	(((mode) & S_IFMT) == S_IFDIR)
#endif

/* 
 * Neccesairy data types 
 */

typedef struct mime mime_t;
typedef struct request req_t;
typedef struct connection conn_t;

/* Recursive list containing all the mime types */
struct mime {
    char *type;			/* The string containing the current type */
    char *ext;
    mime_t *next;		/* Use of chaining in hash table */
};


/* Some flags set in a connection */
struct flags {
    /* Some connection specific booleans */
    unsigned int is_secure:1;
    unsigned int is_ipv6:1;
    unsigned int is_persistent:1;
    unsigned int is_pipelined:1;
};

/* Information on a connection */
struct connection {
    int s;			/* The socket */
    int sock_num;		/* Number the socket has in the queue */
    unsigned char state;	/* Current state of the connection */
    /*conn_t **connections;	*//* The list of connections */
    req_t *req;			/* Relevant request data of this connection */
    struct sockaddr_in *sa;	/* IPv4 Info */
#ifdef HAVE_IPV6
    struct sockaddr_in6 *sa6;	/* IPv6 info */
#endif /* HAVE_IPV6 */
    vhost_t *vh;		/* Virtual host */
    struct flags f;
    time_t last_success; /* The time of the last successful send */
    time_t send_interval;	/* Time we should wait for a slow connection */
};

/* Struct containing all info on a request */
struct request {
    char *host,			/* Host field */
	*useragent,		/* The browser of the client */
	*referer,		/* Well duh (typo RFC mandated :P) */
	*file,			/* Requested file */
	*file_buf,		/* Actual file */
	*file_loc,		/* Physical file location */
	*recv_buf,		/* What we received from the client */
	*http_version,		/* The HTTP version used */
	*cookie;		/* Cookie string */
    unsigned char method;	/* Method used in the request */
    unsigned long file_size;	/* size of the requested file */
    unsigned short response,	/* The response code for the request */
	double_err,		/* We could encounter an error upon an error */
	cgi_slot;		/* The slot number when in cgi mode */
    int sent_bytes,		/* Amount we sent so far */
	fd,
	write_pipe;		/* Filedescriptor and write pipe for the requested file/cgi */
# ifdef HAVE_OPENSSL
    SSL *ssl_s;			/* the SSL socket */
# endif	/* HAVE_OPENSSL */
    unsigned char script_type;	/* Kind of executable we're dealing with */
# ifdef HAVE_PERL
    int perl_argc;		/* Argument count */
    char **perl_env,		/* The enviroment of the perl script */
	**perl_argv;		/* Arguments of the perl script */
#endif	/* HAVE_PERL */
#ifdef HAVE_LINUX_ZCT
    off_t *offset;		/* Used by sendfile as offset */
#endif	/* HAVE_LINUX_ZCT */
    struct stat *sbuf;		/* stat information */
    vhost_t *vh;		/* Vhost we're in */
    conn_t *conn;		/* Our connection */
    unsigned int error:1;	/* Indicates if the current request is erred */
    unsigned int has_cookie:1;	/* If this request needs a cookie */
};

#ifdef HAVE_PERL
/* A descriptor for a node in the Perl interpreter pool */
typedef struct pi {
    PerlInterpreter *pi;
    pthread_mutex_t *lock;
} pi_t;
#endif /* HAVE_PERL */

#ifdef HAVE_PERL
/* A descriptor for a script in execution */
typedef struct script {
    pthread_t tid; /* Recognize the thread */
    pthread_cond_t *scriptPresent; /* Used if there aren't any scripts needing to run */
    pthread_mutex_t *scriptLock; /* Have to use mutexes for locking */
    conn_t *conn;
/* #ifdef HAVE_PERL */
    pi_t *pi;
/* #endif */
} script_t;
#endif /* HAVE_PERL */

#endif /* TYPES_H */
