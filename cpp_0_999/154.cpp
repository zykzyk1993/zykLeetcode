/*
 * 154. 寻找旋转排序数组中的最小值 II
 * 题意：含有重复元素的旋转数组中找最小值
 * 难度：困难
 * 分类：二分
 * 算法：二分即可，注意必须先排除末尾的重复元素
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
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
        return nums[rotate_idx];
    }
};
