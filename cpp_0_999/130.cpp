/*
 * 130. 被围绕的区域
 * 题意：只有和边界接壤的元素保留O，否则全部设为X
 * 难度：中等
 * 分类：搜索
 * 算法：从每个边界元素向内搜索，没被访问到的全部设为X
 */
class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(vector<vector<bool>> &visited, int x, int y, vector<vector<char>> &board){
        int m = board.size(), n = board[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || board[x][y]=='X'){
            return;
        }
        visited[x][y]=true;
        for(int i = 0; i < 4; i ++){
            dfs(visited, x+dx[i], y+dy[i], board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m ; i++){
            dfs(visited, i, 0, board);
            dfs(visited, i, n-1, board);
        }
        for(int i = 0; i < n; i++){
            dfs(visited, 0, i, board);
            dfs(visited, m-1, i, board);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
