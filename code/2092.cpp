/*
 * 2092.找出知晓秘密的所有专家
 * 题意：给出一个会议时间表，0和firstperson知道秘密，随着会议传播，最终多少人知道秘密
 * 难度：困难
 * 分类：并查集
 * 算法：并查集，按照时间戳遍历，详细见注释
 */
class Solution {
public:
    int find(int x, vector<int> &parent){
        if(parent[x] == x)return x;
        parent[x] = find(parent[x], parent);
        return parent[x];
    }
    void merge(int x, int y, vector<int> &parent){
        int a = find(x, parent);
        int b = find(y, parent);
        if(a == 0) parent[b] = a;
        else parent[a] = b;
    }
    bool isSame(int x, int y, vector<int> &parent){
        return find(x, parent) == find(y, parent);
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> know(n, false); // 标记是否know
        map<int, vector<vector<int>>> m; // 按照时间戳保存meetings
        vector<int> parent(n, -1); // 并查集parent
        // 初始化
        know[0] = true;
        know[firstPerson] = true;
        for(int i = 0; i < n; i ++){
            parent[i] = know[i]?0:i;
        }
        for(auto &meeting:meetings){
            m[meeting[2]].push_back(meeting);
        }
        for(auto &p:m){
            vector<vector<int>> current_meetings = p.second;
            set<int> s; // 用于保存这次可能会know的candidate（在这之前不know但本次时间有活动的人）
            for(auto &cur_meet:current_meetings){
                int p_a = cur_meet[0], p_b = cur_meet[1];
                if(know[p_a] && know[p_b]) continue;
                if(!know[p_a] && s.count(p_a) == 0) s.insert(p_a);
                if(!know[p_b] && s.count(p_b) == 0) s.insert(p_b);
                merge(p_a, p_b, parent);
            }
             for(auto &candidate:s){ // 遍历所有candidate
                if(isSame(candidate, 0, parent)){
                    know[candidate] = true; // 如果确实和0连接了 则设置
                }else{
                    parent[candidate] = candidate; // 否则将parent回退到自己本身，这一步很关键
                }
             }
        }
        vector<int> res;
        for(int i = 0; i < n; i ++){
            if(know[i])res.push_back(i);
        }
        return res;
    }
};
