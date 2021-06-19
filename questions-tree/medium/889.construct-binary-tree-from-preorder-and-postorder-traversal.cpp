/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.15%)
 * Likes:    1157
 * Dislikes: 62
 * Total Accepted:    48.9K
 * Total Submissions: 72.2K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 * 
 * Values in the traversals pre and post are distinct positive integers.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
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
    TreeNode* constructFromPrePost(
                vector<int> const& pre,
                vector<int> const& post) {
        if (pre.size() == 0) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        if (pre.size() == 1) return root;

        int l;
        for (int i = 0; i < pre.size(); i++) {
            if (pre[1] == post[i]) {
                l = i + 1;
            }
        }

        vector<int> lpre(pre.begin() + 1, pre.begin() + l + 1);
        vector<int> lpost(post.begin(), post.begin() + l);
        root->left = constructFromPrePost(lpre, lpost);

        vector<int> rpre(pre.begin() + l + 1, pre.end());
        vector<int> rpost(post.begin() + l, post.end() - 1);
        root->right = constructFromPrePost(rpre, rpost);
        return root;
    }
};
// @lc code=end
