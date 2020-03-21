class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums);
        sort(nums.begin(),nums.end());
        int n = nums.size(),i=0,j=n-1;
        while(i<=j&&temp[i]==nums[i])i++;
        while(i<=j&&temp[j]==nums[j])j--;
        return j-i+1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(),left=-1,right=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                left=i;
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                right=i;
                break;
            }
        }
        if(left==right)return 0;
        int minVal=INT_MAX,maxVal=INT_MIN;
        for(int i=left;i<=right;i++){
            minVal=min(minVal,nums[i]);
            maxVal=max(maxVal,nums[i]);
        }
        int i=left-1,j=right+1;
        while(i>=0&&nums[i]>minVal)i--;
        while(j<n&&nums[j]<maxVal)j++;
        return j-i-1;
    }
};
