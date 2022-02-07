/*
 * 260. 只出现一次的数字 III
 * 题意：数组中有两个数字出现1次，其余出现2次，找出它们
 * 难度：中等
 * 分类：位运算
 * 算法：分组异或，全部异或得到两个数字的diff，取其中1位为1的，将数组按照该位1或0分为两组分别异或，得到最终结果
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto &num:nums){
            x = x ^ num;
        }
        int mask = 1;
        while((x & mask) == 0){
            mask <<= 1;
        }
        int res1 = 0, res2 = 0;
        for(auto &num:nums){
            if(num & mask){
                res1 = res1 ^ num;
            }else{
                res2 = res2 ^ num;
            }
        }
        return {res1, res2};
    }
};
