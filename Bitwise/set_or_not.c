#include <stdio.h>

int main() 
{
	unsigned int num;
	unsigned int pos;
	printf("Enter a number:\n");
	scanf("%u", &num);

	printf("Enter the position of bit to check if its set\n");
	scanf("%u", &pos);

	if(pos >= sizeof(num) * 8U) {
		printf("Invalid Position!!\n");
		return -1;
	}

	if(num & (1U<<pos)){
		printf("Bit at pos %u, is set\n", pos);
	} else {
		printf("Bit at pos %u, is not set\n", pos);
	}	
	return 0;
}

