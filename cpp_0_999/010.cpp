 /*
 * 10. 正则表达式匹配
 * 题意：正则表达式匹配
 * 难度：困难
 * 分类：字符串，dp
 * 算法：递推情况有 * 两个字符 . 或匹配 一个字符
    注意先填充字符串为空的情况
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen=s.size(),pLen=p.size();
        //dp[i][j]代表s[0]~s[i-1]与p[0]~p[j-1]是否match
        vector<vector<bool>> dp(sLen+1,vector<bool>(pLen+1));
        dp[0][0]=true;
        for(int j=1;j<pLen;j++){
            if(p[j]=='*'){
                //处理s为空的，p带*的情况
                dp[0][j+1]=dp[0][j-1]; 
            }
        }
        for(int i=1;i<=sLen;i++){
            for(int j=1;j<=pLen;j++){
                if(j<pLen&&p[j]=='*'){
                    //忽略p串中的*
                    dp[i][j+1]=dp[i][j-1];
                    if(p[j-1]=='.'||s[i-1]==p[j-1]){
                        //去掉前一个字符，同时是否保留*都可以。由于递推关系，不需要考虑再靠前的字符了
                        dp[i][j+1]=dp[i][j+1]||dp[i-1][j+1]||dp[i-1][j-1];
                    }
                }
                else if(p[j-1]=='.'||s[i-1]==p[j-1]){
                    dp[i][j]=dp[i][j]||dp[i-1][j-1];
                }
            }
        }
        return dp[sLen][pLen];
    }
};

//2021
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 0; i < p.size(); i++) {
            if (i > 0 && p[i] == '*'){
                dp[i+1][0] = dp[i-1][0];
            }
        }
        for(int i = 0; i < p.size(); i++) {
            for(int j = 0; j < s.size(); j++){
                if (i > 0 && p[i] == '*'){
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i-1][j+1];
                    if (p[i-1] == '.' || p[i-1] == s[j]) {
                        dp[i+1][j+1] = dp[i+1][j+1] || dp[i+1][j] || dp[i-1][j];
                    }
                }
                else if (p[i] == '.' || p[i] == s[j]){
                    dp[i+1][j+1] = dp[i+1][j+1] || dp[i][j];
                }
            }
        }
        return dp[m][n];
    }
};
