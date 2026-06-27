/*
Problem: Pair Sum (Two Pointer Approach)

Algorithm:
1. Initialize two pointers:
   - One at the beginning of the sorted array.
   - One at the end of the sorted array.
2. Calculate the sum of the elements at both pointers.
3. If the sum equals the target, store the pair and terminate the search.
4. If the sum is greater than the target, move the right pointer one step to the left.
5. If the sum is less than the target, move the left pointer one step to the right.
6. Repeat the process until the two pointers meet.
7. Return the found pair.

Time Complexity: O(n)
Space Complexity: O(1) (excluding the output vector)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> pair_sum(vector<int> vec, int n, int target)
{
        vector<int> ans;

        int i = 0;
        int j = n-1;

        int p_sum = 0;

        while(i < j) {
                p_sum = vec[i] + vec[j];

                if(p_sum == target) {
                        ans.push_back(vec[i]);
                        ans.push_back(vec[j]);
                        break;

                } else if(p_sum > target) {
                        j--;
                } else {
                        i++;
                }
        }
        return ans;
}

int main()
{
        vector<int> vec = {2, 7, 11, 15};

        int target = 9;

        int n = vec.size();

        vector<int> ans;

        ans = pair_sum(vec, n, target);

        for(int val: ans) {
                cout<<val<<" ";
        }

        cout<<endl;

        return 0;
}
