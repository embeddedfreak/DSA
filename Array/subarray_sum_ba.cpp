/*
Problem: Maximum Subarray Sum (Better Approach)

Algorithm:
1. Consider every possible starting index of a subarray.
2. Initialize the sum as 0 for the current starting index.
3. Extend the subarray one element at a time by moving the ending index.
4. Add the current element to the running sum instead of recalculating the entire subarray sum.
5. Compare the running sum with the maximum sum found so far.
6. Update the maximum sum if the current subarray sum is greater.
7. After checking all possible subarrays, print the maximum subarray sum.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
        vector<int> arr = {1, 2, 3, 4, 5};
        int n = arr.size();

        int maxSum = INT_MIN;

        for(int st = 0; st < n; st++) {
                int sum = 0;
                for(int end = st; end < n; end++) {
                        sum += arr[end];
                        maxSum = (maxSum < sum)? sum : maxSum;
                }
        }

        cout<<"Max Sum is:"<<maxSum<<endl;

}
