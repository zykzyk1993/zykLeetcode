/*
 * 342. 4的幂
 * 题意：判断是否为4的幂
 * 难度：简单
 * 分类：位运算
 * 算法：4的幂就是1左移 2 4 6..位
 */
class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i = 0; i < 32; i+=2){
            if(n == (1 << i)){
                return true;
            }
        }
        return false;
    }
};
