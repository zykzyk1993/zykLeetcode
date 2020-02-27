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
