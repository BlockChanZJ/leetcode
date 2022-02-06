/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    void reverse(ListNode *head, ListNode *tail) {
        stack <ListNode*> stk;
        ListNode *cur = head, *last = tail->next;
        while (cur != tail) {
            stk.push(cur->next);
            cur = cur->next;
        }
        cur = head;
        while (!stk.empty()) {
            // cout << stk.top()->val << endl;
            cur->next = stk.top();
            stk.pop();
            cur = cur->next;
        }
        cur->next = last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *vhead = new ListNode(0, head);
        ListNode *cur = vhead;
        while (1) {
            ListNode *cur_head = cur, *cur_tail = cur;
            // cout << ": " << cur->val << " " << cur->next->val << endl;
            for (int i = 0; i < k; i++) {
                cur_tail = cur_tail->next;
                if (cur_tail == nullptr) goto end;
            }
            // cout << cur_head << " " << cur_tail << endl;
            // cout << cur_head->val << " ";
            // cout << cur_tail->val << endl;
            // cout << cur_head->val << " " << cur_tail->val << endl;
            reverse(cur_head, cur_tail);
            for (int i = 0; i < k; i++)
                cur = cur->next;
        }
        end:
        // cur = vhead;
        // cout << vhead->val << endl;
        // while (cur != nullptr)  {
        //     cout << "!" << cur->val << " ";
        //     cur = cur->next;
        // }
        head = vhead->next;
        delete vhead;
        return head;
    }
};
// @lc code=end

