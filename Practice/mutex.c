#include <stdio.h>
#include <pthread.h>


int count = 0;
pthread_mutex_t lock;

void* func(void* args)
{

	for(int i = 0; i < 100000; i++) {
		pthread_mutex_lock(&lock);
		count+=1;
		pthread_mutex_unlock(&lock);
	}	
}

int main()
{
	pthread_t t1, t2;
	
	pthread_mutex_init(&lock, NULL);

	pthread_create(&t1, NULL, func, NULL);
	pthread_create(&t2, NULL, func, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Count = %d\n", count);

	pthread_mutex_destroy(&lock);
	return 0;
}
