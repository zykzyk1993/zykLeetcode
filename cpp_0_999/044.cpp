/*
 * 44. 通配符匹配
 * 题意：带？和*的字符串匹配
 * 难度：困难
 * 分类：字符串 动态规划
 * 算法：和10题一样，*状态转移为dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1] || dp[i+1][j]，？或匹配字符则为dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j]
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i < p.size(); i++) {
            if (p[i] == '*'){
                dp[i+1][0] = dp[i][0];
            }
        }
        for(int i = 0; i < p.size(); i++) {
            for(int j = 0; j < s.size(); j++){
                if (p[i] == '*'){
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j+1] || dp[i+1][j];
                }
                else if (p[i] == '?' || p[i] == s[j]){
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};
