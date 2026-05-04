#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    // Input array
    vector<int> arr = {3, 1, 0, 8, 6};
    
    // Result array to store previous smaller elements
    vector<int> ans(arr.size(), 0);
    
    // Stack to maintain elements in increasing order
    stack<int> st;
    
    // Step 1: Traverse the array from left to right
    for(int i = 0; i < arr.size(); i++) {

        // Step 2: Remove elements from the stack that are
        // greater than or equal to the current element
        while(st.size() > 0 && st.top() >= arr[i]) {
            st.pop();
        }
        
        // Step 3: If stack is empty, no smaller element exists on the left
        if(st.empty()) {
            ans[i] = -1;
        } 
        // Step 4: If stack is not empty, top of the stack
        // is the previous smaller element
        else {
            ans[i] = st.top();
        }
        
        // Step 5: Push the current element onto the stack
        st.push(arr[i]);
    }
    
    // Step 6: Print the result array
    for(int val: ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
