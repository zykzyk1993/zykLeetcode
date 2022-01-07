/*
 * 787. K 站中转内最便宜的航班
 * 题意：从src到dst最多中转k次，最便宜价格
 * 难度：中等
 * 分类：图 dp
 * 算法：dp数组保存最多k次，以i结尾的最便宜价格，用类似floyd算法更新
 */
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst){
            return 0;
        }
        int ans = INT_MAX;
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        for(int i = 1; i <= k + 1; i ++) {
            for(auto &flight:flights) {
                if (dp[i-1][flight[0]] != INT_MAX) {
                    dp[i][flight[1]] = min(dp[i][flight[1]], dp[i-1][flight[0]] + flight[2]);
                }
            }
            ans = min(ans, dp[i][dst]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
