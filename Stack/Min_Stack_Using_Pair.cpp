
class MinStack {
public:
    // Stack to store pairs:
    // first  -> actual value pushed
    // second -> minimum value in the stack up to this point
    stack<pair<int, int>> st;

    // Constructor
    MinStack() {
    }
    
    // Step 1: Push a value into the stack
    void push(int val) {

        // Step 2: If the stack is empty,
        // the pushed value itself is the minimum
        if(st.empty()) {
            st.push({val, val});
            return;
        } 

        // Step 3: Compare current value with
        // the minimum value stored at the top
        if(val < st.top().second) {
            // New value becomes the new minimum
            st.push({val, val});
        } else {
            // Minimum remains unchanged
            st.push({val, st.top().second});
        }
    }
    
    // Step 4: Remove the top element from the stack
    void pop() {
        st.pop();
    }
    
    // Step 5: Return the top element of the stack
    int top() {
        return st.top().first;
    }
    
    // Step 6: Return the minimum element in the stack
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
