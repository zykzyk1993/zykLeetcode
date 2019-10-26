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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* fast=head,*slow=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=NULL;
        ListNode* head1=sortList(head);
        ListNode* head2=sortList(temp);
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        while(head1&&head2){
            if(head1->val<head2->val){
                pre->next=head1;
                head1=head1->next;
            }else{
                pre->next=head2;
                head2=head2->next;
            }
            pre=pre->next;
        }
        pre->next=head1?head1:head2;
        return dummy->next;
    }
};
