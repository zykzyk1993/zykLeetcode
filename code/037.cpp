/*
 * 37. 解数独
 * 题意：按照数独规则填写剩余数字
 * 难度：困难
 * 分类：dfs
 * 算法：dfs+回溯
 */
class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<char>> temp, int cur_idx, vector<vector<bool>> rows, vector<vector<bool>> cols, vector<vector<bool>> subboxes, bool &valid){
        if(valid)
            return;
        if(cur_idx == 81) {
            valid = true;
            board = temp;
            return;
        }
        int row = cur_idx / 9, col = cur_idx % 9, sub_box=row/3*3+col/3;
        if (board[row][col]!='.'){
            dfs(board, temp, cur_idx+1, rows, cols, subboxes, valid);
        }
        else{
            for(int i=0;i<9;i++){
                if(rows[row][i])continue;
                if(cols[col][i])continue;
                if(subboxes[sub_box][i])continue;
                rows[row][i]=true;
                cols[col][i]=true;
                subboxes[sub_box][i]=true;
                temp[row][col]='0'+i+1;
                dfs(board, temp, cur_idx+1, rows, cols, subboxes, valid);
                rows[row][i]=false;
                cols[col][i]=false;
                subboxes[sub_box][i]=false;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9));
        vector<vector<bool>> columns(9, vector<bool>(9));
        vector<vector<bool>> subboxes(9, vector<bool>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int index = c - '0' - 1;
                    rows[i][index]=true;
                    columns[j][index]=true;
                    subboxes[i / 3 * 3 + j / 3][index]=true;
                }
            }
        }
        vector<vector<char>> temp = board;
        bool valid = false;
        dfs(board, temp, 0, rows, columns, subboxes, valid);
    }
};

class Solution {
private:
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9];
    bool valid;
    vector<pair<int, int>> spaces;

public:
    void dfs(vector<vector<char>>& board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        auto [i, j] = spaces[pos];
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = digit + '0' + 1;
                dfs(board, pos + 1);
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(line, false, sizeof(line));
        memset(column, false, sizeof(column));
        memset(block, false, sizeof(block));
        valid = false;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.emplace_back(i, j);
                }
                else {
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }

        dfs(board, 0);
    }
};
