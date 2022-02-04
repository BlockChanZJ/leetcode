/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto get_dist = [&] (int x, int y) {
            return abs(x - y);
        };
        int ans = nums[0] + nums[1] + nums.back();
        for (int i = 0; i < nums.size(); i++) {
            int k = nums.size() - 1;
            for (int j = i + 1; j < nums.size(); j++) {
                int res = nums[i] + nums[j] + nums[k];
                while (k - 1 > j && get_dist(nums[i]+nums[j]+nums[k-1],target) <= get_dist(nums[i]+nums[j]+nums[k],target)) k--;
                // cout << i << " " << j << " " << k << " " << ans << endl;
                if (j<k&&get_dist(nums[i]+nums[j]+nums[k],target) <= get_dist(ans,target))
                    ans = nums[i]+nums[j]+nums[k];
                if (k+1<nums.size()&&get_dist(nums[i]+nums[j]+nums[k+1],target) <= get_dist(ans,target))
                    ans = nums[i]+nums[j]+nums[k+1];
                // cout << i << " " << j << " " << k << " " << ans << endl;

            }
        }
        return ans;
    }
};
// @lc code=end

