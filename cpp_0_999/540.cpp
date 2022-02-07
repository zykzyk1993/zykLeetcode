/*
 * 540. 有序数组中的单一元素
 * 题意：有序数组除了某个元素其他元素都有两个，找出该元素
 * 难度：中等
 * 分类：二分
 * 算法：单一元素在左侧和右侧，中点的重复元素情况会不同
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        int low = 0, high = n - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if (mid == 0 && nums[mid]!= nums[mid+1])
                return nums[mid];
            if (mid == n - 1 && nums[mid]!= nums[mid-1]) 
                return nums[mid];
            if (nums[mid] == nums[mid+1]){
                if(mid % 2 == 0){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }else if(nums[mid] == nums[mid-1]){
                if(mid % 2 != 0){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }

            }else{
                return nums[mid];
            }
        }
        return nums[mid];
    }
};
