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
