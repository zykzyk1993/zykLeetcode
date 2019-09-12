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
