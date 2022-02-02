/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        // for (int x : nums) cout <<  x << " "; cout << endl;
        for (int i = 0; i < n; i++) {
            int k = n - 1;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; j++) {
                if (nums[j] == nums[j-1] && j > i+1) continue;
                while (k > j && nums[i] + nums[j] + nums[k] > 0) k--;
                // cout << i << " " << j << " " << k << endl;
                if (k > j && nums[i] + nums[j] + nums[k] == 0)
                    ans.push_back({nums[i], nums[j], nums[k]});
                // while (k < n && nums[i] + nums[j] + nums[k] == 0) k++;
            }
        }
        return ans;
    }
};
// @lc code=end

