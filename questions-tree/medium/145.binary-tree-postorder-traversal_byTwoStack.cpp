/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Medium (56.73%)
 * Likes:    2336
 * Dislikes: 110
 * Total Accepted:    450.9K
 * Total Submissions: 787.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,2]
 * Output: [2,1]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = [1,null,2]
 * Output: [2,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        stack<TreeNode*> stkFinal;
        stack<TreeNode*> stkTraverse;
        if (root) stkTraverse.push(root);
        while (!stkTraverse.empty()) {
            TreeNode* top = stkTraverse.top();
            stkTraverse.pop();
            stkFinal.push(top);
            if (top->left) stkTraverse.push(top->left);
            if (top->right) stkTraverse.push(top->right);
        }
        while (!stkFinal.empty()) {
            TreeNode* top = stkFinal.top();
            stkFinal.pop();
            result.push_back(top->val);
        }
        return result;
    }
};
// @lc code=end
