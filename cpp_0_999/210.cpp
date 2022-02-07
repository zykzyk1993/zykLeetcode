/*
 * 210. 课程表 II
 * 题意：给定课程和先修课程，求可行的课程完成顺序
 * 难度：中等
 * 分类：图 拓扑排序
 * 算法：标准拓扑排序，记录入度，每次删除入度和邻接表，每次队列里push入度为0的节点
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto &prerequisite:prerequisites){
            degree[prerequisite[0]]++;
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<int> res;
        queue<int> q;
        for(int i = 0; i < numCourses; i ++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int t = q.front();
            res.push_back(t);
            q.pop();
            for(auto &next:adj[t]){
                degree[next]--;
                if(degree[next] == 0){
                    q.push(next);
                }
            }
        }
        vector<int> empty;
        return res.size() == numCourses ? res:empty;
    }
};
