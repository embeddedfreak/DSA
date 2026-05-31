#include <stdio.h>
#include <pthread.h>
#include<semaphore.h>


int count = 0;
sem_t sem;

void* func(void* args)
{
	for(int i = 0; i < 100000; i++) {
		sem_wait(&sem);
		count+= 1;
		sem_post(&sem);
	}
}
int main()
{
	pthread_t t1, t2;


	sem_init(&sem, 0, 1);

	pthread_create(&t1, NULL, func, NULL);
	pthread_create(&t2, NULL, func, NULL);


	pthread_join(t1, NULL);
	pthread_join(t2, NULL);


	printf("Count = %d\n", count);

	sem_destroy(&sem);
	return 0;
}
