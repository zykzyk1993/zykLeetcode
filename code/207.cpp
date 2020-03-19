 /*
 * 207. 课程表
 * 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习
 * 难度：中等
 * 分类：图 dfs 拓扑排序
 * 算法：经典拓扑排序，使用队列
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> emptyVec;
        vector<vector<int>> courses(numCourses, emptyVec);
        vector<int> degree(numCourses, 0);
        for(auto pres:prerequisites){
            courses[pres[1]].push_back(pres[0]);
            degree[pres[0]]++;
        }
        int finished = 0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int courseIdx = q.front();
            q.pop();
            finished++;
            for(auto c:courses[courseIdx]){
                degree[c]--;
                if(degree[c]==0)q.push(c);
            }
        }
        return finished==numCourses;
    }
};
