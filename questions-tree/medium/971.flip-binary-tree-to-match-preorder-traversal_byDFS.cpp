/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
 *
 * https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/
 *
 * algorithms
 * Medium (46.10%)
 * Likes:    519
 * Dislikes: 209
 * Total Accepted:    29.4K
 * Total Submissions: 58.7K
 * Testcase Example:  '[1,2]\n[2,1]'
 *
 * You are given the root of a binary tree with n nodes, where each node is
 * uniquely assigned a value from 1 to n. You are also given a sequence of n
 * values voyage, which is the desired pre-order traversal of the binary tree.
 * 
 * Any node in the binary tree can be flipped by swapping its left and right
 * subtrees. For example, flipping node 1 will have the following effect:
 * 
 * Flip the smallest number of nodes so that the pre-order traversal of the
 * tree matches voyage.
 * 
 * Return a list of the values of all flipped nodes. You may return the answer
 * in any order. If it is impossible to flip the nodes in the tree to make the
 * pre-order traversal match voyage, return the list [-1].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2], voyage = [2,1]
 * Output: [-1]
 * Explanation: It is impossible to flip the nodes such that the pre-order
 * traversal matches voyage.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3], voyage = [1,3,2]
 * Output: [1]
 * Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal
 * matches voyage.
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,2,3], voyage = [1,2,3]
 * Output: []
 * Explanation: The tree's pre-order traversal already matches voyage, so no
 * nodes need to be flipped.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * n == voyage.length
 * 1 <= n <= 100
 * 1 <= Node.val, voyage[i] <= n
 * All the values in the tree are unique.
 * All the values in voyage are unique.
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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int> const& voyage) {
        ans.clear();
        if (!root) return ans;

        stack<TreeNode*> stk;
        stk.push(root);
        int idx = 0;
        while (!stk.empty()) {
            TreeNode* top = stk.top();
            stk.pop();
            if (voyage[idx] != top->val) {
                ans.clear();
                ans.push_back(-1);
                return ans;
            } else if (idx == voyage.size() - 1) {
                return ans;
            }

            int next = voyage[++idx];
            if (top->left) {
                if (top->left->val == next) {
                    if (top->right) stk.push(top->right);
                    stk.push(top->left);
                } else {
                    ans.push_back(top->val);
                    stk.push(top->left);
                    if (top->right) stk.push(top->right);
                }
            } else if (top->right) {
                stk.push(top->right);
            }
        }
        return ans;
    }

 private:
    vector<int> ans;
};
// @lc code=end
