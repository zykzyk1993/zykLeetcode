/*
 * 137. 只出现一次的数字 II
 * 题意：数组中有一个数字出现一次，其余数字出现三次，找出该数字
 * 难度：中等
 * 分类：位运算
 * 算法：使用32位数组保存每一位出现的次数，然后每一位余3等于1的数位为1，凑成最终数字
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit_cnt(32, 0);
        for (auto &num : nums) {
            for (int i = 0; i < 32; i ++) {
                if (num & (1 << i)) {
                    bit_cnt[i] ++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i ++) {
            if (bit_cnt[i] % 3 == 1) {
                res |= 1 << i;
            }
        }
        return res;
    }
};
