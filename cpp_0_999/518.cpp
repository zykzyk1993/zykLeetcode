/*
 * 518. 零钱兑换 II
 * 题意：给定数值，和硬币种类，不限使用次数，求所有凑整的方案个数
 * 难度：中等
 * 分类：dp
 * 算法：完全背包问题变种，每种新硬币，可以令i属于coin~amount加上i-coin的方案数
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto &coin:coins){
            for(int i = coin; i <= amount; i ++){
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
