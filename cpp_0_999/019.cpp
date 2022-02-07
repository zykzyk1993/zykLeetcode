 /*
 * 19. 删除链表的倒数第N个节点
 * 题意：删除链表的倒数第N个节点
 * 难度：简单
 * 分类：链表，快慢指针
 * 算法：快慢指针，快指针达到链表尾部时，慢指针所在位置即为操作的节点，注意声明dummy更方便
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        int cnt=0;
        while(head){
            if(cnt<n){
                cnt++;
            }else{
                pre=pre->next;
            }
            head=head->next;
        }
        pre->next=pre->next->next;
        return dummy->next;
    }
};
