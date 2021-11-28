/*
 * 1312. 让字符串成为回文串的最少插入次数
 * 题意：如题
 * 难度：困难
 * 分类：字符串 dp
 * 算法：和经典回文串类似，设置dp[start][end]相等则设为1
 */
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, n));
        for(int i = 0; i < n; i ++){
            if(i > 0){
                if(s[i-1] == s[i]){
                    dp[i-1][i] = 0;
                }else{
                    dp[i-1][i] = 1;
                }
            }
            dp[i][i] = 0;
        }
        for(int len = 3; len <= n; len ++){
            for(int start = 0; start <= n - len; start ++){
                int end = start + len - 1;
                if(s[start] == s[end]){
                    dp[start][end] = dp[start+1][end-1];
                }else{
                    dp[start][end] = min(dp[start+1][end], dp[start][end-1]) + 1;
                }
            }
        }
        return dp[0][n-1];
    }
};
