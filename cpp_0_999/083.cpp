/*
 * 83. 删除排序链表中的重复元素
 * 题意：题意
 * 难度：简单
 * 分类：链表
 * 算法：按顺序遍历链表即可，后继和当前重复则删除后继，否则向后
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        while(head){
            if(head->next && (head->val == head->next->val)){
                head->next = head->next->next;
            }
            else{
                head = head->next;
            }
        }
        return dummy->next;
    }
};
