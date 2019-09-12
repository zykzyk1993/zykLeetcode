class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),minIndex,low=0,high=n-1,mid;
        if(n==0)return -1;
        if(nums[0]<nums[n-1]){
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
            while(high>0&&nums[high]==nums[0])high--;
            while(low<high){
                mid=low+(high-low)/2;
                if(nums[mid]>nums[high]){
                    low=mid+1;
                }else{
                    high=mid;
                }
            }
            minIndex=high;
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
