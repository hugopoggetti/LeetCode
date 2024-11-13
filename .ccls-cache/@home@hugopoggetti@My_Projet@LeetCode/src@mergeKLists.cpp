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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<int> merge;
        ListNode *head = nullptr;
        ListNode *ans = nullptr;

        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != nullptr) {
                merge.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(merge.begin(), merge.end());

        for (int i = 0; i < merge.size(); i++) {
            ListNode *l = new ListNode(merge[i]);
            if (head == nullptr) {
                head = l;
                ans = head;
            } else {
                head->next = l;
                head = head->next;
            }
        }
        return ans->next;
    }
};

