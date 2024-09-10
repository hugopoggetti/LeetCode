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

    void helper(TreeNode* root, int val, TreeNode** ans)
    {
        if (root != NULL)
        {
            helper(root->left);
            if (root->val == val)
                *ans = root;
            helper(roo->right);
        }
    }
    
    TreeNode* searchBST(TreeNode* root, int val)
    {
        TreeNode* ans = NULL;
        helper(root, val, &ans);
        return ans;
    }
};