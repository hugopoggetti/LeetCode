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
    ListNode* insertionSortList(ListNode* head)
    {
        vector<int> values;

        ListNode *curr = head;

        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        sort(values.begin(), values.end());
        int count = 0;
        curr = head;
        while (curr) {
            curr->val = values[count++];
            curr = curr->next;
        }
        return head;
    }
};
