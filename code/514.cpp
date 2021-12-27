/*
 * 514. 自由之路
 * 题意：给定解锁序列，以及环形密码锁，求最少挪动步数
 * 难度：困难
 * 分类：dp
 * 算法：维特比算法，dp数组为第i个字符，最终转到第j个位置的最小步数，逐步迭代更新每一步的局部最小值
 */
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size(), n = key.size(), res = m * n;
        vector<vector<int>> dp(n, vector<int>(m, m * n)); // 第i个字符，最终转到第j个位置的所需最小
        unordered_map<char, vector<int>> char_idx;
        for(int i = 0; i < m; i ++){
            char_idx[ring[i]].push_back(i);
        }
        int start_c = key[0];
        for(auto &idx:char_idx[start_c]){
            dp[0][idx] = min(idx, m - idx);
            if(n == 1){
                res = min(res, dp[0][idx]);
            }
        }
        for(int i = 1; i < n; i ++){
            for(auto &cur:char_idx[key[i]]){
                for(auto &prev:char_idx[key[i-1]]){
                    int dis = min(abs(cur - prev), m - abs(cur - prev));
                    dp[i][cur] = min(dp[i][cur], dp[i-1][prev] + dis);
                }
                if(i == n - 1){
                    res = min(res, dp[i][cur]);
                }
            }
        }
        return res + key.size();
    }
};
