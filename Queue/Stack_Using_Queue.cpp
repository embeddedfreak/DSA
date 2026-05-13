class MyStack {
public:

    // Two queues used to simulate stack behavior
    queue<int> q1;
    queue<int> q2;

    // Constructor
    MyStack() {
    }
    
    // Step 1: Push element onto stack
    void push(int x) {

        // Move all elements from q1 to q2
        // This helps maintain stack (LIFO) order
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the new element into q1
        q1.push(x);

        // Move all elements back from q2 to q1
        // Now, the newest element is at the front of q1
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
    }
    
    // Step 2: Remove and return the top element
    int pop() {
        int ans = q1.front();  // Front element acts as stack top
        q1.pop();              // Remove it
        return ans;
    }
    
    // Step 3: Return the top element without removing it
    int top() {
        return q1.front();
    }
    
    // Step 4: Check if the stack is empty
    bool empty() {
        return q1.empty();   
    }
};
