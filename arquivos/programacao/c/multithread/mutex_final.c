/* Program: Mutex demo
 * Author: Adenilson Cavalcanti savagobr@yahoo.com
 * Purpose: Shows effect of running a program with 2 extra execution threads
 *  with and *without* synchronization. Uses mutex for controling access
 *  to a global common resource.
 *  You can change program behaviour by setting environment variable
 *  RUN_MODE to "UNSYNC" to run the app without synchronization.
 * How to use: only execute it (from a terminal, execute "./mutex").
 * Licence: GPL vs 2.
 * To-do: Add semaphore example.
 *
 * Versions
 *
 * 10-07-2006: wrote all code.
 * 29-09-2006:
 *     code clean up && coding style.
 *     get running mode from environment variable.
 * 01-10-2006:
 *     removed warnings.
 *     added thread safe checking code.
 */

/* Gives a hint to compiler to use some thread safe function versions
 * of some functions normaly defined as macros.
 */
#define _REENTRANT
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

/* This environment variable controls running mode */
const char RUN_MODE[] = "RUN_MODE";
const char UNSYNC[] = "UNSYNC";
const char SYNC[] = "SYNC"; /* not really necessary */

/* This variable is going to be increased/decreased */
int global = 100;

/* Our beloved mutex (only used when running in 'SYNC' mode */
static pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

/* Times to run each function loop */
int mtimes = 0x10; /* 16 in decimal base */

/* Auxiliary function */
float square(float i);

/* Unsynchronized functions */
void *add(void *);
void *minus(void *);

/* Synchronized functions */
void *s_add(void *);
void *s_minus(void *);

/* Main app function */
int main(int argc, char * argv[])
{

	int res;
	pthread_t thread1, thread2;
	char *env;

	/* Export environment variable to change program running mode. */
	env = getenv(RUN_MODE);
	if (env)
		printf("var is: %s\n", env);

	/* Run unsynchronized */
	if (env && (!strncmp(UNSYNC, env, sizeof(UNSYNC)))) {

		printf("Running unsynchronized\n");
		res = pthread_create(&thread1, NULL, add, NULL);
		if (res)
			goto error;

		res = pthread_create(&thread2, NULL, minus, NULL);
		if (res)
			goto error;

	} else { /* otherwise, run synchronized */

		printf("Running synchronized\n");
		/*	pthread_mutex_init(&mutex1, NULL);	 */
		res = pthread_create(&thread1, NULL, s_add, NULL);
		if (res)
			goto error;

		res = pthread_create(&thread2, NULL, s_minus, NULL);
		if (res)
			goto error;

	}


	/* Collect the running threads (we don't want to risk close
	 * the process with running threads).
	 */
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);


/* Test to see if system provides thread safe versions of functions
 * e.g. ctime X ctime_r
 */
#ifdef _POSIX_THREAD_SAFE_FUNCTIONS
	printf("System does support thread safe reentrant functions\n");
#endif

	pthread_mutex_destroy(&mutex1);
	exit(0);

error:
	printf("Thread creation failed! Exiting...\n");
	exit(1);
}

/* From here the code is self explanatory. */
void *add(void *msg)
{
	printf("\tentering add\n");
	fflush(NULL);
	int i;

	for (i= 0; i < mtimes; ++i) {
		global++;
		printf("global add  (should be 101) %d\n", global);
		/* Give time to other thread run. */
		usleep(5);
		global--;
	}

	/* Give us some time to see how many threads does it have. */
	sleep(20);
	pthread_exit(NULL);
}

void *minus(void *msg)
{
	printf("\tentering minus\n");
	fflush(NULL);
	int i;

	for (i = 0; i < mtimes; ++i) {
		global--;
		printf("global minus (should be 99) %d\n", global);
		/* Give time to other thread run. */
		usleep(5);
		global++;
	}

	/* Give us some time to see how many threads does it have. */
	sleep(20);
	pthread_exit(NULL);
}

void *s_add(void *msg)
{
	printf("\tentering s_add\n");
	fflush(NULL);
	int i;

	for (i= 0; i < mtimes; ++i) {
		pthread_mutex_lock(&mutex1);
		global++;
		printf("global s_add  (should be  101) %d\n", global);
		global--;
		/* Flushes all output streams */
		fflush(NULL);
		pthread_mutex_unlock(&mutex1);

		/* Simulate some useful number crunching, that DONT
		 * needs to run synchronized.
		 */
		square(12.333);
	}

	/* Give us some time to see how many threads does it have. */
	sleep(20);
	pthread_exit(NULL);
}

void *s_minus(void *msg)
{

	printf("\tentering s_minus\n");
	fflush(NULL);
	int i;

	for (i= 0; i < mtimes; ++i) {
		pthread_mutex_lock(&mutex1);
		global--;
		printf("global s_minus (should be  99)  %d\n", global);
		global++;
		/* Flushes all output streams */
		fflush(NULL);
		pthread_mutex_unlock(&mutex1);

		/* Simulate some useful number crunching, that DONT
		 * needs to run synchronized.
		 */
		square(12.333);

	}

	/* Give us some time to see how many threads does it have. */
	sleep(20);
	pthread_exit(NULL);
}

float square(float i)
{

	float tmp = 0;
	tmp = i;
	tmp *= i;
	/* Lets suppose that it will take longer (2/1000000 sec)... */
	usleep(2);

	return tmp;
}
