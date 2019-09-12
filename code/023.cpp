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
