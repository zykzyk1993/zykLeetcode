class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        if(n==0){
            return {-1,-1};
        }
        //注意二分的边界条件不同即可
        int low=0,high=n-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        //注意此处应判断low>=n的情况也为未查找到
        if(low>=n||nums[low]!=target){
            return {-1,-1};
        }
        ans.push_back(low);
        low=0,high=n-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<=target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        //此时不必判断
        ans.push_back(high);
        return ans;
    }
};
