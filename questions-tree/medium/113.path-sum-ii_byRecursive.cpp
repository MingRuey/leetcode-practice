/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (48.33%)
 * Likes:    2471
 * Dislikes: 86
 * Total Accepted:    386.8K
 * Total Submissions: 793.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where each path's sum equals targetSum.
 * 
 * A leaf is a node with no children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,2], targetSum = 0
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        if (!root) return result;

        int remains = targetSum - root->val;
        if (!remains && !(root->left) && !(root->right)) {
            vector<int> head = { root->val };
            result.push_back(head);
            return result;
        }

        vector<vector<int>> lpath = pathSum(root->left, remains);
        vector<vector<int>> rpath = pathSum(root->right, remains);

        for (int i = 0; i < lpath.size(); i++) {
            vector<int> head =  { root->val };
            head.insert(head.end(), lpath[i].begin(), lpath[i].end());
            result.push_back(head);
        }

        for (int i = 0; i < rpath.size(); i++) {
            vector<int> head =  { root->val };
            head.insert(head.end(), rpath[i].begin(), rpath[i].end());
            result.push_back(head);
        }
        return result;
    }
};
// @lc code=end
