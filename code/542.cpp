/*
 * 542. 01 矩阵
 * 题意：输出矩阵，每个元素为输入矩阵中每个元素到周围0的最短距离
 * 难度：中等
 * 分类：dp
 * 算法：分为左上，右下递推两次，然后取两个dp数组的最小值
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, m*n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    dp[i][j] = 0;
                }
                if(i > 0){
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                }
                if(j > 0){
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
            }
        }

        for(int i = m-1; i >=0; i--){
            for(int j = n-1; j >=0; j--){
                if(mat[i][j] != 0){
                    if(i < m-1){
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    }
                    if(j < n-1){
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                    }
                }
            }
        }
        
        return dp;
    }
};
