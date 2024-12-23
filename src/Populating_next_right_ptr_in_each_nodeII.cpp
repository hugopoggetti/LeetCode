/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <ctime>
class Solution {
public:
    Node* connect(Node* root)
    {
        Node *head = root;

        while (head) {
            Node dummy(0);
            Node *tmp = &dummy;

            while (head) {
                if (head->left) {
                    tmp->next = head->left;
                    tmp = tmp->next;
                }
                if (head->right) {
                    tmp->next = head->right;
                    tmp = tmp->next;
                }
                head = head->next;
            }
            head = dummy.next;
        }
        return root;
    }
};
