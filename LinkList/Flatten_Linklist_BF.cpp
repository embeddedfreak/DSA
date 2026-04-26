/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) {
            return NULL;
        }

        Node* curr = head;
        Node* currhead, *tail;

        Node* next;
        while(curr->child ==NULL) {
            if(curr->next == NULL) {
                tail = curr;
                return head;
            }
            curr = curr->next;
        }

        //keep backup of first node of new level
        currhead = curr->child;
       // if(curr->next == NULL)
        //    return curr->next;
        if(curr->next)
            next = curr->next;
        currhead = flatten(curr->child);

        curr->child = NULL;
        curr->next = currhead;
        currhead->prev = curr;

        Node* temp = currhead;
        while(temp->next!=NULL) {
            temp = temp->next;
        }

        temp->next = next;
        if(next)
            next->prev = temp;

        return head;
        
    }
};
