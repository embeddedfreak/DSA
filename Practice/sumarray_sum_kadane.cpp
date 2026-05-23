#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/* This is the most optimised */
int main()
{
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	int n = nums.size();
	int sum = 0, maxsum = INT_MIN;
	for(int i = 0; i < n; i++) {
		sum+=nums[i];
		maxsum = maxsum < sum ? sum : maxsum;
		if(sum < 0) {
			sum = 0;
		}
	}

	cout<<"Max Subarray sum = " <<maxsum<<endl;

	return 0;
}
