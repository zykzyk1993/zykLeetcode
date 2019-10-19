/*
 * 35. 搜索插入位置
 * 搜索指定值，找不到就返回插入位置
 * 难度：简单
 * 分类：数组 二分
 * 算法：直接二分，找不到的话返回边界右侧low
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size(),low=0,high=n-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
