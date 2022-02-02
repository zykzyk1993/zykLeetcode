/*
 * 59. 螺旋矩阵 II
 * 题意：螺旋向内遍历矩阵
 * 难度：中等
 * 分类：模拟
 * 算法：设置四个变量表示边界，然后每次一个方向，在最外侧行列遍历
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1, l = 0, r = n - 1, t = 0, b = n - 1;
        while(num <= n * n) {
            for (int i = l; i <= r; i++) {
                res[t][i] = num;
                num ++;
            }
            t++;
            if (num > n * n) {
                break;
            }
            for (int i = t; i <= b; i++) {
                res[i][r] = num;
                num ++;
            }
            r--;
            if (num > n * n) {
                break;
            }
            for (int i = r; i >= l; i--) {
                res[b][i] = num;
                num ++;
            }
            b--;
            if (num > n * n) {
                break;
            }
            for (int i = b; i >= t; i--) {
                res[i][l] = num;
                num ++;
            }
            l++;
        }
        return res;
    }
};
