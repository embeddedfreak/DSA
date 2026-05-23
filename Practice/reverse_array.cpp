#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	int n = sizeof(arr)/sizeof(int);

	int st = 0, end = n-1;

	while(st <= end) {
		int temp = arr[st];
		arr[st] = arr[end];
		arr[end] = temp;		
		st++;
		end--;
	}

	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
