/*
 * 63. 不同路径 II
 * 题意：同上题，grid中有障碍物
 * 难度：中等
 * 分类：dp
 * 算法：障碍物方案为0，其他情况状态由左+上
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                if(obstacleGrid[i][j] != 0) {
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }else if(i == 0){
                    dp[i][j] = dp[i][j-1];
                }else if(j == 0){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];        
    }
};
