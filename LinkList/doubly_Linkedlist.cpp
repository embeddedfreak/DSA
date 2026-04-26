#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class LinkList {
public:
    Node* head;
    Node* tail;
    
    LinkList() {
        head = tail = NULL;
    }
    
    void push_front(int val) {
        Node* newNode = new Node(val);
        
        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            newNode->prev = NULL;
            head = newNode;
        }
    }
    
    void push_back(int val) {
        Node* newNode = new Node(val);
        
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void pop_front()
    {
        if(head == NULL) {
            cout<<"LinkList is empty"<<endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        
        if(head != NULL) {
            head->prev = NULL;
        }
        
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back()
    {
        if(head == NULL) {
            cout<<"LinkList is empty"<<endl;
            return;
        }
        
        Node* temp = tail;
        tail = tail->prev;
        
        if(tail != NULL) {
            tail->next = NULL;
        }
        
        temp->prev = NULL;
        delete temp;
    }
    
    void printll() 
    {
        if(head == NULL) {
            cout<<"LinkList is Empty"<<endl;
            return;
        }
        
        Node* temp = head;
        while(temp!=NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        
        cout<<"NULL"<<endl;
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

    return 0;
}
