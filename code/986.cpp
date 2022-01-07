/*
 * 986. 区间列表的交集
 * 题意：给定两组排序好的区间列表，每组区间列表内部都不想交，求两组的所有交集区间
 * 难度：中等
 * 分类：双指针
 * 算法：用IOU的方法求交集，然后推进右端较小的那个指针
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        vector<vector<int>> res;
        while(i < m && j < n) {
            int left = max(firstList[i][0], secondList[j][0]);
            int right = min(firstList[i][1], secondList[j][1]);
            if (left <= right) {
                res.push_back({left, right});
            }
            if (firstList[i][1] < secondList[j][1]) {
                i ++;
            }
            else {
                j ++;
            }
        }
        return res;
    }
};
