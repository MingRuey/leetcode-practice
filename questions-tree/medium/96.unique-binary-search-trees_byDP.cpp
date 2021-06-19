/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (53.97%)
 * Likes:    4203
 * Dislikes: 155
 * Total Accepted:    342.8K
 * Total Submissions: 632.9K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */

// @lc code=start
class Solution {
 public:
    int numTrees(int n) {
        if (n == 0) return 0;
        for (int i = 0; i <= n; i++) {
            ans.push_back(unique_bst(i));
        }
        return ans[n];
    }

 private:
    vector<int> ans;

    int unique_bst(int n) {
        if (n == 0) return 1;

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int count = 1;
            int left = ans[i - 1];
            int right = ans[n - i];
            count *= left;
            count *= right;
            sum += count;
        }
        return sum;
    }
};
// @lc code=end
