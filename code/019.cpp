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
