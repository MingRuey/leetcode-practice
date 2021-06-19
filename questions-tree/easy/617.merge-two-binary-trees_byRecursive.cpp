/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
 *
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (74.94%)
 * Likes:    3807
 * Dislikes: 187
 * Total Accepted:    353.9K
 * Total Submissions: 471.2K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * Given two binary trees and imagine that when you put one of them to cover
 * the other, some nodes of the two trees are overlapped while the others are
 * not.
 * 
 * You need to merge them into a new binary tree. The merge rule is that if two
 * nodes overlap, then sum node values up as the new value of the merged node.
 * Otherwise, the NOT null node will be used as the node of new tree.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * Output: 
 * Merged tree:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 
 * 
 * Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        TreeNode* root = new TreeNode();
        merge(root, t1, t2);
        return root;
    }

 private:
    void merge(TreeNode* node, TreeNode* t1, TreeNode* t2) {
        node->val = (t2? t2->val : 0) + (t1? t1->val : 0);

        if ((t1 && t1->left) || (t2 && t2->left)) {
            node->left = new TreeNode();
            merge(node->left, t1? t1->left: NULL, t2? t2->left : NULL);
        }

        if ((t1 && t1->right) || (t2 && t2->right)) {
            node->right = new TreeNode();
            merge(node->right, t1? t1->right: NULL, t2? t2->right : NULL);
        }
    }
};
// @lc code=end
