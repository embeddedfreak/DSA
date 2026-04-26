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
        Node* curr = head;
        Node* next;

        /* Remember to traverse entire Linked list till end */
        while (curr != NULL) {
            if (curr->child) {
                /* Flatten the Linklist */
                next = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                /* Find the tail */
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                /* Attach the tail with next pointer*/
                if (next) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            // update curr to next;
            curr = curr->next;
        }

        return head;
    }
};
