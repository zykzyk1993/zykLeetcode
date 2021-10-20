/*
 * 476. 数字的补数
 * 题意：求数字补数，5(101)补数为2(010)
 * 难度：简单
 * 分类：位运算
 * 算法：找到位数和当前数字一样的全1数字，异或后得到答案
 */
class Solution {
public:
    int findComplement(int num) {
        int temp = num, c = 0;
        while(temp){
            temp >>= 1;
            c = (c << 1) + 1;
        }
        return num ^ c;
    }
};
