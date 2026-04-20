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
    
    // Inserts a new node at the beginning of the linked list
    void push_front(int val)
    {
    // Step 1: Create a new node with the given value
        Node* newNode = new Node(val);

        // Step 2: If the list is empty,
        // both head and tail should point to the new node
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            // Step 3: Point the new node to the current head
            newNode->next = head;
            // Step 4: Update head to the new node
            head = newNode;
        }
    }
    
    // Inserts a new node at the end of the linked list
    void push_back(int val)
    {
        // Step 1: Create a new node with the given value
        Node* newNode = new Node(val);

        // Step 2: If the list is empty,
        // both head and tail should point to the new node
        if(head == NULL) {
            head = tail = newNode;
        }
        else {
            // Step 3: Link the current tail node to the new node
            tail->next = newNode;
            // Step 4: Update tail to point to the new node
            tail = newNode;
        }
    }
    
    // Removes the first node (head) from the linked list
    void pop_front()
    {
        // Step 1: If the list is empty, nothing to delete
        if (head == NULL) {
            cout << "pop_front: LList is Empty" << endl;
            return;
        }

        // Step 2: Store current head node to delete later
        Node* nodeToDel = head;

        // Step 3: If there is ONLY ONE node in the list
        if (head->next == NULL) {
            // After deletion, list becomes empty
            head = tail = NULL;
        } else {
            // Step 4: If there are MULTIPLE nodes,
            // move head to the next node
            head = head->next;
        }
        
        // Step 5: Disconnect the node (optional but safe)
        nodeToDel->next = NULL;

        // Step 6: Free memory
        delete nodeToDel;
    }
    
    // Removes the last node (tail) from the linked list
    void pop_back()
    {
        // Case 1: If the list is empty, nothing to delete
        if (head == NULL) {
            cout << "pop_back: LList is Empty" << endl;
            return;
        }

        // Case 2: If there is only one node in the list
        if (head->next == NULL) {

            // After deletion, list becomes empty
            head = tail = NULL;
            return;
        }

        // Case 3: If there are multiple nodes in the list
        // Traverse to the node just before the tail
        Node* prev_nodetoDel = head;
        while (prev_nodetoDel->next != tail) {
            prev_nodetoDel = prev_nodetoDel->next;
        }

        // Delete the tail node
        delete tail;

        // Update tail to the previous node
        tail = prev_nodetoDel;

        // Detach the new tail from the deleted node
        tail->next = NULL;
    }
    
    // Deletes the first occurrence of a node with the given value
    void deletebyVal(int val)
    {
        // Case 1: Empty list
        if (head == NULL) {
            cout << "deletebyVal: LList is Empty" << endl;
            return;
        }

        // Case 2: Value is at head
        if (head->data == val) {
            pop_front();
            return;
        }

        // Case 3: Search for the node (keep track of previous)
        Node* prev = head;

        while (prev->next != NULL && prev->next->data != val) {
            prev = prev->next;
        }

        // Case 4: Value not found
        if (prev->next == NULL) {
            cout << "Value not found" << endl;
            return;
        }

        // Case 5: Node found (middle or tail)
        Node* nodeToDel = prev->next;
        prev->next = nodeToDel->next;

        // If deleting tail, update tail
        if (nodeToDel == tail) {
            tail = prev;
        }
        delete nodeToDel;
    }
    
    // Inserts a value at the given position (0-based index)
    void insert(int pos, int val)
    {
        // Case 1: Invalid position
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        // Case 2: Insert at front
        if (pos == 0) {
            push_front(val);
            return;
        }

        // Case 3: Empty list and pos != 0
        if (head == NULL) {
            cout << "Index out of range" << endl;
            return;
        }

        // Traverse to node at position (pos - 1)
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp->next == NULL) {
                cout << "Index out of range" << endl;
                return;
            }
            temp = temp->next;
        }

        // Case 4: Insert at tail
        if (temp == tail) {
            push_back(val);
            return;
        }

        // Case 5: Insert in the middle
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    // Searches for a value and returns its index (0-based), or -1 if not found
    int search(int val)
    {
        if(head == NULL) {
            cout<<"Search: Linklist is empty"<<endl;
            return -1;
        } else {
            Node* temp = head;
            int idx = 0;
            while(temp!=NULL) {
                if(temp->data == val)
                    return idx;;
                idx++;
                temp = temp->next;
            }
        }
        return -1;
    }

    void printll()
    {
        if(head == NULL) {
            cout<<"LList is empty"<<endl;
            return;
        } else {
            Node* temp = head;
            while(temp != NULL) {
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main()
{
    LinkList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.printll();
    
    ll.push_back(100);
    ll.push_back(200);
    ll.printll();
    
    ll.pop_front();
    ll.printll();
    
    ll.pop_back();
    ll.printll();
    
    ll.deletebyVal(100);
    ll.printll();
    
    ll.insert(1, 50);
    ll.printll();
    
    cout<<"Searching: "<<ll.search(50)<<endl;
    
    cout<<"head: "<<ll.head->data<<endl;
    cout<<"tail: "<<ll.tail->data<<endl;
    
    return 0;
}
