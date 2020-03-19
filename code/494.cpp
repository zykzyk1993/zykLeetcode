class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int diff = sum-S;
        if(diff<0||diff%2==1)return 0;        
        vector<int> dp(diff/2+1,0);
        dp[0]=1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=diff/2;j>=nums[i];j--){
                dp[j]=dp[j]+dp[j-nums[i]];
            }
        }
        return dp[diff/2];
    }
};
