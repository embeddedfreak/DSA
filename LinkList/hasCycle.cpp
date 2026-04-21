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
    
    
    bool hasCycle() {
        // Slow pointer: moves one step at a time
        Node* slow;

        // Fast pointer: moves two steps at a time
        Node* fast;

        // Initialize both pointers to the head of the linked list
        slow = fast = head;

        // Traverse the list while fast pointer can move ahead safely
        while(fast != NULL && fast->next != NULL) {
            // Move slow pointer by one node
            slow = slow->next;
            // Move fast pointer by two nodes
            fast = fast->next->next;
            // If slow and fast meet, a cycle exists
            if(slow == fast) {
                return true;
            }
        }
        // If fast reaches NULL, there is no cycle in the list
        return false;
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


    cout<<"Check for Cycle: "<<ll.hasCycle()<<endl;
    
    return 0;
}
