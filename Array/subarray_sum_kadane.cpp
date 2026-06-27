/*
Problem: Maximum Subarray Sum (Kadane's Algorithm)

Algorithm:
1. Initialize the current sum as 0 and the maximum sum as the smallest possible integer.
2. Traverse the array from left to right.
3. Add the current element to the current sum.
4. Update the maximum sum if the current sum is greater than the maximum sum.
5. If the current sum becomes negative, reset it to 0 since a negative sum cannot contribute to a larger subarray sum.
6. Continue until all elements are processed.
7. Print the maximum subarray sum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
        vector<int> arr = {3, -4, 5, 4, -1, 7, -8};
        int n = arr.size();

        int maxSum = INT_MIN;

        int sum = 0;
        for(int i = 0; i < n; i++) {
                        sum += arr[i];
                        maxSum = (maxSum < sum)? sum : maxSum;

                        if(sum < 0) {
                                sum = 0;
                        }
        }

        cout<<"Max Sum is:"<<maxSum<<endl;
}
