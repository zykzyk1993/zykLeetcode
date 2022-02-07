/*
 * 1288. 删除被覆盖区间
 * 题意：给定区间列表中，删除完全被覆盖的区间，返回剩余数量
 * 难度：中等
 * 分类：数组
 * 算法：按照起点排序，起点相等终点逆序，然后遍历，判断终点是否小于当前，即可
 */
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2){
            if(v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        });
        int end = intervals[0][1];
        int res = 1;
        for (int i = 1; i < intervals.size(); i ++) {
            if (intervals[i][1] <= end) {
                continue;
            }
            res++;
            end = intervals[i][1];
        }
        return res;
    }
};
