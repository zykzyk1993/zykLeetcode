/*
 * 547. 省份数量
 * 题意：求连通域个数
 * 难度：中等
 * 分类：dfs
 * 算法：dfs即可，注意数据结构的变化，用isConnected[i][i]保存是否访问过
 */
class Solution {
public: 
    int findCircleNum(vector<vector<int>>& isConnected) {
        stack<int> s;
        int ans = 0;
        int n = isConnected.size();
        for(int i = 0; i < n; i++){
            if(isConnected[i][i]==0)
                continue;
            isConnected[i][i]=0;
            ans++;
            s.push(i);
            while(!s.empty()){
                int cur = s.top();
                s.pop();
                for(int j = 0; j < n; j++){
                    if(isConnected[j][j]==1&&isConnected[cur][j]==1){
                        isConnected[j][j]=0;
                        s.push(j);
                    }
                }
            }
        }
        return ans;
    }
};
