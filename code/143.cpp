/*
 * 143. 重排链表
 * 题意：将链表后半段倒序穿插排入
 * 难度：中等
 * 分类：链表
 * 算法：模拟，快慢指针找到中点，头插法reverse，最后穿插插入
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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * t = slow->next;
        slow->next = nullptr;
        ListNode * dummy = new ListNode(-1);
        while(t) {
            ListNode * temp = t->next;
            t->next = dummy->next;
            dummy->next = t;
            t = temp;
        } 
        t = dummy->next;
        ListNode * p = head;
        while(p && t) {
            ListNode * temp = t->next;
            ListNode * temp2 = p->next;
            t->next = p->next;
            p->next = t;
            t = temp;
            p = temp2;
        }
    }
};
