#include <stdio.h>
#include <string.h>

#if 0
size_t my_strlen(char *str)
{
	char *start = str;

	while(*str) {
		str++;
	}	

	return str - start;
}

int my_strcmp(char *str1, char *str2)
{
	if(my_strlen(str1) != my_strlen(str2)) {
		return 0;
	}

        while (*str1 && *str2) {
		if(*str1++ != *str2++)
			return 0;
	}
	return 1;

}
#endif

/*
strcmp(): returns

0
Strings are completely identical.
strcmp("Apple", "Apple") → 0

< 0 (Negative)
str1 is lexicographically less than str2.
strcmp("Apple", "Banana") → negative value

> 0 (Positive)
str1 is lexicographically greater than str2.
strcmp("Banana", "Apple") → positive value
*/
int my_strcmp(char* str1, char* str2)
{
	while((*str1 == *str2) && (*str1 != '\0')) {
		str1++;
		str2++;
	}
	return (unsigned char)*str1 - (unsigned char)*str2;
}

int main()
{
        char str1[10], str2[10];

        printf("Enter string 1:\n");
        scanf("%9s", str1);

        printf("Enter string 2:\n");
        scanf("%9s", str2);
        
	if(!my_strcmp(str1, str2)) {
		printf("Both Strings are equal\n");
	} else {
		printf("Both Strings are not equal\n");
		
	}

        return 0;
}
