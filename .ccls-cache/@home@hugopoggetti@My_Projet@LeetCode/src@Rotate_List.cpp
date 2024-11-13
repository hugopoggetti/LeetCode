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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == NULL)
            return NULL;

        int count = 1;
        ListNode *current = head;

        while (current->next != NULL) {
            current = current->next;
            count++;
        }
        current->next = head;
        k = k % count;
        for (auto i = 0; i < count - k; i++) {
            current = current->next;
        }
        head = current->next;
        current->next = NULL;
        return head;
    }
};
