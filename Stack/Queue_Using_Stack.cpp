class MyQueue {
public:

    // Two stacks used to simulate queue behavior
    stack<int> s1;
    stack<int> s2;

    // Constructor
    MyQueue() {
        
    }
    
    // Step 1: Push element to the queue
    void push(int x) {

        // Move all elements from s1 to s2
        // This helps maintain FIFO order
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element into s1
        s1.push(x);

        // Move all elements back to s1
        // Now the oldest element remains at the top of s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    // Step 2: Remove and return the front element
    int pop() {
        int ans = s1.top();  // Top of s1 acts as queue front
        s1.pop();            // Remove it
        return ans;
    }
    
    // Step 3: Return the front element without removing it
    int peek() {
        return s1.top(); 
    }
    
    // Step 4: Check whether the queue is empty
    bool empty() {
        return s1.empty();
    }
};
