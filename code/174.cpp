/*
 * 174. 地下城游戏
 * 题意：从左上角到右下角至少需要携带多少体力，进入每个房间至少需要1体力
 * 难度：困难
 * 分类：dp
 * 算法：反向思路，从右下角反推到左上角，可以根据情况从右或下推，每次必须保证体力最少为1
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = m - 1; i >= 0; i --){
            for(int j = n - 1; j >= 0; j --){
                if(i == m - 1 && j == n - 1){
                    dp[i][j] = 1 + max(0, -dungeon[i][j]);
                }
                else if(i == m - 1){
                    dp[i][j] = max(1, dp[i][j+1] - dungeon[i][j]);
                }
                else if(j == n - 1){
                    dp[i][j] = max(1, dp[i+1][j] - dungeon[i][j]);
                }
                else{
                    dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
                }
            }
        }
        return dp[0][0];
    }
};
