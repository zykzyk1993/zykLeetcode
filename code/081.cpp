/*
 * 81. 搜索旋转排序数组 II
 * 题意：非递减旋转数组中可能有相同元素，查找元素
 * 难度：中等
 * 分类：二分
 * 算法：思路和前题二分类似，但必须从后往前先排除结尾和头部相等的元素
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int rotate_idx=0, n=nums.size();
        while(n>1&&nums[0]==nums[n-1]){
            n--;
        }
        int low=0,high=n-1,mid;
        if(nums[0]<nums[high])
            rotate_idx=0;
        else{
            while(low<=high){
                mid=low+(high-low)/2;
                if(nums[mid]>nums[n-1]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            rotate_idx=low;
        }
        if(target<=nums[n-1]){
            low=rotate_idx;
            high=n-1;
        }else{
            low=0;
            high=rotate_idx-1;
        }
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return false;
    }
};
