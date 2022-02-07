/*
 * 326. 3的幂
 * 题意：判断给定数字是否是3的幂
 * 难度：简单
 * 分类：数学
 * 算法：判断是否大于0且3^19能够整除，即int范围最大的幂
 */
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && ((int)pow(3,19) % n == 0);
    }
};
