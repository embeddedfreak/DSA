#include <stdio.h>


int add(int a, int b)
{
	return a + b;
}

int main()
{
	int a, b;
	printf("Enter 2 numbers to add\n");
	scanf("%d%d", &a, &b);

	int (*fptr) (int, int);

	fptr = add;

	printf("Summ of a and b is %d\n", fptr(a, b));

	return 0;
}


