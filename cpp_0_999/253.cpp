/*
 * 253. 会议室 II
 * 给定起始和终止时间，至少需要多少间会议室，才能满足这些会议安排
 * 难度：中等
 * 分类：贪心 堆
 * 算法：先按照起始时间排序，然后贪心插入堆，每次查看堆顶(最小可安排的会议室)是否出堆
 */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b){
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < intervals.size(); i++) {
            if (!heap.empty() && heap.top() <= intervals[i][0]) {
                heap.pop();
            }
            heap.push(intervals[i][1]);
        }
        return heap.size();
    }
};
