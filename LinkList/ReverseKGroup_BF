class Solution {
public:
    void reverse_Linklist(ListNode* head, ListNode* tail)
    {
        ListNode* prev = tail->next; 
        ListNode* curr = head;
        ListNode* next = NULL;

        while(prev != tail) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* Ghead = NULL;
        ListNode* Gtail = NULL;
        ListNode* prevTail = NULL;
        ListNode* newHead = head;

        while (temp != NULL) {
            // find k nodes
            for (int i = 0; i < k; i++) {
                if (temp == NULL) return newHead;
                if (i == 0) Ghead = temp;
                if (i == k - 1) Gtail = temp;
                temp = temp->next;
            }

            // reverse the group
            reverse_Linklist(Ghead, Gtail);

            // update new head after first group
            if (prevTail == NULL)
                newHead = Gtail;
            else
                prevTail->next = Gtail;

            prevTail = Ghead; // Ghead becomes tail after reversal
        }

        return newHead;
    }
};
