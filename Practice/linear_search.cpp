#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};

	int n = sizeof(arr)/sizeof(int);

	int key = 5;
	int index = -1;

	for(int i = 0; i < n; i++) {
		if(arr[i] == key) {
			index = i;
			break;
		}
	}
	cout<<key<<" is at index: "<<index;
	cout<<endl;
}
