/*
 * 120. 三角形最小路径和
 * 题意：三角形自顶向下最小路径和
 * 难度：中等
 * 分类：dp
 * 算法：dp数组通过上一行相邻结点中小的那一个加上当前元素来转移
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        int ans = INT_MAX;
        if (n == 1){
            return triangle[0][0];
        }
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < n; i ++){
            for(int j = 0; j <= i; j ++){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }else{
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
                if(i == n-1){
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};

//空间优化 注意因为要用到j-1所以要从大到小遍历
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        int ans = INT_MAX;
        if (n == 1){
            return triangle[0][0];
        }
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i ++){
            for(int j = i; j >= 0; j --){
                if(j == 0){
                    dp[j] = dp[j] + triangle[i][j];
                }else{
                    dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
                }
                if(i == n-1){
                    ans = min(ans, dp[j]);
                }
            }
        }
        return ans;
    }
};
