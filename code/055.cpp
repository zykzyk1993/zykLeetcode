class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return true;
        int right=nums[0];
        for(int i=0;i<n;i++){
            if(i>right)return false;
            right=max(right,i+nums[i]);
        }
        return true;
    }
};
