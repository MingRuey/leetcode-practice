/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (42.31%)
 * Likes:    3760
 * Dislikes: 116
 * Total Accepted:    177.1K
 * Total Submissions: 418.6K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,2,6,1]
 * Output: [2,1,1,0]
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [-1,-1]
 * Output: [0,0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
struct MyNode {
    int val;
    int smaller;
    int duplicate;
    MyNode* left;
    MyNode* right;
    MyNode(int x, int i) : val(x), smaller(i), duplicate(0), left(NULL), right(NULL) {}
    MyNode(int x, int i, int c) : val(x), smaller(i), duplicate(c), left(NULL), right(NULL) {}
};


class Solution {
 public:
    vector<int> countSmaller(vector<int> const& nums) {
        ans = vector<int>(nums.size());
        root = NULL;
        buildTree(nums);
        return ans;
    }

 private:
    MyNode* root;
    vector<int> ans;

    void buildTree(vector<int> const& nums) {
        for (int i = nums.size()-1; i >= 0; i--) {
            ans[i] = _insert(&root, nums[i]);
        }
    }

    int _insert(MyNode** node, int val) {
        MyNode* target = *node;
        if (!target) {
            *node = new MyNode(val, 0);
            return 0;
        }

        if (val > target->val) {
            auto cnt = target->smaller + target->duplicate + 1;
            return cnt + _insert(&(target->right), val);
        } else if (val < target->val) {
            (target->smaller)++;
            return _insert(&(target->left), val);
        } else {
            (target->duplicate)++;
            return target->smaller;
        }
    }
};
// @lc code=end
