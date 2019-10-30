class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN,curMax=1,curMin=1;
        for(auto num:nums){
            if(num<0){
                swap(curMax,curMin);
            }
            curMax=max(curMax*num,num);
            curMin=min(curMin*num,num);
            ans=max(ans,curMax);
        }
        return ans;
    }
};
