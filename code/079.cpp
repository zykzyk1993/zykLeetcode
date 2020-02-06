/*
 * 79. 单词搜索
 * 二维网格，可以四个方向游走，确定单词是否在其中
 * 难度：中等
 * 分类：dfs 回溯
 * 算法：从每一个位置开始经典dfs和回溯
 */
class Solution {
public:
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    bool flag=false;
    bool check(int x, int y, int cur, vector<vector<char>>& board, vector<vector<bool>>& visited, string &word){
        return x>=0&&x<board.size()&&y>=0&&y<board[0].size()&&!visited[x][y]&&board[x][y]==word[cur];
    }
    void dfs(int x, int y, int cur, string &word, vector<vector<char>>& board, vector<vector<bool>> &visited){
        if(flag)return;
        if(cur==word.size()-1){
            flag=true;
            return;
        }
        for(int i=0;i<4;i++){
            int nextX=x+dx[i];
            int nextY=y+dy[i];
            if(check(nextX,nextY,cur+1,board,visited,word)){
                visited[nextX][nextY]=true;
                dfs(nextX,nextY,cur+1,word,board,visited);
                visited[nextX][nextY]=false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(!m)return false;
        int n=board[0].size();
        if(!n)return false;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        string temp="";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(check(i,j,0,board,visited,word)){
                    visited[i][j]=true;
                    dfs(i,j,0,word,board,visited);
                    visited[i][j]=false;
                }
                if(flag)return true;
            }
        }
        return flag;
    }
};

//代码优化
class Solution {
public:
    bool exist(vector<vector<char>>& board, string str) {
        for (int i = 0; i < board.size(); i ++ )
            for (int j = 0; j < board[i].size(); j ++ )
                if (dfs(board, str, 0, i, j))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &str, int u, int x, int y) {
        if (board[x][y] != str[u]) return false;
        if (u == str.size() - 1) return true;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        char t = board[x][y];
        board[x][y] = '*';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < board.size() && b >= 0 && b < board[a].size()) {
                if (dfs(board, str, u + 1, a, b)) return true;
            }
        }
        board[x][y] = t;
        return false;
    }
};
