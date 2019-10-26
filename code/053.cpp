/*
 * 53. 最大子序和
 * 题意：最大连续子序列和
 * 难度：简单
 * 分类：数组 DP
 * 算法：每次和为负数则更新为0，并且随时比较
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0],sum=0;
        for(int num:nums){
            sum=max(sum,0);
            sum+=num;
            res=max(sum,res);
        }
        return res;
    }
};
