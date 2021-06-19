/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Medium (36.92%)
 * Likes:    2193
 * Dislikes: 548
 * Total Accepted:    110.5K
 * Total Submissions: 295.9K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given the root of a binary tree, return the length of the longest path,
 * where each node in the path has the same value. This path may or may not
 * pass through the root.
 * 
 * The length of the path between two nodes is represented by the number of
 * edges between them.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,5,1,1,5]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,4,5,4,4,5]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * The depth of the tree will not exceed 1000.
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;

        max_cnt = 0;
        traverse(root, 1 + root->val);
        return max_cnt;
    }

 private:
    int max_cnt;
    int traverse(TreeNode* node, int val) {
        if (!node) return 0;

        int left = traverse(node->left, node->val);
        int right = traverse(node->right, node->val);
        max_cnt = max(max_cnt, left + right);

        if (node->val == val) {
            return 1 + max(left, right);
        } else {
            return 0;
        }
    }
};
// @lc code=end
