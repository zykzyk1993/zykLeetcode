/*
 * 338. 比特位计数
 * 对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回
 * 难度：中等
 * 分类：位运算 dp
 * 算法：注意每个数可以由i/2的数递推
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++){
            dp[i]=dp[i/2]+i%2;
        }
        return dp;
    }
};
