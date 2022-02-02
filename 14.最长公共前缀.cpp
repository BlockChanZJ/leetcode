/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = 1e9;
        string ans;
        for (int i = 0; i < strs.size(); i++) n = min(n, (int)strs[i].size());
        for (int j = 0; j < n; j++) {
            char c = strs[0][j];
            for (int i = 0; i < strs.size(); i++) {
                if (c != strs[i][j]) return ans;
            }
            ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end

