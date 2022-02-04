/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head, *dummy = new ListNode(0, head);
        int len = 0;
        while (tmp != nullptr) tmp = tmp->next, len++;
        tmp = dummy;
        for (int i = 0; i < len - n; i++) {
            tmp = tmp->next;
        }
        
        tmp->next = tmp->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

