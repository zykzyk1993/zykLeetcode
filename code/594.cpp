/*
 * 594. 最长和谐子序列
 * 题意：和谐数组，最大值和最小值相差不超过1，求最长和谐序列长度
 * 难度：简单
 * 分类：哈希表
 * 算法：对哈希表中每个数，判断其前后一个数是否能合成和谐子序列，然后移除
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int>m;
        for(auto &num:nums){
            m[num]++;
        }
        int ans = 0;
        while(!m.empty()){
            pair<int, int> p = *(m.begin());
            int cur = p.first;
            if(m.count(cur-1)){
                ans = max(ans, p.second+m[cur-1]);
            }
            if(m.count(cur+1)){
                ans = max(ans, p.second+m[cur+1]);
            }
            m.erase(cur);
        }
        return ans;
    }
};
