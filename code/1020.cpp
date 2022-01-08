/*
 * 1020. 飞地的数量
 * 题意：1为陆地，0为水域，返回无法任意次移动后离开网格的区域数量
 * 难度：中等
 * 分类：dfs
 * 算法：边界所有1dfs一次，淹没之后，就剩下无法离开的飞地，遍历计数得到结果
 */
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        for(int k = 0; k < 4; k ++) {
            dfs(grid, i + dx[k], j + dy[k]);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
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
                if (grid[i][j] == 1){
                    ans ++;
                }
            }
        }
        return ans;
    }
};
