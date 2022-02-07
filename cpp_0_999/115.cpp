/*
 * 115. 不同的子序列
 * 题意：s中最多可以有t的多少个子序列方案
 * 难度：困难
 * 分类：dp
 * 算法：dp[i][j]表示s和t的下标，dp[i][j] = dp[i-1][j]+(s[i-1]==t[j-1]?dp[i-1][j-1]:0)，本题的坑在于溢出，答案都错
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(n==0) return 1;
        if(m<n) return 0;
        vector<vector<long>> dp(m+1, vector<long>(n+1, 0));
        for(int i = 0;i<=m;i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j <= n; j++){
            dp[j][j] = s.substr(0,j) == t.substr(0, j)?1:0;
            for(int i = j+1; i <= m; i++){
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
                dp[i][j] = dp[i][j] % INT_MAX;
            }
        }
        return dp[m][n];
    }
};
