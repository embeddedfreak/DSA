#include <stdio.h>

int main()
{
	/* variable is constant */
	const int a = 10;
	//a = 20; Cannnot be done like this
	printf("Value of a = %d\n", a);

	/* ptr is the pointer pointing to constant data */
	int b = 20;
	const int *ptr = &b;
	int c = 30;
	//*ptr = 30; Not allowed
	ptr = &c;
	printf("Value in ptr = %d\n", *ptr);

	/* ptr is the constant pointer pointing to variable data */
	int d = 40;
	int *const ptr1 = &d;

	int e = 50;
	//ptr1 = &e; This is not allowed
	*ptr1 = 50;
	printf("Value in ptr1 = %d\n", *ptr1);

	/* ptr2 is the constant pointer pointing to constant data*/
	int f = 60;
	const int *const ptr2 = &f;
	//*ptr2 = 70;
	int g = 70;
	//ptr2 = &g;

	printf("Value in ptr2 = %d\n", *ptr2);
	
	return 0;
}
