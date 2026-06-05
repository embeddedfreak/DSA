#include <stdio.h>
#include<string.h>
#include <stdbool.h>

bool isPalindrome(char str[])
{
	int len = strlen(str);

	int i = 0;
	int j = len-1;

	while(i <= j) {
		if(str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}

int main()
{
	char str[10];

	printf("Enter a string\n");
	scanf("%9s", str);

	if(isPalindrome(str)) {
		printf("String entered is a palindrome\n");
	} else {
		printf("String entered is not a palindrome\n");
	}

	return 0;
}
