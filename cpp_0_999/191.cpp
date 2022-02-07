/*
 * 191. 位1的个数
 * 题意：返回整数二进制表示中1的个数
 * 难度：简单
 * 分类：位运算
 * 算法：n &= (n-1)能快速消除最后一位1 
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n) {
            ans ++;
            n &= (n-1);
        }
        return ans;
    }
};
