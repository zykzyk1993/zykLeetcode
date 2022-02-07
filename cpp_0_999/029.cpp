/*
* 29. 两数相除
* 题意：不用乘除mod实现整数除法
* 难度：中等
* 分类：位运算 数学
* 算法：转化为uint，从右移31位到0位，逐个判断相减，注意INT_MIN的边界条件
*/

#define LIMIT 0x80000000
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
		return 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool negative;
        negative = (dividend ^ divisor) < 0;//用异或来计算是否符号相异
        unsigned int t = dividend == INT_MIN ? LIMIT : abs(dividend);
        unsigned int d = divisor == INT_MIN ? LIMIT : abs(divisor);
        unsigned int result = 0;
        for (int i = 31; i >= 0; i--) {
            if ((t >> i) >= d) {//找出足够大的数2^n*divisor
                result += ((unsigned int)1) << i;//将结果加上2^n
                t -= d << i;//将被除数减去2^n*divisor
            }
        }
        if (result == LIMIT) {//特殊数不能将unsigned int转为int
            return INT_MIN;
        }
        else {
            return negative ? -(int)result : (int)result;//符号相异取反
        }
    }
};
