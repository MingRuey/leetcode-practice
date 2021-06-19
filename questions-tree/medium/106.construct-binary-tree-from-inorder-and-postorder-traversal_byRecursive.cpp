/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (48.84%)
 * Likes:    2373
 * Dislikes: 44
 * Total Accepted:    276.3K
 * Total Submissions: 560.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int> const &inorder,
                        vector<int> const &postorder) {
        if (!postorder.size() || !inorder.size()) return NULL;
        int head = postorder.back();
        TreeNode* root = new TreeNode(head);

        int idx = rsearch(inorder, head);

        vector<int> r_post(postorder.end() - 1 - idx, postorder.end() - 1);
        vector<int> r_in(inorder.end() - idx, inorder.end());
        root->right = buildTree(r_in, r_post);

        vector<int> l_post(postorder.begin(), postorder.end() - 1 - idx);
        vector<int> l_in(inorder.begin(), inorder.end() - idx - 1);
        root->left = buildTree(l_in, l_post);
        return root;
    }

 private:
    int rsearch(vector<int> const &inorder, int val) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[inorder.size() - 1 - i] == val) return i;
        }
        return -1;
    }
};
// @lc code=end
