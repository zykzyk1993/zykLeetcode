/*
 * 583. 两个字符串的删除操作
 * 题意：每次删除一个字符，使两个字符串相等的最小次数
 * 难度：中等
 * 分类：字符串 dp
 * 算法：两者长度减去最长公共子序列长度
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m+n-2*dp[m][n];
    }
};
