/*
 * 1094. 拼车
 * 题意：给定乘客上下车的列表和车的容量，判断能否拼车成功，顺利送达每个乘客
 * 难度：中等
 * 分类：差分数组
 * 算法：用差分数组保存每个时刻上下车的情况，然后遍历一遍
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cnt(1001, 0); // 每个时刻上下车的动态变化
        for(auto &trip:trips) {
            cnt[trip[1]] += trip[0];
            cnt[trip[2]] -= trip[0];
        }
        int cur = 0;
        for(auto &c:cnt) {
            cur += c;
            if (cur > capacity) {
                return false;
            }
        }
        return true;
    }
};
