/*
 * 48. 旋转图像
 * 将图像矩阵顺时针旋转90
 * 难度：中等
 * 分类：数组 模拟
 * 算法：三种思路：先对角，再以竖轴对称；先以横轴对称，再对角;四个元素一轮换
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

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0, n = matrix.size() - 1;
        for(int i = 0; i <= n/2; i++){
            for(int j = i; j < n - i; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = temp;
            }
        }
    }
};
