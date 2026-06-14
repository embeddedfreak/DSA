#include <stdio.h>

int main()
{
	int arr[] = {6, 1, 3, 3, 3, 6, 6};
//	int arr[] = {5, 5, 5, 12, 7, 7, 7};

	int n = sizeof(arr)/sizeof(arr[0]);

	int unique = 0;

	for(int i = 0; i < 32; i++) {
		int count = 0;
		for(int j = 0; j < n; j++) { 
			if(arr[j] & (1 << i)) {
				count++;
			}
		}
		if((count % 3) == 1) {
			unique = unique | (1 << i);			
		}
	}

	printf("Unique element is %d\n", unique);

	return 0;
}

