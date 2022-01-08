/*
 * 231. 2 的幂
 * 题意：判断是否是2的幂
 * 难度：简单
 * 分类：数学
 * 算法：判断和1左移后是否相等
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i < 31; i ++) {
            if(n == (1 << i)) {
                return true;
            }
        }
        return false;
    }
};
