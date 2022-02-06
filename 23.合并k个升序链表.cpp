/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0), *cur = head;
        for (int k = 0; k < 10000; k++) {
            int Min = 1e4 + 1, p = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr) continue;
                if (lists[i]->val < Min) {
                    Min = lists[i]->val;
                    p = i;
                } 
            }
            if (p == -1) break;
            // cout << p << " " << Min << endl;
            cur->next = lists[p];
            lists[p] = lists[p]->next;
            cur = cur->next;
        }
        cur = head->next;
        delete head;
        return cur;
    }
};
// @lc code=end

