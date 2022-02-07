/*
 * 445. 两数相加 II
 * 题意：将被链表正序存储的2个整数相加，返回链表
 * 难度：中等
 * 分类：链表
 * 算法：反转链表后，按顺序遍历相加链表，最后反转回去
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
    ListNode* reverseList(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        while(head) {
            ListNode * temp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = temp;
        }
        return dummy->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = reverseList(l1);
        ListNode *p2 = reverseList(l2);
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        int carry = 0;
        while(p1 || p2 || carry) {
            int val1 = p1 ? p1->val:0;
            int val2 = p2 ? p2->val:0;
            int sum = val1 + val2 + carry;
            ListNode * newNode = new ListNode(sum % 10);
            carry = sum / 10;
            p->next = newNode;
            p = newNode;
            if(p1)p1 = p1->next;
            if(p2)p2 = p2->next;
        }
        return reverseList(dummy->next);
    }
};
