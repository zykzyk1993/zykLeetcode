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
