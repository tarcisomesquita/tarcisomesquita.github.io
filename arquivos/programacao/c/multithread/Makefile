all: sync_mutex minimal sem mutex

minimal: minimal.o
	gcc -o minimal minimal.o -lpthread

sem: semaphore_simple.o
	gcc -o sem semaphore_simple.o -lpthread

mutex: mutex_simple.o
	gcc -o mutex mutex_simple.o -lpthread

sync_mutex: mutex_final.o
	gcc -o sync_mutex mutex_final.o -lpthread

clean:
	rm -f *.o *~ minimal mutex sem sync_mutex