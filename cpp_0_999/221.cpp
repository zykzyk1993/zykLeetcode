/*
 * 221. 最大正方形
 * 找到01矩阵中的最大正方形
 * 难度：中等
 * 分类：dp
 * 算法：递推公式dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m)return 0;
        int n = matrix[0].size();
        if(!n)return 0;
        int ans=0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                ans=1;
            }
        }
        for(int j=0;j<n;j++){
            if(matrix[0][j]=='1'){
                dp[0][j]=1;
                ans=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};
