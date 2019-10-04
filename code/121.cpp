class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        int ans=0,minPre=prices[0];
        for(int i=1;i<prices.size();i++){
            ans=max(ans,prices[i]-minPre);
            minPre=min(minPre,prices[i]);
        }
        return ans;
    }
};
