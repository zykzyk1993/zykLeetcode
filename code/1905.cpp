/*
 * 1905. 统计子岛屿
 * 题意：grid2的岛屿完全被grid1包围，则称为子岛屿，统计子岛屿个数
 * 难度：中等
 * 分类：dfs
 * 算法：先dfs淹掉grid2中，grid1为0，grid2为1的部分，再正常dfs
 */
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size(), res = 0;
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(grid1[i][j] == 0 && grid2[i][j] == 1){
                    dfs(grid2, i, j);
                }
            }
        }
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(grid2[i][j] == 1){
                    dfs(grid2, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid2, int i, int j){
        int m = grid2.size(), n = grid2[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid2[i][j] == 0){
            return;
        }
        grid2[i][j] = 0;
        dfs(grid2, i+1, j);
        dfs(grid2, i-1, j);
        dfs(grid2, i, j+1);
        dfs(grid2, i, j-1);
    }
};
