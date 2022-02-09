/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> ma;
        int cnt = 0;
        vector <int> ans, sum_count;
        for (int i = 0; i < words.size(); i++) {
            if (ma.count(words[i])) {
                sum_count[ma[words[i]]]++;
            } else {
                ma[words[i]] = cnt++;
                sum_count.push_back(1);
            }
        }
        assert (cnt == sum_count.size());
        int len = words[0].size();
        for (int shift = 0; shift < len; shift++) {
            vector <int> cur_count(cnt, 0);
            int have = 0;
            for (int i = shift, j = shift; i < s.size() && j < s.size(); j += len) {
                string t = s.substr(j, len);
                if (ma.count(t)) {
                    int id = ma[t];
                    cur_count[id]++;
                    have++;
                    while (cur_count[id] > sum_count[id]) {
                        int last_id = ma[s.substr(i, len)];
                        i += len;
                        cur_count[last_id]--;
                        have--;
                    }
                } else {
                    while (i < j) {
                        int last_id = ma[s.substr(i, len)];
                        i += len;
                        cur_count[last_id]--;
                        have--;
                    }
                    i = j + len;
                }
                if (have == words.size()) ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

