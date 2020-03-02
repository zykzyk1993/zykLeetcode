class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=prices.size();
        if(k<2)return 0;
        int dpSell[k]={0};
        int dpnotSell[k]={0};
        for(int i=1;i<k;i++){
            dpSell[i]=dpSell[i-1]+prices[i]-prices[i-1];//当天卖出的一定是前一天卖出加上差价，未新增交易
            if(i>1)
                dpSell[i]=max(dpSell[i],dpnotSell[i-2]+max(prices[i]-prices[i-1],0));//允许新增交易的情况            
            dpnotSell[i]=max(dpnotSell[i-1],dpSell[i-1]);
        }
        return max(dpnotSell[k-1],dpSell[k-1]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=prices.size();
        int dp_i_0=0,dp_i_1=INT_MIN,dp_pre_0=0;//dp_pre_0代表dp[i-2][0]
        for(int i=0;i<k;i++){
            int temp=dp_i_0;
            dp_i_0=max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1=max(dp_i_1,dp_pre_0-prices[i]);
            dp_pre_0=temp;
        }
        return dp_i_0;
    }
};
