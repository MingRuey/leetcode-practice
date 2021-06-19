/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (51.62%)
 * Likes:    1777
 * Dislikes: 231
 * Total Accepted:    83.9K
 * Total Submissions: 160.2K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given the root of a binary tree, return all duplicate subtrees.
 * 
 * For each kind of duplicate subtrees, you only need to return the root node
 * of any one of them.
 * 
 * Two trees are duplicate if they have the same structure with the same node
 * values.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,null,2,4,null,null,4]
 * Output: [[2,4],[4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [2,1,1]
 * Output: [[1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [2,2,2,3,null,3,null]
 * Output: [[2,3],[3]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the tree will be in the range [1, 10^4]
 * -200 <= Node.val <= 200
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ans.clear();
        cnt.clear();
        lookup.clear();
        curmax = 1;
        Traverse(root);
        return ans;
    }

 private:
    vector<TreeNode*> ans;

    unsigned int curmax;
    unordered_map<unsigned int, unsigned int> lookup;
    unordered_map<unsigned int, unsigned int> cnt;

    unsigned int Traverse(TreeNode* node) {
        if (!node) return 0;
        unsigned int leftId = Traverse(node->left);
        unsigned int rightId = Traverse(node->right);
        unsigned int id = encode(node, leftId, rightId);
        if (1 == cnt[id]++) ans.push_back(node);
        return id;
    }

    inline unsigned int encode(
            TreeNode* node,
            unsigned int id1,
            unsigned int id2) {
        unsigned int unique = canton(id1, id2);
        unique = canton(unique, z2n(node->val));
        return regist(unique);
    }

    inline unsigned int regist(unsigned int val) {
        unsigned int uid = lookup[val];
        if (!uid) {
            uid = curmax++;
            lookup[val] = uid;
            return uid;
        }
        return uid;
    }

    inline unsigned int canton(unsigned int val1, unsigned int val2) {
        return (val1 + val2) * (val1 + val2 + 1) / 2 + val2;
    }

    inline unsigned int z2n(int val) {
        return val >= 0 ? 2 * val : -2 * val - 1;
    }
};
// @lc code=end
