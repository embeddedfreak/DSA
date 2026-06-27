/*
Problem: Majority Element (Moore’s Voting Algorithm)

Algorithm:
1. Initialize a candidate element and a frequency counter.
2. Traverse the array:
   - If frequency is 0, set current element as the candidate and set frequency to 1.
   - If current element equals the candidate, increment frequency.
   - Otherwise, decrement frequency.
3. After traversal, the candidate is the potential majority element.
4. Since majority element is guaranteed in this problem, print the candidate.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
        vector<int> vec = {2, 2, 1, 1, 2};

        int n = vec.size();

        sort(vec.begin(), vec.end());

        int freq = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
                if(freq == 0) {
                        ans = vec[i];
                        freq++;
                } else if (vec[i] == ans) {
                        freq++;
                } else {
                        freq--;
                }
        }
        if(freq > 0) {
                cout<<"Majority Elements is: "<<ans<<endl;
        }
        return 0;
}

