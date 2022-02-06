/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3 = new ListNode(-101), *cur = list3;
        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                cur->next = list2;
                list2 = list2->next;
            } else if (list2 == nullptr) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                if (list1->val < list2->val) {
                    cur->next = list1;
                    list1 = list1->next;
                } else {
                    cur->next = list2;
                    list2 = list2->next;
                }
            }
            cur = cur->next;
        }
        cur = list3->next;
        delete list3;
        return cur;
    }
};
// @lc code=end

