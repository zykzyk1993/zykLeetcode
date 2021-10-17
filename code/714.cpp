/*
 * 714. 买卖股票的最佳时机含手续费
 * 题意：无限次交易，每次需要交手续费
 * 难度：中等
 * 分类：dp
 * 算法：直接在122题的dp递推上每次买入需要减去交易费用即可
 */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0] - fee, sell = 0;
        for(int i = 1; i < prices.size(); i ++){
            hold = max(hold, sell - prices[i] - fee);
            sell = max(sell, hold + prices[i]);
        }
        return sell;
    }
};
