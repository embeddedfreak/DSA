#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // Input array
    vector<int> arr = {6, 8, 0, 1, 3};
    int n = arr.size();
    
    // Array to store the next greater element for each index
    vector<int> ans(arr.size(), 0);
    
    // Stack used to keep elements to compare for next greater element
    stack<int> st;
    
    // Traverse the array from right to left
    for(int i = n-1; i >= 0; i--) {

        // Remove elements from stack that are smaller
        // or equal to the current element
        while(st.size() > 0 && st.top() <= arr[i]) {
            st.pop();
        }
        
        // If stack is empty, no greater element exists on the right
        if(st.empty()) {
            ans[i] = -1;
        } 
        // If stack is not empty, the top of the stack
        // represents the next greater element
        else {
            ans[i] = st.top();
        }
        
        // Push current element onto the stack
        st.push(arr[i]);
    }
    
    // Print the result array
    for(int val: ans) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
