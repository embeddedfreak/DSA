#include <iostream>

using namespace std;

int binary_search(int arr[], int n)
{
	int st = 0;
	int end = n-1;
	int mid;
	int key = 1;

	while(st <= end) {
		
		mid = st + (end-st)/2;
		if(arr[mid] == key) {
			return mid;
		}

		if(key < arr[mid]) {
			end = mid - 1;
		} else {
			st = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	int n = sizeof(arr)/sizeof(int);

	cout<<binary_search(arr, n);

	cout<<endl;
}
