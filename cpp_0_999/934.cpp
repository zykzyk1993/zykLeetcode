/*
 * 934. 最短的桥
 * 题意：两个连通域之间的最短距离
 * 难度：中等
 * 分类：bfs
 * 算法：bfs两次，先将第一个连通域全部置为2，并将第一连通域所有元素作为第二次搜索的第一层，然后逐层往外计算最小step
 */
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int start_x = -1, start_y = -1, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m && start_x < 0; i++){
            for(int j = 0; j < n && start_x < 0; j++){
                if(grid[i][j]==1){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        int dx[4]={0, 1, 0, -1};
        int dy[4]={1, 0, -1, 0};
        queue<pair<int, int>> q;
        queue<pair<int, int>> q2;
        q.push(make_pair(start_x, start_y));
        int step = 0;
        grid[start_x][start_y]=2;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            q2.push(p);
            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++){
                int next_x = x + dx[i], next_y = y + dy[i];
                if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y] == 1){
                    grid[next_x][next_y] = 2;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }

        while(!q2.empty()){
            step++;
            int k = q2.size();
            while(k--){
                pair<int, int> p = q2.front();
                q2.pop();
                int x = p.first, y = p.second;
                for(int i = 0; i < 4; i++){
                    int next_x = x + dx[i], next_y = y + dy[i];
                    if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n){
                        if(grid[next_x][next_y] == 2){
                            continue;
                        }
                        if(grid[next_x][next_y] == 1){
                            return step - 1;
                        }
                        grid[next_x][next_y] = 2;
                        q2.push(make_pair(next_x, next_y));
                    }
                }
            }
        }
        return step;
    }
};
