/*
 * 48. 旋转图像
 * 将图像矩阵顺时针旋转90
 * 难度：中等
 * 分类：数组 模拟
 * 算法：两种思路：先对角，再以竖轴对称；先以横轴对称，再对角
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-j;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
