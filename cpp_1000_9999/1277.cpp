/*
 * 1277. 统计全为 1 的正方形子矩阵
 * 题意：给定01矩阵，求全为1的正方形子矩阵个数
 * 难度：中等
 * 分类：dp
 * 算法：求解以每一个元素为右下角的正方形个数(最大正方形长度就是正方形个数)，和最大正方形思路基本一致
 */
 class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m ; i ++) {
            for(int j = 0; j < n; j ++){
                if(matrix[i][j] == 0){
                    continue;
                }
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
