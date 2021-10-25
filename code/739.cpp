/*
 * 739. 每日温度
 * 题意：求下一次更高温度的天数，没有记录为0
 * 难度：中等
 * 分类：单调栈
 * 算法：保存单调递减栈，每次出栈更新栈顶索引的值为i-s.top()
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for(int i = 0; i < n ; i ++) {
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
