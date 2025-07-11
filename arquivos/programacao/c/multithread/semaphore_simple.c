/* Program: Pthread sample program
 * Author: Adenilson Cavalcanti savagobr@yahoo.com
 * Purpose: Shows how to synchronize a thread using semaphore.
 *
 * How to use: only execute it (from a terminal, execute "./sem").
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
#include <semaphore.h>

void *first(void *arg);
void *second(void *arg);

sem_t bin_sem;

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	char argt1[] = "thread1";
	char argt2[] = "thread2";
	int rc;

	rc = sem_init(&bin_sem, 0, 0);

	rc = pthread_create(&t1, NULL, first, (void *)&argt1);
	rc = pthread_create(&t2, NULL, second, (void *)&argt2);

	rc = pthread_join(t1, NULL);
	rc = pthread_join(t2, NULL);

	sem_destroy(&bin_sem);

	return 0;


}

void *first(void *arg)
{
	int i;
	pthread_t myId;
	myId = pthread_self();

	printf("I'm the firsthread, my ID is: %d \n", myId);
	sleep(5);

	for (i = 0; i < 4; ++i) {
		printf("%s \n", (char *)arg);
		sem_post(&bin_sem);
		/* Give time to kernel schedule other thread */
		usleep(1);
	}
	pthread_exit(NULL);
}

void *second(void *arg)
{
	int i;
	pthread_t myId;
	myId = pthread_self();

	printf("I'm the secondthread, my ID is: %d \n", myId);

	for (i = 0; i < 4; ++i) {
		sem_wait(&bin_sem);
		printf("%s \n", (char *)arg);
		/* Since this thread will wait for semaphore be
		 * incremented by sem_post, we don't need to
		 * sleep to force the kernel to schedule other
		 * thread.
		 */

	}

	pthread_exit(NULL);
}

