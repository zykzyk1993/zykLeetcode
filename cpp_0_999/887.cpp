/*
 * 887. 鸡蛋掉落
 * 题意：给定鸡蛋个数和楼层数，求最坏情况最少需要试几次能试出鸡蛋破碎的楼层
 * 难度：困难
 * 分类：分治 dp
 * 算法：
 */

// 超时 dp[i][j]表示i层j个最少需要多少次 遍历分割点
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n+1, k * n));
        for(int j = 0; j <= n; j ++) {
            dp[1][j] = j;
        }
        for(int i = 0; i <= k; i ++) {
            dp[i][0] = 0;
        }
        for(int i = 2; i <= k; i ++) {
            for (int j = 1; j <= n; j ++) {
                for (int split = 1; split <= j; split ++) {
                    dp[i][j] = min(dp[i][j], max(dp[i-1][split-1], dp[i][j - split]) + 1);
                }
            }
        }
        return dp[k][n];
    }
};

// 反向思路 dp[j][i]表示i个鸡蛋扔j次最多能测多少楼，超过n直接返回 则dp[i][j] = dp[i][j-1] + dp[i-1][j-1] + 1
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n));
        for(int j = 1; j < n; j ++) {
            for(int i = 1; i <= k; i ++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1] + 1;
            }
            if (dp[k][j] >= n) {
                return j;
            }
        }
        return n;
    }
};
