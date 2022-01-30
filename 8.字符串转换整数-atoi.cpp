/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int course = 0;
        long long ans = 0, res = 0;
        int sig = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (course >= 1) return res;
            } else if (s[i] == '-' || s[i] == '+') {
                if (course >= 1) return res;
                course = 1;
                if (s[i] == '-') sig = -1;
            } else if (s[i] <= '9' && s[i] >= '0') {
                course = 2;
                ans = ans * 10 + sig * (s[i] - '0');
                if (ans > INT_MAX) res = INT_MAX;
                if (ans < INT_MIN) res = INT_MIN;
                if (ans <= INT_MAX && ans >= INT_MIN) res = ans;
                if (res == INT_MAX || res == INT_MIN) return res;
            } else {
                return res;
            }
            cout << res << " " << ans << endl;
        }
        if (res == 0) res = ans;
        return res;
    }
};
// @lc code=end

