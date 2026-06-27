/*
Problem: Maximum Subarray Sum (Brute Force)

Algorithm:
1. Consider every possible starting index of a subarray.
2. For each starting index, consider every possible ending index.
3. Calculate the sum of the current subarray by traversing from the starting index to the ending index.
4. Compare the current subarray sum with the maximum sum found so far.
5. Update the maximum sum if the current subarray sum is greater.
6. After checking all possible subarrays, print the maximum subarray sum.

Time Complexity: O(n^3)
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
                for(int end = st; end < n; end++) {
                        int sum = 0;
                        for(int i = st; i <= end; i++) {
                                sum = sum + arr[i];
                        }
                        maxSum = (maxSum < sum) ? sum : maxSum;
                }
        }

        cout << "Max Sum is:" << maxSum << endl;

}

