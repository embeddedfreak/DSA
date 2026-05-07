#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Input array representing block heights
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int n = height.size();
    
    // Step 1: Initialize two pointers at both ends
    int l = 0, r = n - 1;
    
    // Step 2: Track maximum heights from left and right
    int lmax = 0, rmax = 0;

    // Variable to store total trapped water
    int ans = 0;   
    
    // Step 3: Traverse the array until both pointers meet
    while (l < r) {

        // Update left and right maximums
        lmax = max(height[l], lmax);
        rmax = max(height[r], rmax);
        
        // Step 4: Decide which side to process
        if (lmax < rmax) {
            // Water trapped at left index depends on lmax
            ans += (lmax - height[l]);
            l++;
        } else {
            // Water trapped at right index depends on rmax
            ans += (rmax - height[r]);
            r--;
        }
    }

    // Step 5: Output total trapped rain water
    cout << ans << endl;
}
