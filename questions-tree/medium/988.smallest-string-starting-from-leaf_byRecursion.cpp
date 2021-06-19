/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
 *
 * https://leetcode.com/problems/smallest-string-starting-from-leaf/description/
 *
 * algorithms
 * Medium (46.45%)
 * Likes:    593
 * Dislikes: 118
 * Total Accepted:    35.9K
 * Total Submissions: 76.6K
 * Testcase Example:  '[0,1,2,3,4,3,4]'
 *
 * Given the root of a binary tree, each node has a value from 0 to 25
 * representing the letters 'a' to 'z': a value of 0 represents 'a', a value of
 * 1 represents 'b', and so on.
 * 
 * Find the lexicographically smallest string that starts at a leaf of this
 * tree and ends at the root.
 * 
 * (As a reminder, any shorter prefix of a string is lexicographically smaller:
 * for example, "ab" is lexicographically smaller than "aba".  A leaf of a node
 * is a node that has no children.)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [0,1,2,3,4,3,4]
 * Output: "dba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [25,1,3,1,3,0,2]
 * Output: "adz"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: [2,2,1,null,1,0,null,0]
 * Output: "abc"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the given tree will be between 1 and 8500.
 * Each node in the tree will have a value between 0 and 25.
 * 
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
    string smallestFromLeaf(TreeNode* root) {
        candidate.clear();
        candidate = vector<int> { 26 };
        traverse(root);
        stringstream ss;
        for (int i = candidate.size() - 1; i >=0; i--) {
            char c = 'a' + candidate[i];
            ss << c;
        }
        return ss.str();
    }

 private:
    vector<int> prefix;
    vector<int> candidate;

    void traverse(TreeNode* node) {
        if (!node) return;
        prefix.push_back(node->val);

        traverse(node->left);
        traverse(node->right);

        if (!node->left && !node->right) {
            if (less(prefix, candidate)) {
                candidate = prefix;
            }
        }
        prefix.pop_back();
    }

    bool less(vector<int> const& prefix, vector<int> const& candidate) {
        int lp = prefix.size();
        int lc = candidate.size();
        int l = min(lp, lc);
        for (int i = 0; i < l; i++) {
            int ip = prefix[lp - i - 1];
            int ic = candidate[lc - i - 1];
            if (ip < ic) return true;
            if (ip > ic) return false;
        }
        if (lp < lc) return true;
        return false;
    }
};
// @lc code=end
