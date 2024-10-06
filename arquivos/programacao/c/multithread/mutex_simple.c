/* Program: Pthread sample program
 * Author: Adenilson Cavalcanti savagobr@yahoo.com
 * Purpose: Shows how to synchronize a thread using mutex.
 *
 * How to use: only execute it (from a terminal, execute "./mutex").
 * Licence: GPL vs 2.
 *
 * Versions
 *
 * 02-10-2006: wrote all code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>


void *first(void *arg);
void *second(void *arg);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	char argt1[] = "thread1";
	char argt2[] = "thread2";
	int rc;

	rc = pthread_create(&t1, NULL, first, &argt1);
	rc = pthread_create(&t2, NULL, second, &argt2);

	rc = pthread_join(t1, NULL);
	rc = pthread_join(t2, NULL);

	return 0;


}

void *first(void *arg)
{
	int i;
	pthread_t id;
	id = pthread_self();

	printf("I'm the first thread, my ID is: %d \n", id);
	sleep(1);

	for (i = 0; i < 4; ++i) {
		pthread_mutex_lock(&mutex);
		printf("%s \n", (char *)arg);
		fflush(NULL);
		pthread_mutex_unlock(&mutex);
		/* Give time to kernel schedule other thread */
		usleep(1);
	}
	pthread_exit(NULL);
}

void *second(void *arg)
{
	int i;
	pthread_t id;
	id = pthread_self();

	printf("I'm the second thread, my ID is: %d \n", id);
	sleep(1);

	for (i = 0; i < 4; ++i) {
		pthread_mutex_lock(&mutex);
		printf("%s \n", (char *)arg);
		fflush(NULL);
		pthread_mutex_unlock(&mutex);
		/* Give time to kernel schedule other thread */
		usleep(1);
	}
	pthread_exit(NULL);
}

