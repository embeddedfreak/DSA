#include <stdio.h>
#include <string.h>

struct Count {
	int vow_count;
	int cons_count;
	int digit_count;
	int space_count;	
};

int main()
{
	char str[10];

	struct Count c = {0};
	printf("Enter a String\n");
	scanf("%[^\n]s", str);

	int i = 0;

	while(str[i] != '\0') {
		if(str[i] >= '0' && str[i] <= '9') {
			c.digit_count++;
		} else if(str[i] == ' ') {
			c.space_count++;
		} else if((str[i] >= 'A' && str[i] <= 'Z') || 
				(str[i] >= 'a' && str[i] <= 'z')) {
			if(str[i] == 'A' || str[i] == 'a' ||
					str[i] == 'E' || str[i] == 'e' || 
					str[i] == 'I' || str[i] == 'i' ||
					str[i] == 'O' || str[i] == 'o' ||
					str[i] == 'U' || str[i] == 'u') {
				c.vow_count++;
			} else {
				c.cons_count++;
			}
		}
		i++;
	}		
	printf("%d %d %d %d\n", c.vow_count, c. cons_count, c.digit_count, c.space_count);
	return 0;
}
