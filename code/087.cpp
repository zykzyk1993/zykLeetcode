/*
 * 87. 扰乱字符串
 * 题意：如果递归两两交换可以完成字符串替换，则称为扰乱字符串，判断两个字符串是否是扰乱字符串
 * 难度：困难
 * 分类：字符串 dp
 * 算法：dp数组，两个字符串起始位置和长度，通过查找每个split点，判断是否能构成扰乱字符串
 */
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1)));
        for(int i = 0; i < s1.size(); i ++){
            for(int j = 0; j < s2.size(); j ++){
                if(s1[i] == s2[j]){
                    dp[i][j][1] = true;
                }
            }
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i ++){
                for(int j = 0; j <= n - len; j ++){
                    for(int split = 1; split < len && !dp[i][j][len]; split++){
                        dp[i][j][len] = (dp[i][j][split] && dp[i+split][j+split][len-split]) || (dp[i][j+len-split][split] && dp[i+split][j][len-split]);
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};
