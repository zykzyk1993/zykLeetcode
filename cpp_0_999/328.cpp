/*
 * 328. 奇偶链表
 * 题意：将奇数索引值的统一排前面
 * 难度：中等
 * 分类：链表
 * 算法：按顺序遍历链表即可，用两个结点进行逐个链接，最后将两个链表连接
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *dummy1 = new ListNode(-1), *dummy2 = new ListNode(-1), *p1 = dummy1, *p2 = dummy2;
        while(head){
            p1->next = head;
            p2->next = head->next;
            p1 = head;
            p2 = head->next;
            if(head->next)
                head = head->next->next;
            else
                break;
        }
        p1->next = dummy2->next;
        return dummy1->next;
    }
};
