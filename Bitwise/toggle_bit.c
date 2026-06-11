#include <stdio.h>

int main() 
{
	unsigned int num;
	unsigned int pos;
	printf("Enter a number:\n");
	scanf("%u", &num);

	printf("Enter the position of bit to toggle\n");
	scanf("%u", &pos);

	if(pos >= sizeof(num) * 8) {
		printf("Invalid Position!!\n");
		return -1;
	}

	num ^= (1U<<pos);

	printf("After toggling %u position num is: %u\n", pos, num);
	return 0;
}

