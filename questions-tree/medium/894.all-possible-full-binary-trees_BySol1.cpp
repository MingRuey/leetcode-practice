/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
 *
 * https://leetcode.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (76.72%)
 * Likes:    1349
 * Dislikes: 112
 * Total Accepted:    50.2K
 * Total Submissions: 65K
 * Testcase Example:  '7'
 *
 * Given an integer n, return a list of all possible full binary trees with n
 * nodes. Each node of each tree in the answer must have Node.val == 0.
 * 
 * Each element of the answer is the root node of one possible tree. You may
 * return the final list of trees in any order.
 * 
 * A full binary tree is a binary tree where each node has exactly 0 or 2
 * children.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 7
 * Output:
 * [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: [[0,0,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if (n%2 == 0) return ans;

        vector<string> lst = generate(n);
        for (auto seq : lst) {
            ans.push_back(decode(seq));
        }
        return ans;
    }

 private:
    unordered_map<int, vector<string>> map;

    vector<string> generate(int n) {
        if (map.find(n) != map.end()) return map[n];

        vector<string> ans;
        if (n % 2 == 0) {
            string root("n");
            ans.push_back(root);
            map[n] = ans;
            return ans;
        }

        if (n == 1) {
            string root("yn");
            ans.push_back(root);
            map[n] = ans;
            return ans;
        }

        for (int i = 1; i < n - 1; i += 2) {
            string root("y");
            vector<string> left = generate(i);
            vector<string> right = generate(n - i - 1);
            for (auto l : left) {
                for (auto r : right) {
                    string tree = root + l + r;
                    ans.push_back(tree);
                }
            }
        }
        map[n] = ans;
        return ans;
    }

    TreeNode* decode(const string &seq) {
        TreeNode* root;
        TreeNode** trace = &root;
        stack<TreeNode**> stk;
        for (auto c = seq.begin(); c != seq.end();) {
            TreeNode* node = new TreeNode(0);
            *trace = node;
            if (*(c + 1) == 'n') {
                if (!stk.size()) break;
                trace = stk.top();
                stk.pop();
                c += 2;
            } else {
                stk.push(&(node->left));
                trace = &(node->right);
                c++;
            }
        }
        return root;
    }
};
// @lc code=end
