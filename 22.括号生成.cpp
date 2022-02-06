/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void dfs (vector<string> &ans, string &s, int l, int r, int n) {
        if (l == r && r == n) {
            ans.push_back(s);
            return;
        }
        if (l < n) {
            s.push_back('(');
            dfs(ans, s, l+1, r, n);
            s.pop_back();
        } 
        if (r < l) {
            s.push_back(')');
            dfs(ans, s, l, r+1, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        string s;
        dfs (ans, s, 0, 0, n);
        return ans;
    }
};
// @lc code=end

