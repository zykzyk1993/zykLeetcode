/*
 * 61. 旋转链表
 * 题意：返回链表旋转k次的结果
 * 难度：中等
 * 分类：链表
 * 算法：连接成环，找到第k个节点，从该节点出断开，注意要取余数
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return NULL;
        ListNode* p = head;
        //计数
        int cnt = 1;
        while(p->next){
            p=p->next;
            cnt++;
        }
        p->next = head; //连接成环
        k = cnt - k % cnt; //找到第k个节点，该节点处断开
        p = head, cnt = 1;
        while(cnt < k){
            p=p->next;
            cnt++;
        }
        ListNode * res = p->next; //记录后继节点用于返回
        p->next = NULL; //断开链表
        return res;
    }
};
