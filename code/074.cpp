/*
 * 74. 搜索二维矩阵
 * 题意：二维矩阵，从左到右递增，下一行严格大于上一行，判断给定元素是否在矩阵中
 * 难度：中等
 * 分类：二分
 * 算法：展平为一维数组二分查找
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            int num = matrix[mid/n][mid%n];
            if (num == target) {
                return true;
            }
            if (num < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};
