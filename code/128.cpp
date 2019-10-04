class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num:nums)
            s.insert(num);
        int ans=0;
        for(auto num:nums){
            if(s.count(num)>0){
                int len=1;
                int r=num+1;
                while(s.count(r)){
                    len++;
                    s.erase(r);
                    r++;
                }
                int l=num-1;
                while(s.count(l)){
                    len++;
                    s.erase(l);
                    l--;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
