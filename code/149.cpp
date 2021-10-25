/*
 * 149. 直线上最多的点数
 * 题意：给定点列表中，同一条直线上最多有几个点
 * 难度：困难
 * 分类：数学 哈希表
 * 算法：哈希表记录，以当前结点为第一个结点，记录后续结点的斜率
 * 注意，相同的点可以加入每一条直线，垂直的点没有斜率，要单独记录
 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for(int i = 0; i < n; i ++){
            unordered_map<double, int> m;
            int start_points = 1, vertical_points = 0, other_points = 0;
            for(int j = i + 1; j < n; j ++){
                if(points[j] == points[i]){
                    start_points++;
                    continue;
                }
                if(points[j][0] == points[i][0]){
                    vertical_points ++;
                    continue;
                }
                double k = (points[i][1] - points[j][1]) * 1.0/ (points[i][0] - points[j][0]);
                m[k] ++;
                other_points = max(m[k], other_points);
            }
            ans = max(ans, max(other_points, vertical_points) + start_points);
        }
        return ans;
    }
};
