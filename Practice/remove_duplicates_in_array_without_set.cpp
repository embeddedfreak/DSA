#include <iostream>
#include <vector>

using namespace std;


void remove_Duplicate(vector<int> &arr, vector<int> &nums, int n)
{
    for(int i = 0; i < n; i++) {
        bool duplicate = false;
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                duplicate = true;
                break;
            }
        }
        
        if(!duplicate) {
            nums.push_back(arr[i]);
        }
        
    }
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 4};
    
    vector<int> new_arr;
    
    int n = arr.size();
    
    remove_Duplicate(arr, new_arr, n);
    
    for(int val : new_arr) {
        cout<<val<<" ";
    }
    
    cout<<endl;

    return 0;
}
