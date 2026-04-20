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
    
    void reverse() 
    {
        if(head == NULL) {
            cout<<"Reverse: Llist is emply"<<endl;
            return;
        } else {
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            
            tail = head;
            
            while(curr!=NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
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
    ll.head = new Node(10);
    ll.head->next = new Node(20);
    ll.head->next->next = new Node(30);
    ll.tail = ll.head->next->next->next = new Node(40);
    ll.printll();
    cout<<"head->"<<ll.head->data<<endl;
    cout<<"tail->"<<ll.tail->data<<endl;
    
    ll.reverse();
    
    cout<<"After Reverse"<<endl;
    ll.printll();
    cout<<"head->"<<ll.head->data<<endl;
    cout<<"tail->"<<ll.tail->data<<endl;
  
    return 0;
}
