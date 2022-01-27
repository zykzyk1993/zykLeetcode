/*
 * 718. 最长重复子数组
 * 题意：本质上是求最长公共子串
 * 难度：中等
 * 分类：数组 dp
 * 算法：对于相等的字符，dp[i][j]=dp[i-1][j-1]+1
 */
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if(nums1[i] == nums2[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
