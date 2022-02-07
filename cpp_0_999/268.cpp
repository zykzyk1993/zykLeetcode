/*
 * 268. 丢失的数字
 * 题意：查找0～n中丢失的数字
 * 难度：简单
 * 分类：位运算
 * 算法：异或运算即可找出
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = n;
        for(int i = 0; i < n; i ++){
            res = res ^ i;
            res = res ^ nums[i];
        }
        return res;
    }
};
