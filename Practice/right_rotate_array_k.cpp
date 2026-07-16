#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate_array(vector<int> &nums, int k) 
{
	/* If k = 10 and n = 7
	* That means the k > n edge case
	* Bring it to limit within n
	*/
	int n = nums.size();
	k = k % n;
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin()+k);
	reverse(nums.begin()+k, nums.end());
}	

int main()
{
	vector<int> nums = {1,2,3,4,5,6,7};
	int k = 3;
	
	rotate_array(nums, k);

	for(int var: nums) {
		cout<<var<<" ";
	}

	cout<<endl;

	return 0;
}
