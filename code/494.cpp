/*
 * 494. 目标和
 * 给一个序列添加正负号，得到目标和
 * 难度：中等
 * 分类：DP
 * 算法：背包问题，实际上还是能否组成diff/2的和，把这些部分+改成-即可
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int diff = sum-S;
        if(diff<0||diff%2==1)return 0;        
        vector<int> dp(diff/2+1,0);
        dp[0]=1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=diff/2;j>=nums[i];j--){
                dp[j]=dp[j]+dp[j-nums[i]];
            }
        }
        return dp[diff/2];
    }
};
