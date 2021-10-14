/*
 * 413. 等差数列划分
 * 题意：返回数组中所有是等差序列的子数组个数
 * 难度：中等
 * 分类：数组 dp
 * 算法：dp[i]表示i结尾的子序列等差子数组个数，如果三个元素为等差，则dp[i]=dp[i-1]+1(加上最后那个)，最终结果为dp数组之和
 */
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        if(n < 3)return 0;
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1]+1;
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
