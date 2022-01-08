/*
 * 1254. 统计封闭岛屿的数目
 * 题意：统计被水域包围的岛屿数量
 * 难度：中等
 * 分类：dfs
 * 算法：和1020题类似，先dfs边缘陆地，淹掉所有连接的陆地，再根据dfs次数计算岛屿数量
 */
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 1) {
            return;
        }
        grid[i][j] = 1;
        for(int k = 0; k < 4; k ++) {
            dfs(grid, i + dx[k], j + dy[k]);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i ++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int i = 0; i < n; i ++) {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }
        int ans = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 0){
                    dfs(grid, i, j);
                    ans ++;
                }
            }
        }
        return ans;
    }
};
