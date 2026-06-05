#include <stdio.h>
#include<string.h>

int main()
{
	char str[10];

	printf("Enter a string\n");
	scanf("%9s", str);

	int len = strlen(str);

	int i = 0;
	int j = len-1;

	while(i <= j) {
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

	printf("String after reverse is %s\n", str);

	return 0;
}
