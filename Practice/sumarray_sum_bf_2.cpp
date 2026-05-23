#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5};

	int n = arr.size();
	int maxsum = INT_MIN;


	for(int st = 0; st < n; st++) {
		int sum = 0; 
		for(int end = st; end < n; end++) {

			sum+=arr[end];
			maxsum = maxsum < sum? sum : maxsum;
		}   
	}   
	cout<<"Maxsum = " << maxsum <<endl;
}
