/*
Problem: Product of Array Except Self (Brute Force)

Algorithm:
1. Create an answer array initialized with 1 for all positions.
2. For each index i in the array:
   - Traverse the entire array again.
   - Multiply all elements except the element at index i.
3. Store the product in ans[i].
4. Print the resulting array.

Time Complexity: O(n^2)
Space Complexity: O(n) (output array only)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
        vector<int> vec = {1, 2, 3, 4};

        int n = vec.size();

        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j ++) {
                        if(i != j) {
                                ans[i] *= vec[j];
                        }
                }
        }

        for(int val: ans) {
                cout<<val<<" ";
        }

        cout<<endl;
        return 0;
}
