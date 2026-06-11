#include <stdio.h>

int main() 
{
	unsigned int num;
	unsigned int pos;
	printf("Enter a number:\n");
	scanf("%u", &num);

	printf("Enter the position of bit to clear\n");
	scanf("%u", &pos);

	if(pos >= 32) {
		printf("Invalid Position!!\n");
		return -1;
	}

	unsigned int mask = ~(1U<<pos);
	num &= mask;

	printf("After clearing %d position num is: %u\n", pos, num);
	return 0;
}

