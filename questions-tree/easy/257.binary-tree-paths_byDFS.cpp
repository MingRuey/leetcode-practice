/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        if (!root->left && !root->right) {
            res.push_back(to_string(root->val));
        }

        vector<string> leftPaths = binaryTreePaths(root->left);
        for (int i = 0; i < leftPaths.size(); i++) {
            res.push_back(to_string(root->val) + "->" + leftPaths[i]);
        }
        vector<string> rightPaths = binaryTreePaths(root->right);
        for (int i = 0; i < rightPaths.size(); i++) {
            res.push_back(to_string(root->val) + "->" + rightPaths[i]);
        }
        return res;
    }
};

// @lc code=end
