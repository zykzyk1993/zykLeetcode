/*
 * 153. 寻找旋转排序数组中的最小值
 * 题意：不含重复元素的旋转数组中找最小值
 * 难度：中等
 * 分类：二分
 * 算法：和最后一个元素相比进行二分，注意完全升序的情况
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] < nums[n-1]) {
            return nums[0];
        }
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > nums[n - 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};
