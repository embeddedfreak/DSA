#include <stdio.h>
#include <pthread.h>

void* thread_func(void * args)
{
	int num = *(int*)args;
	printf("I am runnning thread t1 = %d\n", num);

}

int main() 
{
	pthread_t t1;

	int num = 10;

	pthread_create(&t1, NULL, thread_func, &num);


	pthread_join(t1, NULL);
	return 0;
}
