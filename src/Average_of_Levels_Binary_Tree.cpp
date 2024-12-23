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
        if (!root)
        // Get the height of the tree
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

    void level_order(TreeNode *root, int i, double *sum, double *div)
    {
        if (!root)
            return;
        if (i == 0) {
            *(sum) += root->val;
            (*div)++;
        } else {
            level_order(root->left, i - 1, sum, div);
            level_order(root->right, i - 1, sum, div);
        }
    }

    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ans;
        TreeNode *head = root;

        if (!root)
            return {};

        int height = tree_height(head);
        for (int i = 0; i < height; i++) {
            double level_sum = 0;
            double div = 0;
            level_order(root, i, &level_sum, &div);
            ans.push_back(level_sum / div);
        }
        return ans;
    }
};
