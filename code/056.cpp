/*
 * 56. 合并区间
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 难度：困难
 * 分类：数组 排序
 * 算法：按照左端点从小到大排序然后遍历，保留当前集合右端点
 */
class Solution {
public:
    static bool cmp(const vector<int> &v1,const vector<int> &v2){
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0)return ans;
        sort(intervals.begin(),intervals.end(),cmp);
        int curLeft=intervals[0][0],curRight=intervals[0][1];
        for(auto interval:intervals){
            if(interval[0]<=curRight){
                curRight=max(interval[1],curRight);
            }else{
                ans.push_back({curLeft,curRight});
                curLeft=interval[0];
                curRight=interval[1];
            }
        }
        ans.push_back({curLeft,curRight});
        return ans;
    }
};
