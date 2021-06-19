/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (57.19%)
 * Likes:    3298
 * Dislikes: 67
 * Total Accepted:    123.9K
 * Total Submissions: 213.7K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
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
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        ans.clear();
        dst = K;
        t = target;
        traverse(root, -1);
        return ans;
    }

 private:
    int dst;
    TreeNode* t;
    vector<int> ans;

    int traverse(TreeNode* node, int relative) {
        if (!node) return -1;
        if (node == t) relative = 0;
        if (dst == relative) {
            ans.push_back(node->val);
            return 0;
        }

        if (relative >= 0) {
            traverse(node->left, relative + 1);
            traverse(node->right, relative + 1);
            return 0;
        } else {
            int l = traverse(node->left, -1);
            int r = traverse(node->right, -1);
            if (l >= 0) {
                relative = l + 1;
                if (dst == relative) ans.push_back(node->val);
                traverse(node->right, relative + 1);
            } else if (r >= 0) {
                relative = r + 1;
                if (dst == relative) ans.push_back(node->val);
                traverse(node->left, relative + 1);
            }
            return relative;
        }
    }
};
// @lc code=end
