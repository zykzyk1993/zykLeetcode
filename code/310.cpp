/*
 * 310. 最小高度树
 * 题意：给定一个树，选择任意一个结点为根结点，使树高度最小，求这些根结点
 * 难度：中等
 * 分类：树 bfs
 * 算法：必须从叶子结点向内进行bfs，参考拓扑排序，保存度，更新度，当度为0时进入队列
 */
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        vector<int> degrees(n, 0);
        vector<vector<int>> links(n);
        for(auto &v:edges){
            degrees[v[0]]++;
            degrees[v[1]]++;
            links[v[0]].push_back(v[1]);
            links[v[1]].push_back(v[0]);
        }
        queue<int> q;
        vector<bool> visited(n);
        vector<int> cur_level, next_level;
        for(int i = 0; i < n; i++){
            if(degrees[i] == 1){
                q.push(i);
                visited[i] = true;
                next_level.push_back(i);
                degrees[i] = 0;
            }
        }
        while(!q.empty()){
            int points = q.size();
            cur_level = next_level;
            next_level.clear();
            while(points--){
                int v = q.front();
                q.pop();
                for(auto &j:links[v]){
                    if(visited[j])
                        continue;
                    degrees[j]--;
                    if(degrees[j] == 1){
                        q.push(j);
                        next_level.push_back(j);
                        visited[j] = true;
                    }
                }
            }
        }
        return cur_level;
    }
};
