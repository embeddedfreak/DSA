#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
    }
};

class CLinkList {
public:
    Node* head;
    Node* tail;
    
    CLinkList() {
        head = tail = NULL;
    }
    
    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            tail = head = newNode;
            tail->next = head;
            return;
        }
        
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    
    void push_back(int val) 
    {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    
    void pop_front()
    {
        if(head == NULL) {
            cout<<"pop_front: Linked List is Empty"<<endl;
            return;
        }
        
        if(head == tail) {
            delete head;
            head = tail = NULL;
        }
        
        Node* temp = head;
        head = head->next;
        tail->next = head;
        
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back()
    {
        if(head == NULL) {
            cout<<"pop_back: Linklist is Empty"<<endl;
            return;
        }
        
        if(head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        
        Node *temp = head;
        
        while(temp->next!=tail) {
            temp = temp->next;
        }
        
        tail->next = NULL;
        delete tail;
        
        tail = temp;
        tail->next = head;
    }
    
    void printll() {
        if(head == NULL) {
            cout<<"Linked List is empty"<<endl;
            return;
        }
        
        cout<<head->data<<"->";
        Node* temp = head->next;
        
        while(temp!=head) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
   
};

int main()
{
    CLinkList ll;
    
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
    
    return 0;
}
