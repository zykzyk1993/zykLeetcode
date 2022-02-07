/*
 * 82. 删除排序链表中的重复元素 II
 * 题意：排序链表中，如果有重复的元素，全部删除
 * 难度：中等
 * 分类：链表
 * 算法：保留前驱节点，注意如果删除相等元素时，指针不能向后移动(有可能下一组还是重复元素)
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = head, *prev = dummy;
        while(p) {
            if(p->next && p->val == p->next->val){
                int cur_val = p->val;
                while(p && p->val == cur_val) {
                    p = p->next;
                }
                prev->next = p;
            }
            else{
                prev = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
