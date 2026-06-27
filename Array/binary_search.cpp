/*
Problem: Binary Search (Iterative)

Algorithm:
1. Initialize two pointers: start (st) at 0 and end at n-1.
2. Repeat while st <= end:
   - Find mid = st + (end - st) / 2.
   - If middle element equals the target, return mid.
   - If target is smaller than middle element, search in left half (end = mid - 1).
   - Otherwise, search in right half (st = mid + 1).
3. If element is not found, return -1.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> vec, int ele)
{
        int n = vec.size();

        int st = 0;
        int end = n-1;
        while(st<=end) {
                int mid = st+(end-st)/2;
                if(vec[mid] == ele) {
                        return mid;
                } else if(ele < vec[mid]) {
                        end = mid - 1;
                } else {
                        st = mid + 1;
                }
        }
        return -1;

}

int main()
{
        vector<int> vec = {1, 2, 3, 4, 5};

        int ele = 5;

        cout<<"Element "<<ele<<" is at location "<<binary_search(vec, ele)<<endl;
        return 0;
}
