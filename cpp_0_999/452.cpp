/*
 * 452. 用最少数量的箭引爆气球
 * 题意：有交叠的可以一次性引爆，最少用几支箭
 * 难度：中等
 * 分类：贪心
 * 算法：按照右端点排序，如果左端点大于右端点，结果加1，更新右端点
 */

bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[1] < v2[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0) return 0;
        int cnt = 1;
        sort(intervals.begin(), intervals.end(), cmp);
        int cur_end = intervals[0][1];
        for(auto &v:intervals){
            if(v[0]>cur_end){
                cnt++;
                cur_end=v[1];
            }
        }
        return cnt;
    }
};
