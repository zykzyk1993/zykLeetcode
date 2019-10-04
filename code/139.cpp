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
