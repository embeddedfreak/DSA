#include <stdio.h>

int main()
{
	unsigned int num;
	printf("Enter a number\n");
	scanf("%u", &num);
/* Below is my method, which might be right for num = 12 
 * but its wrong approach
 */
//	printf("Right most set bit is : %u\n", (num & ~(num-1)));
/* Take example of num = 6 -> 0x0110
 * Two's complement is -6 -> 0x1010 
 * Now & both.
 */
	printf("Right most set bit is : %u\n", (num & (-num)));

	return 0;
}

