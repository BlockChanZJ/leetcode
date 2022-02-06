/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *vhead = new ListNode(0, head);
        ListNode *cur = vhead;
        while (cur->next != nullptr) {
            if (cur->next->next == nullptr) {
                break;
            } else {
                ListNode *v1 = cur->next, *v2 = cur->next->next;
                cout << v1->val << " " << v2->val << endl;
                cur->next = v2;
                v1->next = v2->next;
                v2->next = v1;
            }
            cur = cur->next->next;
        }
        head = vhead->next;
        delete vhead;
        return head;
    }
};
// @lc code=end

