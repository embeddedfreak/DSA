/*
Problem: Pair Sum (Brute Force)

Algorithm:
1. Traverse the array using the first loop and select one element at a time.
2. For each selected element, traverse the remaining elements using the second loop.
3. Check whether the sum of the current pair equals the target value.
4. If a matching pair is found, store both elements in the answer vector.
5. Continue checking all possible pairs.
6. Return the answer vector and print the pair.

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding the output vector)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> pair_sum(vector<int> vec, int n, int target)
{
        vector<int> ans;

        for(int i = 0; i < n -1 ; i++) {
                for(int j = i+1; j < n; j++) {
                        if(target == (vec[i] + vec[j])) {
                                ans.push_back(vec[i]);
                                ans.push_back(vec[j]);
                        }
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
