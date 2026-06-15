#include <stdio.h>

int CountFlippedBits(int a , int b)
{
	int xornum = (a ^ b);

	int count = 0;

	while(xornum) {
		if(xornum & 1)
			count++;
		xornum = xornum >> 1;
	}

	return count;

}


int main()
{
	int a = 3, b = 8;

	printf("Total Flipped bits are: %d\n", CountFlippedBits(a, b));
	return 0;
}
