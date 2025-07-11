
// Generate a log message using FMT string and option arguments.

// #include<sys/syslog.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern void syslog (int priority, const char *fmt, ...);
extern void openlog (const char *ident, int option, int facility);
extern void closelog (void);

#define	LOG_DAEMON	(3<<3)	// system daemons
#define	LOG_PID		0x01	// log the pid with each message

// priority
#define	LOG_EMERG	0	/* system is unusable */
#define	LOG_ALERT	1	/* action must be taken immediately */
#define	LOG_CRIT	2	/* critical conditions */
#define	LOG_ERR		3	/* error conditions */
#define	LOG_WARNING	4	/* warning conditions */
#define	LOG_NOTICE	5	/* normal but significant condition */
#define	LOG_INFO	6	/* informational */
#define	LOG_DEBUG	7	/* debug-level messages */

int main()
{
   openlog("syslog.c", LOG_PID, LOG_DAEMON);
   syslog(LOG_INFO, "Isso é um teste.");
   // veja o arquivo /var/log/syslog
   closelog();
   return(0);
}

