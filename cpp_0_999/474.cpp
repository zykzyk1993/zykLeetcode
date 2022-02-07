/*
 * 474. 一和零
 * 题意：共m个0和n个1，判断最多能组合成字符串数组中的多少个
 * 难度：中等
 * 分类：dp
 * 算法：背包问题，费用为0和1的个数，value为1
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for(auto &str:strs){
            int cnt0 = 0, cnt1 = 0;
            for(auto &c:str){
                if(c == '0')cnt0++;
                else cnt1++;
            }
            for(int i = m ; i >= cnt0; i--){
                for(int j = n; j >= cnt1; j --){
                    dp[i][j] = max(dp[i][j], dp[i-cnt0][j-cnt1]+1);
                }
            }
            ans = max(ans, dp[m][n]);
        }
        return ans;
    }
};
