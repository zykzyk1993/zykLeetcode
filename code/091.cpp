/*
 * 91. 解码方法
 * 题意：给定数字解码成字母，1-26对应字母，求可能方案数
 * 难度：中等
 * 分类：dp
 * 算法：方案数服从递推关系，注意0的特殊情况
 */
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0'){
            return 0;
        }
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    if(i > 1)
                        dp[i] = dp[i-2]; 
                    else
                        dp[i] = 1;
                }
                else{
                    return 0;
                }
            }
            else{
                if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')){
                    if(i > 1)
                        dp[i] = dp[i-1] + dp[i-2]; 
                    else
                        dp[i] = 2;
                }
                else{
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[n-1];
    }
};
