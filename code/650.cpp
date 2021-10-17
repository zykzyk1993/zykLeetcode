/*
 * 650. 只有两个键的键盘
 * 题意：只能复制粘贴，从一个'A'一共操作几次到n个'A'
 * 难度：中等
 * 分类：dp
 * 算法：如果i被j整除，则dp[i]可以为dp[j]+dp[i/j]，等同于完成j，以及从1复制到i/j个等效操作
 */
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        int h = sqrt(n);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j <= h; ++j) {
                if (i % j == 0) {
                    dp[i] = dp[j] + dp[i/j];
                    break;
                }
            }
        }
        return dp[n];
    }
};

//实际问题还可以抽象成分解质因数之和
class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i * i <= n; ++i) {
            while (n % i == 0) {
                n /= i;
                ans += i;
            }
        }
        if (n > 1) {
            ans += n;
        }
        return ans;
    }
};
