/*
 * 234. 回文链表
 * 判断一个链表是否是回文链表
 * 难度：简单
 * 分类：链表
 * 算法：注意，O(n)空间情况，直接保存到数组然后双指针，使用O(1)空间，使用快慢指针找到中点，然后翻转头插法，然后逐个比较，可能还需要还原
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)return true;
        ListNode* fast = head, *slow = head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode * cur = slow->next;
        slow->next = NULL;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = slow->next;    
            slow->next = cur;
            cur = temp;
        }
        ListNode* p1=head,*p2=slow->next;
        while(p2){
            if(p1->val!=p2->val)return false;
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};
