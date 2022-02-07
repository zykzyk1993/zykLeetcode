/*
 * 240. 搜索二维矩阵 II
 * 在从左到右从上到下递增的矩阵中快速查找
 * 难度：中等
 * 分类：二分 分治
 * 算法：从右上角开始，根据大小情况来左移或者下移
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(!m)return false;
        int n=matrix[0].size();
        if(!n)return false;
        int i=0,j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]<target)i++;
            else j--;
        }
        return false;
    }
};
