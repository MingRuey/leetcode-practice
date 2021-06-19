/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (50.84%)
 * Likes:    4557
 * Dislikes: 117
 * Total Accepted:    444.7K
 * Total Submissions: 867.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
    TreeNode* buildTree(vector<int> const &preorder,
                        vector<int> const &inorder) {
        if (!preorder.size() || !inorder.size()) return NULL;
        int head = preorder[0];
        TreeNode* root = new TreeNode(head);

        int idx = search_head(inorder, head);
        if (idx < 0) return root;

        vector<int> l_inorder(inorder.begin(), inorder.begin() + idx);
        vector<int> l_preorder(preorder.begin() + 1,
                               preorder.begin() + idx + 1);
        root->left = buildTree(l_preorder, l_inorder);

        vector<int> r_inorder(inorder.begin() + idx + 1, inorder.end());
        vector<int> r_preorder(preorder.begin() + idx + 1, preorder.end());
        root->right = buildTree(r_preorder, r_inorder);
        return root;
    }

 private:
    int search_head(vector<int> const &inorder, int val) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
