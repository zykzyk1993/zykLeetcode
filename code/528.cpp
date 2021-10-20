/*
 * 528. 按权重随机选择
 * 题意：实现按照权重随机选择数组中的数
 * 难度：中等
 * 分类：数学
 * 算法：计算前缀和，随机，然后二分查找
 */
class Solution {
public:
    vector<int> sums;
    Solution(vector<int>& w) {
        sums = w;
        partial_sum(sums.begin(), sums.end(), sums.begin());
    }
    
    int pickIndex() {
        int pos = (rand() % sums.back()) + 1;
        return lower_bound(sums.begin(), sums.end(), pos) - sums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
