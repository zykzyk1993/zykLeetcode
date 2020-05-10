/*
 * 647. 回文子串
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 难度：中等
 * 分类：dp 字符串
 * 算法：经典回文子串dp算法，每次记得记录更新计数结果即可
 */
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),res=n;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(i<n-1&&s[i]==s[i+1]){
                dp[i][i+1]=true;
                res++;
            }
        }
        for(int len=2;len<n;len++){
            for(int start=0;start<n-len;start++){
                int end=start+len;
                if(dp[start+1][end-1]&&s[start]==s[end]){
                    dp[start][end]=true;
                    res++;
                }
            }
        }
        return res;
    }
};
