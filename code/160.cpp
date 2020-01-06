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
