/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (62.17%)
 * Likes:    1234
 * Dislikes: 164
 * Total Accepted:    123.5K
 * Total Submissions: 197.6K
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, return the leftmost value in the last row
 * of the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [2,1,3]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
    int findBottomLeftValue(TreeNode* root) {
        maxdepth = 0;
        leftmost = 0;
        Traverse(root, 0);
        return leftmost;
    }

 private:
    int leftmost;
    int maxdepth;

    void Traverse(TreeNode* node, int depth) {
        if (!node) return;
        Traverse(node->right, depth + 1);
        Traverse(node->left, depth + 1);
        if (depth >= maxdepth) {
            maxdepth = depth;
            leftmost = node->val;
        }
    }
};
// @lc code=end
