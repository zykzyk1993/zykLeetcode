 /*
 * 136. 只出现一次的数字
 * 数组中其他都出现两次，只有一个数字出现一次，找出来
 * 难度：简单
 * 分类：位运算
 * 算法：直接异或一遍
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto num:nums){
            ans=ans^num;
        }
        return ans;
    }
};
