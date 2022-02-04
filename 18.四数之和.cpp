/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int d = nums.size() - 1;
                for (int k = j + 1; k < nums.size(); k++) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    long long x = nums[i], y = nums[j], z =  nums[k];
                    while (k < d && x + y + z + nums[d] > target) d--;
                    if (k < d && x + y + z + nums[d] == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[d]});
                    }
                    while (k < d && x + y + z + nums[d] == target) d--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

