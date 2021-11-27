/*
 * 410. 分割数组的最大值
 * 题意：给定数组和m，划分m次的情况下，每组的最大值，希望最小可以是说少
 * 难度：困难
 * 分类：二分答案
 * 算法：通过二分查找答案，判定每个答案是否能满足划分不超过m次，初始情况low为最大元素，high为所有元素之和
 */
class Solution {
public:
    bool C(vector<int> &nums, int m, int sum){
        int cur_sum = 0, cnt = 1;
        for(auto &num:nums){
            if(cur_sum + num <= sum){
                cur_sum += num;
            }else{
                cnt++;
                cur_sum = num;
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = accumulate(nums.begin(), nums.end(), 0), mid;;
        for(auto &num:nums){
            low = max(low, num);
        }
        while(low <= high){
            mid = low + (high - low) / 2;
            if(C(nums, m, mid)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};
