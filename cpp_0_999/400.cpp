/*
 * 400. 第n位数字
 * 题意：返回数组中和为给定数的下标
 * 难度：中等
 * 分类：数学
 * 算法：找规律，每组指定位数的数字，都是9*10^xx个，然后找到起始位置，再找到对应数字，最后找到对应位
 */
class Solution {
public:
    int findNthDigit(int n) {
        long long cur_digit = 1, cur_cnt = 9;
        while (n - cur_digit * cur_cnt > 0) {
            n -= cur_digit * cur_cnt;
            cur_digit ++;
            cur_cnt *= 10;
        }
        int start = pow(10, cur_digit - 1); // 第几组的起始
        int num = start + (n - 1) / cur_digit; // 位于第几个数字
        int digit_idx = cur_digit - (n - 1) % cur_digit; //从右往左第几位
        return (num / (int)(pow(10, digit_idx - 1))) % 10; // 返回对应位数
    }
};
