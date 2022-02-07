/*
 * 773. 滑动谜题
 * 题意：给定两行三列的puzzle，0为可滑动位置，求变成123 450最小步数，不能解决则返回-1
 * 难度：困难
 * 分类：bfs
 * 算法：用字符串保存visited，预先设定好每个位置如果是0的可滑动方向，bfs
 */
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string correct = "123450";
        int step = 0;
        vector<vector<int>> next_idx = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };
        string cur;
        for(int i = 0; i < 2; i ++) {
            for (int j = 0; j < 3; j ++) {
                cur += (char)(board[i][j] + '0');
            }
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push(cur);
        visited.insert(cur);
        while(!q.empty()) {
            int n = q.size();
            while(n--){
                string temp = q.front();
                q.pop();
                if (temp == correct) {
                    return step;
                }
                int zero_idx = 0;
                for (zero_idx = 0; zero_idx < 6; zero_idx ++) {
                    if (temp[zero_idx] == '0') {
                        break;
                    }
                }
                for(auto idx:next_idx[zero_idx]) {
                    string next = temp;
                    swap(next[idx], next[zero_idx]);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
