/*
 * 122. 买卖股票的最佳时机 II
 * 题意：每天都可以买进或卖出，求最大利润
 * 难度：中等
 * 分类：贪心
 * 算法：贪心计算，合理买卖情况下，每天都可以赚到差价
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res=0;
        for(int i=1;i<n;i++){
            res+=max(0, prices[i]-prices[i-1]);
        }
        return res;
    }
};
