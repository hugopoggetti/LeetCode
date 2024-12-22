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
#include <climits>
#include <ctime>
class Solution {
public:

    ListNode *getKth(ListNode *cur, int k)
    {
        while (cur && k > 0) {
            cur = cur->next;
            k--;
        }
        return cur;
    }


    ListNode* reverseKGroup(ListNode* head, int k)
   {
        ListNode *dummy = new ListNode(0, head);
        ListNode *group_prev = dummy;

        while (true) {
            ListNode *kth = getKth(group_prev, k);
            if (!kth)
                break;
            ListNode *group_next = kth->next;

            // reverseKGroup
            ListNode *prev = kth->next;
            ListNode *cur = group_prev->next;

            while (cur != group_next) {
                ListNode *tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }
            ListNode *tmp = group_prev->next;
            group_prev->next = kth;
            group_prev = tmp;
        }
        return dummy->next;

    }
};
