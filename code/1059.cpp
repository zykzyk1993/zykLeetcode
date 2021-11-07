/*
 * 1059. 从始点到终点的所有路径
 * 题意：判断该图是否只包含有限条，从起始点到终点的路径
 * 难度：中等
 * 分类：图
 * 算法：采用dfs判断是否有环，排除终点后有后继、有环、终结在非终点的情况
 */
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
    	vector<bool> visited(n, false);
    	vector<vector<int>> m(n);
    	for(auto& e : edges)
    		m[e[0]].push_back(e[1]);
    	if(!m[destination].empty())
    		return false;//终点后面还有路径
		  return dfs(m,visited,source,destination);
    }
    bool dfs(vector<vector<int>>& m, vector<bool>& visited, int cur, int destination) 
    {
    	if(m[cur].size()==0 && cur != destination)
    		return false;//到达一个终点，但不是目标点
    	for(int next : m[cur])//往下走
    	{
    		if(visited[next])//访问过了
    			return false;//有环
    		visited[next] = true;//访问
    		if(!dfs(m, visited, next, destination))
    			return false;
    		visited[next] = false;//回溯
    	}
      return true;
    }
};
