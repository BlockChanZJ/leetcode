/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string new_s(2 * s.size() + 1, ' ');
        new_s[0] = '$';
        for (int i = 0; i < s.size(); i++) {
            new_s[(i << 1) + 1] = s[i];
            new_s[(i << 1) + 2] = '#';
        }
        new_s[2 * s.size()] = '@';
        
        int n = new_s.size();

        int maxLength = 1, pos, maxRight = -1, bestPos = 1, length, circle = 1;
        vector <int> longest(n, 0);
        for (int i = 0; i < n; i++) {
            // case 1 or 2
            if (i < maxRight)
                longest[i] = min(longest[pos - (i - pos)], maxRight - i);
            else 
                longest[i] = 1;
            
            while (i - longest[i] >= 0 && i + longest[i] < n && new_s[i - longest[i]] == new_s[i + longest[i]])
                longest[i]++;
            if (i + longest[i] > maxRight) {
                pos = i;
                maxRight = i + longest[i];
            }

            if (new_s[i] == '#') {
                length = longest[i] / 2 * 2;
            } else {
                length = (longest[i] - 1) / 2 * 2 + 1;
            }

            if (length > maxLength) {
                maxLength = length;
                bestPos = i;
                circle = longest[i];
            }
        }
        // cout << new_s << endl;
        // for (int x : longest) cout << x << " ";
        // cout << endl;
        // cout << bestPos << " " << maxLength << " " << circle << endl;
        string ans;
        for (int i = bestPos - circle + 1; i <= bestPos + circle - 1; i++)
            if (new_s[i] != '#' && new_s[i] != '@' && new_s[i] != '$')
                ans.push_back(new_s[i]);
        return ans;
    }
};
// @lc code=end

