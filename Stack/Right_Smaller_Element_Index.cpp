/******************************************************************************

Program to find the Right Smaller Element index for each bar
in a histogram using a stack-based approach.

*******************************************************************************/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    // Input histogram heights
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    // Print the input array
    for(int val: heights) {
        cout << val << " ";
    }
    cout << endl;
    
    /* Step 1: Prepare array to store Right Smaller indices */
    vector<int> rs(heights.size());
    
    /* Step 2: Stack to store indices of bars */
    stack<int> st;
    
    int n = heights.size();
    
    /* Step 3: Traverse the histogram from right to left */
    for(int i = n - 1; i >= 0; i--) {
        
        /* Step 4: Pop indices from stack while the height at
           those indices is greater than or equal to current height */
        while(!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        
        /* Step 5: If stack becomes empty, no smaller bar exists on the right */
        if(st.empty()) {
            rs[i] = n;
        }
        /* Step 6: Otherwise, the top of stack is the right smaller index */
        else {
            rs[i] = st.top();
        }
        
        /* Step 7: Push current index onto stack */
        st.push(i);
    }
    
    /* Step 8: Print the Right Smaller indices */
    for(int val: rs) {
        cout << val << " ";
    }
    
    cout << endl;
    
    return 0;
}
