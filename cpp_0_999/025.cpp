
/*
* 25. K 个一组翻转链表
* 题意：以k个为一组反转链表，剩余不变
* 难度：困难
* 分类：链表
* 算法：模拟，对每一组进行头插法，注意不要断链
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||k==1)return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy; //保存当前组的前驱节点
        int cur_cnt = 0;
        while(head) {
            cur_cnt ++; 
            if(cur_cnt == k) { //当前组达到k个
                ListNode *next_head = head->next; //暂存下一组节点
                ListNode *next_prev = prev->next;
                ListNode *cur_p = prev->next; //开始反转链表
                prev->next = next_head; //先连接尾部
                while(cur_p != next_head){ //头插法 反转链表
                    ListNode *temp = cur_p->next;
                    cur_p->next = prev->next;
                    prev->next = cur_p;
                    cur_p = temp;
                }
                prev = next_prev;
                head = next_head;
                cur_cnt = 0;
            }
            else
                head = head->next;
        }
        return dummy->next;
    }
};
