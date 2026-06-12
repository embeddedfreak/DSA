#include <stdio.h>

int main()
{
	int arr[5] = {1, 2, 3, 2, 1};

	int size = sizeof(arr)/sizeof(arr[0]);

	int unique = 0;

	for(int i = 0; i < size; i++) {
		unique ^= arr[i];	
	}

	printf("Unique number = %d\n", unique);

}
