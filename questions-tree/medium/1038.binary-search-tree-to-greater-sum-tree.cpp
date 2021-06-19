/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
 *
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/
 *
 * algorithms
 * Medium (81.79%)
 * Likes:    1419
 * Dislikes: 116
 * Total Accepted:    77.7K
 * Total Submissions: 94.1K
 * Testcase Example:  '[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]'
 *
 * Given the root of a Binary Search Tree (BST), convert it to a Greater Tree
 * such that every key of the original BST is changed to the original key plus
 * sum of all keys greater than the original key in BST.
 * 
 * As a reminder, a binary search tree is a tree that satisfies these
 * constraints:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * Note: This question is the same as 538:
 * https://leetcode.com/problems/convert-bst-to-greater-tree/
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
 * Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [0,null,1]
 * Output: [1,null,1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,0,2]
 * Output: [3,3,2]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [3,2,4,1]
 * Output: [7,9,4,10]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 100].
 * 0 <= Node.val <= 100
 * All the values in the tree are unique.
 * root is guaranteed to be a valid binary search tree.
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
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        traverse(root);
        return root;
    }

 private:
    int sum;
    void traverse(TreeNode* node) {
        if (!node) return;
        traverse(node->right);
        int val = node->val;
        node->val += sum;
        sum += val;
        traverse(node->left);
    }
};
// @lc code=end
