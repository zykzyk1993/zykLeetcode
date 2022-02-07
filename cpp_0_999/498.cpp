/*
 * 498. 对角线遍历
 * 题意：按照右上左下右上的方式对角线遍历矩阵
 * 难度：中等
 * 分类：模拟
 * 算法：模拟，注意两个方向遍历到头后如何改变指针
 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        int i = 0, j = 0, dir = 1;
        while(res.size() < m * n) {
            res.push_back(mat[i][j]);
            if (dir == 1) {
                if (i > 0 && j < n - 1) {
                    i --;
                    j ++;
                }
                else {
                    if(j < n - 1) {
                        j++;
                    }
                    else {
                        i++;
                    }
                    dir = 0;
                }
            }
            else {
                if (i < m - 1 && j > 0) {
                    i ++;
                    j --;
                }
                else {
                    if (i < m - 1) {
                        i ++;
                    }
                    else {
                        j ++;
                    }
                    dir = 1;
                }
            }
        }
        return res;
    }
};
