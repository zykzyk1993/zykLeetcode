class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),minIndex,low=0,high=n-1,mid;
        //判断特殊情况
        if(n==0)return -1;
        //先二分找到minIndex然后再二分查找
        if(nums[0]<nums[n-1]){
            //特殊情况：递增数组
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
        }else{
            //去掉尾部与nums[0]相等的数值
            while(high>0&&nums[high]==nums[0])high--;
            //找minIndex过程注意二分条件
            while(low<high){
                mid=low+(high-low)/2;
                if(nums[mid]>nums[high]){
                    low=mid+1;
                }else{
                    high=mid;
                }
            }
            //记录minIndex
            minIndex=high;
            //根据target大小确定二分查找的空间
            if(target>=nums[0]){
                low=0;
                high=minIndex;
            }else if(target<=nums[n-1]&&target>=nums[minIndex]){
                low=minIndex;
                high=n-1;
            }
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
        }
        return -1;
    }
};
