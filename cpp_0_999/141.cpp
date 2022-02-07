 /*
 * 141. 环形链表
 * 判断链表是否有环
 * 难度：中等
 * 分类：链表 快慢指针
 * 算法：使用快慢指针，判断是否相遇
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        ListNode* fast=head,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)return true;
        }
        return false;
    }
};
