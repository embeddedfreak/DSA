/******************************************************************************

Program to find the Left Smaller Element index for each element
in an integer array using a stack-based approach.

*******************************************************************************/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    // Input array
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    
    // Print the input array
    for(int val : heights) {
        cout << val << " ";
    }
    cout << endl;
    
    /* Step 1: Prepare array to store Left Smaller indices */
    vector<int> ls(heights.size());
    
    /* Step 2: Stack to store indices of elements */
    stack<int> st;
    
    int n = heights.size();
    
    /* Step 3: Traverse the array from left to right */
    for(int i = 0; i <= n - 1; i++) {
        
        /* Step 4: Remove indices from stack while the element
           at those indices is greater than or equal to current element */
        while(!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        
        /* Step 5: If stack becomes empty, no smaller element exists on the left */
        if(st.empty()) {
            ls[i] = -1;
        }
        /* Step 6: Otherwise, top of stack is the left smaller index */
        else {
            ls[i] = st.top();
        }
        
        /* Step 7: Push current index onto the stack */
        st.push(i);
    }
    
    /* Step 8: Print the Left Smaller indices */
    for(int val : ls) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
