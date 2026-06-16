#include <stdio.h>
#include <stddef.h>
/*
struct Student {
	char a;
	int num;
	char b;
}__attribute__((packed));
*/

#pragma pack()

struct Student {
	char a;
	int num;
	char b;
};

int main()
{
	printf("%zu\n", offsetof(struct Student, a));
	printf("%zu\n", offsetof(struct Student, num));
	printf("%zu\n", offsetof(struct Student, b));
	printf("Size of struct Student is : %ld\n", sizeof(struct Student));
	return 0;
}
