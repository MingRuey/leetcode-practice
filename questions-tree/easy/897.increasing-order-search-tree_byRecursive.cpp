/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
 *
 * https://leetcode.com/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (74.12%)
 * Likes:    1161
 * Dislikes: 514
 * Total Accepted:    110K
 * Total Submissions: 148K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * Given the root of a binary search tree, rearrange the tree in in-order so
 * that the leftmost node in the tree is now the root of the tree, and every
 * node has no left child and only one right child.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,1,7]
 * Output: [1,null,5,null,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree will be in the range [1, 100].
 * 0 <= Node.val <= 1000
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
    TreeNode* increasingBST(TreeNode* root) {
        ans = NULL;
        InOrder(root);
        return ans;
    }
 private:
    TreeNode* ans;
    TreeNode* cur;
    void InOrder(TreeNode* node) {
        if (!node) return;
        InOrder(node->left);
        if (!ans) {
            ans = new TreeNode(node->val);
            cur = ans;
        } else {
            cur->right = new TreeNode(node->val);
            cur = cur->right;
        }
        InOrder(node->right);
    }
};
// @lc code=end
