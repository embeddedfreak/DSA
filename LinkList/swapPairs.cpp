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
    ListNode* swapPairs(ListNode* head) {
        /* If its not a pair */
        if(head == NULL || head->next == NULL) {
            return head;
        }

        /* Take pair as (first, second) */
        ListNode* first = head;
        ListNode* second = head->next;
        
        /* Recursive call */
        first->next = swapPairs(second->next);

        /* returned head of next pair is already pointed by first->next */
        /* second->next pointed to first will swap */
        second->next = first;

        /* Should return second which will be the head now of that pair */
        return second;
    } 
};
