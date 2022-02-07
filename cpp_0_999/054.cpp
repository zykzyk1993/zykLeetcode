 /*
 * 54. 螺旋矩阵
 * 题意：按照螺旋的形式，从外向内打印矩阵的元素
 * 难度：中等
 * 分类：模拟
 * 算法：设定lrtb四个变量表示当前未访问元素的边界，然后每层分为四趟遍历
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int l = 0, r = n - 1, t = 0, b = m - 1;
        while(l <= r && t <= b) {
            for(int i = l; i <= r; i ++) {
                ans.push_back(matrix[t][i]);
            }
            t++;
            if (t > b) break;
            for(int i = t; i <= b; i ++) {
                ans.push_back(matrix[i][r]);
            }
            r--;
            if (l > r) break;
            for(int i = r; i >= l; i --) {
                ans.push_back(matrix[b][i]);
            }
            b--;
            if (t > b) break;
            for(int i = b; i >= t; i --) {
                ans.push_back(matrix[i][l]);
            }
            l++;
            if (l > r) break;
        }
        return ans;
    }
};
