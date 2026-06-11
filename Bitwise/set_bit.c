#include <stdio.h>

int main() 
{
	unsigned int num;
	unsigned int pos;
	printf("Enter a number:\n");
	scanf("%d", &num);

	printf("Enter the bit to set\n");
	scanf("%d", &pos);

	if(pos >= 32) {
		printf("Invalid Position!!\n");
		return -1;
	}

	num |= (1U<<pos);

	printf("After setting %d position num is: %d", pos, num);
	return 0;
}

