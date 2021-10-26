/*
 * 313. 超级丑数
 * 题意：给定一组质因数，求由这几个构成的第n个"丑数"
 * 难度：中等
 * 分类：数学 dp
 * 算法：和264题方法类似，只是将2 3 5替换为质数数组，选取最小值，更新索引
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> dp(m, 0);
        vector<long long> nums{1};
        for(int i = 1; i < n ; i ++){
            long long val = nums[dp[0]] * primes[0];
            for(int j = 1; j < m ; j ++){
                val = min(val, nums[dp[j]] * primes[j]);
            }
            nums.push_back(val);
            for(int j = 0; j < m ; j ++){
                while(nums[dp[j]] * primes[j] <= val)
                    dp[j] ++;
            }
        }
        return nums.back();
    }
};
