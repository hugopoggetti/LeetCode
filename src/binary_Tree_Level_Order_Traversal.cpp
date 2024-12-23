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

    int tree_height(TreeNode *root)
    {
        // Get the height of the tree
        if (!root)
            return 0;
        else {
            // Find the height of both subtrees
            // and use the larger one
            int left_height = tree_height(root->left);
            int right_height = tree_height(root->right);
            if (left_height >= right_height)
                return left_height + 1;
            else
                return right_height + 1;
        }
    }

    void level_order(TreeNode *root, int i, vector<int>& ans)
    {
        if (!root)
            return;
        if (i == 0) {
            // add to vector of the current level
            ans.push_back(root->val);
        } else {
            level_order(root->left, i - 1, ans);
            level_order(root->right, i - 1, ans);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        TreeNode *head = root;

        if (!root)
            return {};

        // get the numbers of tree level
        int height = tree_height(head);

        for (int i = 0; i < height; i++) {
            vector<int> current_level;
            level_order(root, i, current_level);
            ans.push_back(current_level);
        }
        return ans;
    }
};
