/*
 * 693. 交替位二进制数
 * 题意：判断n的二进制是否是10交替的
 * 难度：简单
 * 分类：位运算
 * 算法：循环判断n和n/2最后一位是否相同即可
 */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n){
            int temp1 = n & 1;
            int temp2 = (n >> 1) & 1;
            if(temp1^temp2 == 0)return false;
            else n >>= 1;
        }
        return true;
    }
};
