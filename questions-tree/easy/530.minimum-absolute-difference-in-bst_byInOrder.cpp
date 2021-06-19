/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (54.46%)
 * Likes:    1088
 * Dislikes: 83
 * Total Accepted:    103.1K
 * Total Submissions: 188.9K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * There are at least two nodes in this BST.
 * This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        minimum = -1;
        InOrder(root);
        return minimum;
    }

 private:
    TreeNode* prev;
    int minimum;

    void InOrder(TreeNode* node) {
        if (!node) return;
        InOrder(node->left);
        if (prev) {
            int diff = node->val - prev->val;
            if (diff < minimum || minimum < 0) minimum = diff;
        }
        prev = node;
        InOrder(node->right);
    }
};
// @lc code=end
