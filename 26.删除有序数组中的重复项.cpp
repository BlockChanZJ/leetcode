/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pos == 0 || nums[i] != nums[pos - 1])
                nums[pos++] = nums[i];
        }
        return pos;
    }
};
// @lc code=end

