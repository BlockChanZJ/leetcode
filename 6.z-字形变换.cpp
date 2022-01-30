/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        if (numRows == 1) return s;
        for (int i = 0; i < numRows; i++) {
            int p = i, flag = 1;
            while (p < s.size()) {
                ans.push_back(s[p]);
                // cout << p << " " << s[p] << "  ";
                if (flag) p += 2 * (i > 0 && i < numRows-1 ? (numRows - i - 1) : (numRows-1)); 
                else p += 2 * (i > 0 && i < numRows-1 ? i : (numRows - 1));
                
                flag ^= 1;
            }
            // cout << endl;
        }
        return ans;
    }
};
// @lc code=end

