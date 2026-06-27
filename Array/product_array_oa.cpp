/*
Problem: Product of Array Except Self (Optimized Prefix-Suffix Approach)

Algorithm:
1. Use a single answer array to store prefix products.
2. First pass (prefix):
   - ans[i] stores product of all elements to the left of index i.
   - ans[0] is initialized to 1 since there are no elements on the left.
3. Second pass (suffix):
   - Maintain a running suffix product starting from the right side.
   - Multiply suffix product with ans[i] to include right-side contribution.
4. Update suffix while traversing from right to left.
5. Final ans array contains product of all elements except self.

Time Complexity: O(n)
Space Complexity: O(1) extra space (excluding output array)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
        vector<int> vec = {1, 2, 3, 4};

        int n = vec.size();

        vector<int> ans(n, 1);

        //prefix
        for(int i=1; i < n; i++) {
                ans[i] = ans[i-1] * vec[i-1];
        }

        //suffix
        int suffix = 1;
        for(int j = n-2; j >= 0; j--) {
                suffix = suffix * vec[j+1];
                ans[j] *= suffix;
        }


        for(int val : ans) {
                cout<<val<<" ";
        }

        cout<<endl;

        return 0;
}

