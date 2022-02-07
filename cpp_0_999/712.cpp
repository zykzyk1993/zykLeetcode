/*
 * 712. 两个字符串的最小ASCII删除和
 * 题意：找到使两个字符串相等所需删除字符的ASCII值的最小和
 * 难度：中等
 * 分类：字符串 dp
 * 算法：编辑距离dp扩展，变为加上ASCII值
 */
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i ++){
            dp[i][0] = dp[i-1][0] + (int)s1[i-1];
        } 
        for(int j = 1; j <= n; j ++){
            dp[0][j] = dp[0][j-1] + (int)s2[j-1];
        }
        for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j ++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j] + (int)s1[i-1], dp[i][j-1] + (int)s2[j-1]);
                }
            }
        } 
        return dp[m][n];
    }
};
