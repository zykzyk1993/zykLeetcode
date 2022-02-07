/*
 * 2.两数相加
 * 题意：将被链表逆序存储的2个整数相加，返回链表
 * 难度：中等
 * 分类：链表
 * 算法：按顺序遍历链表即可，注意保存进位值carry
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        int carry=0;
        while(l1||l2||carry){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            int sum=val1+val2+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* newNode=new ListNode(sum);
            pre->next=newNode;
            pre=newNode;
        }
        return dummy->next;
    }
};
