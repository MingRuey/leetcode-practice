/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (64.26%)
 * Likes:    1621
 * Dislikes: 177
 * Total Accepted:    151.7K
 * Total Submissions: 235.3K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 * 
 * 
 * 
 * Note:
 * 
 * The range of node's value is in the range of 32-bit signed integer.
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        stack<TreeNode*> current_stack = s1;
        stack<TreeNode*> other = s2;
        while (!current_stack.empty()) {
            double sum = 0;
            int size = current_stack.size();
            for (int i = size - 1; i >= 0; i--) {
                TreeNode* node = current_stack.top();
                sum += node->val;
                if (node->left) other.push(node->left);
                if (node->right) other.push(node->right);
                current_stack.pop();
            }
            sum /= size;
            res.push_back(sum);
            stack<TreeNode*> tmp = current_stack;
            current_stack = other;
            other = tmp;
        }
        return res;
    }
};

// @lc code=end
