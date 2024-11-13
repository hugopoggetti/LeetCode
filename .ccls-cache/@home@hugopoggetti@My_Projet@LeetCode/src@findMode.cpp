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
#include <unordered_map>
#include <vector>
class Solution {
public:
    void helper(TreeNode *root, unordered_map<int, int>& map)
    {
        if (!root) return;
        map[root->val] += 1;
        helper(root->left, map);
        helper(root->right, map);
    }

    vector<int> findMode(TreeNode* root)
    {
        int Mode = 0;
        vector<int> ans;
        unordered_map<int,int> map;
        helper(root, map);
        for (const auto& pair : map) {
            if (pair.second > Mode) {
                Mode = pair.second;
                ans = { pair.first }; // Remplace le vecteur ans par le nouveau mode
            } else if (pair.second == Mode) {
                ans.push_back(pair.first); // Ajoute la valeur au vecteur ans si elle a la même fréquence que le mode actuel
            }
        }
    }
};
