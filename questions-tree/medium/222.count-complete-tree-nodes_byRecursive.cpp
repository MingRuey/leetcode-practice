/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (48.47%)
 * Likes:    2662
 * Dislikes: 245
 * Total Accepted:    276.2K
 * Total Submissions: 564.1K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a complete binary tree, return the number of the nodes in
 * the tree.
 * 
 * According to Wikipedia, every level, except possibly the last, is completely
 * filled in a complete binary tree, and all nodes in the last level are as far
 * left as possible. It can have between 1 and 2^h nodes inclusive at the last
 * level h.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,6]
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 5 * 10^4].
 * 0 <= Node.val <= 5 * 10^4
 * The tree is guaranteed to be complete.
 * 
 * 
 * 
 * Follow up: Traversing the tree to count the number of nodes in the tree is
 * an easy solution but with O(n) complexity. Could you find a faster algorithm?
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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        if (lh == rh) {
            return (1 << lh) + countNodes(root->right);
        } else {
            int result = 1 + countNodes(root->left) + countNodes(root->right);
            return result;
        }
    }
 private:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + getHeight(root->left);
    }
};
// @lc code=end
