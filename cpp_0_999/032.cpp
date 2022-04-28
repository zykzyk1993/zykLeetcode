 /*
 * 32. 最长有效括号
 * 题意：寻找字符串最长有效括号
 * 难度：困难
 * 分类：DP 栈 线性扫描
 * 算法：
 * 动态规划：当s[i]=')' 若s[i-1]='(' 则dp[i]=dp[i−2]+2  若s[i-1]=')'且s[i-dp[i-1]-1]='('  dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2
 * 栈：左括号入栈index, 右括号出栈 计算当前index之差
 * 线性扫描：两次不同方向的线性扫描，记录right和left数量，相等时记录，超过时清零
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
