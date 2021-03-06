/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (49.09%)
 * Likes:    4353
 * Dislikes: 200
 * Total Accepted:    450.2K
 * Total Submissions: 888K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,2]
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Codec {
 public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        encoded.clear();
        preorder(root);
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        TreeNode** cur = &root;
        stack<TreeNode**> stk;
        stk.push(cur);

        string accumulated = "";
        for (auto ch : data) {
            if (ch == ',') {
                int val = stoi(accumulated);
                accumulated = "";

                TreeNode** cur = stk.top();
                stk.pop();
                TreeNode* node = new TreeNode(val);
                *cur = node;
                stk.push(&(node->right));
                stk.push(&(node->left));
            } else if (ch == '#') {
                stk.pop();
                accumulated = "";
            } else {
                accumulated += ch;
            }
        }
        return root;
    }

 private:
    string encoded;

    void preorder(TreeNode* node) {
        bool nonEmpty = record(node);
        if (nonEmpty) {
            preorder(node->left);
            preorder(node->right);
        }
    }

    bool record(TreeNode* node) {
        if (!node) {
            encoded += "#";
            return false;
        }
        string s = to_string(node->val);
        encoded += s;
        encoded += ",";
        return true;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
