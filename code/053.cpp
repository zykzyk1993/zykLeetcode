class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0],sum=0;
        for(int num:nums){
            sum=max(sum,0);
            sum+=num;
            res=max(sum,res);
        }
        return res;
    }
};
