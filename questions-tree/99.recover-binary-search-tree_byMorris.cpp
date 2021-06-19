/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (41.91%)
 * Likes:    2370
 * Dislikes: 91
 * Total Accepted:    207.4K
 * Total Submissions: 484.7K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * You are given the root of a binary search tree (BST), where exactly two
 * nodes of the tree were swapped by mistake. Recover the tree without changing
 * its structure.
 * 
 * Follow up: A solution using O(n) space is pretty straight forward. Could you
 * devise a constant space solution?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
 * makes the BST valid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
 * and 3 makes the BST valid.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 1000].
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
    void recoverTree(TreeNode* root) {
        TreeNode* abnormal = NULL;
        TreeNode* buff = NULL;
        TreeNode* previous = NULL;
        TreeNode* cur = root;
        bool done = false;
        while (cur) {
            TreeNode* mostRight = cur->left;
            if (mostRight) {
                while (mostRight->right && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == cur) {
                    mostRight->right = NULL;
                    if (previous && cur->val < previous->val) {
                        if (abnormal) {
                            swap(abnormal->val, cur->val);
                            done = true;
                        }
                        abnormal = previous;
                        buff = cur;
                    }
                    previous = cur;
                    cur = cur->right;
                } else {
                    mostRight->right = cur;
                    cur = cur->left;
                }
            } else {
                if (previous && cur->val < previous->val) {
                    if (abnormal) {
                        swap(abnormal->val, cur->val);
                        done = true;
                    }
                    abnormal = previous;
                    buff = cur;
                }
                previous = cur;
                cur = cur->right;
            }
        }

        if (!done) swap(buff->val, abnormal->val);
    }
};
// @lc code=end
