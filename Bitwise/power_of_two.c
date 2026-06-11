#include <stdio.h>

int main()
{
	unsigned int num;
	printf("Enter the number:\n");
	scanf("%u", &num);

	if((num != 0) && !(num & (num-1))) {
		printf("Number %u is power of two\n", num);
	} else {
		printf("Number %u is not power of two\n", num);
	}
}
