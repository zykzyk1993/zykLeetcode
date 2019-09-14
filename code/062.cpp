
//dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++)dp[i][0]=1;
        for(int j=0;j<n;j++)dp[0][j]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

//排列组合
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int M=m<n?m-1:n-1;
        //计算 C(N,M)
        //根据：C(N,M)=C(N,M-1)*M/(N-M+1);
        long ans=1;
        for(int i=1;i<=M;i++)
            ans=ans*(N-i+1)/i;
        return ans;
    }
};
