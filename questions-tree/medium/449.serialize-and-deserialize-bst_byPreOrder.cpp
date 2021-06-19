/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (53.64%)
 * Likes:    1816
 * Dislikes: 92
 * Total Accepted:    144K
 * Total Submissions: 266.8K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is converting a data structure or object into a sequence of
 * bits so that it can be stored in a file or memory buffer, or transmitted
 * across a network connection link to be reconstructed later in the same or
 * another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You need to ensure that a binary search tree can be serialized to a
 * string, and this string can be deserialized to the original tree structure.
 * 
 * The encoded string should be as compact as possible.
 * 
 * 
 * Example 1:
 * Input: root = [2,1,3]
 * Output: [2,1,3]
 * Example 2:
 * Input: root = []
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * 0 <= Node.val <= 10^4
 * The input tree is guaranteed to be a binary search tree.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preorder = "";
        Traverse(root);
        return preorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size()) return NULL;
        vector<int> decoded = decode(data);
        TreeNode* root = new TreeNode(decoded[0]);
        TreeNode* trace = root;
        int index = 0;
        return bstFromPre(decoded, &index, INT_MAX);
    }

 private:
    const char delim = ',';
    string preorder;

    TreeNode* bstFromPre(vector<int> const &decoded, int* i, int bound) {
        if (*i == decoded.size() || decoded[*i] > bound) return NULL;
        TreeNode* root = new TreeNode(decoded[(*i)++]);
        root->left = bstFromPre(decoded, i, root->val);
        root->right = bstFromPre(decoded, i, bound);
        return root;
    }

    vector<int> decode(const string &data) {
        istringstream ss(data);
        string item;
        vector<int> decoded;

        while (getline(ss, item, delim)) {
            decoded.push_back(stoi(item));
        }
        return decoded;
    }

    void Traverse(TreeNode* node) {
        if (!node) return;
        preorder += to_string(node->val) + delim;
        Traverse(node->left);
        Traverse(node->right);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
