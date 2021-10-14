/*
 * 51. N 皇后
 * 题意：经典n皇后问题，皇后横竖斜不能互相攻击
 * 难度：困难
 * 分类：dfs 回溯
 * 算法：按行逐个摆放，回溯
 */
class Solution {
public:
    vector<vector<string>> ans;
    bool check(vector<string> &board, int x, int y){
        for(int i = 0; i < x; i++){
            if(board[i][y]=='Q')
                return false;
            int left_idx = y-(x-i);
            if(left_idx>=0 && board[i][left_idx]=='Q')
                return false;
            int right_idx = y+(x-i);
            if(right_idx<board.size() && board[i][right_idx]=='Q')
                return false;
        }
        return true;
    }
    void dfs(vector<string> &board, int row){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < board.size(); i++){
            if(check(board, row, i)){
                board[row][i]='Q';
                dfs(board, row+1);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string empty(n, '.');
        vector<string> board(n, empty);
        dfs(board, 0);
        return ans;
    }
};
