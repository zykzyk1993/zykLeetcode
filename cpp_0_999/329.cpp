/*
 * 329. 矩阵中的最长递增路径
 * 题意：可以上下左右移动
 * 难度：困难
 * 分类：dfs 拓扑排序
 * 算法：将矩阵转化为图，小的位置指向相邻的大的位置，然后采用拓扑排序，看最多需要多少step
 */
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> edges(m * n, vector<int>());
        vector<int> degree(m * n, 0);
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int idx = i * n + j;
                for (int k = 0; k < 4; k ++) {
                    int adj_x = i + dx[k];
                    int adj_y = j + dy[k];
                    if (adj_x >= 0 && adj_x < m && adj_y >= 0 && adj_y < n && matrix[adj_x][adj_y] > matrix[i][j]) {
                        int adj_idx = adj_x * n + adj_y;
                        edges[idx].push_back(adj_idx);
                        degree[adj_idx] ++;
                    }
                }
            }
        }

        queue<int> q;
        for(int i = 0; i < m * n; i ++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        } 
        int step = 0;
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                int cur = q.front();
                q.pop();
                for (auto &next_idx:edges[cur]) {
                    degree[next_idx]--;
                    if (degree[next_idx] == 0) {
                        q.push(next_idx);
                    }
                }
            }
            step++;
        }
        return step;
    }
};
