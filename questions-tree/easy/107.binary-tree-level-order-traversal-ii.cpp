/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (54.62%)
 * Likes:    1856
 * Dislikes: 231
 * Total Accepted:    392.2K
 * Total Submissions: 717.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        DfsTraverse(root, 0, &ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

 private:
    void DfsTraverse(TreeNode* node, int depth, vector<vector<int>> *stack) {
        if (!node) return;

        vector<vector<int>> val = *stack;
        if (depth >= val.size()) val.push_back({});
        val[depth].push_back(node->val);
        *stack = val;

        DfsTraverse(node->left, depth + 1, stack);
        DfsTraverse(node->right, depth + 1, stack);
    }
};
// @lc code=end
