 /*
 * 200. 岛屿数量
 * 01矩阵计算岛屿的总数(连通域个数)
 * 难度：中等
 * 分类：dfs
 * 算法：标准四向dfs，计算dfs次数
 */
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    void dfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[0].size() && grid[tx][ty] == '1')
                dfs(tx, ty, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid);
                }
        return ans
