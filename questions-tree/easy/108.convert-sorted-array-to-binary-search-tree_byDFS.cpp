/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (59.62%)
 * Likes:    3250
 * Dislikes: 246
 * Total Accepted:    477.5K
 * Total Submissions: 799.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        int size = nums.size();
        TreeNode *root;
        return createSubTree(root, nums, 0, size - 1);
    }
 private:
    TreeNode* createSubTree(
            TreeNode* root,
            const vector<int>& nums, int start, int end) {
        int size = end - start + 1;
        if (!size) { return NULL; }

        int center = (start + end) / 2;

        root = new TreeNode(nums[center]);
        root->left = createSubTree(root->left, nums, start, center - 1);
        root->right = createSubTree(root->right, nums, center + 1, end);
        return root;
    }
};
// @lc code=end
