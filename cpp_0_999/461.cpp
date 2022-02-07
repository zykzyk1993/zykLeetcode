/*
 * 461. 汉明距离
 * 题意：计算汉明距离
 * 难度：简单
 * 分类：位运算
 * 算法：异或，计算1的位数
 */
class Solution {
public:
    int hammingDistance(int x, int y){
        int cnt = 0, num = x ^ y;
        while(num > 0)
        {
            if(num % 2 == 1) ++cnt;
            num /= 2;
        }
        return cnt;
    }
};
