class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),sum=0,res=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(auto num:nums){
            sum+=num;
            if(m.count(sum-k)>0){
                res+=m[sum-k];
            }
            m[sum]++;
        }
        return res;
    }
};
