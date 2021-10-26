/*
 * 264. 丑数 II
 * 题意：因子只有2 3 5的为丑数，求第n个丑数
 * 难度：中等
 * 分类：数学 dp
 * 算法：用dp2 dp3 dp5分别保存下一个乘2 3 5会超出当前范围的索引(所有丑数都是由之前的乘2 3 5得到的)，每次取最小的一个，然后更新dp2 dp3 dp5
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp2=0, dp3=0, dp5=0;
        vector<int> nums{1};
        for(int i = 1; i < n; i ++){
            int val = min(nums[dp2]*2, min(nums[dp3]*3, nums[dp5]*5));
            nums.push_back(val);
            while(nums[dp2]*2<=val)
                dp2++;
            while(nums[dp3]*3<=val)
                dp3++;
            while(nums[dp5]*5<=val)
                dp5++;
        }
        return nums.back();
    }
};
