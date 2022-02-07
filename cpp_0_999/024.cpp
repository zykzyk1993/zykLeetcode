 /*
 * 24. 两两交换链表中的节点
 * 题意：给定链表，两两交换相邻的节点，多余的不用换
 * 难度：中等
 * 分类：链表
 * 算法：模拟，注意不要断链
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy; //记录每组前驱节点
        while(head && head->next){
            ListNode* nextNode = head->next->next; //head 和 head->next 互换 1号 2号
            prev->next = head->next; //前驱节点后继为2号节点
            prev->next->next = head; //2号节点后继为1号节点
            head->next = nextNode; //1号节点后继为下一组节点
            prev = head;
            head = nextNode;
        }
        return dummy->next;
    }
};
