/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char,int> ma;
        ma['I'] = 1;
        ma['V'] = 5;
        ma['X'] = 10;
        ma['L'] = 50;
        ma['C'] = 100;
        ma['D'] = 500;
        ma['M'] = 1000;

        int mode = 0, cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && ma[s[i]] < ma[s[i+1]]) ans -= ma[s[i]];
            else ans += ma[s[i]];
        }
        return ans;
    }
};
// @lc code=end

