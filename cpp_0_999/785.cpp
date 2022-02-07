/*
 * 785. 判断二分图
 * 题意：
 * 难度：中等
 * 分类：图
 * 算法：广度优先搜索并"上色"，或使用并查集
 */
//广度优先，标准二分图
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i ++){
            if(color[i] != -1){
                continue;
            }
            queue<int> q;
            color[i] = 0;
            int c = 0;
            q.push(i);
            while(!q.empty()){
                int m = q.size();
                c = 1 - c;
                for(int j = 0; j < m; j ++){
                    int cur = q.front();
                    q.pop();
                    for(auto &next:graph[cur]){
                        if(color[next] == -1){
                            color[next] = c;
                            q.push(next);
                        }else{
                            if(color[next] == color[cur]){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
//并查集
class Solution {
public:
    static const int N = 210;
    static const int offset = 105;
    int pa[N], rk[N];

    void init() {
        for(int i = 0; i < N; i++) {
            pa[i] = i;
        }
    }

    int find(int x) {
        return pa[x] == x? x : pa[x] = find(pa[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    void merge(int x, int y) {
        if(same(x, y)) {
            return;
        }
        if(rk[pa[x]] < rk[pa[y]]) {
            pa[pa[x]] = pa[pa[y]];
        } else {
            rk[pa[x]] += rk[pa[x]] == rk[pa[y]];
            pa[pa[y]] = pa[pa[x]];
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        init();
        int n = graph.size();
        for(int i = 0; i < n; i++) {
            for(auto t : graph[i]) {
                if(same(t, i) || same(t + offset, i + offset)) {
                    return false;
                }
                merge(t, i + offset);
                merge(i, t + offset);
            }
        }
        return true;
    }
};
