#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;
    
    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    // If original list is empty, nothing to copy
    if (head == NULL) {
        return NULL;
    }

    // Map to store mapping from original node -> copied node
    unordered_map<Node*, Node*> m;

    // Create the first node of copied list using head's data
    Node* newhead = new Node(head->data);

    // temp is used to traverse original list (starting from second node)
    Node* temp = head->next;

    // newtemp is used to build the copied list
    Node* newtemp = newhead;

    // Store mapping from original head to copied head
    m[head] = newhead;

    // First pass:
    // Copy all nodes and set only NEXT pointers
    while (temp != NULL) {

        // Create a copy of current original node
        Node* copyNode = new Node(temp->data);

        // Save mapping from original node to copied node
        m[temp] = copyNode;

        // Connect copied nodes using next pointer
        newtemp->next = copyNode;

        // Move to next nodes in both lists
        temp = temp->next;
        newtemp = newtemp->next;
    }

    // Reset temp and newtemp to the start of both lists
    temp = head;
    newtemp = newhead;

    // Second pass:
    // Set RANDOM pointers using the map
    while (temp != NULL) {

        // If original random exists, copy it using map
        // Otherwise, copied random should be NULL
        newtemp->random =  m[temp->random];

        // Move forward in both lists
        temp = temp->next;
        newtemp = newtemp->next;
    }

    // Return head of deep-copied list
    return newhead;
}


void printll(Node* head)
{
    Node* temp = head;
    
    if(head == NULL) {
        cout<<"Linked List is empty"<<endl;
    }
    
    while(temp!=NULL) {
        cout << "Node Address: " << temp
        << " [" << temp->data << "] "
        << "Next: ";

        if (temp->next)
            cout << temp->next << " (" << temp->next->data << ") ";
        else
            cout << "NULL ";

        cout << "Random: ";
        if (temp->random)
            cout << temp->random << " (" << temp->random->data << ")";
        else
            cout << "NULL";

        cout << endl;
            temp = temp->next;
        }
        cout<<endl;
}

int main()
{
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);
    
    
    //Create single link
    Node* head = n1; 
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    
    //Create random pointers;
    
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;
    
    printll(head);
    
    Node* newhead = copyRandomList(head);

    printll(newhead);
  
    return 0;
}
