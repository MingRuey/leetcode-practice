/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (36.23%)
 * Likes:    1682
 * Dislikes: 100
 * Total Accepted:    128.4K
 * Total Submissions: 350.6K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an array nums and two types of queries where you should update the
 * value of an index in the array, and retrieve the sum of a range in the
 * array.
 * 
 * Implement the NumArray class:
 * 
 * 
 * NumArray(int[] nums) Initializes the object with the integer array nums.
 * void update(int index, int val) Updates the value of nums[index] to be
 * val.
 * int sumRange(int left, int right) Returns the sum of the subarray nums[left,
 * right] (i.e., nums[left] + nums[left + 1], ..., nums[right]).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * Output
 * [null, 9, null, 8]
 * 
 * Explanation
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // return 9 = sum([1,3,5])
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // return 8 = sum([1,2,5])
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -100 <= nums[i] <= 100
 * 0 <= index < nums.length
 * -100 <= val <= 100
 * 0 <= left <= right < nums.length
 * At most 3 * 10^4 calls will be made to update and sumRange.
 * 
 * 
 */

// @lc code=start
class SegTree {
 public:
    int sum;
    SegTree* left;
    SegTree* right;

    explicit SegTree(int sum): SegTree(sum, NULL, NULL) {
    }

    SegTree(int sum, SegTree* left, SegTree* right) {
        this->sum = sum;
        this->left = left;
        this->right = right;
    }
};

class NumArray {
 public:
    explicit NumArray(vector<int> const &nums) {
        seg = Build(nums.data(), nums.size());
        size = nums.size();
    }

    void update(int index, int val) {
        if (index < 0 || index > size - 1) return;
        _update(seg, index, val, size);
    }

    int sumRange(int left, int right) {
        if (left > right) {
            int tmp = left;
            left = right;
            right = tmp;
        }

        if (left < 0) left = 0;
        if (right > size - 1) right = size - 1;
        return _sum(seg, left, right, size);
    }

 private:
    int size;
    SegTree* seg;
    SegTree* Build(const int* start, int size) {
        if (!size) return NULL;
        if (size == 1) return new SegTree(*start);
        int half = size / 2 + size % 2;
        SegTree* left = Build(start, half);
        SegTree* right = Build(start + half, size - half);
        return new SegTree(left->sum + right->sum, left, right);
    }

    int _update(SegTree* node, int index, int val, int cursize) {
        if (!(node->left) && !(node->right)) {
            int diff = val - (node->sum);
            node->sum = val;
            return diff;
        }

        int half = cursize / 2 + cursize % 2;
        int diff;
        if (index + 1 <= half) {
            diff = _update(node->left, index, val, half);
        } else {
            diff = _update(node->right, index - half, val, cursize - half);
        }
        node->sum += diff;
        return diff;
    }

    int _sum(SegTree* node, int left, int right, int cursize) {
        if (left > right) return 0;
        if (right - left + 1 == cursize) return node->sum;
        int half = cursize / 2 + cursize % 2;
        int mleft = right + 1 > half ? half - 1: right;
        int lsum = _sum(node->left, left, mleft, half);
        int mright = left + 1 <= half ? half: left;
        int rsum = _sum(node->right, mright - half, right - half, cursize - half);
        return lsum + rsum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
