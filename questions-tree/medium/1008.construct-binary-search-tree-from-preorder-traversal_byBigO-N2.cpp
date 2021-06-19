/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* bstFromPreorder(vector<int> const& preorder) {
        if (!preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;

        int idx = preorder.size();
        for (int i = 1; i < preorder.size(); i++) {
            if (preorder[i] > preorder[0]) {
                idx = i;
                break;
            }
        }

        vector<int> left(preorder.begin() + 1, preorder.begin() + idx);
        vector<int> right(preorder.begin() + idx, preorder.end());
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};
// @lc code=end
