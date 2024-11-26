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
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;
            // swap Nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            // increment
            prev = first;;
        }
        return dummy->next;
    }
};
