/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse_swap(TreeNode *left, TreeNode *right, int lev) {
        if (!left || !right)
            return;
        if (lev % 2 == 0) {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
        traverse_swap(left->left, right->right, lev + 1);
        traverse_swap(left->right, right->left, lev + 1);

    }
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        traverse_swap(root->left, root->right, 0);
        return root;
    }
};
