/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> used(256, 0);
        int l, r, ans = 0;
        for (l = 0, r = 0; r < s.size(); used[s[l]]--, l++) {
            while (r < s.size() && used[s[r]] == 0) used[s[r]]++, r++;
            ans = max (ans, r - l);
        }
        return ans;
    }
};
// @lc code=end

