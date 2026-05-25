#include <iostream>
#include <vector>

using namespace std;


int miss_num(vector<int> nums) 
{
    if(nums.empty()) {
        return -1;
    }
    
    int st = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
            st++;
            
            if(nums[i] != st) {
                return st;
            }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 6};

    cout<<"Missing number is : "<< miss_num(nums)<<endl;

    return 0;
}
