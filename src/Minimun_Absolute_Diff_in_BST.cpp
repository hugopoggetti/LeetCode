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

    int ans = INT_MAX;
    TreeNode *cur = nullptr;

    void dfs(TreeNode *root)
    {
        if (root->left) dfs(root->left);
        if (cur) ans = min(ans, abs(cur->val -root->val));
        cur = root;
        if (root->right) dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root)
    {
        dfs(root);
        return ans;
    }
};
