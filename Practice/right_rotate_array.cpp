#include <iostream> 
#include <vector>

using namespace std;


int main()
{
	vector<int> arr = {1, 2, 3, 4, 5};

	int n = arr.size();

	int save_last = arr[n-1];

	for(int i = n-2; i >= 0; i--) {
		arr[i+1] = arr[i];
	}

	arr[0] = save_last;
	for(int var: arr) {
		cout<<var<<" ";
	}

	cout<<endl;
}
