#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Input array representing block heights
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int n = height.size();

    /* Step 1: Compute the maximum height to the right of each index */
    vector<int> rbound(n);

    // Rightmost boundary is the height itself
    rbound[n - 1] = height[n - 1];

    // Traverse from right to left to fill right boundary array
    for(int i = n - 2; i >= 0; i--) {
        rbound[i] = max(height[i], rbound[i + 1]);
    }

    // Print right boundary array
    for(int val : rbound) {
        cout << val << " ";
    }
    cout << endl;

    /* Step 2: Compute the maximum height to the left of each index */
    vector<int> lbound(n);

    // Leftmost boundary is the height itself
    lbound[0] = height[0];

    // Traverse from left to right to fill left boundary array
    for(int i = 1; i < n; i++) {
        lbound[i] = max(height[i], lbound[i - 1]);
    }

    // Print left boundary array
    for(int val : lbound) {
        cout << val << " ";
    }
    cout << endl;

    /* Step 3: Calculate trapped rain water */
    int ans = 0;

    // Skip first and last index because water cannot be trapped there
    for(int i = 1; i < n - 1; i++) {
        ans += min(rbound[i], lbound[i]) - height[i];
    }

    // Print total trapped water
    cout << ans << endl;
}
``
