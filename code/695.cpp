/*
 * 695. 岛屿的最大面积
 * 题意：01矩阵，求最大连通域
 * 难度：中等
 * 分类：dfs
 * 算法：dfs从每个元素开始搜索，将1置为0
 */
class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int ans = 0;
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()){
            return 0;
        }
        if(grid[x][y]==0){
            return 0;
        }
        int area = 1;
        grid[x][y] = 0;
        for(int i = 0;i < 4; i++){
            area+=dfs(grid, x+dx[i], y+dy[i]);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
