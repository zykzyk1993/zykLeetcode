/*
 * 188. 买卖股票的最佳时机 IV
 * 题意：最多交易k次，求最大收益
 * 难度：困难
 * 分类：dp
 * 算法：经典股票交易问题，设置持有和不持有的dp数组，代表最多进行k次时的最大收益，按照每天价格更新
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2) return 0;
        // 最多k次交易，持有和不持有
        vector<int> hold(k+1, -prices[0]), sell(k+1, 0);
        for(int i = 1; i<prices.size(); i++){
            for(int j = 1; j <= k; j ++){
                hold[j] = max(hold[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], hold[j] + prices[i]);
            }
        }
        return sell[k];
    }
};
