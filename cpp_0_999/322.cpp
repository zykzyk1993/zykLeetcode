/*
 * 322. 零钱兑换
 * 计算可以凑成总金额所需的最少的硬币个数
 * 难度：中等
 * 分类：dp
 * 算法：可以重复使用的完全背包问题，注意初始条件
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i&&dp[i-coins[j]]<INT_MAX)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};
