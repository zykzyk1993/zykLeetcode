class Solution {
public:
    //四平方和定理 数学公式
    int numSquares(int n) {
        //先根据上面提到的公式来缩小n
        while(n % 4 == 0) {
            n /= 4;
        }
        //如果满足公式 则返回4
        if(n % 8 == 7) {
            return 4;
        }
        //在判断缩小后的数是否可以由一个数的平方或者两个数平方的和组成
        int a = 0;
        while ((a * a) <= n) {
            int b = sqrt((n - a * a));
            if(a * a + b * b == n) {
                //如果可以 在这里返回
                if(a != 0 && b != 0) {
                    return 2;
                } else{
                    return 1;
                }
            }
            a++;
        }
        //如果不行 返回3
        return 3;
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        int i=1;
        while(i*i<=n){
            squares.push_back(i*i);
            i++;
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int j=0;j<squares.size();j++){
            for(int k=1;k<=n;k++){
                if(k>=squares[j]){
                    dp[k]=min(dp[k],dp[k-squares[j]]+1);
                }
            }
        }
        return dp[n];
    }
};
