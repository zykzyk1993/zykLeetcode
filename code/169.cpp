class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,curNum=nums[0];
        for(auto num:nums){
            if(cnt==0){
                curNum=num;
            }
            if(curNum==num)cnt++;
            else cnt--;
        }
        return curNum;
    }
};
