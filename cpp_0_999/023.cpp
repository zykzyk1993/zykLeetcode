 /*
 * 23. 合并K个排序链表
 * 题意：给定括号对数n, 生成所有可能的并且有效的括号组合
 * 难度：困难
 * 分类：链表 优先队列
 * 算法：将val和链表序号组成pair输入优先队列，排队输入
 * 也可以每次pop的时候将后继节点push
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct cmp
{
    bool operator()(const pair<int,int> p1, const pair<int,int> p2)
    {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push(make_pair(lists[i]->val,i));
                lists[i]=lists[i]->next;
            }
        }
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            pre->next=new ListNode(p.first);
            if(lists[p.second]){
                pq.push(make_pair(lists[p.second]->val,p.second));
                lists[p.second]=lists[p.second]->next;
            }
            pre=pre->next;
        }
        return dummy->next;
    }
};

//2021
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
class Compare_Node
{
public:
    bool operator () (ListNode * l1, ListNode * l2)
    {
        return l1->val > l2->val;
    }
};
priority_queue<ListNode*, vector<ListNode*>, Compare_Node> pq;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * dummy = new ListNode(-1);
        ListNode * head = dummy;
        for(auto &p:lists){
            if(p){
                pq.push(p);
            }
        }
        while(!pq.empty()){
            ListNode *temp = pq.top();
            pq.pop();
            head->next = temp;
            if(temp->next)pq.push(temp->next);
            head = head->next;
        }
        return dummy->next;
    }
};
