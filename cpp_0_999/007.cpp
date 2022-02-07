/*
 * 7. 整数反转
 * 题意：反转整数，溢出返回0
 * 难度：简单
 * 分类：数学 模拟
 * 算法：模拟即可，注意先判断乘10以前是否溢出
 */
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x) {
            if(res > INT_MAX / 10 || res < INT_MIN / 10)
                return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};
