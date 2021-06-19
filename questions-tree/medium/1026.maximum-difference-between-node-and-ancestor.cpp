/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 *
 * https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/
 *
 * algorithms
 * Medium (68.94%)
 * Likes:    1198
 * Dislikes: 43
 * Total Accepted:    80.8K
 * Total Submissions: 115.8K
 * Testcase Example:  '[8,3,10,1,6,null,14,null,null,4,7,13]'
 *
 * Given the root of a binary tree, find the maximum value V for which there
 * exist different nodes A and B where V = |A.val - B.val| and A is an ancestor
 * of B.
 * 
 * A node A is an ancestor of B if either: any child of A is equal to B, or any
 * child of A is an ancestor of B.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 * Explanation: We have various ancestor-node differences, some of which are
 * given below :
 * |8 - 3| = 5
 * |3 - 7| = 4
 * |8 - 1| = 7
 * |10 - 13| = 3
 * Among all possible differences, the maximum value of 7 is obtained by |8 -
 * 1| = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,null,2,null,0,3]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 5000].
 * 0 <= Node.val <= 10^5
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
    int maxAncestorDiff(TreeNode* root) {
        diff = 0;
        if (!root) return diff;
        traverse(root, root->val, root->val);
        return diff;
    }

 private:
    int diff;

    void traverse(TreeNode* node, int ma, int mi) {
        if (!node) return;
        ma = node->val > ma ? ma : node->val;
        mi = node->val < mi ? mi : node->val;
        int tmp = max(abs(ma - node->val), abs(mi - node->val));
        diff = diff > tmp ? diff : tmp;
        traverse(node->left, ma, mi);
        traverse(node->right, ma, mi);
    }
};
// @lc code=end
