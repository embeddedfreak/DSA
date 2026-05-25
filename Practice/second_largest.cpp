#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int Second_Largest(vector<int> nums) 
{
	int largest = INT_MIN, slar = INT_MIN;

	for(int i = 0; i < nums.size(); i ++)
	{
		if(largest < nums[i]) {
			slar = largest;
			largest = nums[i]; 
		}

		else if(nums[i] < largest && nums[i] > slar) {
			slar = nums[i];
		}
	}
	return slar;
}
int main()
{
	//vector<int> nums = {1, 2, 3, 5, 10};
	vector<int> nums = {10, 2, 3, 7, 8};

	cout<<"Second Largest Element is: "<<Second_Largest(nums)<<endl;
	return 0;
}
