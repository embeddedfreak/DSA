#include <stdio.h>

int main() 
{
	unsigned int num, count = 0;

	printf("Enter a number:\n");
	scanf("%u", &num);

/* This was my method of implementing 
	while(num){
		if(num & 1U) {
			count++;
		}
		num = num >> 1U;
	}	
*/

/* Brian Kernighan’s Algorithm is a fast way 
 * to count how many 1s (set bits) are in a binary number.
 * Instead of checking every bit one by one, 
 * the algorithm repeatedly removes the rightmost 1 bit from the number.
 * n = n & (n - 1)
 * 13 = 1101
 * 1101 & 1100 = 1100
 * 1100 & 1011 = 1000
 * 1000 & 0111 = 0000
 */
	while(num) {
		num = num & (num-1);
		count++;
	}

	printf("Total set bits are: %u\n", count);
	return 0;
}

