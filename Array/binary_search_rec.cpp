/*
Problem: Binary Search (Recursive)

Algorithm:
1. Define a recursive function with start (st) and end (end) indices.
2. Base condition: If st > end, return -1 (element not found).
3. Find mid = st + (end - st) / 2.
4. If mid element equals target, return mid.
5. If target is smaller than mid element, search in left half recursively.
6. Otherwise, search in right half recursively.
7. Return the index if found, otherwise return -1.

Time Complexity: O(log n)
Space Complexity: O(log n) due to recursion stack
*/

#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> vec, int tar, int st, int end)
{

        if(st<=end) {
                int mid = st+(end-st)/2;
                if(vec[mid] == tar) {
                        return mid;
                } else if(tar < vec[mid]) {
                        return binary_search(vec, tar, st, mid-1);
                } else {
                        return binary_search(vec, tar, mid+1, end);
                }
        }
        return -1;

}

int main()
{
        vector<int> vec = {1, 2, 3, 4, 5};

        int tar = 5;

        int n = vec.size();

               int st = 0;
        int end = n-1;


        cout<<"Element "<<tar<<" is at location "<<binary_search(vec, tar, st, end)<<endl;
        return 0;
}
