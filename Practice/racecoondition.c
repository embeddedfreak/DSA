#include <stdio.h>
#include <pthread.h>

int count = 0;

void* func(void* args)
{
	for(int i = 0; i < 100000; i++) {
		count += 1;
	}	
}

int main()
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, func, NULL);
	pthread_create(&t2, NULL, func, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("Count = %d\n", count);
	return 0;
}
