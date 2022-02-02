/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string s = "IVXLCDM";
        vector <int> nums = {1, 5, 10, 50, 100, 500, 1000};
        string ans;
        while (num >= 4) {
            for (int i = 6; i >= 1; --i) {
                if (nums[i] / nums[i-1] == 5) {
                    if (num >= nums[i]) {
                        num -= nums[i];
                        ans.push_back(s[i]);  
                    } else if (num >= nums[i] - nums[i-1]) {
                        ans.push_back(s[i-1]);
                        ans.push_back(s[i]);
                        num -= nums[i] - nums[i-1];
                    } 
                } else {
                    while (num >= nums[i]) {
                        num -= nums[i];
                        ans.push_back(s[i]);
                    }
                    if (num >= nums[i] - nums[i-2]) {
                        num -= nums[i] - nums[i-2];
                        ans.push_back(s[i-2]);
                        ans.push_back(s[i]);
                    } 
                    // else if (num >= nums[i] - 2 * nums[i-2]) {
                    //     num -= nums[i] - 2 * nums[i-2];
                    //     ans.push_back(s[i-2]);
                    //     ans.push_back(s[i-2]);
                    //     ans.push_back(s[i]);
                    // }
                }
            }
        }
        while (num > 0) {
            num--;
            ans.push_back(s[0]);
        }
        return ans;
    }
};
// @lc code=end

