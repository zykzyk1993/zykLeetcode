/*
 * 50. Pow(x, n)
 * 题意：计算x的n次方
 * 难度：中等
 * 分类：数学
 * 算法：快速幂运算，按照指数的每一位，如果是1则乘base，每次base平方
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0) {
            if (n == INT_MIN) {
                return (x == 1 || x == -1)? 1 : 0;
            }
            n = -n;
            x = 1 / x;
        }
        double res = 1.0, base = x;
        int i = 0;
        while(i < 32 && (1 << i) <= n) {
            if (n & (1 << i)) {
                res *= base;
            }
            base = base * base;
            i++;
        }
        return res;
    }
};
