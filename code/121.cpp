 /*
 * 121. 买卖股票的最佳时机
 * 只能买卖一次，最佳时机
 * 难度：简单
 * 分类：数组 dp
 * 算法：记录minPre即可
 */
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
