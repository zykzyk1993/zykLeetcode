class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        sum/=2;
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>sum)return false;
            for(int j=sum;j>=nums[i];j--){
                dp[j]=dp[j]||dp[j-nums[i]];
            }
            if(dp[sum])return true;
        }
        return false;
    }
};

class Solution {
public:
    bool dfs(vector<int> &nums, int idx, int target){
        if(target==0)return true;
        if(idx==nums.size())return false;
        if(nums[idx]<=target&&dfs(nums,idx+1,target-nums[idx]))return true;
        return dfs(nums,idx+1,target);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        sort(nums.rbegin(),nums.rend());
        if(nums[0]>sum/2)return false;
        return dfs(nums,0,sum/2);
    }
};
