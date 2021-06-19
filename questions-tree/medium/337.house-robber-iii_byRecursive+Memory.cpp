/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (51.60%)
 * Likes:    3701
 * Dislikes: 65
 * Total Accepted:    199.7K
 * Total Submissions: 385.6K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Output: 7 
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,5,1,3,null,1]
 * 
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode* root) {
        cache_rob.clear();
        cache_not_rob.clear();
        return _rob(root, true);
    }

 private:
    unordered_map<TreeNode*, int> cache_rob;
    unordered_map<TreeNode*, int> cache_not_rob;

    int _rob(TreeNode* node, bool canrob) {
        if (!node) return 0;

        int notrobbed, robbed;
        unordered_map<TreeNode*, int>::const_iterator found;

        // find cached if availiable
        if (!canrob) {
            found = cache_not_rob.find(node);
            if (found != cache_not_rob.end()) return found->second;
        } else {
            found = cache_rob.find(node);
            if (found != cache_rob.end()) return found->second;
        }

        notrobbed = _rob(node->left, true) + _rob(node->right, true);
        cache_not_rob[node] = notrobbed;
        if (!canrob) return notrobbed;

        robbed = node->val + \
            _rob(node->left, false) + _rob(node->right, false);
        robbed = max(robbed, notrobbed);
        cache_rob[node] = robbed;
        return robbed;
    }
};
// @lc code=end
