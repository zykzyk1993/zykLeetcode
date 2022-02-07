 /*
 * 139. 单词拆分
 * 给定非空字符串和字典，判断是否能够拆分
 * 难度：中等
 * 分类：dp
 * 算法：对于每个位置，对应字典中每个单词，判断是否能够往前倒推
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(auto word:wordDict){
                int wl=word.size();
                if(dp[i]==false&&wl<=i&&s.substr(i-wl,wl)==word){
                    dp[i]=dp[i-wl];
                }
            }
        }
        return dp[n];
    }
};
