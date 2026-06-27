/*
Problem: Majority Element (Brute Force)

Algorithm:
1. Traverse each element of the array.
2. For every element, count its frequency by scanning the entire array.
3. If the frequency of any element is greater than n/2, it is the majority element.
4. Print the majority element and stop the execution.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
        vector<int> vec = {2, 2, 3, 1, 2};

        int n = vec.size();

        for(int ele: vec) {
                int freq = 0;
                for(int val: vec) {
                        if(ele == val) {
                                freq++;
                        }
                }
                if(freq > n/2) {
                        cout<<"Majority Elements is: "<<ele<<endl;
                        break;
                }
        }
        return 0;
}
