/* Divide by 2 to make a number 0 */

#include <stdio.h>

int CountDivision(int num)
{
	int count = 0;
	while(num) {
		num = num >> 1;
		count++;
	}
	return count;
}

int main()
{
	int num;
	printf("Enter a number:\n");
	scanf("%d", &num);

	printf("Total number of times num %d, should be divided "
			"is %d to make it 0\n", num, CountDivision(num));
	return 0;
}
