#include <iostream>
using namespace std;

class CirQueue {
public:
    int* arr;        // Dynamic array to store queue elements
    int cap;         // Maximum capacity of the queue
    int currSize;    // Current number of elements in the queue
    int f, r;        // Front and rear indices
    
    // Step 1: Initialize the circular queue
    CirQueue(int size) 
    {
        arr = new int[size];  // Allocate memory for queue
        cap = size;           // Set capacity
        currSize = 0;         // Queue starts empty
        f = 0;                // Front starts at index 0
        r = -1;               // Rear starts before the first element
    }
    
    // Step 2: Insert an element into the circular queue
    void push(int data)
    {
        // Check if the queue is full
        if(currSize == cap) {
            cout << "Circular Queue is FULL" << endl;
            return;
        }
        
        // Move rear forward and insert element
        r = (r + 1);
        arr[r] = data;
        
        // Increase current size
        currSize++;
    }
    
    // Step 3: Remove an element from the circular queue
    void pop()
    {
        // Check if the queue is empty
        if(currSize == 0) {
            cout << "Circular Queue is Empty" << endl;
            return;
        }
        
        // Move front forward to remove the element
        f = (f + 1);
        
        // Decrease current size
        currSize--;
    }
    
    // Step 4: Return the front element of the queue
    int front()
    {
        return arr[f];
    }
};

int main()
{
    // Create a circular queue with capacity 3
    CirQueue cq(3);
    
    // Insert elements into the queue
    cq.push(10);
    cq.push(20);
    cq.push(30);
    
    // Remove one element from the queue
    cq.pop();
    
    // Insert another element to demonstrate reuse of space
    cq.push(40);

    // Print and remove all elements from the queue
    while(cq.currSize != 0) {
        cout << cq.front() << " ";
        cq.pop();
    }

    return 0;
}
