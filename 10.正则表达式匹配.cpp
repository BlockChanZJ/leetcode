/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> f(n + 1, vector<int> (m+1));
        f[0][0] = 1;
        auto match = [&] (int x, int y) {
            if (p[y - 1] == '.') return true;
            return s[x] == p[y - 1];
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] == p[j]) {
                    f[i + 1][j + 1] |= f[i][j];
                } else if (p[j] == '.') {
                    f[i + 1][j + 1] |= f[i][j];
                } else if (p[j] == '*') {
                    f[i][j + 1] |= f[i][j - 1];
                    f[i + 1][j + 1] |= f[i + 1][j - 1];
                    if (match(i, j)) {
                        f[i + 1][j + 1] |= f[i][j - 1];
                        f[i + 1][j + 1] |= f[i][j + 1]; 
                        f[i + 1][j + 1] |= f[i][j];
                    }
                    //cout << i << " " << j << " " << match(i, j) << " " << f[i + 1][j + 1] << endl;

                }
            }
        }
        return f[n][m];
    }
};
// @lc code=end

