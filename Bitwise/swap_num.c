#include <stdio.h>

void swap(int *a, int *b) 
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main() 
{
	int a, b;
	printf("Enter 2 numbers:\n");
	scanf("%d %d", &a, &b);

	swap(&a, &b);

	printf("After swap: a = %d, b = %d\n", a, b);



}
