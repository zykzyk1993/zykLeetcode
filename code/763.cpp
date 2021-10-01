/*
 * 763. 划分字母区间
 * 题意：尽可能多的划分字母区间，使得每个字母都只出现在一个区间
 * 难度：中等
 * 分类：贪心
 * 算法：按照左端点排序，贪心遍历，如果有交叠就更新右端点
 */
bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[0] < v2[0];
}
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<vector<int>> idx(26, vector<int>(2, -1));
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(idx[c-'a'][0]==-1){
                idx[c-'a'][0]=i;
            }
            idx[c-'a'][1]=i;
        }
        sort(idx.begin(), idx.end(), cmp);
        int cur_start=0, cur_end=0;
        for(auto &v:idx){
            if(v[0]==-1)
                continue;
            if(v[0]>cur_end){
                res.push_back(cur_end-cur_start+1);
                cur_start=v[0];
                cur_end=v[1];
            }
            else{
                cur_start=min(cur_start, v[0]);
                cur_end=max(cur_end, v[1]);
            }
        }
        res.push_back(cur_end-cur_start+1);
        return res;
    }
};
