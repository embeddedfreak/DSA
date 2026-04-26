/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        /* Check if K node exists */
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }

        /* Recursive call to remaining Linklist */
        ListNode* newhead = reverseKGroup(temp, k);

        /* Reverse the LinkList */
        ListNode* next;
        temp = head;

        for (int i = 0; i < k; i++) {
            next = temp->next;
            temp->next = newhead;
            newhead = temp;
            temp = next;
        }
        return newhead;
    }
};
