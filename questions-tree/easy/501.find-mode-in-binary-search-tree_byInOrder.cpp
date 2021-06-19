/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (43.06%)
 * Likes:    1160
 * Dislikes: 389
 * Total Accepted:    99.6K
 * Total Submissions: 230.8K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        if (!root) return res;
        InOrder(root);
        Update(prev->val);
        return res;
    }

 private:
    TreeNode* prev;
    int count;
    int max;
    vector<int> res;

    void InOrder(TreeNode* node) {
        if (node->left) InOrder(node->left);
        if (!prev) {
            count = 1;
            max = 1;
        } else {
            if (prev->val == node->val) {
                count++;
            } else {
                Update(prev->val);
                count = 1;
            }
        }
        prev = node;
        if (node->right) InOrder(node->right);
    }

    void Update(int val) {
        if (count >= max) {
            if (count > max) {
                max = count;
                res.clear();
            }
            res.push_back(val);
        }
    }
};
// @lc code=end
