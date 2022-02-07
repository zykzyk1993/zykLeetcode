 /*
 * 160. 相交链表
 * 找到两个单链表相交的起始节点
 * 难度：简单
 * 分类：链表
 * 算法：先计算长度，然后长的先走差值，然后同步开始走，直到相遇
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA=headA;
        ListNode* curB=headB;
        int a=0,b=0;
        while(curA){
            curA=curA->next;
            a++;
        }
        while(curB){
            curB=curB->next;
            b++;
        }
        curA=headA;
        curB=headB;
        int cnt=0;
        if(a>b){
            while(cnt<(a-b)){
               curA=curA->next;
               cnt++;
            }
        }
        cnt=0;
        if(a<b){
            while(cnt<(b-a)){
               curB=curB->next;
               cnt++;
            }
        }
        while(curA&&curB){
            if(curA==curB)
                return curA;
            curA=curA->next;
            curB=curB->next;
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while(p1!=p2){
            p1 = p1?p1->next:headB;
            p2 = p2?p2->next:headA;
        }
        return p1;
    }
};
