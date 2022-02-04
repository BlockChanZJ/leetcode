/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int x = 0, y = 0, z = 0;
        stack <char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push('(');
            } else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(') return false;
                stk.pop();
            } else if (s[i] == '[') {
                stk.push(s[i]);
            } else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[') return false;
                stk.pop();
            } else if (s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty() || stk.top() != '{') return false;
                stk.pop();
            }
        }
        if (stk.empty())
            return true;
        return false;
    }
};
// @lc code=end

