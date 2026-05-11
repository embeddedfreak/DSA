/******************************************************************************

Program to implement a Queue using a Singly Linked List.

*******************************************************************************/
#include <iostream>
using namespace std;

class Node {
public: 
    int data;      // Stores the value of the node
    Node* next;    // Pointer to the next node
    
    // Constructor to initialize node
    Node(int val) 
    {
        data = val;
        next = NULL;
    }
};

class Queue {
public:
    Node *head, *tail;   // Head -> front of queue, Tail -> rear of queue
    
    // Step 1: Initialize an empty queue
    Queue() {
        head = tail = NULL;
    }
    
    // Step 2: Check if the queue is empty
    bool empty()
    {
        return head == NULL;
    }
    
    // Step 3: Insert an element at the rear of the queue
    void enqueue(int val) {
        Node* newNode = new Node(val);
        
        // If queue is empty, both head and tail point to new node
        if(empty()) {
            head = tail = newNode;
            return;
        }
        
        // Otherwise, add new node after tail and update tail
        tail->next = newNode;
        tail = newNode;
    }
    
    // Step 4: Remove an element from the front of the queue
    void dequeue() {
        
        // If queue is empty, no element to remove
        if(empty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        
        // Store current head node
        Node* temp = head;
        
        // Move head to the next node
        head = head->next;
        
        // If queue becomes empty, reset tail as well
        if(head == NULL) {
            tail = NULL;
        }
        
        // Delete the removed node
        delete temp;
    }
    
    // Step 5: Get the front element of the queue
    int front()
    {
        if(empty()) {
            return -1;
        }
        return head->data; 
    }
};

int main()
{
    Queue q;
   
    // Insert elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
   
    // Remove and print elements from the queue
    while(!q.empty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
    cout << endl;
   
    return 0;
}
