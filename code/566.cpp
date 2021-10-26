/*
 * 566. 重塑矩阵
 * 题意：执行reshape操作，不合法的话返回原矩阵
 * 难度：简单
 * 分类：模拟
 * 算法：计算1维的index，再反推回去
 */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>> ans = vector<vector<int>> (r, vector<int>(c, 0));
        for(int i = 0; i < r; i ++) {
            for(int j = 0; j < c; j ++){
                int index = i * c + j;
                int m_idx = index / n, n_idx = index % n;
                ans[i][j] = mat[m_idx][n_idx];
            }
        }
        return ans;
    }
};
