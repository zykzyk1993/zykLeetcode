/*
 * 319. 灯泡开关
 * 题意：n个灯泡，n个人分别开关整除1~n的灯泡，求最后亮着的灯泡个数
 * 难度：中等
 * 分类：数学
 * 算法：分解质因数个数为奇数(即平方数)的灯泡最后才会亮着
 */
class Solution {
public:
    int bulbSwitch(int n) {
        int i = 1, res = 0;
        while(i * i <= n) {
            res++;
            i++;
        }
        return res;
    }
};
