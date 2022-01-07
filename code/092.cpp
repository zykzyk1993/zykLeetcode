/*
 * 92. 反转链表 II
 * 题意：反转指定索引之间的链表
 * 难度：中等
 * 分类：链表
 * 算法：注意保存反转区域左侧节点，然后头插法
 */
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *p = dummy;
        int idx = 1;
        while(idx < left) {
            p = p -> next;
            idx ++;
        }
        ListNode *left_p = p; // 反转区域左侧节点
        p = p -> next;
        ListNode *right_p = p; // 反转区域第一个节点 
        while(idx <= right) {
            ListNode * temp = p->next; // 保存后继
            p->next = left_p->next; 
            left_p->next = p;
            p = temp;
            idx ++;
        }
        right_p->next = p;
        return dummy->next;
    }
};
