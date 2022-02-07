 /*
 * 142. 环形链表II
 * 判断链表是否有环并返回环的入口位置
 * 难度：中等
 * 分类：链表 快慢指针
 * 算法：当快慢指针相遇的时候，让慢指针回到头，同步走就会在链表环入口位置相遇
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
    ListNode *detectCycle(ListNode *head) {
        if(!head)return NULL;
        ListNode* fast=head,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                slow=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return NULL;        
    }
};
