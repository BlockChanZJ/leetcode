/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    vector<int> getNext(string &s) {
        int n = s.size();
        vector<int> next(n);
        for (int i = 1, j = 0; i < n; ) {
            // cout << i << " " << j << endl;
            if (s[i] == s[j]) {
                next[i++] = ++j;
            } else if (j != 0) {
                j = next[j-1];
            } else {
                next[i++] = 0;
            }
            
        }
        return next;
    }
    int getFirstPlace(string &s, string &t, vector<int> &next) {
        int m = s.size(), n = t.size();
        int i, j = 0;
        // cout << s << " " << t << endl;
        // for (int x : next) cout << x << " "; cout << endl;
        for (i = 0; i < m; ) {
            if (s[i] == t[j]) j++, i++;
            else if (j > 0) j = next[j - 1];
            else i++;
            // cout << i << " " << j << endl;
            if (j == n) return i - j;
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if (haystack.size() == needle.size() && needle.size() == 0)
            return 0;
        if (needle.size() == 0) return 0;
        if (haystack.size() == 0) return -1;
        auto next = getNext(needle);
        return getFirstPlace(haystack, needle, next);
    }
};
// @lc code=end

