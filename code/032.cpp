 /*
 * 32. 最长有效括号
 * 题意：给定括号对数n, 生成所有可能的并且有效的括号组合
 * 难度：困难
 * 分类：DP 栈 线性扫描
 * 算法：
 * 动态规划：当s[i]=')' 若s[i-1]='(' 则dp[i]=dp[i−2]+2  若s[i-1]=')'且s[i-dp[i-1]-1]='('  dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,n=s.size(),left=0,right=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')left++;
            else right++;
            if(right==left){
                ans=max(ans,left+right);
            }
            if(right>left){
                right=0;
                left=0;
            }
        }
        left=0;
        right=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')left++;
            else right++;
            if(right==left){
                ans=max(ans,left+right);
            }
            if(right<left){
                right=0;
                left=0;
            }
        }
        return ans;
    }
};
