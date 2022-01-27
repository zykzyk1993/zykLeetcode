/*
 * 162. 寻找峰值
 * 题意：寻找峰值位置，两侧默认为负无穷，要求logn复杂度
 * 难度：中等
 * 分类：二分
 * 算法：二分，如果是峰值直接返回，否则往高的一边二分，总会有峰值
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if (mid < n - 1 && nums[mid + 1] > nums[mid]) {
                low = mid + 1;
            }
            else if (mid > 0 && nums[mid - 1] > nums[mid]) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
        return mid;
    }
};
