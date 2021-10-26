/*
 * 697. 数组的度
 * 题意：包含所有，数组中出现次数最多元素的，最短子序列
 * 难度：简单
 * 分类：哈希表
 * 算法：记录每个元素的初始位置，然后如果超过度或等于度，就更新
 */
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m, start;
        int degree = 0, n = nums.size(), ans = n;
        for(int i = 0; i < n ; i ++) {
            int num = nums[i];
            if(m[num] == 0){
                start[num] = i;
            }
            m[num]++;
            if(m[num] > degree){
                ans = i - start[num] + 1;
                degree = m[num];
            }
            else if(m[num] == degree){
                ans = min(ans, i - start[num] + 1);
            }
        }
        return ans;
    }
};
