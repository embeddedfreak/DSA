/*
Problem: Single Number

Algorithm:
1. Initialize a variable `xor_num` to 0.
2. Traverse each element of the array.
3. Perform the XOR operation between `xor_num` and the current element.
4. Since XOR of a number with itself is 0 and XOR of a number with 0 is the number itself,
   all duplicate elements cancel each other out.
5. The remaining value is the element that appears only once.
6. Print the unique element.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
        vector<int> vec = {1, 2, 3, 1, 2};

        int xor_num = 0;

        for(int val: vec) {
                xor_num ^= val;
        }

        cout<<xor_num<<endl;

        return 0;
}
