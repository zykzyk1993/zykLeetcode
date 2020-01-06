class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int dpRob=nums[0],dpNotRob=0;
        for(int i=1;i<nums.size();i++){
            int tempRob=dpNotRob+nums[i];
            int tempNotRob=max(dpRob,dpNotRob);
            dpRob=tempRob;
            dpNotRob=tempNotRob;
        }
        return max(dpRob,dpNotRob);
    }
};
