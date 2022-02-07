/*
 * 382. 链表随机节点
 * 题意：实现在链表中随机选择一个节点
 * 难度：中等
 * 分类：数学
 * 算法：采用蓄水池算法，一共m个数随机选择k个，有k/m概率替换，本例中，m不断增大，池子尺寸k为1。
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
    ListNode * head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int ans = head->val;
        int i = 1;
        ListNode *p = head;
        while(p){
            if(rand() % i == 0){
                ans = p->val;
            }
            i++;
            p = p->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
