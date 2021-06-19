/*
 * @lc app=leetcode id=919 lang=cpp
 *
 * [919] Complete Binary Tree Inserter
 *
 * https://leetcode.com/problems/complete-binary-tree-inserter/description/
 *
 * algorithms
 * Medium (58.47%)
 * Likes:    408
 * Dislikes: 59
 * Total Accepted:    22.7K
 * Total Submissions: 38.4K
 * Testcase Example:  '["CBTInserter","insert","get_root"]\n[[[1]],[2],[]]'
 *
 * A complete binary tree is a binary tree in which every level, except
 * possibly the last, is completely filled, and all nodes are as far left as
 * possible.
 * 
 * Write a data structure CBTInserter that is initialized with a complete
 * binary tree and supports the following operations:
 * 
 * 
 * CBTInserter(TreeNode root) initializes the data structure on a given tree
 * with head node root;
 * CBTInserter.insert(int v) will insert a TreeNode into the tree with value
 * node.val = v so that the tree remains complete, and returns the value of the
 * parent of the inserted TreeNode;
 * CBTInserter.get_root() will return the head node of the tree.
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
 * Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
 * Output: [null,1,[1,2]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs =
 * [[[1,2,3,4,5,6]],[7],[8],[]]
 * Output: [null,3,4,[1,2,3,4,5,6,7,8]]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The initial given tree is complete and contains between 1 and 1000
 * nodes.
 * CBTInserter.insert is called at most 10000 times per test case.
 * Every value of a given or inserted node is between 0 and 5000.
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
class CBTInserter {
 public:
    explicit CBTInserter(TreeNode* root) {
        _root = root;
        queue<TreeNode*> empty;
        swap(que, empty);

        // bfs scan
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (!node->left || !node->right) que.push(node);
            }
        }
    }

    int insert(int v) {
        TreeNode* front = que.front();
        if (!front->left) {
            front->left = new TreeNode(v);
            que.push(front->left);
        } else {
            front->right = new TreeNode(v);
            que.push(front->right);
            que.pop();
        }
        return front->val;
    }

    TreeNode* get_root() {
        return _root;
    }

 private:
    TreeNode* _root;
    queue<TreeNode*> que;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
