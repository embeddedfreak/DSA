class MinStack {
public:

    // Stack stores values (normal or encoded)
    stack<long long int> st;

    // Stores the current minimum element in the stack
    long long int minVal = 0;

    // Constructor
    MinStack() {
    }
    
    // Step 1: Push an element into the stack
    void push(int val) {

        // Step 2: If stack is empty, push the value directly
        // and set it as the minimum value
        if(st.empty())  {
            st.push(val);
            minVal = val;
            return;
        }   

        // Step 3: If the value is greater than the current minimum,
        // push it normally
        if(minVal < val) {
            st.push(val);
        } 
        // Step 4: If the value is smaller than the current minimum,
        // push an encoded value and update the minimum
        else {
            st.push(2LL * val - minVal);
            minVal = val;
        }
    }
    
    // Step 5: Remove the top element from the stack
    void pop() {
        if(st.empty()) {
            return;
        } 
        else {
            // Step 6: If the top value is encoded,
            // restore the previous minimum
            if(st.top() < minVal) {
                minVal = 2 * minVal - st.top();
                st.pop();
            } 
            // Step 7: If the value is normal, simply pop it
            else {
                st.pop();
            }
        } 
    }
    
    // Step 8: Return the top element of the stack
    int top() {
        // If top value is encoded, actual top is the current minimum
        if(st.top() < minVal)
            return minVal;
        else 
            return st.top(); 
    }
    
    // Step 9: Return the minimum element present in the stack
    int getMin() {
        return minVal;
    }
};
