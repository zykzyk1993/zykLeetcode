/*
 * 1024. 视频拼接
 * 题意：给定视频剪辑片段，判断最少能凑成完整的0～n的视频的个数，不行则返回-1
 * 难度：中等
 * 分类：数组 贪心
 * 算法：和跳跃游戏类似，按照起点排序，每次更新next能到达的位置，如果下一个视频在next之后则无法拼接，如果在end之后则需要添加一段视频
 */
class Solution {
public:
    int videoStitching(vector<vector<int>>& intervals, int time) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2){
            if(v1[0] == v2[0]) {
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        });
        if(intervals[0][0] > 0) {
            return -1;
        }
        int end = intervals[0][1];
        int res = 1, next = end;
        for (int i = 1; i < intervals.size() && end < time; i ++) {
            if (intervals[i][0] > next) {
                return -1;
            }
            if (intervals[i][0] > end) {
                res++;
                end = next;
            }
            next = max(next, intervals[i][1]);
        }
        if (end < time && next >= time) {
            res++;
            end = time;
        }
        return end >= time ? res : -1;
    }
};
