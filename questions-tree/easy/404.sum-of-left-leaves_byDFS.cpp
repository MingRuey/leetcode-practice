/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (52.14%)
 * Likes:    1618
 * Dislikes: 156
 * Total Accepted:    228K
 * Total Submissions: 437K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        return sumIfLeft(root, false);
    }

 private:
    int sumIfLeft(TreeNode* node, bool isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right) return isLeft ? node->val : 0;
        return sumIfLeft(node->left, true) + sumIfLeft(node->right, false);
    }
};
// @lc code=end
