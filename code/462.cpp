/*
 * 462. 最少移动次数使数组元素相等 II
 * 题意：每次单个元素加减1，求最少的移动次数使数组全部相等
 * 难度：中等
 * 分类：数学
 * 算法：策略上，选择中位数(或两个中间数中的一个)作为target是最合适的，否则，将会有更多的数字需要移动。随后模拟即可
 */
class Solution {
public:
    int calcMoves(vector<int> &nums, int target){
        int sum = 0;
        for(auto &num:nums){
            sum += abs(num-target);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return calcMoves(nums, nums[n/2]);
    }
};
