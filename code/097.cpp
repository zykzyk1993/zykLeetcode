/*
 * 97. 交错字符串
 * 题意：判断s3是否是s1和s2交错形成的
 * 难度：中等
 * 分类：字符串 dp
 * 算法：dp数组，dp[m+1][n+1]代表s1前m个和s2前n个是否能为s3前m+n的交错字符串
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), l = s3.size();
        if(l != m+n) return false;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                int idx = i+j-1;
                if(i==0 && j==0){
                    dp[i][j] = true;
                }else if(i==0){
                    dp[i][j] = dp[i][j-1] && s3[j-1] == s2[j-1]; 
                }else if(j==0){
                    dp[i][j] = dp[i-1][j] && s3[i-1] == s1[i-1]; 
                }else{
                    dp[i][j] = (dp[i-1][j] && s3[idx] == s1[i-1]) || (dp[i][j-1] && s3[idx] == s2[j-1]); 
                }
            }
        }
        return dp[m][n];
    }
};
