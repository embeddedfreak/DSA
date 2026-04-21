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
    
    int findMiddleNode()
    {
        // slow pointer will move one step at a time
        Node* slow;
        // fast pointer will move two steps at a time
        Node* fast;
    
        // Initialize both pointers to the head of the list
        slow = fast = head;
    
        // Traverse the list until fast reaches the end
        // Condition ensures we don't dereference NULL
        while (fast != NULL && fast->next != NULL) {
            // Move slow by one node
            slow = slow->next;
            // Move fast by two nodes
            fast = fast->next->next;
        }
    
        // When fast reaches the end,
        // slow will be pointing to the middle node
        return slow->data;
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

    cout<<"Middle Node is: "<<ll.findMiddleNode()<<endl;
    
    return 0;
}
