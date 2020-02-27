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
