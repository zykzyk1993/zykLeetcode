 /*
 * 148. 排序链表
 * 如题
 * 难度：中等
 * 分类：链表
 * 算法：模拟使用快速排序或者归并排序(快慢指针拆分),注意链表连接情况
 */
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

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }
        
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            
            while (cur) {
                auto left = cur;
                auto right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size); // left->@->@ right->@->@  cur->@->...
                
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
    
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
        
        if (!p) return nullptr;
        
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

//快排版本
class Solution {
public:
    ListNode * quickSort(ListNode* head, ListNode *tail) {
        if(head == nullptr || head == tail) {
            return head;
        }
        ListNode *p = head->next;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while(p != tail) {
            if(p->val < head->val) {
                if(p != p2) {
                    swap(p->val, p2->val);
                }
                if(p1->next)
                    p1 = p1->next;
                if(p2->next)
                    p2 = p2->next;
            }
            p = p->next;
        }
        if(p1 != head)
            swap(p1->val, head->val);
        quickSort(head, p1);
        quickSort(p1->next, tail);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return quickSort(head, nullptr);
    }
};
