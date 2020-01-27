/*
 * 70. 爬楼梯
 * 爬楼梯的不同方法
 * 难度：简单
 * 分类：dp
 * 算法：斐波那契
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        vector<int> dp(n,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
