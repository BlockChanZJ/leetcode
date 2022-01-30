/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *cur = l3;
        int add = 0;
        while (l1 != nullptr || l2 != nullptr || add > 0) {
            if (l1 != nullptr)
                add += l1->val;
            if (l2 != nullptr)
                add += l2->val;
            cout << add << endl;
            cur->val = add % 10;
            add /= 10;
            //cout << add << endl;
            if ((add > 0) || (l1 != nullptr && l1->next != nullptr) || (l2 != nullptr && l2->next != nullptr))
                cur->next = new ListNode(0);
            cur = cur->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return l3;
    }
};
// @lc code=end

