/*
 * 406. 根据身高重建队列
 * 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。
 * 难度：中等
 * 分类：贪心
 * 算法：矮的人相对高的人是看不见的，先排高的人，然后按顺序插入矮的人
 */
class Solution {
public:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        if(v1[1]==v2[1])return v1[0]>v2[0];
        return v1[1]<v2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),cmp);
        for(auto p:people){
            int cnt=0,i=0;
            for(i=0;i<ans.size()&&cnt<p[1];i++){
                if(ans[i][0]>=p[0])cnt++;
            }
            ans.insert(ans.begin()+i,p);
        }
        return ans;
    }
};

//elegant solution
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序
        sort(people.begin(), people.end(),
                [](const vector<int>& lhs, const vector<int>& rhs)
                 {return lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0];});
        int len = people.size();
        list<vector<int>> tmp;
        // 循环插入
        for(int i = 0; i < len; ++i){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        // 重建vector返回
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};
