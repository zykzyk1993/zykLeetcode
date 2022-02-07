/*
 * 2091.从数组中移除最大值和最小值
 * 题意：从数组中，可以从左或右一次性删除多个元素，求移除最大值和最小值最少删除多少个元素
 * 难度：中等
 * 分类：数组
 * 算法：找出最大和最小值位置，有四种移除方式，左左，右右，左右，右左
 */
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int min_idx = 0, max_idx = 0, min_val = nums[0], max_val = nums[0];
        for(int i = 0; i < n; i ++){
            if(nums[i] < min_val){
                min_val = nums[i];
                min_idx = i;
            }
            if(nums[i] > max_val){
                max_val = nums[i];
                max_idx = i;
            }
        }
        int res = n;
        res = min(res, max(min_idx, max_idx) + 1);
        res = min(res, n - min(min_idx, max_idx));
        res = min(res, max_idx + 1 + n - min_idx);
        res = min(res, min_idx + 1 + n - max_idx);
        return res;
    }
};
