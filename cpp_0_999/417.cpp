/*
 * 417. 太平洋大西洋水流问题
 * 题意：左上为太平洋，右下为大西洋，从高向低流动，找出可以同时流到两个大洋的地区
 * 难度：中等
 * 分类：dfs
 * 算法：需要变通，从左上边界和右下边界，判断可以倒流回的区域，取交集
 */
class Solution {
public:
    vector<vector<int>> P, A, ans;
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& M) {
        n = M.size(), m = M[0].size();
        P = A = vector<vector<int>>(n, vector<int>(m, 0));
        //左右两边加上下两边出发深搜
        for(int i = 0; i < n; ++i) dfs(M, P, i, 0), dfs(M, A, i, m - 1);
        for(int j = 0; j < m; ++j) dfs(M, P, 0, j), dfs(M, A, n - 1, j);             
        return ans;
    }
    void dfs(vector<vector<int>>& M, vector<vector<int>>& visited, int i, int j){        
        if(visited[i][j]) return;
        visited[i][j] = 1;

        if(P[i][j] && A[i][j]) ans.push_back({i,j}); 

        //上下左右深搜
        if(i-1 >= 0 && M[i-1][j] >= M[i][j]) dfs(M, visited, i-1, j);
        if(i+1 < n && M[i+1][j] >= M[i][j]) dfs(M, visited, i+1, j); 
        if(j-1 >= 0 && M[i][j-1] >= M[i][j]) dfs(M, visited, i, j-1);
        if(j+1 < m && M[i][j+1] >= M[i][j]) dfs(M, visited, i, j+1); 
    }
};
