#include <iostream>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head)
    {
        std::stack<ListNode *> stack;
        ListNode *cur = head;
    
        while (cur) {
            stack.push(cur);
            cur = cur->next;
        }

        cur = stack.top();
        stack.pop();
        int max = cur->val;
        ListNode *ans = new ListNode(max);

        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            if (cur->val < max)
                continue;
            else {
                ListNode *newN = new ListNode(cur->val);
                newN->next = ans;
                ans = newN;
                max = cur->val;
            }
        }
        return ans;
    }
};
