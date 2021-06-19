/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 *
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (52.11%)
 * Likes:    1256
 * Dislikes: 65
 * Total Accepted:    132K
 * Total Submissions: 252.8K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k
 * node are at depth k+1.
 * 
 * Two nodes of a binary tree are cousins if they have the same depth, but have
 * different parents.
 * 
 * We are given the root of a binary tree with unique values, and the values x
 * and y of two different nodes in the tree.
 * 
 * Return true if and only if the nodes corresponding to the values x and y are
 * cousins.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
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
    bool isCousins(TreeNode* root, int x, int y) {
        _x = x;
        _y = y;
        px = NULL;
        py = NULL;
        Search(root, NULL, 0);
        return (dx > 0) && (px != py) && (dx == dy);
    }

 private:
    int _x, _y, dx = -1, dy = -1;
    TreeNode *px, *py;

    void Search(TreeNode* node, TreeNode* parent, int depth) {
        if (!node) return;
        if (dx >= 0 && dy >= 0) return;
        if (dx < 0 && node->val == _x) {
            dx = depth;
            px = parent;
        }
        if (dy < 0 && node->val == _y) {
            dy = depth;
            py = parent;
        }

        Search(node->left, node, depth + 1);
        Search(node->right, node,  depth + 1);
    }
};
// @lc code=end
