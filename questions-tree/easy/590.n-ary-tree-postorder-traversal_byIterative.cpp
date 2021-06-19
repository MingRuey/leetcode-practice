/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (72.99%)
 * Likes:    861
 * Dislikes: 72
 * Total Accepted:    116.2K
 * Total Submissions: 158.9K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given an n-ary tree, return the postorder traversal of its nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal,
 * each group of children is separated by the null value (See examples).
 * 
 * 
 * 
 * Follow up:
 * 
 * Recursive solution is trivial, could you do it iteratively?
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [5,6,3,2,4,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The height of the n-ary tree is less than or equal to 1000
 * The total number of nodes is between [0, 10^4]
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root) return res;

        stack<Node*> stk;
        stack<Node*> parents;
        stk.push(root);
        while (!stk.empty()) {
            Node* top = stk.top();
            if (parents.size() && top == parents.top()) {
                res.push_back((parents.top())->val);
                parents.pop();
                stk.pop();
            } else if (has_children(top)) {
                parents.push(top);
                int size = top->children.size();
                for (int i = size - 1; i >= 0; i--) {
                    stk.push(top->children[i]);
                }
            } else {
                res.push_back(top->val);
                stk.pop();
            }
        }
        return res;
    }

 private:
    bool has_children(Node* node) {
        return (node->children).size();
    }
};
// @lc code=end
