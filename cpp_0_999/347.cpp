/*
 * 347. 前 K 个高频元素
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素
 * 难度：中等
 * 分类：堆 哈希
 * 算法：哈希表计数，然后用堆找出topK
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int> > pq;
        for(auto n:nums) mp[n]++;
        for(auto m:mp) pq.push(make_pair(m.second,m.first));
        vector<int> res;
        for(int i=0;i<k;i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
