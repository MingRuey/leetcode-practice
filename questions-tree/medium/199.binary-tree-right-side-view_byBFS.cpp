/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (55.48%)
 * Likes:    3262
 * Dislikes: 175
 * Total Accepted:    380K
 * Total Submissions: 680.2K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        queue<TreeNode*> que;
        if (root) que.push(root);

        while (!que.empty()) {
            queue<TreeNode*> queNext;
            result.push_back((que.front())->val);
            while (!que.empty()) {
                TreeNode* front = que.front();
                que.pop();
                if (front->right) queNext.push(front->right);
                if (front->left) queNext.push(front->left);
            }
            que = queNext;
        }
        return result;
    }
};
// @lc code=end
