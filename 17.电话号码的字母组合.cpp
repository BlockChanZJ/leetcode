/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> ma;
        ma['2'] = "abc";
        ma['3'] = "def";
        ma['4'] = "ghi";
        ma['5'] = "jkl";
        ma['6'] = "mno";
        ma['7'] = "pqrs";
        ma['8'] = "tuv";
        ma['9'] = "wxyz";
        vector <string> ans;
        queue <string> q;
        for (int i = 0; i < ma[digits[0]].size(); i++) {
            string s; s.push_back(ma[digits[0]][i]);
            q.push(s); 
        }
        while (!q.empty()) {
            auto s = q.front(); q.pop();
            if (s.size() == digits.size()) {
                ans.push_back(s);
                continue;
            }
            for (int i = 0; i < ma[digits[s.size()]].size(); i++) {
                string t = s;
                t.push_back(ma[digits[s.size()]][i]);
                q.push(t);
            }
        }
        return ans;
    }
};
// @lc code=end

