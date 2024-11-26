/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> old_to_new;

        Node *cur = head;
        while (cur) {
            old_to_new[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            old_to_new[cur]->next = old_to_new[cur->next];
            old_to_new[cur]->random = old_to_new[cur->random];
            cur = cur->next;
        }
        return old_to_new[head];
    }
};
