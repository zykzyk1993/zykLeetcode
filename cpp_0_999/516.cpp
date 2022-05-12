/*
 * 516. 最长回文子序列
 * 题意：不需要连续
 * 难度：中等
 * 分类：字符串 dp
 * 算法：类似回文子串，只是递推公式不同，dp[i][j]表示i到j的最长回文子序列长度
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; i --) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j ++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
