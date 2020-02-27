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
