/*
 * 64. 最小路径和
 * 从左上到右下使路径总和最小
 * 难度：中等
 * 分类：dp
 * 算法：dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j] 然后可以将二维dp压缩成一维dp
 */
//二维动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int j=1;j<n;j++)dp[0][j]=dp[0][j-1]+grid[0][j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

//一维动态规划
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n,0);
        dp[0]=grid[0][0];
        for(int j=1;j<n;j++)dp[j]=dp[j-1]+grid[0][j];
        for(int i=1;i<m;i++){
            dp[0]=dp[0]+grid[i][0];
            for(int j=1;j<n;j++){
                dp[j]=min(dp[j],dp[j-1])+grid[i][j];
            }
        }
        return dp[n-1];
    }
};
