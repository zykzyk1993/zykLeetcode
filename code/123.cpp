/*
 * 123. 买卖股票的最佳时机 III
 * 题意：最多可以交易2次，持有的时候不能买入
 * 难度：困难
 * 分类：dp
 * 算法：利用188题的模板，次数k为2，维护持有和不持有两个dp数组
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        // 最多k次交易，持有和不持有
        int k = 2;
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
