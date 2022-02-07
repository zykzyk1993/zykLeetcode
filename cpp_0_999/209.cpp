/*
 * 209. 长度最小的子数组
 * 题意：找到长度最小的，和大于target的子数组
 * 难度：中等
 * 分类：滑动窗口
 * 算法：每次更新右边界，动态更新左边界
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0;
        int ans = n + 1;
        while(r < n) {
            sum += nums[r];
            while(sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans == (n + 1) ? 0 : ans;
    }
};
