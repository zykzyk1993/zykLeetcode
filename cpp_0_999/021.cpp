 /*
 * 21. 合并两个有序链表
 * 题意：合并两个有序链表为一个单链表
 * 难度：简单
 * 分类：链表
 * 算法：两个指针向后移动，拼接，记得最后判空拼接
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* p=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                p->next=l1;
                l1=l1->next;
            }else{
                p->next=l2;
                l2=l2->next;
            }
            p=p->next;
        }
        p->next=l1?l1:l2;
        return dummy->next;
    }
};
