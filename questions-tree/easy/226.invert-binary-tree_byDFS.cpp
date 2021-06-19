/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (66.35%)
 * Likes:    4476
 * Dislikes: 69
 * Total Accepted:    626.5K
 * Total Submissions: 942.3K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 * 
 * Example:
 * 
 * Input:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 *   1   3 6   9
 * 
 * Output:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 *   9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        Swap(&(root->left), &(root->right));
        return root;
    }

 private:
    void Swap(TreeNode** tree1, TreeNode** tree2) {
        TreeNode* tmp = *tree1;
        *tree1 = *tree2;
        *tree2 = tmp;
        if (*tree1) {
            TreeNode** left = &((*tree1)->left);
            TreeNode** right = &((*tree1)->right);
            Swap(left, right);
        }
        if (*tree2) {
            TreeNode** left = &((*tree2)->left);
            TreeNode** right = &((*tree2)->right);
            Swap(left, right);
        }
    }
};
// @lc code=end
