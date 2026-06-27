/*
Problem: Majority Element (Sorting Approach)

Algorithm:
1. Sort the array in non-decreasing order.
2. Traverse the sorted array and count consecutive occurrences of each element.
3. Maintain a frequency counter:
   - If current element is same as previous, increment frequency.
   - Otherwise, reset frequency to 1.
4. If frequency becomes greater than n/2, that element is the majority element.
5. Print the majority element and stop execution.

Time Complexity: O(n log n) due to sorting
Space Complexity: O(1) (ignoring sorting space depending on implementation)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        vector<int> vec = {2, 2, 3, 1, 2};

        int n = vec.size();

        sort(vec.begin(), vec.end());

        int freq = 1;
        for(int i = 1; i < n; i++) {
                if(vec[i] == vec[i-1]) {
                        freq++;
                } else {
                        freq = 1;
                }
                if(freq > n/2) {
                        cout<<"Majority Elements is: "<<vec[i]<<endl;
                        break;
                }
        }
        return 0;
}
