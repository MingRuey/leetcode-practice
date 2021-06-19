/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 *
 * https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (37.36%)
 * Likes:    1401
 * Dislikes: 2380
 * Total Accepted:    135.4K
 * Total Submissions: 347K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, calculate the vertical order traversal of
 * the binary tree.
 * 
 * For each node at position (row, col), its left and right children will be at
 * positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root
 * of the tree is at (0, 0).
 * 
 * The vertical order traversal of a binary tree is a list of top-to-bottom
 * orderings for each column index starting from the leftmost column and ending
 * on the rightmost column. There may be multiple nodes in the same row and
 * same column. In such a case, sort these nodes by their values.
 * 
 * Return the vertical order traversal of the binary tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[9],[3,15],[20],[7]]
 * Explanation:
 * Column -1: Only node 9 is in this column.
 * Column 0: Nodes 3 and 15 are in this column in that order from top to
 * bottom.
 * Column 1: Only node 20 is in this column.
 * Column 2: Only node 7 is in this column.
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [[4],[2],[1,5,6],[3],[7]]
 * Explanation:
 * Column -2: Only node 4 is in this column.
 * Column -1: Only node 2 is in this column.
 * Column 0: Nodes 1, 5, and 6 are in this column.
 * ⁠         1 is at the top, so it comes first.
 * ⁠         5 and 6 are at the same position (2, 0), so we order them by their
 * value, 5 before 6.
 * Column 1: Only node 3 is in this column.
 * Column 2: Only node 7 is in this column.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,2,3,4,6,5,7]
 * Output: [[4],[2],[1,5,6],[3],[7]]
 * Explanation:
 * This case is the exact same as example 2, but with nodes 5 and 6 swapped.
 * Note that the solution remains the same since 5 and 6 are in the same
 * location and should be ordered by their values.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 1000
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map.clear();
        initialize(root);
        traverse(root, 0, 0);

        vector<vector<int>> ans;
        for (int col = 0; col < width; col++) {
            vector<int> rows;
            for (int row = 0; row < height; row++) {
                int* pt = arr[col] + row;
                unordered_map<int*, vector<int>>::iterator it;
                if ((it = map.find(pt)) != map.end()) {
                    vector<int> val = it->second;
                    sort(val.begin(), val.end());
                    rows.insert(rows.end(), val.begin(), val.end());
                }
            }
            ans.push_back(rows);
        }
        return ans;
    }

 private:
    int **arr;
    int minimum;
    int width;
    int height;
    unordered_map<int*, vector<int>> map;

    void initialize(TreeNode* root) {
        int l = leftMost(root, 0);
        int r = rightMost(root, 0);
        minimum = l;
        width = r - l + 1;
        height = getHeight(root);
        arr = new int*[width];
        for (int i = 0; i < width; i++) {
            arr[i] = new int[height];
            fill_n(arr[i], height, -1);
        }
    }

    int leftMost(TreeNode* root, int cur) {
        if (!root) return cur;
        int l = root->left ? leftMost(root->left, cur - 1) : cur;
        int r = root->right ? leftMost(root->right, cur + 1) : cur;
        return min(l, r);
    }

    int rightMost(TreeNode* root, int cur) {
        if (!root) return cur;
        int l = root->left ? rightMost(root->left, cur - 1) : cur;
        int r = root->right ? rightMost(root->right, cur + 1) : cur;
        return max(l, r);
    }

    int getHeight(TreeNode* node) {
        if (!node) return 0;
        int l = getHeight(node->left);
        int r = getHeight(node->right);
        return max(l, r) + 1;
    }

    void traverse(TreeNode* node, int col, int row) {
        if (!node) return;
        traverse(node->left, col - 1, row + 1);
        traverse(node->right, col + 1, row + 1);

        int* pt = arr[col - minimum] + row;
        unordered_map<int*, vector<int>>::iterator it;
        if ((it = map.find(pt)) != map.end()) {
            it->second.push_back(node->val);
        } else {
            vector<int> rows;
            rows.push_back(node->val);
            map[pt] = rows;
        }
    }
};
// @lc code=end
