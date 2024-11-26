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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *current = head;
        ListNode p1(0), p2(0);

        ListNode *less = &p1;
        ListNode *greater = &p2;

        while (current) {
            if (current->val >= x) {
                greater->next = current;
                greater = greater->next;
            } else {
                less->next = current;
                less = less->next;
            }
            current = current->next;
        }
        greater->next = nullptr;
        less->next = p2.next;
        return p1.next;
    }
};
