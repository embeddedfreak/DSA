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

Node* mergeTwoLists(Node* head1, Node* head2)
{
    // Step 1: Handle base cases
    // If either list is empty, return the non-empty list
    // This also stops the recursion
    if (head1 == NULL || head2 == NULL) {
        return (head1 == NULL ? head2 : head1);
    }

    // Step 2: Compare the current nodes of both lists
    // Choose the node with the smaller value
    if (head1->data <= head2->data) {

        // Step 3: Link the chosen node to the merged result
        // Recursively merge the remaining nodes
        head1->next = mergeTwoLists(head1->next, head2);

        // Step 4: Return the selected node as part of merged list
        return head1;
    } 
    else {

        // Step 3 (alternate path): Choose node from second list
        // Recursively merge the remaining nodes
        head2->next = mergeTwoLists(head1, head2->next);

        // Step 4: Return the selected node as part of merged list
        return head2;
    }
}

void printll(Node* head) 
{
    if(head == NULL) {
        cout<<"Linklist is Empty"<<endl;
        return;
    }
    
    Node* temp = head;
    
    while(temp!=NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(6);

    Node* head = mergeTwoLists(head1, head2);
    
    printll(head);
    
    return 0;
}
