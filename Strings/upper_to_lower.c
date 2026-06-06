#include <stdio.h>
#include <string.h>
int main() {
	char str[10];

	printf("Enter a string\n");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';

	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] >= 'A' && str[i] <='Z') {
			str[i] = str[i] + 32;
		}
	}

	printf("String after converting to lowercase: %s\n", str);

	return 0;
}
