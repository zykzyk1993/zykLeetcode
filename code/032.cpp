//暴力求解会超时，要巧妙地线性扫描
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
