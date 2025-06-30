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

    bool helper(TreeNode *root, int val)
    {
        if (root) {
            if (root->val != val)
                return false;
            return helper(root->left, val) && helper(root->right, val);
        }
        return true;
    }

    bool isUnivalTree(TreeNode* root)
    {
        if (root)
            return helper(root, root->val);
        return true;
    }
};
