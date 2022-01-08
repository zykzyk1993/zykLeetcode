/*
 * 1109. 航班预订统计
 * 题意：给定航班预订数组，求每个航班被预订的座位总数
 * 难度：中等
 * 分类：差分数组
 * 算法：和拼车类似，按照头尾记录每个航班和前一个的差分数组
 */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> cnt(n + 1, 0); //差分数组
        for(auto &booking:bookings) {
            cnt[booking[0] - 1] += booking[2];
            cnt[booking[1]] -= booking[2];
        }
        int cur = 0;
        vector<int> ans;
        for(int i = 0; i < n; i ++) {
            cur += cnt[i];
            ans.push_back(cur);
        }
        return ans;
    }
};
