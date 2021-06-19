/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
 *
 * https://leetcode.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Easy (82.71%)
 * Likes:    1958
 * Dislikes: 273
 * Total Accepted:    319.4K
 * Total Submissions: 385.6K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * Given the root node of a binary search tree, return the sum of values of all
 * nodes with a value in the range [low, high].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
 * Output: 32
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
 * Output: 23
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 2 * 10^4].
 * 1 <= Node.val <= 10^5
 * 1 <= low <= high <= 10^5
 * All Node.val are unique.
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        _low = low;
        _high = high;
        InOrder(root);
        return sum;
    }

 private:
    int sum;
    int _low;
    int _high;

    void InOrder(TreeNode* node) {
        if (!node) return;
        if (node->val >= _low) {
            InOrder(node->left);
        }
        if (node->val >= _low && node->val <= _high) {
            sum += node->val;
        }
        if (node->val <= _high) {
            InOrder(node->right);
        }
    }
};
// @lc code=end
