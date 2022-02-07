 /*
 * 206. 反转链表
 * 题意：如题，返回头节点
 * 难度：简单
 * 分类：链表
 * 算法：基础链表操作，头插法
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        while(head){
            ListNode* temp = head->next;
            head->next=dummy->next;
            dummy->next=head;
            head=temp;
        }
        return dummy->next;
    }
};
