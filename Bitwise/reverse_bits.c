#include <stdio.h>
/* 
 * Expected Approach
 * Create a separate result variable.
 * For each bit:
 * 1. Extract the current LSB from num.
 * 2. Shift result left by one.
 * 3. Insert extracted bit into result.
 * 4. Shift num right by one.
 */

int main()
{
	unsigned int num = 13;

	unsigned int result = 0;

	for(int i = 0; i < 32; i++) {
		
		result <<= 1;
		result |= (num & 1);
		num >>=1;
	}

	printf("Reversed number is %u\n" , result);
	return 0;
}
