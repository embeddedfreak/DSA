/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Node {
public: 
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkList {
public:
    Node* head;
    Node* tail;
    
    LinkList() {
        head = tail = NULL;
    }
    
    void printll()
    {
        if(head == NULL) {
            cout<<"Linklist is empty"<<endl;
        } else {
            Node* temp = head;
            while(temp!=NULL) {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }

    void detectRemoveCycle() {
        // Slow pointer moves one step at a time
        Node* slow;
        
        // Fast pointer moves two steps at a time
        Node* fast;
        
        // Flag to indicate whether a cycle is detected
        bool isCycle = false;
        
        // Initialize both pointers to the head of the linked list
        slow = fast = head;

        // Step 1: Detect cycle using Floyd's Algorithm
        // Loop continues until fast reaches the end (no cycle)
        while (fast != NULL && fast->next != NULL) {
            // Move slow pointer by one node
            slow = slow->next;

            // Move fast pointer by two nodes
            fast = fast->next->next;

            // If slow and fast meet, a cycle exists
            if (slow == fast) {
                isCycle = true;
                break;  // Stop as soon as cycle is detected
            }
        }

        // If no cycle was detected, exit the function
        if (!isCycle) {
            cout << "LinkList has no Cycle" << endl;
            return;
        }

        // Step 2: Find the starting node of the cycle
        // Reset slow pointer to the head
        slow = head;

        Node* prev;
        // Pointer to keep track of node just before fast
        // Used later to break the cycle

        // Move both pointers one step at a time
        // They will meet at the starting node of the cycle
        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
    
        // slow (or fast) now points to the start of the cycle
        cout << "Node where cycle begins is: " << slow->data << endl;

        // Step 3: Remove the cycle
        cout << "Removing the cycle ..." << endl;

        // Break the cycle by setting the last node's next to NULL
        prev->next = NULL;

        // Print the corrected linked list
        printll();
    }

};

int main()
{
    LinkList ll;
    
    ll.head = new Node(10);
    ll.head->next = new Node(20);
    ll.head->next->next = new Node(30);
    ll.head->next->next->next = new Node(40);
    ll.head->next->next->next->next = new Node(50);
    ll.tail = ll.head->next->next->next->next;
    
    // Create cycle: tail (50) points to node with value 30
    ll.tail->next = ll.head->next->next;

    ll.detectRemoveCycle();
    
    return 0;
}
